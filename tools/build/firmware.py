"""处理 SDCC 链接产物：生成 HEX/BIN、校验布局并显示空间统计。"""
# /// script
# requires-python = ">=3.11"
# dependencies = []
# ///

import argparse
from pathlib import Path
import re
import subprocess
import sys

RESET = 0xFF0000
CODE_END = 0x1000000
XRAM_BASE = 0x010000
XRAM_END = 0x030000
STACK_BASE = 0x0100
EDATA_END = 0x4000


def read_hex(path: Path) -> dict[int, int]:
    """支持扩展段/线性地址；每条记录检查长度、校验和和地址重叠。"""
    return parse_hex(path.read_text(encoding="ascii"))


def parse_hex(text: str) -> dict[int, int]:
    memory: dict[int, int] = {}
    base = 0
    ended = False
    for number, line in enumerate(text.splitlines(), 1):
        if not line.strip():
            continue
        if ended or not line.startswith(":"):
            raise ValueError(f"HEX 第 {number} 行格式错误")
        record = bytes.fromhex(line[1:])
        if len(record) < 5 or len(record) != record[0] + 5 or sum(record) & 0xFF:
            raise ValueError(f"HEX 第 {number} 行长度或校验和错误")
        count, high, low, kind = record[:4]
        data = record[4:-1]
        offset = (high << 8) | low
        if kind == 0:
            for index, value in enumerate(data):
                address = base + offset + index
                if address in memory:
                    raise ValueError(f"HEX 地址重复：0x{address:06X}")
                memory[address] = value
        elif kind == 1 and count == 0 and offset == 0:
            ended = True
        elif kind in (2, 4) and count == 2 and offset == 0:
            base = int.from_bytes(data, "big") << (4 if kind == 2 else 16)
        elif kind in (3, 5) and count == 4:
            pass  # 启动地址记录不是程序数据。
        else:
            raise ValueError(f"HEX 第 {number} 行包含无效记录类型 {kind}")
    if not ended or not memory:
        raise ValueError("HEX 缺少结束记录或程序数据")
    return memory


def read_areas(path: Path) -> list[tuple[str, int, int, str]]:
    areas = []
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        match = re.match(r"^\s*(\S+)\s+([\dA-Fa-f]{8})\s+([\dA-Fa-f]{8})\s+=.*\(([^)]*)\)", line)
        if match:
            name, address, size, flags = match.groups()
            area = name, int(address, 16), int(size, 16), flags
            if area not in areas:
                areas.append(area)
    if not areas:
        raise ValueError("无法读取 SDCC MAP 内存段")
    return areas


def read_symbols(path: Path) -> dict[str, int]:
    return {name: int(address, 16) for address, name in re.findall(
        r"^C:\s+([\dA-Fa-f]{8})\s+(_\w+)",
        path.read_text(encoding="utf-8", errors="replace"), re.M)}


def validate(memory: dict[int, int], areas: list[tuple[str, int, int, str]],
             symbols: dict[str, int]) -> None:
    for address in memory:
        if not RESET <= address < CODE_END:
            raise ValueError(f"代码超出默认程序区 FF0000..FFFFFF：0x{address:06X}")
    for address in range(RESET, RESET + 3):
        if address not in memory:
            raise ValueError("复位入口必须位于 0xFF0000")
    by_name = {name: (address, size) for name, address, size, _ in areas}
    home = by_name.get("HOME")
    gsinit0 = by_name.get("GSINIT0")
    stack_init = symbols.get("__stc32_stack_init")
    startup = symbols.get("__sdcc_gsinit_startup")
    if home is None or home[0] != RESET or gsinit0 is None:
        raise ValueError("缺少位于复位地址的 HOME 或后续的 GSINIT0 启动段")
    if startup != RESET + home[1] or gsinit0[0] != startup:
        raise ValueError("GSINIT0 启动入口必须紧跟 HOME")
    # 复位向量先用同区 LJMP 跳到 HOME 内的跳板，跳板再 EJMP 到启动入口。
    trampoline = RESET | (memory[RESET + 1] << 8) | memory[RESET + 2]
    if (memory[RESET] != 0x02 or trampoline < RESET + 3 or trampoline + 4 > startup
            or bytes(memory.get(trampoline + i, 0) for i in range(4))
            != b"\x8a" + startup.to_bytes(3, "big")):
        raise ValueError("复位跳板未跳到 GSINIT0 启动入口")
    # 板级 SPX 初始化应紧跟 GSINIT0，并在首次 C 调用前执行。
    if stack_init != startup + gsinit0[1] or by_name.get("GSINIT1", (None,))[0] != stack_init:
        raise ValueError("缺少 GSINIT1 中的板级 SPX 栈初始化")
    if bytes(memory.get(stack_init + i, 0) for i in range(6)) != bytes.fromhex("7581ff758500"):
        raise ValueError("SPX 启动代码必须在首次 C 调用前设置 SP=FF、SPH=00")
    for name, address, size, flags in areas:
        if not size:
            continue
        if "CODE" in flags and not (RESET <= address and address + size <= CODE_END):
            raise ValueError(f"代码段 {name} 超出默认的 64 KiB 程序区")
        if name in {"XSEG", "XISEG", "XSTK", "PSEG"}:
            if not (XRAM_BASE <= address and address + size <= XRAM_END):
                raise ValueError(f"数据段 {name} 超出 128 KiB XRAM")
        if name in {"DSEG", "ISEG", "OSEG"} and address + size > STACK_BASE:
            raise ValueError(f"near 数据段 {name} 超出保留的 256 字节区域，与 SPX 栈冲突")
        if name == "SSEG" and address + size > STACK_BASE:
            raise ValueError("启动 SSEG 占位超出 near 区域")
    code = [(name, address, address + size) for name, address, size, flags in areas
            if size and "CODE" in flags]
    for index, (left, start, end) in enumerate(code):
        for right, other_start, other_end in code[index + 1:]:
            if max(start, other_start) < min(end, other_end):
                raise ValueError(f"代码段重叠：{left} / {right}")
    if len({address for _, address, _ in code}) != len(code):
        raise ValueError("存在起始地址相同的非空代码段")


def main() -> int:
    sys.stdout.reconfigure(encoding="utf-8", newline="\n")
    sys.stderr.reconfigure(encoding="utf-8", newline="\n")
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--image", type=Path, required=True)
    parser.add_argument("--map", type=Path)
    parser.add_argument("--bin", type=Path)
    mode = parser.add_mutually_exclusive_group()
    mode.add_argument("--packihx", type=Path, help="用指定的 packihx 从 IHX 生成 HEX")
    mode.add_argument("--check", action="store_true", help="检查已有 HEX/BIN，不重新生成")
    args = parser.parse_args()
    args.map = args.map or args.image.with_suffix(".map")
    args.bin = args.bin or args.image.with_suffix(".bin")
    memory = read_hex(args.image)
    areas = read_areas(args.map)
    validate(memory, areas, read_symbols(args.map))
    packed = args.image.with_suffix(".hex")
    if args.packihx is not None:
        result = subprocess.run([args.packihx, args.image], capture_output=True)
        if result.returncode != 0:
            message = result.stderr.decode("utf-8", errors="replace").strip()
            raise ValueError(f"packihx 转换失败（退出码 {result.returncode}）：{message}")
        packed_memory = parse_hex(result.stdout.decode("ascii"))
    else:
        packed_memory = read_hex(packed)
    if packed_memory != memory:
        raise ValueError("HEX 与 IHX 地址或内容不一致")
    # BIN 从复位地址开始，填充中间未编程的 Flash 为 FF。
    binary = bytearray([0xFF]) * (max(memory) - RESET + 1)
    for address, value in memory.items():
        binary[address - RESET] = value
    if args.check:
        if args.bin.read_bytes() != binary:
            raise ValueError("BIN 与 IHX 地址或内容不一致")
    else:
        if args.packihx is not None:
            packed.write_bytes(result.stdout)
        args.bin.write_bytes(binary)
    xram_used = sum(size for name, _, size, _ in areas if name in {"XSEG", "XISEG", "PSEG"})
    print(f"固件：{args.image.stem}（MCS-251 Source，大端，24 位地址）")
    print("内存区域                  已用/预留         容量")
    print(f"CODE 实际记录字节         {len(memory):9d} B    {CODE_END - RESET:9d} B")
    print(f"XRAM 静态数据             {xram_used:9d} B    {XRAM_END - XRAM_BASE:9d} B")
    print(f"EDATA near 区预留         {STACK_BASE:9d} B    {EDATA_END:9d} B")
    print(f"SPX 栈预留                {EDATA_END - STACK_BASE:9d} B（不代表运行时峰值）")
    print("布局：程序区 FF0000..FFFFFF，复位 FF0000，XRAM 010000..02FFFF")
    print(f"BIN：基地址 0x{RESET:06X}，跨度 {len(binary)} B；下载优先使用保留地址的 HEX。")
    if args.check:
        print("固件检查通过：内存布局、复位入口、SPX 初始化和 HEX/BIN 一致性。")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except (OSError, ValueError) as error:
        print(f"固件检查失败：{error}", file=sys.stderr)
        raise SystemExit(2)
