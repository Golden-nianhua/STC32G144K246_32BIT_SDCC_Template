/* 由 tools/registers/generate_registers.py 从 Misc/Reference/aicube_generation.txt 生成。
 * 远地址保持 24 位；非经典 sbit 使用 NAME 读取、NAME_Set(value) 写入。
 * 修改源文件后重新生成，请勿在此直接修改。 */
#ifndef __STC32G144K246_H__
#define __STC32G144K246_H__

/////////////////////////////////////////////////

#include "compiler.h"



/////////////////////////////////////////////////

SFR(P0, 0x80);
    SBIT(P00, 0x80, 0);
    SBIT(P01, 0x80, 1);
    SBIT(P02, 0x80, 2);
    SBIT(P03, 0x80, 3);
    SBIT(P04, 0x80, 4);
    SBIT(P05, 0x80, 5);
    SBIT(P06, 0x80, 6);
    SBIT(P07, 0x80, 7);

SFR(SP, 0x81);
SFR(DPL, 0x82);
SFR(DPH, 0x83);
SFR(DPXL, 0x84);
SFR(SPH, 0x85);

SFR(PCON, 0x87);
#define SMOD STC_READ_BIT(PCON, 7)
#define SMOD_Set(value) STC_WRITE_BIT(PCON, 7, (value))
#define SMOD0 STC_READ_BIT(PCON, 6)
#define SMOD0_Set(value) STC_WRITE_BIT(PCON, 6, (value))
#define LVDF STC_READ_BIT(PCON, 5)
#define LVDF_Set(value) STC_WRITE_BIT(PCON, 5, (value))
#define POF STC_READ_BIT(PCON, 4)
#define POF_Set(value) STC_WRITE_BIT(PCON, 4, (value))
#define GF1 STC_READ_BIT(PCON, 3)
#define GF1_Set(value) STC_WRITE_BIT(PCON, 3, (value))
#define GF0 STC_READ_BIT(PCON, 2)
#define GF0_Set(value) STC_WRITE_BIT(PCON, 2, (value))
#define PD STC_READ_BIT(PCON, 1)
#define PD_Set(value) STC_WRITE_BIT(PCON, 1, (value))
#define IDL STC_READ_BIT(PCON, 0)
#define IDL_Set(value) STC_WRITE_BIT(PCON, 0, (value))

SFR(TCON, 0x88);
    SBIT(TF1, 0x88, 7);
    SBIT(TR1, 0x88, 6);
    SBIT(TF0, 0x88, 5);
    SBIT(TR0, 0x88, 4);
    SBIT(IE1, 0x88, 3);
    SBIT(IT1, 0x88, 2);
    SBIT(IE0, 0x88, 1);
    SBIT(IT0, 0x88, 0);

SFR(TMOD, 0x89);
#define T1_GATE STC_READ_BIT(TMOD, 7)
#define T1_GATE_Set(value) STC_WRITE_BIT(TMOD, 7, (value))
#define T1_CT STC_READ_BIT(TMOD, 6)
#define T1_CT_Set(value) STC_WRITE_BIT(TMOD, 6, (value))
#define T1_M1 STC_READ_BIT(TMOD, 5)
#define T1_M1_Set(value) STC_WRITE_BIT(TMOD, 5, (value))
#define T1_M0 STC_READ_BIT(TMOD, 4)
#define T1_M0_Set(value) STC_WRITE_BIT(TMOD, 4, (value))
#define T0_GATE STC_READ_BIT(TMOD, 3)
#define T0_GATE_Set(value) STC_WRITE_BIT(TMOD, 3, (value))
#define T0_CT STC_READ_BIT(TMOD, 2)
#define T0_CT_Set(value) STC_WRITE_BIT(TMOD, 2, (value))
#define T0_M1 STC_READ_BIT(TMOD, 1)
#define T0_M1_Set(value) STC_WRITE_BIT(TMOD, 1, (value))
#define T0_M0 STC_READ_BIT(TMOD, 0)
#define T0_M0_Set(value) STC_WRITE_BIT(TMOD, 0, (value))

SFR(TL0, 0x8a);
SFR(TL1, 0x8b);
SFR(TH0, 0x8c);
SFR(TH1, 0x8d);

SFR(AUXR, 0x8e);
#define T0x12 STC_READ_BIT(AUXR, 7)
#define T0x12_Set(value) STC_WRITE_BIT(AUXR, 7, (value))
#define T1x12 STC_READ_BIT(AUXR, 6)
#define T1x12_Set(value) STC_WRITE_BIT(AUXR, 6, (value))
#define S1M0x6 STC_READ_BIT(AUXR, 5)
#define S1M0x6_Set(value) STC_WRITE_BIT(AUXR, 5, (value))
#define T2R STC_READ_BIT(AUXR, 4)
#define T2R_Set(value) STC_WRITE_BIT(AUXR, 4, (value))
#define T2_CT STC_READ_BIT(AUXR, 3)
#define T2_CT_Set(value) STC_WRITE_BIT(AUXR, 3, (value))
#define T2x12 STC_READ_BIT(AUXR, 2)
#define T2x12_Set(value) STC_WRITE_BIT(AUXR, 2, (value))
#define EXTRAM STC_READ_BIT(AUXR, 1)
#define EXTRAM_Set(value) STC_WRITE_BIT(AUXR, 1, (value))
#define S1BRT STC_READ_BIT(AUXR, 0)
#define S1BRT_Set(value) STC_WRITE_BIT(AUXR, 0, (value))

SFR(INTCLKO, 0x8f);
#define EX4 STC_READ_BIT(INTCLKO, 6)
#define EX4_Set(value) STC_WRITE_BIT(INTCLKO, 6, (value))
#define EX3 STC_READ_BIT(INTCLKO, 5)
#define EX3_Set(value) STC_WRITE_BIT(INTCLKO, 5, (value))
#define EX2 STC_READ_BIT(INTCLKO, 4)
#define EX2_Set(value) STC_WRITE_BIT(INTCLKO, 4, (value))
#define T2CLKO STC_READ_BIT(INTCLKO, 2)
#define T2CLKO_Set(value) STC_WRITE_BIT(INTCLKO, 2, (value))
#define T1CLKO STC_READ_BIT(INTCLKO, 1)
#define T1CLKO_Set(value) STC_WRITE_BIT(INTCLKO, 1, (value))
#define T0CLKO STC_READ_BIT(INTCLKO, 0)
#define T0CLKO_Set(value) STC_WRITE_BIT(INTCLKO, 0, (value))

SFR(P1, 0x90);
    SBIT(P10, 0x90, 0);
    SBIT(P11, 0x90, 1);
    SBIT(P12, 0x90, 2);
    SBIT(P13, 0x90, 3);
    SBIT(P14, 0x90, 4);
    SBIT(P15, 0x90, 5);
    SBIT(P16, 0x90, 6);
    SBIT(P17, 0x90, 7);

SFR(P1M1, 0x91);
SFR(P1M0, 0x92);
SFR(P0M1, 0x93);
SFR(P0M0, 0x94);
SFR(P2M1, 0x95);
SFR(P2M0, 0x96);

SFR(AUXR2, 0x97);
#define RAMTINY STC_READ_BIT(AUXR2, 7)
#define RAMTINY_Set(value) STC_WRITE_BIT(AUXR2, 7, (value))
#define CPUMODE STC_READ_BIT(AUXR2, 6)
#define CPUMODE_Set(value) STC_WRITE_BIT(AUXR2, 6, (value))
#define LINSEL STC_READ_BIT(AUXR2, 5)
#define LINSEL_Set(value) STC_WRITE_BIT(AUXR2, 5, (value))
#define LIN2EN STC_READ_BIT(AUXR2, 4)
#define LIN2EN_Set(value) STC_WRITE_BIT(AUXR2, 4, (value))
#define CANEDIN STC_READ_BIT(AUXR2, 3)
#define CANEDIN_Set(value) STC_WRITE_BIT(AUXR2, 3, (value))
#define CAN2EN STC_READ_BIT(AUXR2, 2)
#define CAN2EN_Set(value) STC_WRITE_BIT(AUXR2, 2, (value))
#define CANEN STC_READ_BIT(AUXR2, 1)
#define CANEN_Set(value) STC_WRITE_BIT(AUXR2, 1, (value))
#define LINEN STC_READ_BIT(AUXR2, 0)
#define LINEN_Set(value) STC_WRITE_BIT(AUXR2, 0, (value))

SFR(SCON, 0x98);
    SBIT(SM0, 0x98, 7);
    SBIT(SM1, 0x98, 6);
    SBIT(SM2, 0x98, 5);
    SBIT(REN, 0x98, 4);
    SBIT(TB8, 0x98, 3);
    SBIT(RB8, 0x98, 2);
    SBIT(TI, 0x98, 1);
    SBIT(RI, 0x98, 0);

SFR(SBUF, 0x99);

SFR(S2CON, 0x9a);
#define S2SM0 STC_READ_BIT(S2CON, 7)
#define S2SM0_Set(value) STC_WRITE_BIT(S2CON, 7, (value))
#define S2SM1 STC_READ_BIT(S2CON, 6)
#define S2SM1_Set(value) STC_WRITE_BIT(S2CON, 6, (value))
#define S2SM2 STC_READ_BIT(S2CON, 5)
#define S2SM2_Set(value) STC_WRITE_BIT(S2CON, 5, (value))
#define S2REN STC_READ_BIT(S2CON, 4)
#define S2REN_Set(value) STC_WRITE_BIT(S2CON, 4, (value))
#define S2TB8 STC_READ_BIT(S2CON, 3)
#define S2TB8_Set(value) STC_WRITE_BIT(S2CON, 3, (value))
#define S2RB8 STC_READ_BIT(S2CON, 2)
#define S2RB8_Set(value) STC_WRITE_BIT(S2CON, 2, (value))
#define S2TI STC_READ_BIT(S2CON, 1)
#define S2TI_Set(value) STC_WRITE_BIT(S2CON, 1, (value))
#define S2RI STC_READ_BIT(S2CON, 0)
#define S2RI_Set(value) STC_WRITE_BIT(S2CON, 0, (value))

SFR(S2BUF, 0x9b);

SFR(IRCBAND, 0x9d);
#define USBCKS STC_READ_BIT(IRCBAND, 7)
#define USBCKS_Set(value) STC_WRITE_BIT(IRCBAND, 7, (value))
#define USBCKS2 STC_READ_BIT(IRCBAND, 6)
#define USBCKS2_Set(value) STC_WRITE_BIT(IRCBAND, 6, (value))
#define HIRCSEL1 STC_READ_BIT(IRCBAND, 1)
#define HIRCSEL1_Set(value) STC_WRITE_BIT(IRCBAND, 1, (value))
#define HIRCSEL0 STC_READ_BIT(IRCBAND, 0)
#define HIRCSEL0_Set(value) STC_WRITE_BIT(IRCBAND, 0, (value))

SFR(LIRTRIM, 0x9e);
SFR(IRTRIM, 0x9f);

SFR(P2, 0xa0);
    SBIT(P20, 0xA0, 0);
    SBIT(P21, 0xA0, 1);
    SBIT(P22, 0xA0, 2);
    SBIT(P23, 0xA0, 3);
    SBIT(P24, 0xA0, 4);
    SBIT(P25, 0xA0, 5);
    SBIT(P26, 0xA0, 6);
    SBIT(P27, 0xA0, 7);

SFR(BUS_SPEED, 0xa1);

SFR(P_SW1, 0xa2);
#define S1_S1 STC_READ_BIT(P_SW1, 7)
#define S1_S1_Set(value) STC_WRITE_BIT(P_SW1, 7, (value))
#define S1_S0 STC_READ_BIT(P_SW1, 6)
#define S1_S0_Set(value) STC_WRITE_BIT(P_SW1, 6, (value))
#define CAN_S1 STC_READ_BIT(P_SW1, 5)
#define CAN_S1_Set(value) STC_WRITE_BIT(P_SW1, 5, (value))
#define CAN_S0 STC_READ_BIT(P_SW1, 4)
#define CAN_S0_Set(value) STC_WRITE_BIT(P_SW1, 4, (value))
#define SPI_S1 STC_READ_BIT(P_SW1, 3)
#define SPI_S1_Set(value) STC_WRITE_BIT(P_SW1, 3, (value))
#define SPI_S0 STC_READ_BIT(P_SW1, 2)
#define SPI_S0_Set(value) STC_WRITE_BIT(P_SW1, 2, (value))
#define LIN_S1 STC_READ_BIT(P_SW1, 1)
#define LIN_S1_Set(value) STC_WRITE_BIT(P_SW1, 1, (value))
#define LIN_S0 STC_READ_BIT(P_SW1, 0)
#define LIN_S0_Set(value) STC_WRITE_BIT(P_SW1, 0, (value))

SFR(VRTRIM, 0xa6);

SFR(IE, 0xa8);
    SBIT(EA, 0xA8, 7);
    SBIT(ELVD, 0xA8, 6);
    SBIT(EADC, 0xA8, 5);
    SBIT(ES, 0xA8, 4);
    SBIT(ET1, 0xA8, 3);
    SBIT(EX1, 0xA8, 2);
    SBIT(ET0, 0xA8, 1);
    SBIT(EX0, 0xA8, 0);

SFR(SADDR, 0xa9);
SFR(WKTCL, 0xaa);
SFR(WKTCH, 0xab);
#define WKTEN STC_READ_BIT(WKTCH, 7)
#define WKTEN_Set(value) STC_WRITE_BIT(WKTCH, 7, (value))

SFR(S3CON, 0xac);
#define S3SM0 STC_READ_BIT(S3CON, 7)
#define S3SM0_Set(value) STC_WRITE_BIT(S3CON, 7, (value))
#define S3ST3 STC_READ_BIT(S3CON, 6)
#define S3ST3_Set(value) STC_WRITE_BIT(S3CON, 6, (value))
#define S3SM2 STC_READ_BIT(S3CON, 5)
#define S3SM2_Set(value) STC_WRITE_BIT(S3CON, 5, (value))
#define S3REN STC_READ_BIT(S3CON, 4)
#define S3REN_Set(value) STC_WRITE_BIT(S3CON, 4, (value))
#define S3TB8 STC_READ_BIT(S3CON, 3)
#define S3TB8_Set(value) STC_WRITE_BIT(S3CON, 3, (value))
#define S3RB8 STC_READ_BIT(S3CON, 2)
#define S3RB8_Set(value) STC_WRITE_BIT(S3CON, 2, (value))
#define S3TI STC_READ_BIT(S3CON, 1)
#define S3TI_Set(value) STC_WRITE_BIT(S3CON, 1, (value))
#define S3RI STC_READ_BIT(S3CON, 0)
#define S3RI_Set(value) STC_WRITE_BIT(S3CON, 0, (value))

SFR(S3BUF, 0xad);
SFR(TA, 0xae);

SFR(IE2, 0xaf);
#define EUSB STC_READ_BIT(IE2, 7)
#define EUSB_Set(value) STC_WRITE_BIT(IE2, 7, (value))
#define ET4 STC_READ_BIT(IE2, 6)
#define ET4_Set(value) STC_WRITE_BIT(IE2, 6, (value))
#define ET3 STC_READ_BIT(IE2, 5)
#define ET3_Set(value) STC_WRITE_BIT(IE2, 5, (value))
#define ES4 STC_READ_BIT(IE2, 4)
#define ES4_Set(value) STC_WRITE_BIT(IE2, 4, (value))
#define ES3 STC_READ_BIT(IE2, 3)
#define ES3_Set(value) STC_WRITE_BIT(IE2, 3, (value))
#define ET2 STC_READ_BIT(IE2, 2)
#define ET2_Set(value) STC_WRITE_BIT(IE2, 2, (value))
#define ESPI STC_READ_BIT(IE2, 1)
#define ESPI_Set(value) STC_WRITE_BIT(IE2, 1, (value))
#define ES2 STC_READ_BIT(IE2, 0)
#define ES2_Set(value) STC_WRITE_BIT(IE2, 0, (value))

SFR(P3, 0xb0);
    SBIT(P30, 0xB0, 0);
    SBIT(P31, 0xB0, 1);
    SBIT(P32, 0xB0, 2);
    SBIT(P33, 0xB0, 3);
    SBIT(P34, 0xB0, 4);
    SBIT(P35, 0xB0, 5);
    SBIT(P36, 0xB0, 6);
    SBIT(P37, 0xB0, 7);

    SBIT(RD, 0xB0, 7);
    SBIT(WR, 0xB0, 6);
    SBIT(T1, 0xB0, 5);
    SBIT(T0, 0xB0, 4);
    SBIT(INT1, 0xB0, 3);
    SBIT(INT0, 0xB0, 2);
    SBIT(TXD, 0xB0, 1);
    SBIT(RXD, 0xB0, 0);

SFR(P3M1, 0xb1);
SFR(P3M0, 0xb2);
SFR(P4M1, 0xb3);
SFR(P4M0, 0xb4);

SFR(IP2, 0xb5);
#define PUSB STC_READ_BIT(IP2, 7)
#define PUSB_Set(value) STC_WRITE_BIT(IP2, 7, (value))
#define PI2C STC_READ_BIT(IP2, 6)
#define PI2C_Set(value) STC_WRITE_BIT(IP2, 6, (value))
#define PCMP STC_READ_BIT(IP2, 5)
#define PCMP_Set(value) STC_WRITE_BIT(IP2, 5, (value))
#define PX4 STC_READ_BIT(IP2, 4)
#define PX4_Set(value) STC_WRITE_BIT(IP2, 4, (value))
#define PPWMB STC_READ_BIT(IP2, 3)
#define PPWMB_Set(value) STC_WRITE_BIT(IP2, 3, (value))
#define PPWMA STC_READ_BIT(IP2, 2)
#define PPWMA_Set(value) STC_WRITE_BIT(IP2, 2, (value))
#define PSPI STC_READ_BIT(IP2, 1)
#define PSPI_Set(value) STC_WRITE_BIT(IP2, 1, (value))
#define PS2 STC_READ_BIT(IP2, 0)
#define PS2_Set(value) STC_WRITE_BIT(IP2, 0, (value))

SFR(IP2H, 0xb6);
#define PUSBH STC_READ_BIT(IP2H, 7)
#define PUSBH_Set(value) STC_WRITE_BIT(IP2H, 7, (value))
#define PI2CH STC_READ_BIT(IP2H, 6)
#define PI2CH_Set(value) STC_WRITE_BIT(IP2H, 6, (value))
#define PCMPH STC_READ_BIT(IP2H, 5)
#define PCMPH_Set(value) STC_WRITE_BIT(IP2H, 5, (value))
#define PX4H STC_READ_BIT(IP2H, 4)
#define PX4H_Set(value) STC_WRITE_BIT(IP2H, 4, (value))
#define PPWMBH STC_READ_BIT(IP2H, 3)
#define PPWMBH_Set(value) STC_WRITE_BIT(IP2H, 3, (value))
#define PPWMAH STC_READ_BIT(IP2H, 2)
#define PPWMAH_Set(value) STC_WRITE_BIT(IP2H, 2, (value))
#define PSPIH STC_READ_BIT(IP2H, 1)
#define PSPIH_Set(value) STC_WRITE_BIT(IP2H, 1, (value))
#define PS2H STC_READ_BIT(IP2H, 0)
#define PS2H_Set(value) STC_WRITE_BIT(IP2H, 0, (value))

SFR(IPH, 0xb7);
#define PPCAH STC_READ_BIT(IPH, 7)
#define PPCAH_Set(value) STC_WRITE_BIT(IPH, 7, (value))
#define PLVDH STC_READ_BIT(IPH, 6)
#define PLVDH_Set(value) STC_WRITE_BIT(IPH, 6, (value))
#define PADCH STC_READ_BIT(IPH, 5)
#define PADCH_Set(value) STC_WRITE_BIT(IPH, 5, (value))
#define PSH STC_READ_BIT(IPH, 4)
#define PSH_Set(value) STC_WRITE_BIT(IPH, 4, (value))
#define PT1H STC_READ_BIT(IPH, 3)
#define PT1H_Set(value) STC_WRITE_BIT(IPH, 3, (value))
#define PX1H STC_READ_BIT(IPH, 2)
#define PX1H_Set(value) STC_WRITE_BIT(IPH, 2, (value))
#define PT0H STC_READ_BIT(IPH, 1)
#define PT0H_Set(value) STC_WRITE_BIT(IPH, 1, (value))
#define PX0H STC_READ_BIT(IPH, 0)
#define PX0H_Set(value) STC_WRITE_BIT(IPH, 0, (value))

SFR(IP, 0xb8);
    SBIT(PPCA, 0xB8, 7);
    SBIT(PLVD, 0xB8, 6);
    SBIT(PADC, 0xB8, 5);
    SBIT(PS, 0xB8, 4);
    SBIT(PT1, 0xB8, 3);
    SBIT(PX1, 0xB8, 2);
    SBIT(PT0, 0xB8, 1);
    SBIT(PX0, 0xB8, 0);

SFR(SADEN, 0xb9);

SFR(P_SW2, 0xba);
#define EAXFR STC_READ_BIT(P_SW2, 7)
#define EAXFR_Set(value) STC_WRITE_BIT(P_SW2, 7, (value))
#define I2C_S1 STC_READ_BIT(P_SW2, 5)
#define I2C_S1_Set(value) STC_WRITE_BIT(P_SW2, 5, (value))
#define I2C_S0 STC_READ_BIT(P_SW2, 4)
#define I2C_S0_Set(value) STC_WRITE_BIT(P_SW2, 4, (value))
#define CMPO_S STC_READ_BIT(P_SW2, 3)
#define CMPO_S_Set(value) STC_WRITE_BIT(P_SW2, 3, (value))
#define S4_S STC_READ_BIT(P_SW2, 2)
#define S4_S_Set(value) STC_WRITE_BIT(P_SW2, 2, (value))
#define S3_S STC_READ_BIT(P_SW2, 1)
#define S3_S_Set(value) STC_WRITE_BIT(P_SW2, 1, (value))
#define S2_S STC_READ_BIT(P_SW2, 0)
#define S2_S_Set(value) STC_WRITE_BIT(P_SW2, 0, (value))

SFR(P_SW3, 0xbb);
#define I2S_S1 STC_READ_BIT(P_SW3, 7)
#define I2S_S1_Set(value) STC_WRITE_BIT(P_SW3, 7, (value))
#define I2S_S0 STC_READ_BIT(P_SW3, 6)
#define I2S_S0_Set(value) STC_WRITE_BIT(P_SW3, 6, (value))
#define S2SPI_S1 STC_READ_BIT(P_SW3, 5)
#define S2SPI_S1_Set(value) STC_WRITE_BIT(P_SW3, 5, (value))
#define S2SPI_S0 STC_READ_BIT(P_SW3, 4)
#define S2SPI_S0_Set(value) STC_WRITE_BIT(P_SW3, 4, (value))
#define S1SPI_S1 STC_READ_BIT(P_SW3, 3)
#define S1SPI_S1_Set(value) STC_WRITE_BIT(P_SW3, 3, (value))
#define S1SPI_S0 STC_READ_BIT(P_SW3, 2)
#define S1SPI_S0_Set(value) STC_WRITE_BIT(P_SW3, 2, (value))
#define CAN2_S1 STC_READ_BIT(P_SW3, 1)
#define CAN2_S1_Set(value) STC_WRITE_BIT(P_SW3, 1, (value))
#define CAN2_S0 STC_READ_BIT(P_SW3, 0)
#define CAN2_S0_Set(value) STC_WRITE_BIT(P_SW3, 0, (value))

SFR(ADC_CONTR, 0xbc);
#define ADC_POWER STC_READ_BIT(ADC_CONTR, 7)
#define ADC_POWER_Set(value) STC_WRITE_BIT(ADC_CONTR, 7, (value))
#define ADC_START STC_READ_BIT(ADC_CONTR, 6)
#define ADC_START_Set(value) STC_WRITE_BIT(ADC_CONTR, 6, (value))
#define ADC_FLAG STC_READ_BIT(ADC_CONTR, 5)
#define ADC_FLAG_Set(value) STC_WRITE_BIT(ADC_CONTR, 5, (value))
#define ADC_EPWMT STC_READ_BIT(ADC_CONTR, 4)
#define ADC_EPWMT_Set(value) STC_WRITE_BIT(ADC_CONTR, 4, (value))

SFR(ADC_RES, 0xbd);
SFR(ADC_RESL, 0xbe);

SFR(P_SW4, 0xbf);
#define QSPI_S1 STC_READ_BIT(P_SW4, 1)
#define QSPI_S1_Set(value) STC_WRITE_BIT(P_SW4, 1, (value))
#define QSPI_S0 STC_READ_BIT(P_SW4, 0)
#define QSPI_S0_Set(value) STC_WRITE_BIT(P_SW4, 0, (value))

SFR(P4, 0xc0);
    SBIT(P40, 0xC0, 0);
    SBIT(P41, 0xC0, 1);
    SBIT(P42, 0xC0, 2);
    SBIT(P43, 0xC0, 3);
    SBIT(P44, 0xC0, 4);
    SBIT(P45, 0xC0, 5);
    SBIT(P46, 0xC0, 6);
    SBIT(P47, 0xC0, 7);

SFR(WDT_CONTR, 0xc1);
#define WDT_FLAG STC_READ_BIT(WDT_CONTR, 7)
#define WDT_FLAG_Set(value) STC_WRITE_BIT(WDT_CONTR, 7, (value))
#define EN_WDT STC_READ_BIT(WDT_CONTR, 5)
#define EN_WDT_Set(value) STC_WRITE_BIT(WDT_CONTR, 5, (value))
#define CLR_WDT STC_READ_BIT(WDT_CONTR, 4)
#define CLR_WDT_Set(value) STC_WRITE_BIT(WDT_CONTR, 4, (value))
#define IDL_WDT STC_READ_BIT(WDT_CONTR, 3)
#define IDL_WDT_Set(value) STC_WRITE_BIT(WDT_CONTR, 3, (value))

SFR(IAP_DATA, 0xc2);
SFR(IAP_ADDRH, 0xc3);
SFR(IAP_ADDRL, 0xc4);
SFR(IAP_CMD, 0xc5);
SFR(IAP_TRIG, 0xc6);

SFR(IAP_CONTR, 0xc7);
#define IAPEN STC_READ_BIT(IAP_CONTR, 7)
#define IAPEN_Set(value) STC_WRITE_BIT(IAP_CONTR, 7, (value))
#define SWBS STC_READ_BIT(IAP_CONTR, 6)
#define SWBS_Set(value) STC_WRITE_BIT(IAP_CONTR, 6, (value))
#define SWRST STC_READ_BIT(IAP_CONTR, 5)
#define SWRST_Set(value) STC_WRITE_BIT(IAP_CONTR, 5, (value))
#define CMD_FAIL STC_READ_BIT(IAP_CONTR, 4)
#define CMD_FAIL_Set(value) STC_WRITE_BIT(IAP_CONTR, 4, (value))
#define SWBS2 STC_READ_BIT(IAP_CONTR, 3)
#define SWBS2_Set(value) STC_WRITE_BIT(IAP_CONTR, 3, (value))

SFR(P5, 0xc8);
    SBIT(P50, 0xC8, 0);
    SBIT(P51, 0xC8, 1);
    SBIT(P52, 0xC8, 2);
    SBIT(P53, 0xC8, 3);
    SBIT(P54, 0xC8, 4);
    SBIT(P55, 0xC8, 5);
    SBIT(P56, 0xC8, 6);
    SBIT(P57, 0xC8, 7);

SFR(P5M1, 0xc9);
SFR(P5M0, 0xca);
SFR(P6M1, 0xcb);
SFR(P6M0, 0xcc);

SFR(SPSTAT, 0xcd);
#define SPIF STC_READ_BIT(SPSTAT, 7)
#define SPIF_Set(value) STC_WRITE_BIT(SPSTAT, 7, (value))
#define WCOL STC_READ_BIT(SPSTAT, 6)
#define WCOL_Set(value) STC_WRITE_BIT(SPSTAT, 6, (value))

SFR(SPCTL, 0xce);
#define SSIG STC_READ_BIT(SPCTL, 7)
#define SSIG_Set(value) STC_WRITE_BIT(SPCTL, 7, (value))
#define SPEN STC_READ_BIT(SPCTL, 6)
#define SPEN_Set(value) STC_WRITE_BIT(SPCTL, 6, (value))
#define DORD STC_READ_BIT(SPCTL, 5)
#define DORD_Set(value) STC_WRITE_BIT(SPCTL, 5, (value))
#define MSTR STC_READ_BIT(SPCTL, 4)
#define MSTR_Set(value) STC_WRITE_BIT(SPCTL, 4, (value))
#define CPOL STC_READ_BIT(SPCTL, 3)
#define CPOL_Set(value) STC_WRITE_BIT(SPCTL, 3, (value))
#define CPHA STC_READ_BIT(SPCTL, 2)
#define CPHA_Set(value) STC_WRITE_BIT(SPCTL, 2, (value))
#define SPR1 STC_READ_BIT(SPCTL, 1)
#define SPR1_Set(value) STC_WRITE_BIT(SPCTL, 1, (value))
#define SPR0 STC_READ_BIT(SPCTL, 0)
#define SPR0_Set(value) STC_WRITE_BIT(SPCTL, 0, (value))

SFR(SPDAT, 0xcf);

SFR(PSW, 0xd0);
    SBIT(CY, 0xD0, 7);
    SBIT(AC, 0xD0, 6);
    SBIT(F0, 0xD0, 5);
    SBIT(RS1, 0xD0, 4);
    SBIT(RS0, 0xD0, 3);
    SBIT(OV, 0xD0, 2);
    SBIT(F1, 0xD0, 1);
    SBIT(P, 0xD0, 0);

SFR(PSW1, 0xd1);
#define N STC_READ_BIT(PSW1, 5)
#define N_Set(value) STC_WRITE_BIT(PSW1, 5, (value))
#define Z STC_READ_BIT(PSW1, 1)
#define Z_Set(value) STC_WRITE_BIT(PSW1, 1, (value))

SFR(T4H, 0xd2);
SFR(T4L, 0xd3);
SFR(T3H, 0xd4);
SFR(T3L, 0xd5);
SFR(T2H, 0xd6);
SFR(T2L, 0xd7);

SFR(TH4, 0xd2);
SFR(TL4, 0xd3);
SFR(TH3, 0xd4);
SFR(TL3, 0xd5);
SFR(TH2, 0xd6);
SFR(TL2, 0xd7);

SFR(USBCLK, 0xdc);

SFR(T3T4M, 0xdd);
SFR(T4T3M, 0xdd);
#define T4R STC_READ_BIT(T4T3M, 7)
#define T4R_Set(value) STC_WRITE_BIT(T4T3M, 7, (value))
#define T4_CT STC_READ_BIT(T4T3M, 6)
#define T4_CT_Set(value) STC_WRITE_BIT(T4T3M, 6, (value))
#define T4x12 STC_READ_BIT(T4T3M, 5)
#define T4x12_Set(value) STC_WRITE_BIT(T4T3M, 5, (value))
#define T4CLKO STC_READ_BIT(T4T3M, 4)
#define T4CLKO_Set(value) STC_WRITE_BIT(T4T3M, 4, (value))
#define T3R STC_READ_BIT(T4T3M, 3)
#define T3R_Set(value) STC_WRITE_BIT(T4T3M, 3, (value))
#define T3_CT STC_READ_BIT(T4T3M, 2)
#define T3_CT_Set(value) STC_WRITE_BIT(T4T3M, 2, (value))
#define T3x12 STC_READ_BIT(T4T3M, 1)
#define T3x12_Set(value) STC_WRITE_BIT(T4T3M, 1, (value))
#define T3CLKO STC_READ_BIT(T4T3M, 0)
#define T3CLKO_Set(value) STC_WRITE_BIT(T4T3M, 0, (value))

SFR(ADCCFG, 0xde);
#define RESFMT STC_READ_BIT(ADCCFG, 5)
#define RESFMT_Set(value) STC_WRITE_BIT(ADCCFG, 5, (value))

SFR(IP3, 0xdf);
#define PPWMD STC_READ_BIT(IP3, 7)
#define PPWMD_Set(value) STC_WRITE_BIT(IP3, 7, (value))
#define PPWMC STC_READ_BIT(IP3, 6)
#define PPWMC_Set(value) STC_WRITE_BIT(IP3, 6, (value))
#define PI2C2 STC_READ_BIT(IP3, 5)
#define PI2C2_Set(value) STC_WRITE_BIT(IP3, 5, (value))
#define PI2S2 STC_READ_BIT(IP3, 4)
#define PI2S2_Set(value) STC_WRITE_BIT(IP3, 4, (value))
#define PI2S STC_READ_BIT(IP3, 3)
#define PI2S_Set(value) STC_WRITE_BIT(IP3, 3, (value))
#define PRTC STC_READ_BIT(IP3, 2)
#define PRTC_Set(value) STC_WRITE_BIT(IP3, 2, (value))
#define PS4 STC_READ_BIT(IP3, 1)
#define PS4_Set(value) STC_WRITE_BIT(IP3, 1, (value))
#define PS3 STC_READ_BIT(IP3, 0)
#define PS3_Set(value) STC_WRITE_BIT(IP3, 0, (value))

SFR(ACC, 0xE0);
    SBIT(ACC0, 0xE0, 0);
    SBIT(ACC1, 0xE0, 1);
    SBIT(ACC2, 0xE0, 2);
    SBIT(ACC3, 0xE0, 3);
    SBIT(ACC4, 0xE0, 4);
    SBIT(ACC5, 0xE0, 5);
    SBIT(ACC6, 0xE0, 6);
    SBIT(ACC7, 0xE0, 7);

SFR(P7M1, 0xe1);
SFR(P7M0, 0xe2);
SFR(DPS, 0xe3);

SFR(CMPCR1, 0xe6);
#define CMPEN STC_READ_BIT(CMPCR1, 7)
#define CMPEN_Set(value) STC_WRITE_BIT(CMPCR1, 7, (value))
#define CMPIF STC_READ_BIT(CMPCR1, 6)
#define CMPIF_Set(value) STC_WRITE_BIT(CMPCR1, 6, (value))
#define PIE STC_READ_BIT(CMPCR1, 5)
#define PIE_Set(value) STC_WRITE_BIT(CMPCR1, 5, (value))
#define NIE STC_READ_BIT(CMPCR1, 4)
#define NIE_Set(value) STC_WRITE_BIT(CMPCR1, 4, (value))
#define CMPOE STC_READ_BIT(CMPCR1, 1)
#define CMPOE_Set(value) STC_WRITE_BIT(CMPCR1, 1, (value))
#define CMPRES STC_READ_BIT(CMPCR1, 0)
#define CMPRES_Set(value) STC_WRITE_BIT(CMPCR1, 0, (value))

SFR(CMPCR2, 0xe7);
#define INVCMPO STC_READ_BIT(CMPCR2, 7)
#define INVCMPO_Set(value) STC_WRITE_BIT(CMPCR2, 7, (value))
#define DISFLT STC_READ_BIT(CMPCR2, 6)
#define DISFLT_Set(value) STC_WRITE_BIT(CMPCR2, 6, (value))

SFR(P6, 0xe8);
    SBIT(P60, 0xE8, 0);
    SBIT(P61, 0xE8, 1);
    SBIT(P62, 0xE8, 2);
    SBIT(P63, 0xE8, 3);
    SBIT(P64, 0xE8, 4);
    SBIT(P65, 0xE8, 5);
    SBIT(P66, 0xE8, 6);
    SBIT(P67, 0xE8, 7);

SFR(WTST, 0xe9);
SFR(CKCON, 0xea);
#define RAMEXE STC_READ_BIT(CKCON, 7)
#define RAMEXE_Set(value) STC_WRITE_BIT(CKCON, 7, (value))

SFR(MXAX, 0xeb);
SFR(USBDAT, 0xec);
SFR(DMAIR, 0xed);

SFR(IP3H, 0xee);
#define PPWMDH STC_READ_BIT(IP3H, 7)
#define PPWMDH_Set(value) STC_WRITE_BIT(IP3H, 7, (value))
#define PPWMCH STC_READ_BIT(IP3H, 6)
#define PPWMCH_Set(value) STC_WRITE_BIT(IP3H, 6, (value))
#define PI2C2H STC_READ_BIT(IP3H, 5)
#define PI2C2H_Set(value) STC_WRITE_BIT(IP3H, 5, (value))
#define PI2S2H STC_READ_BIT(IP3H, 4)
#define PI2S2H_Set(value) STC_WRITE_BIT(IP3H, 4, (value))
#define PI2SH STC_READ_BIT(IP3H, 3)
#define PI2SH_Set(value) STC_WRITE_BIT(IP3H, 3, (value))
#define PRTCH STC_READ_BIT(IP3H, 2)
#define PRTCH_Set(value) STC_WRITE_BIT(IP3H, 2, (value))
#define PS4H STC_READ_BIT(IP3H, 1)
#define PS4H_Set(value) STC_WRITE_BIT(IP3H, 1, (value))
#define PS3H STC_READ_BIT(IP3H, 0)
#define PS3H_Set(value) STC_WRITE_BIT(IP3H, 0, (value))

SFR(AUXINTIF, 0xef);
#define INT4IF STC_READ_BIT(AUXINTIF, 6)
#define INT4IF_Set(value) STC_WRITE_BIT(AUXINTIF, 6, (value))
#define INT3IF STC_READ_BIT(AUXINTIF, 5)
#define INT3IF_Set(value) STC_WRITE_BIT(AUXINTIF, 5, (value))
#define INT2IF STC_READ_BIT(AUXINTIF, 4)
#define INT2IF_Set(value) STC_WRITE_BIT(AUXINTIF, 4, (value))
#define T4IF STC_READ_BIT(AUXINTIF, 2)
#define T4IF_Set(value) STC_WRITE_BIT(AUXINTIF, 2, (value))
#define T3IF STC_READ_BIT(AUXINTIF, 1)
#define T3IF_Set(value) STC_WRITE_BIT(AUXINTIF, 1, (value))
#define T2IF STC_READ_BIT(AUXINTIF, 0)
#define T2IF_Set(value) STC_WRITE_BIT(AUXINTIF, 0, (value))

SFR(B, 0xF0);
    SBIT(B0, 0xF0, 0);
    SBIT(B1, 0xF0, 1);
    SBIT(B2, 0xF0, 2);
    SBIT(B3, 0xF0, 3);
    SBIT(B4, 0xF0, 4);
    SBIT(B5, 0xF0, 5);
    SBIT(B6, 0xF0, 6);
    SBIT(B7, 0xF0, 7);

SFR(CANICR, 0xf1);
#define PCAN2H STC_READ_BIT(CANICR, 7)
#define PCAN2H_Set(value) STC_WRITE_BIT(CANICR, 7, (value))
#define CAN2IF STC_READ_BIT(CANICR, 6)
#define CAN2IF_Set(value) STC_WRITE_BIT(CANICR, 6, (value))
#define CAN2IE STC_READ_BIT(CANICR, 5)
#define CAN2IE_Set(value) STC_WRITE_BIT(CANICR, 5, (value))
#define PCAN2L STC_READ_BIT(CANICR, 4)
#define PCAN2L_Set(value) STC_WRITE_BIT(CANICR, 4, (value))
#define PCANH STC_READ_BIT(CANICR, 3)
#define PCANH_Set(value) STC_WRITE_BIT(CANICR, 3, (value))
#define CANIF STC_READ_BIT(CANICR, 2)
#define CANIF_Set(value) STC_WRITE_BIT(CANICR, 2, (value))
#define CANIE STC_READ_BIT(CANICR, 1)
#define CANIE_Set(value) STC_WRITE_BIT(CANICR, 1, (value))
#define PCANL STC_READ_BIT(CANICR, 0)
#define PCANL_Set(value) STC_WRITE_BIT(CANICR, 0, (value))

SFR(IP4, 0xf2);
#define PPWMF STC_READ_BIT(IP4, 1)
#define PPWMF_Set(value) STC_WRITE_BIT(IP4, 1, (value))
#define PPWME STC_READ_BIT(IP4, 0)
#define PPWME_Set(value) STC_WRITE_BIT(IP4, 0, (value))

SFR(IP4H, 0xf3);
#define PPWMFH STC_READ_BIT(IP4H, 1)
#define PPWMFH_Set(value) STC_WRITE_BIT(IP4H, 1, (value))
#define PPWMEH STC_READ_BIT(IP4H, 0)
#define PPWMEH_Set(value) STC_WRITE_BIT(IP4H, 0, (value))

SFR(USBCON, 0xf4);
#define ENUSB STC_READ_BIT(USBCON, 7)
#define ENUSB_Set(value) STC_WRITE_BIT(USBCON, 7, (value))
#define ENUSBRST STC_READ_BIT(USBCON, 6)
#define ENUSBRST_Set(value) STC_WRITE_BIT(USBCON, 6, (value))
#define PS2M STC_READ_BIT(USBCON, 5)
#define PS2M_Set(value) STC_WRITE_BIT(USBCON, 5, (value))
#define PUEN STC_READ_BIT(USBCON, 4)
#define PUEN_Set(value) STC_WRITE_BIT(USBCON, 4, (value))
#define PDEN STC_READ_BIT(USBCON, 3)
#define PDEN_Set(value) STC_WRITE_BIT(USBCON, 3, (value))
#define DFREC STC_READ_BIT(USBCON, 2)
#define DFREC_Set(value) STC_WRITE_BIT(USBCON, 2, (value))
#define DP STC_READ_BIT(USBCON, 1)
#define DP_Set(value) STC_WRITE_BIT(USBCON, 1, (value))
#define DM STC_READ_BIT(USBCON, 0)
#define DM_Set(value) STC_WRITE_BIT(USBCON, 0, (value))

SFR(IAP_TPS, 0xf5);
SFR(IAP_ADDRE, 0xf6);

SFR(P7, 0xf8);
    SBIT(P70, 0xF8, 0);
    SBIT(P71, 0xF8, 1);
    SBIT(P72, 0xF8, 2);
    SBIT(P73, 0xF8, 3);
    SBIT(P74, 0xF8, 4);
    SBIT(P75, 0xF8, 5);
    SBIT(P76, 0xF8, 6);
    SBIT(P77, 0xF8, 7);

SFR(LINICR, 0xf9);
#define PLINH STC_READ_BIT(LINICR, 3)
#define PLINH_Set(value) STC_WRITE_BIT(LINICR, 3, (value))
#define LINIF STC_READ_BIT(LINICR, 2)
#define LINIF_Set(value) STC_WRITE_BIT(LINICR, 2, (value))
#define LINIE STC_READ_BIT(LINICR, 1)
#define LINIE_Set(value) STC_WRITE_BIT(LINICR, 1, (value))
#define PLINL STC_READ_BIT(LINICR, 0)
#define PLINL_Set(value) STC_WRITE_BIT(LINICR, 0, (value))
SFR(LINAR, 0xfa);
SFR(LINDR, 0xfb);
SFR(USBADR, 0xfc);

SFR(S4CON, 0xfd);
#define S4SM0 STC_READ_BIT(S4CON, 7)
#define S4SM0_Set(value) STC_WRITE_BIT(S4CON, 7, (value))
#define S4ST4 STC_READ_BIT(S4CON, 6)
#define S4ST4_Set(value) STC_WRITE_BIT(S4CON, 6, (value))
#define S4SM2 STC_READ_BIT(S4CON, 5)
#define S4SM2_Set(value) STC_WRITE_BIT(S4CON, 5, (value))
#define S4REN STC_READ_BIT(S4CON, 4)
#define S4REN_Set(value) STC_WRITE_BIT(S4CON, 4, (value))
#define S4TB8 STC_READ_BIT(S4CON, 3)
#define S4TB8_Set(value) STC_WRITE_BIT(S4CON, 3, (value))
#define S4RB8 STC_READ_BIT(S4CON, 2)
#define S4RB8_Set(value) STC_WRITE_BIT(S4CON, 2, (value))
#define S4TI STC_READ_BIT(S4CON, 1)
#define S4TI_Set(value) STC_WRITE_BIT(S4CON, 1, (value))
#define S4RI STC_READ_BIT(S4CON, 0)
#define S4RI_Set(value) STC_WRITE_BIT(S4CON, 0, (value))

SFR(S4BUF, 0xfe);

SFR(RSTCFG, 0xff);
#define ENLVR STC_READ_BIT(RSTCFG, 6)
#define ENLVR_Set(value) STC_WRITE_BIT(RSTCFG, 6, (value))
#define P54RST STC_READ_BIT(RSTCFG, 4)
#define P54RST_Set(value) STC_WRITE_BIT(RSTCFG, 4, (value))

/////////////////////////////////////////////////
//
//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将EAXFR设置为1,才可正常读写
//    EAXFR = 1;
//或者
//    P_SW2 |= 0x80;
///////////////////////////////////////////////////

/////////////////////////////////////////////////
//7E:FF00H-7E:FFFFH
/////////////////////////////////////////////////



/////////////////////////////////////////////////
//7E:FE00H-7E:FEFFH
/////////////////////////////////////////////////

#define     CLKSEL                  (*(unsigned char volatile __FAR *)0x7efe00)
#define     CLKDIV                  (*(unsigned char volatile __FAR *)0x7efe01)
#define     HIRCCR                  (*(unsigned char volatile __FAR *)0x7efe02)
#define     XOSCCR                  (*(unsigned char volatile __FAR *)0x7efe03)
#define     IRC32KCR                (*(unsigned char volatile __FAR *)0x7efe04)
#define     MCLKOCR                 (*(unsigned char volatile __FAR *)0x7efe05)
#define     IRCDB                   (*(unsigned char volatile __FAR *)0x7efe06)
#define     IRC48MCR                (*(unsigned char volatile __FAR *)0x7efe07)
#define     X32KCR                  (*(unsigned char volatile __FAR *)0x7efe08)
#define     IRC48MATRIM             (*(unsigned char volatile __FAR *)0x7efe09)
#define     IRC48MBTRIM             (*(unsigned char volatile __FAR *)0x7efe0a)
#define     HSCLKDIV                (*(unsigned char volatile __FAR *)0x7efe0b)
#define     HPLLCR                  (*(unsigned char volatile __FAR *)0x7efe0c)
#define     HPLLPDIV                (*(unsigned char volatile __FAR *)0x7efe0d)
#define     HPLL2CR                 (*(unsigned char volatile __FAR *)0x7efe0e)
#define     HPLL2PDIV               (*(unsigned char volatile __FAR *)0x7efe0f)

#define     P0PU                    (*(unsigned char volatile __FAR *)0x7efe10)
#define     P1PU                    (*(unsigned char volatile __FAR *)0x7efe11)
#define     P2PU                    (*(unsigned char volatile __FAR *)0x7efe12)
#define     P3PU                    (*(unsigned char volatile __FAR *)0x7efe13)
#define     P4PU                    (*(unsigned char volatile __FAR *)0x7efe14)
#define     P5PU                    (*(unsigned char volatile __FAR *)0x7efe15)
#define     P6PU                    (*(unsigned char volatile __FAR *)0x7efe16)
#define     P7PU                    (*(unsigned char volatile __FAR *)0x7efe17)

#define     P0NCS                   (*(unsigned char volatile __FAR *)0x7efe18)
#define     P1NCS                   (*(unsigned char volatile __FAR *)0x7efe19)
#define     P2NCS                   (*(unsigned char volatile __FAR *)0x7efe1a)
#define     P3NCS                   (*(unsigned char volatile __FAR *)0x7efe1b)
#define     P4NCS                   (*(unsigned char volatile __FAR *)0x7efe1c)
#define     P5NCS                   (*(unsigned char volatile __FAR *)0x7efe1d)
#define     P6NCS                   (*(unsigned char volatile __FAR *)0x7efe1e)
#define     P7NCS                   (*(unsigned char volatile __FAR *)0x7efe1f)

#define     P0SR                    (*(unsigned char volatile __FAR *)0x7efe20)
#define     P1SR                    (*(unsigned char volatile __FAR *)0x7efe21)
#define     P2SR                    (*(unsigned char volatile __FAR *)0x7efe22)
#define     P3SR                    (*(unsigned char volatile __FAR *)0x7efe23)
#define     P4SR                    (*(unsigned char volatile __FAR *)0x7efe24)
#define     P5SR                    (*(unsigned char volatile __FAR *)0x7efe25)
#define     P6SR                    (*(unsigned char volatile __FAR *)0x7efe26)
#define     P7SR                    (*(unsigned char volatile __FAR *)0x7efe27)

#define     P0DR                    (*(unsigned char volatile __FAR *)0x7efe28)
#define     P1DR                    (*(unsigned char volatile __FAR *)0x7efe29)
#define     P2DR                    (*(unsigned char volatile __FAR *)0x7efe2a)
#define     P3DR                    (*(unsigned char volatile __FAR *)0x7efe2b)
#define     P4DR                    (*(unsigned char volatile __FAR *)0x7efe2c)
#define     P5DR                    (*(unsigned char volatile __FAR *)0x7efe2d)
#define     P6DR                    (*(unsigned char volatile __FAR *)0x7efe2e)
#define     P7DR                    (*(unsigned char volatile __FAR *)0x7efe2f)

#define     P0IE                    (*(unsigned char volatile __FAR *)0x7efe30)
#define     P1IE                    (*(unsigned char volatile __FAR *)0x7efe31)
#define     P2IE                    (*(unsigned char volatile __FAR *)0x7efe32)
#define     P3IE                    (*(unsigned char volatile __FAR *)0x7efe33)
#define     P4IE                    (*(unsigned char volatile __FAR *)0x7efe34)
#define     P5IE                    (*(unsigned char volatile __FAR *)0x7efe35)
#define     P6IE                    (*(unsigned char volatile __FAR *)0x7efe36)
#define     P7IE                    (*(unsigned char volatile __FAR *)0x7efe37)

#define     P0PD                    (*(unsigned char volatile __FAR *)0x7efe40)
#define     P1PD                    (*(unsigned char volatile __FAR *)0x7efe41)
#define     P2PD                    (*(unsigned char volatile __FAR *)0x7efe42)
#define     P3PD                    (*(unsigned char volatile __FAR *)0x7efe43)
#define     P4PD                    (*(unsigned char volatile __FAR *)0x7efe44)
#define     P5PD                    (*(unsigned char volatile __FAR *)0x7efe45)
#define     P6PD                    (*(unsigned char volatile __FAR *)0x7efe46)
#define     P7PD                    (*(unsigned char volatile __FAR *)0x7efe47)

#define     P0BP                    (*(unsigned char volatile __FAR *)0x7efe48)
#define     P1BP                    (*(unsigned char volatile __FAR *)0x7efe49)
#define     P2BP                    (*(unsigned char volatile __FAR *)0x7efe4a)
#define     P3BP                    (*(unsigned char volatile __FAR *)0x7efe4b)
#define     P4BP                    (*(unsigned char volatile __FAR *)0x7efe4c)
#define     P5BP                    (*(unsigned char volatile __FAR *)0x7efe4d)
#define     P6BP                    (*(unsigned char volatile __FAR *)0x7efe4e)
#define     P7BP                    (*(unsigned char volatile __FAR *)0x7efe4f)

#define     LCMIFCFG                (*(unsigned char volatile __FAR *)0x7efe50)
#define     LCMIFCFG2               (*(unsigned char volatile __FAR *)0x7efe51)
#define     LCMIFCR                 (*(unsigned char volatile __FAR *)0x7efe52)
#define     LCMIFSTA                (*(unsigned char volatile __FAR *)0x7efe53)
#define     LCMIFDATL               (*(unsigned char volatile __FAR *)0x7efe54)
#define     LCMIFDATH               (*(unsigned char volatile __FAR *)0x7efe55)
#define     LCMIFPSCR               (*(unsigned char volatile __FAR *)0x7efe56)

#define     RSTCR6                  (*(unsigned char volatile __FAR *)0x7efe58)
#define     RSTCR7                  (*(unsigned char volatile __FAR *)0x7efe59)
#define     RSTCR8                  (*(unsigned char volatile __FAR *)0x7efe5a)
#define     RSTCR9                  (*(unsigned char volatile __FAR *)0x7efe5b)
#define     RSTCR10                 (*(unsigned char volatile __FAR *)0x7efe5c)
#define     RSTCR11                 (*(unsigned char volatile __FAR *)0x7efe5d)
#define     RSTCR12                 (*(unsigned char volatile __FAR *)0x7efe5e)
#define     RSTCR13                 (*(unsigned char volatile __FAR *)0x7efe5f)

#define     RTCCR                   (*(unsigned char volatile __FAR *)0x7efe60)
#define     RTCCFG                  (*(unsigned char volatile __FAR *)0x7efe61)
#define     RTCIEN                  (*(unsigned char volatile __FAR *)0x7efe62)
#define     RTCIF                   (*(unsigned char volatile __FAR *)0x7efe63)
#define     ALAHOUR                 (*(unsigned char volatile __FAR *)0x7efe64)
#define     ALAMIN                  (*(unsigned char volatile __FAR *)0x7efe65)
#define     ALASEC                  (*(unsigned char volatile __FAR *)0x7efe66)
#define     ALASSEC                 (*(unsigned char volatile __FAR *)0x7efe67)
#define     INIYEAR                 (*(unsigned char volatile __FAR *)0x7efe68)
#define     INIMONTH                (*(unsigned char volatile __FAR *)0x7efe69)
#define     INIDAY                  (*(unsigned char volatile __FAR *)0x7efe6a)
#define     INIHOUR                 (*(unsigned char volatile __FAR *)0x7efe6b)
#define     INIMIN                  (*(unsigned char volatile __FAR *)0x7efe6c)
#define     INISEC                  (*(unsigned char volatile __FAR *)0x7efe6d)
#define     INISSEC                 (*(unsigned char volatile __FAR *)0x7efe6e)
#define     RTCWEEK                 (*(unsigned char volatile __FAR *)0x7efe6f)
#define     RTCYEAR                 (*(unsigned char volatile __FAR *)0x7efe70)
#define     RTCMONTH                (*(unsigned char volatile __FAR *)0x7efe71)
#define     RTCDAY                  (*(unsigned char volatile __FAR *)0x7efe72)
#define     RTCHOUR                 (*(unsigned char volatile __FAR *)0x7efe73)
#define     RTCMIN                  (*(unsigned char volatile __FAR *)0x7efe74)
#define     RTCSEC                  (*(unsigned char volatile __FAR *)0x7efe75)
#define     RTCSSEC                 (*(unsigned char volatile __FAR *)0x7efe76)

#define     T11CR                   (*(unsigned char volatile __FAR *)0x7efe78)
#define     T11PS                   (*(unsigned char volatile __FAR *)0x7efe79)
#define     T11H                    (*(unsigned char volatile __FAR *)0x7efe7a)
#define     T11L                    (*(unsigned char volatile __FAR *)0x7efe7b)
#define     TH11                    (*(unsigned char volatile __FAR *)0x7efe7a)
#define     TL11                    (*(unsigned char volatile __FAR *)0x7efe7b)

#define     I2CCFG                  (*(unsigned char volatile __FAR *)0x7efe80)
#define     I2CMSCR                 (*(unsigned char volatile __FAR *)0x7efe81)
#define     I2CMSST                 (*(unsigned char volatile __FAR *)0x7efe82)
#define     I2CSLCR                 (*(unsigned char volatile __FAR *)0x7efe83)
#define     I2CSLST                 (*(unsigned char volatile __FAR *)0x7efe84)
#define     I2CSLADR                (*(unsigned char volatile __FAR *)0x7efe85)
#define     I2CTXD                  (*(unsigned char volatile __FAR *)0x7efe86)
#define     I2CRXD                  (*(unsigned char volatile __FAR *)0x7efe87)
#define     I2CMSAUX                (*(unsigned char volatile __FAR *)0x7efe88)
#define     I2CPSCR                 (*(unsigned char volatile __FAR *)0x7efe89)

#define     SPI_CLKDIV              (*(unsigned char volatile __FAR *)0x7efe90)
#define     PWMA_CLKDIV             (*(unsigned char volatile __FAR *)0x7efe91)
#define     PWMB_CLKDIV             (*(unsigned char volatile __FAR *)0x7efe92)
#define     TFPU_CLKDIV             (*(unsigned char volatile __FAR *)0x7efe93)
#define     I2S_CLKDIV              (*(unsigned char volatile __FAR *)0x7efe94)
#define     I2S2_CLKDIV             (*(unsigned char volatile __FAR *)0x7efe95)
#define     PWMC_CLKDIV             (*(unsigned char volatile __FAR *)0x7efe96)
#define     PWMD_CLKDIV             (*(unsigned char volatile __FAR *)0x7efe97)

#define     RSTFLAG                 (*(unsigned char volatile __FAR *)0x7efe99)
#define     RSTCR0                  (*(unsigned char volatile __FAR *)0x7efe9a)
#define     RSTCR1                  (*(unsigned char volatile __FAR *)0x7efe9b)
#define     RSTCR2                  (*(unsigned char volatile __FAR *)0x7efe9c)
#define     RSTCR3                  (*(unsigned char volatile __FAR *)0x7efe9d)
#define     RSTCR4                  (*(unsigned char volatile __FAR *)0x7efe9e)
#define     RSTCR5                  (*(unsigned char volatile __FAR *)0x7efe9f)

#define     TM0PS                   (*(unsigned char volatile __FAR *)0x7efea0)
#define     TM1PS                   (*(unsigned char volatile __FAR *)0x7efea1)
#define     TM2PS                   (*(unsigned char volatile __FAR *)0x7efea2)
#define     TM3PS                   (*(unsigned char volatile __FAR *)0x7efea3)
#define     TM4PS                   (*(unsigned char volatile __FAR *)0x7efea4)
#define     ADCTIM                  (*(unsigned char volatile __FAR *)0x7efea8)
#define     INTXIT                  (*(unsigned char volatile __FAR *)0x7efea9)
#define     ADC_RESH                (*(unsigned char volatile __FAR *)0x7efeaa)
#define     ADC2_RESH               (*(unsigned char volatile __FAR *)0x7efeab)
#define     TIMER_PS                (*(unsigned char volatile __FAR *)0x7efeac)
#define     ADCEXCFG                (*(unsigned char volatile __FAR *)0x7efead)
#define     CMPEXCFG                (*(unsigned char volatile __FAR *)0x7efeae)
#define     ADCEXCFG2               (*(unsigned char volatile __FAR *)0x7efeaf)

#define     PWMA_ETRPS              (*(unsigned char volatile __FAR *)0x7efeb0)
#define     PWMA_ENO                (*(unsigned char volatile __FAR *)0x7efeb1)
#define     PWMA_PS                 (*(unsigned char volatile __FAR *)0x7efeb2)
#define     PWMA_IOAUX              (*(unsigned char volatile __FAR *)0x7efeb3)
#define     PWMB_ETRPS              (*(unsigned char volatile __FAR *)0x7efeb4)
#define     PWMB_ENO                (*(unsigned char volatile __FAR *)0x7efeb5)
#define     PWMB_PS                 (*(unsigned char volatile __FAR *)0x7efeb6)
#define     PWMB_IOAUX              (*(unsigned char volatile __FAR *)0x7efeb7)
#define     PWMA_PS2                (*(unsigned char volatile __FAR *)0x7efeb8)
#define     PWMA_RCRH               (*(unsigned char volatile __FAR *)0x7efeb9)
#define     PWMB_RCRH               (*(unsigned char volatile __FAR *)0x7efeba)

#define     PWMA_CR1                (*(unsigned char volatile __FAR *)0x7efec0)
#define     PWMA_CR2                (*(unsigned char volatile __FAR *)0x7efec1)
#define     PWMA_SMCR               (*(unsigned char volatile __FAR *)0x7efec2)
#define     PWMA_ETR                (*(unsigned char volatile __FAR *)0x7efec3)
#define     PWMA_IER                (*(unsigned char volatile __FAR *)0x7efec4)
#define     PWMA_SR1                (*(unsigned char volatile __FAR *)0x7efec5)
#define     PWMA_SR2                (*(unsigned char volatile __FAR *)0x7efec6)
#define     PWMA_EGR                (*(unsigned char volatile __FAR *)0x7efec7)
#define     PWMA_CCMR1              (*(unsigned char volatile __FAR *)0x7efec8)
#define     PWMA_CCMR2              (*(unsigned char volatile __FAR *)0x7efec9)
#define     PWMA_CCMR3              (*(unsigned char volatile __FAR *)0x7efeca)
#define     PWMA_CCMR4              (*(unsigned char volatile __FAR *)0x7efecb)
#define     PWMA_CCER1              (*(unsigned char volatile __FAR *)0x7efecc)
#define     PWMA_CCER2              (*(unsigned char volatile __FAR *)0x7efecd)
#define     PWMA_CNTRH              (*(unsigned char volatile __FAR *)0x7efece)
#define     PWMA_CNTRL              (*(unsigned char volatile __FAR *)0x7efecf)
#define     PWMA_PSCRH              (*(unsigned char volatile __FAR *)0x7efed0)
#define     PWMA_PSCRL              (*(unsigned char volatile __FAR *)0x7efed1)
#define     PWMA_ARRH               (*(unsigned char volatile __FAR *)0x7efed2)
#define     PWMA_ARRL               (*(unsigned char volatile __FAR *)0x7efed3)
#define     PWMA_RCR                (*(unsigned char volatile __FAR *)0x7efed4)
#define     PWMA_CCR1H              (*(unsigned char volatile __FAR *)0x7efed5)
#define     PWMA_CCR1L              (*(unsigned char volatile __FAR *)0x7efed6)
#define     PWMA_CCR2H              (*(unsigned char volatile __FAR *)0x7efed7)
#define     PWMA_CCR2L              (*(unsigned char volatile __FAR *)0x7efed8)
#define     PWMA_CCR3H              (*(unsigned char volatile __FAR *)0x7efed9)
#define     PWMA_CCR3L              (*(unsigned char volatile __FAR *)0x7efeda)
#define     PWMA_CCR4H              (*(unsigned char volatile __FAR *)0x7efedb)
#define     PWMA_CCR4L              (*(unsigned char volatile __FAR *)0x7efedc)
#define     PWMA_BKR                (*(unsigned char volatile __FAR *)0x7efedd)
#define     PWMA_DTR                (*(unsigned char volatile __FAR *)0x7efede)
#define     PWMA_OISR               (*(unsigned char volatile __FAR *)0x7efedf)

#define     PWMB_CR1                (*(unsigned char volatile __FAR *)0x7efee0)
#define     PWMB_CR2                (*(unsigned char volatile __FAR *)0x7efee1)
#define     PWMB_SMCR               (*(unsigned char volatile __FAR *)0x7efee2)
#define     PWMB_ETR                (*(unsigned char volatile __FAR *)0x7efee3)
#define     PWMB_IER                (*(unsigned char volatile __FAR *)0x7efee4)
#define     PWMB_SR1                (*(unsigned char volatile __FAR *)0x7efee5)
#define     PWMB_SR2                (*(unsigned char volatile __FAR *)0x7efee6)
#define     PWMB_EGR                (*(unsigned char volatile __FAR *)0x7efee7)
#define     PWMB_CCMR1              (*(unsigned char volatile __FAR *)0x7efee8)
#define     PWMB_CCMR2              (*(unsigned char volatile __FAR *)0x7efee9)
#define     PWMB_CCMR3              (*(unsigned char volatile __FAR *)0x7efeea)
#define     PWMB_CCMR4              (*(unsigned char volatile __FAR *)0x7efeeb)
#define     PWMB_CCER1              (*(unsigned char volatile __FAR *)0x7efeec)
#define     PWMB_CCER2              (*(unsigned char volatile __FAR *)0x7efeed)
#define     PWMB_CNTRH              (*(unsigned char volatile __FAR *)0x7efeee)
#define     PWMB_CNTRL              (*(unsigned char volatile __FAR *)0x7efeef)
#define     PWMB_PSCRH              (*(unsigned char volatile __FAR *)0x7efef0)
#define     PWMB_PSCRL              (*(unsigned char volatile __FAR *)0x7efef1)
#define     PWMB_ARRH               (*(unsigned char volatile __FAR *)0x7efef2)
#define     PWMB_ARRL               (*(unsigned char volatile __FAR *)0x7efef3)
#define     PWMB_RCR                (*(unsigned char volatile __FAR *)0x7efef4)
#define     PWMB_CCR5H              (*(unsigned char volatile __FAR *)0x7efef5)
#define     PWMB_CCR5L              (*(unsigned char volatile __FAR *)0x7efef6)
#define     PWMB_CCR6H              (*(unsigned char volatile __FAR *)0x7efef7)
#define     PWMB_CCR6L              (*(unsigned char volatile __FAR *)0x7efef8)
#define     PWMB_CCR7H              (*(unsigned char volatile __FAR *)0x7efef9)
#define     PWMB_CCR7L              (*(unsigned char volatile __FAR *)0x7efefa)
#define     PWMB_CCR8H              (*(unsigned char volatile __FAR *)0x7efefb)
#define     PWMB_CCR8L              (*(unsigned char volatile __FAR *)0x7efefc)
#define     PWMB_BKR                (*(unsigned char volatile __FAR *)0x7efefd)
#define     PWMB_DTR                (*(unsigned char volatile __FAR *)0x7efefe)
#define     PWMB_OISR               (*(unsigned char volatile __FAR *)0x7efeff)

/////////////////////////////////////////////////
//7E:FD00H-7E:FDFFH
/////////////////////////////////////////////////

#define     P0INTE                  (*(unsigned char volatile __FAR *)0x7efd00)
#define     P1INTE                  (*(unsigned char volatile __FAR *)0x7efd01)
#define     P2INTE                  (*(unsigned char volatile __FAR *)0x7efd02)
#define     P3INTE                  (*(unsigned char volatile __FAR *)0x7efd03)
#define     P4INTE                  (*(unsigned char volatile __FAR *)0x7efd04)
#define     P5INTE                  (*(unsigned char volatile __FAR *)0x7efd05)
#define     P6INTE                  (*(unsigned char volatile __FAR *)0x7efd06)
#define     P7INTE                  (*(unsigned char volatile __FAR *)0x7efd07)
#define     P8INTE                  (*(unsigned char volatile __FAR *)0x7efd08)
#define     P9INTE                  (*(unsigned char volatile __FAR *)0x7efd09)
#define     PAINTE                  (*(unsigned char volatile __FAR *)0x7efd0a)
#define     PBINTE                  (*(unsigned char volatile __FAR *)0x7efd0b)
#define     PCINTE                  (*(unsigned char volatile __FAR *)0x7efd0c)
#define     PDINTE                  (*(unsigned char volatile __FAR *)0x7efd0d)
#define     PEINTE                  (*(unsigned char volatile __FAR *)0x7efd0e)
#define     PFINTE                  (*(unsigned char volatile __FAR *)0x7efd0f)

#define     P0INTF                  (*(unsigned char volatile __FAR *)0x7efd10)
#define     P1INTF                  (*(unsigned char volatile __FAR *)0x7efd11)
#define     P2INTF                  (*(unsigned char volatile __FAR *)0x7efd12)
#define     P3INTF                  (*(unsigned char volatile __FAR *)0x7efd13)
#define     P4INTF                  (*(unsigned char volatile __FAR *)0x7efd14)
#define     P5INTF                  (*(unsigned char volatile __FAR *)0x7efd15)
#define     P6INTF                  (*(unsigned char volatile __FAR *)0x7efd16)
#define     P7INTF                  (*(unsigned char volatile __FAR *)0x7efd17)
#define     P8INTF                  (*(unsigned char volatile __FAR *)0x7efd18)
#define     P9INTF                  (*(unsigned char volatile __FAR *)0x7efd19)
#define     PAINTF                  (*(unsigned char volatile __FAR *)0x7efd1a)
#define     PBINTF                  (*(unsigned char volatile __FAR *)0x7efd1b)
#define     PCINTF                  (*(unsigned char volatile __FAR *)0x7efd1c)
#define     PDINTF                  (*(unsigned char volatile __FAR *)0x7efd1d)
#define     PEINTF                  (*(unsigned char volatile __FAR *)0x7efd1e)
#define     PFINTF                  (*(unsigned char volatile __FAR *)0x7efd1f)

#define     P0IM0                   (*(unsigned char volatile __FAR *)0x7efd20)
#define     P1IM0                   (*(unsigned char volatile __FAR *)0x7efd21)
#define     P2IM0                   (*(unsigned char volatile __FAR *)0x7efd22)
#define     P3IM0                   (*(unsigned char volatile __FAR *)0x7efd23)
#define     P4IM0                   (*(unsigned char volatile __FAR *)0x7efd24)
#define     P5IM0                   (*(unsigned char volatile __FAR *)0x7efd25)
#define     P6IM0                   (*(unsigned char volatile __FAR *)0x7efd26)
#define     P7IM0                   (*(unsigned char volatile __FAR *)0x7efd27)
#define     P8IM0                   (*(unsigned char volatile __FAR *)0x7efd28)
#define     P9IM0                   (*(unsigned char volatile __FAR *)0x7efd29)
#define     PAIM0                   (*(unsigned char volatile __FAR *)0x7efd2a)
#define     PBIM0                   (*(unsigned char volatile __FAR *)0x7efd2b)
#define     PCIM0                   (*(unsigned char volatile __FAR *)0x7efd2c)
#define     PDIM0                   (*(unsigned char volatile __FAR *)0x7efd2d)
#define     PEIM0                   (*(unsigned char volatile __FAR *)0x7efd2e)
#define     PFIM0                   (*(unsigned char volatile __FAR *)0x7efd2f)

#define     P0IM1                   (*(unsigned char volatile __FAR *)0x7efd30)
#define     P1IM1                   (*(unsigned char volatile __FAR *)0x7efd31)
#define     P2IM1                   (*(unsigned char volatile __FAR *)0x7efd32)
#define     P3IM1                   (*(unsigned char volatile __FAR *)0x7efd33)
#define     P4IM1                   (*(unsigned char volatile __FAR *)0x7efd34)
#define     P5IM1                   (*(unsigned char volatile __FAR *)0x7efd35)
#define     P6IM1                   (*(unsigned char volatile __FAR *)0x7efd36)
#define     P7IM1                   (*(unsigned char volatile __FAR *)0x7efd37)
#define     P8IM1                   (*(unsigned char volatile __FAR *)0x7efd38)
#define     P9IM1                   (*(unsigned char volatile __FAR *)0x7efd39)
#define     PAIM1                   (*(unsigned char volatile __FAR *)0x7efd3a)
#define     PBIM1                   (*(unsigned char volatile __FAR *)0x7efd3b)
#define     PCIM1                   (*(unsigned char volatile __FAR *)0x7efd3c)
#define     PDIM1                   (*(unsigned char volatile __FAR *)0x7efd3d)
#define     PEIM1                   (*(unsigned char volatile __FAR *)0x7efd3e)
#define     PFIM1                   (*(unsigned char volatile __FAR *)0x7efd3f)

#define     P0WKUE                  (*(unsigned char volatile __FAR *)0x7efd40)
#define     P1WKUE                  (*(unsigned char volatile __FAR *)0x7efd41)
#define     P2WKUE                  (*(unsigned char volatile __FAR *)0x7efd42)
#define     P3WKUE                  (*(unsigned char volatile __FAR *)0x7efd43)
#define     P4WKUE                  (*(unsigned char volatile __FAR *)0x7efd44)
#define     P5WKUE                  (*(unsigned char volatile __FAR *)0x7efd45)
#define     P6WKUE                  (*(unsigned char volatile __FAR *)0x7efd46)
#define     P7WKUE                  (*(unsigned char volatile __FAR *)0x7efd47)
#define     P8WKUE                  (*(unsigned char volatile __FAR *)0x7efd48)
#define     P9WKUE                  (*(unsigned char volatile __FAR *)0x7efd49)
#define     PAWKUE                  (*(unsigned char volatile __FAR *)0x7efd4a)
#define     PBWKUE                  (*(unsigned char volatile __FAR *)0x7efd4b)
#define     PCWKUE                  (*(unsigned char volatile __FAR *)0x7efd4c)
#define     PDWKUE                  (*(unsigned char volatile __FAR *)0x7efd4d)
#define     PEWKUE                  (*(unsigned char volatile __FAR *)0x7efd4e)
#define     PFWKUE                  (*(unsigned char volatile __FAR *)0x7efd4f)

#define     PINIPL                  (*(unsigned char volatile __FAR *)0x7efd60)
#define     PINIPH                  (*(unsigned char volatile __FAR *)0x7efd61)
#define     PIN2IPL                 (*(unsigned char volatile __FAR *)0x7efd62)
#define     PIN2IPH                 (*(unsigned char volatile __FAR *)0x7efd63)

#define     P_SWX1                  (*(unsigned char volatile __FAR *)0x7efd69)
#define     P_SWX2                  (*(unsigned char volatile __FAR *)0x7efd6a)
#define     P_SWX3                  (*(unsigned char volatile __FAR *)0x7efd6b)
#define     P_SWX4                  (*(unsigned char volatile __FAR *)0x7efd6c)
#define     P_SWX5                  (*(unsigned char volatile __FAR *)0x7efd6d)
#define     P_SWX6                  (*(unsigned char volatile __FAR *)0x7efd6e)
#define     P_SWX7                  (*(unsigned char volatile __FAR *)0x7efd6f)

#define     UR1TOCR                 (*(unsigned char volatile __FAR *)0x7efd70)
#define     UR1TOSR                 (*(unsigned char volatile __FAR *)0x7efd71)
#define     UR1TOTH                 (*(unsigned char volatile __FAR *)0x7efd72)
#define     UR1TOTL                 (*(unsigned char volatile __FAR *)0x7efd73)
#define     UR2TOCR                 (*(unsigned char volatile __FAR *)0x7efd74)
#define     UR2TOSR                 (*(unsigned char volatile __FAR *)0x7efd75)
#define     UR2TOTH                 (*(unsigned char volatile __FAR *)0x7efd76)
#define     UR2TOTL                 (*(unsigned char volatile __FAR *)0x7efd77)
#define     UR3TOCR                 (*(unsigned char volatile __FAR *)0x7efd78)
#define     UR3TOSR                 (*(unsigned char volatile __FAR *)0x7efd79)
#define     UR3TOTH                 (*(unsigned char volatile __FAR *)0x7efd7a)
#define     UR3TOTL                 (*(unsigned char volatile __FAR *)0x7efd7b)
#define     UR4TOCR                 (*(unsigned char volatile __FAR *)0x7efd7c)
#define     UR4TOSR                 (*(unsigned char volatile __FAR *)0x7efd7d)
#define     UR4TOTH                 (*(unsigned char volatile __FAR *)0x7efd7e)
#define     UR4TOTL                 (*(unsigned char volatile __FAR *)0x7efd7f)
#define     SPITOCR                 (*(unsigned char volatile __FAR *)0x7efd80)
#define     SPITOSR                 (*(unsigned char volatile __FAR *)0x7efd81)
#define     SPITOTH                 (*(unsigned char volatile __FAR *)0x7efd82)
#define     SPITOTL                 (*(unsigned char volatile __FAR *)0x7efd83)
#define     I2CTOCR                 (*(unsigned char volatile __FAR *)0x7efd84)
#define     I2CTOSR                 (*(unsigned char volatile __FAR *)0x7efd85)
#define     I2CTOTH                 (*(unsigned char volatile __FAR *)0x7efd86)
#define     I2CTOTL                 (*(unsigned char volatile __FAR *)0x7efd87)

#define     UR1TOTE                 (*(unsigned char volatile __FAR *)0x7efd88)
#define     UR2TOTE                 (*(unsigned char volatile __FAR *)0x7efd89)
#define     UR3TOTE                 (*(unsigned char volatile __FAR *)0x7efd8a)
#define     UR4TOTE                 (*(unsigned char volatile __FAR *)0x7efd8b)
#define     SPITOTE                 (*(unsigned char volatile __FAR *)0x7efd8c)
#define     I2CTOTE                 (*(unsigned char volatile __FAR *)0x7efd8d)

#define     I2S2CR                  (*(unsigned char volatile __FAR *)0x7efd90)
#define     I2S2SR                  (*(unsigned char volatile __FAR *)0x7efd91)
#define     I2S2DRH                 (*(unsigned char volatile __FAR *)0x7efd92)
#define     I2S2DRL                 (*(unsigned char volatile __FAR *)0x7efd93)
#define     I2S2PRH                 (*(unsigned char volatile __FAR *)0x7efd94)
#define     I2S2PRL                 (*(unsigned char volatile __FAR *)0x7efd95)
#define     I2S2CFGH                (*(unsigned char volatile __FAR *)0x7efd96)
#define     I2S2CFGL                (*(unsigned char volatile __FAR *)0x7efd97)

#define     I2SCR                   (*(unsigned char volatile __FAR *)0x7efd98)
#define     I2SSR                   (*(unsigned char volatile __FAR *)0x7efd99)
#define     I2SDRH                  (*(unsigned char volatile __FAR *)0x7efd9a)
#define     I2SDRL                  (*(unsigned char volatile __FAR *)0x7efd9b)
#define     I2SPRH                  (*(unsigned char volatile __FAR *)0x7efd9c)
#define     I2SPRL                  (*(unsigned char volatile __FAR *)0x7efd9d)
#define     I2SCFGH                 (*(unsigned char volatile __FAR *)0x7efd9e)
#define     I2SCFGL                 (*(unsigned char volatile __FAR *)0x7efd9f)
#define     I2SMD                   (*(unsigned char volatile __FAR *)0x7efda0)
#define     I2SMCKDIV               (*(unsigned char volatile __FAR *)0x7efda1)
#define     I2SINSEL                (*(unsigned char volatile __FAR *)0x7efda2)

#define     I2S2MD                  (*(unsigned char volatile __FAR *)0x7efda4)
#define     I2S2MCKDIV              (*(unsigned char volatile __FAR *)0x7efda5)
#define     I2S2INSEL               (*(unsigned char volatile __FAR *)0x7efda6)

#define     CRECR                   (*(unsigned char volatile __FAR *)0x7efda8)
#define     CRECNTH                 (*(unsigned char volatile __FAR *)0x7efda9)
#define     CRECNTL                 (*(unsigned char volatile __FAR *)0x7efdaa)
#define     CRERES                  (*(unsigned char volatile __FAR *)0x7efdab)
#define     CRECFG                  (*(unsigned char volatile __FAR *)0x7efdac)

#define     S2CFG                   (*(unsigned char volatile __FAR *)0x7efdb4)
#define     S2ADDR                  (*(unsigned char volatile __FAR *)0x7efdb5)
#define     S2ADEN                  (*(unsigned char volatile __FAR *)0x7efdb6)

#define     S3CFG                   (*(unsigned char volatile __FAR *)0x7efdb8)
#define     S3ADDR                  (*(unsigned char volatile __FAR *)0x7efdb9)
#define     S3ADEN                  (*(unsigned char volatile __FAR *)0x7efdba)

#define     S4CFG                   (*(unsigned char volatile __FAR *)0x7efdbc)
#define     S4ADDR                  (*(unsigned char volatile __FAR *)0x7efdbd)
#define     S4ADEN                  (*(unsigned char volatile __FAR *)0x7efdbe)

#define     USARTCR1                (*(unsigned char volatile __FAR *)0x7efdc0)
#define     USARTCR2                (*(unsigned char volatile __FAR *)0x7efdc1)
#define     USARTCR3                (*(unsigned char volatile __FAR *)0x7efdc2)
#define     USARTCR4                (*(unsigned char volatile __FAR *)0x7efdc3)
#define     USARTCR5                (*(unsigned char volatile __FAR *)0x7efdc4)
#define     USARTGTR                (*(unsigned char volatile __FAR *)0x7efdc5)
#define     USARTBRH                (*(unsigned char volatile __FAR *)0x7efdc6)
#define     USARTBRL                (*(unsigned char volatile __FAR *)0x7efdc7)

#define     USART2CR1               (*(unsigned char volatile __FAR *)0x7efdc8)
#define     USART2CR2               (*(unsigned char volatile __FAR *)0x7efdc9)
#define     USART2CR3               (*(unsigned char volatile __FAR *)0x7efdca)
#define     USART2CR4               (*(unsigned char volatile __FAR *)0x7efdcb)
#define     USART2CR5               (*(unsigned char volatile __FAR *)0x7efdcc)
#define     USART2GTR               (*(unsigned char volatile __FAR *)0x7efdcd)
#define     USART2BRH               (*(unsigned char volatile __FAR *)0x7efdce)
#define     USART2BRL               (*(unsigned char volatile __FAR *)0x7efdcf)

#define     USART3CR1               (*(unsigned char volatile __FAR *)0x7efdd0)
#define     USART3CR2               (*(unsigned char volatile __FAR *)0x7efdd1)
#define     USART3CR3               (*(unsigned char volatile __FAR *)0x7efdd2)
#define     USART3CR4               (*(unsigned char volatile __FAR *)0x7efdd3)
#define     USART3CR5               (*(unsigned char volatile __FAR *)0x7efdd4)
#define     USART3GTR               (*(unsigned char volatile __FAR *)0x7efdd5)
#define     USART3BRH               (*(unsigned char volatile __FAR *)0x7efdd6)
#define     USART3BRL               (*(unsigned char volatile __FAR *)0x7efdd7)

#define     USART4CR1               (*(unsigned char volatile __FAR *)0x7efdd8)
#define     USART4CR2               (*(unsigned char volatile __FAR *)0x7efdd9)
#define     USART4CR3               (*(unsigned char volatile __FAR *)0x7efdda)
#define     USART4CR4               (*(unsigned char volatile __FAR *)0x7efddb)
#define     USART4CR5               (*(unsigned char volatile __FAR *)0x7efddc)
#define     USART4GTR               (*(unsigned char volatile __FAR *)0x7efddd)
#define     USART4BRH               (*(unsigned char volatile __FAR *)0x7efdde)
#define     USART4BRL               (*(unsigned char volatile __FAR *)0x7efddf)

#define     CHIPID                  ( (unsigned char volatile __FAR *)0x7efde0)

#define     CHIPID0                 (*(unsigned char volatile __FAR *)0x7efde0)
#define     CHIPID1                 (*(unsigned char volatile __FAR *)0x7efde1)
#define     CHIPID2                 (*(unsigned char volatile __FAR *)0x7efde2)
#define     CHIPID3                 (*(unsigned char volatile __FAR *)0x7efde3)
#define     CHIPID4                 (*(unsigned char volatile __FAR *)0x7efde4)
#define     CHIPID5                 (*(unsigned char volatile __FAR *)0x7efde5)
#define     CHIPID6                 (*(unsigned char volatile __FAR *)0x7efde6)
#define     CHIPID7                 (*(unsigned char volatile __FAR *)0x7efde7)
#define     CHIPID8                 (*(unsigned char volatile __FAR *)0x7efde8)
#define     CHIPID9                 (*(unsigned char volatile __FAR *)0x7efde9)
#define     CHIPID10                (*(unsigned char volatile __FAR *)0x7efdea)
#define     CHIPID11                (*(unsigned char volatile __FAR *)0x7efdeb)
#define     CHIPID12                (*(unsigned char volatile __FAR *)0x7efdec)
#define     CHIPID13                (*(unsigned char volatile __FAR *)0x7efded)
#define     CHIPID14                (*(unsigned char volatile __FAR *)0x7efdee)
#define     CHIPID15                (*(unsigned char volatile __FAR *)0x7efdef)
#define     CHIPID16                (*(unsigned char volatile __FAR *)0x7efdf0)
#define     CHIPID17                (*(unsigned char volatile __FAR *)0x7efdf1)
#define     CHIPID18                (*(unsigned char volatile __FAR *)0x7efdf2)
#define     CHIPID19                (*(unsigned char volatile __FAR *)0x7efdf3)
#define     CHIPID20                (*(unsigned char volatile __FAR *)0x7efdf4)
#define     CHIPID21                (*(unsigned char volatile __FAR *)0x7efdf5)
#define     CHIPID22                (*(unsigned char volatile __FAR *)0x7efdf6)
#define     CHIPID23                (*(unsigned char volatile __FAR *)0x7efdf7)
#define     CHIPID24                (*(unsigned char volatile __FAR *)0x7efdf8)
#define     CHIPID25                (*(unsigned char volatile __FAR *)0x7efdf9)
#define     CHIPID26                (*(unsigned char volatile __FAR *)0x7efdfa)
#define     CHIPID27                (*(unsigned char volatile __FAR *)0x7efdfb)
#define     CHIPID28                (*(unsigned char volatile __FAR *)0x7efdfc)
#define     CHIPID29                (*(unsigned char volatile __FAR *)0x7efdfd)
#define     CHIPID30                (*(unsigned char volatile __FAR *)0x7efdfe)
#define     CHIPID31                (*(unsigned char volatile __FAR *)0x7efdff)

/////////////////////////////////////////////////
//7E:FC00H-7E:FCFFH
/////////////////////////////////////////////////



/////////////////////////////////////////////////
//7E:FB00H-7E:FBFFH
/////////////////////////////////////////////////

#define     CRC_CR                  (*(unsigned char volatile __FAR *)0x7efb30)
#define     CRC_DIN                 (*(unsigned char volatile __FAR *)0x7efb31)
#define     CRC_DOH                 (*(unsigned char volatile __FAR *)0x7efb32)
#define     CRC_DOL                 (*(unsigned char volatile __FAR *)0x7efb33)
#define     CRC_DO0                 (*(unsigned char volatile __FAR *)0x7efb32)
#define     CRC_DO1                 (*(unsigned char volatile __FAR *)0x7efb33)
#define     CRC_DO2                 (*(unsigned char volatile __FAR *)0x7efb34)
#define     CRC_DO3                 (*(unsigned char volatile __FAR *)0x7efb35)

#define     ADC2_CONTR              (*(unsigned char volatile __FAR *)0x7efb38)
#define     ADC2CFG                 (*(unsigned char volatile __FAR *)0x7efb39)
#define     ADC2_RES                (*(unsigned char volatile __FAR *)0x7efb3a)
#define     ADC2_RESL               (*(unsigned char volatile __FAR *)0x7efb3b)
#define     ADC2TIM                 (*(unsigned char volatile __FAR *)0x7efb3c)
#define     ADC2EXCFG               (*(unsigned char volatile __FAR *)0x7efb3d)
#define     ADC2INTR                (*(unsigned char volatile __FAR *)0x7efb3e)
#define     ADC2EXCFG2              (*(unsigned char volatile __FAR *)0x7efb3f)

#define     CMP1_6P6N_CR1           (*(unsigned char volatile __FAR *)0x7efb70)
#define     CMP1_6P6N_CR2           (*(unsigned char volatile __FAR *)0x7efb71)
#define     CMP1_6P6N_CR3           (*(unsigned char volatile __FAR *)0x7efb72)
#define     CMP1_6P6N_CR4           (*(unsigned char volatile __FAR *)0x7efb73)
#define     CMP2_6P6N_CR1           (*(unsigned char volatile __FAR *)0x7efb74)
#define     CMP2_6P6N_CR2           (*(unsigned char volatile __FAR *)0x7efb75)
#define     CMP2_6P6N_CR3           (*(unsigned char volatile __FAR *)0x7efb76)
#define     CMP2_6P6N_CR4           (*(unsigned char volatile __FAR *)0x7efb77)
#define     CMP3_6P6N_CR1           (*(unsigned char volatile __FAR *)0x7efb78)
#define     CMP3_6P6N_CR2           (*(unsigned char volatile __FAR *)0x7efb79)
#define     CMP3_6P6N_CR3           (*(unsigned char volatile __FAR *)0x7efb7a)
#define     CMP3_6P6N_CR4           (*(unsigned char volatile __FAR *)0x7efb7b)
#define     CMP4_6P6N_CR1           (*(unsigned char volatile __FAR *)0x7efb7c)
#define     CMP4_6P6N_CR2           (*(unsigned char volatile __FAR *)0x7efb7d)
#define     CMP4_6P6N_CR3           (*(unsigned char volatile __FAR *)0x7efb7e)
#define     CMP4_6P6N_CR4           (*(unsigned char volatile __FAR *)0x7efb7f)

#define     TM5PS                   (*(unsigned char volatile __FAR *)0x7efbb0)
#define     TM6PS                   (*(unsigned char volatile __FAR *)0x7efbb1)
#define     T6T5CFG                 (*(unsigned char volatile __FAR *)0x7efbb2)
#define     T6T5M                   (*(unsigned char volatile __FAR *)0x7efbb3)
#define     TH6                     (*(unsigned char volatile __FAR *)0x7efbb4)
#define     TL6                     (*(unsigned char volatile __FAR *)0x7efbb5)
#define     TH5                     (*(unsigned char volatile __FAR *)0x7efbb6)
#define     TL5                     (*(unsigned char volatile __FAR *)0x7efbb7)
#define     T6H                     (*(unsigned char volatile __FAR *)0x7efbb4)
#define     T6L                     (*(unsigned char volatile __FAR *)0x7efbb5)
#define     T5H                     (*(unsigned char volatile __FAR *)0x7efbb6)
#define     T5L                     (*(unsigned char volatile __FAR *)0x7efbb7)
#define     T6                      (*(unsigned int  volatile __FAR *)0x7efbb4)
#define     T5                      (*(unsigned int  volatile __FAR *)0x7efbb6)

#define     TM7PS                   (*(unsigned char volatile __FAR *)0x7efbb8)
#define     TM8PS                   (*(unsigned char volatile __FAR *)0x7efbb9)
#define     T8T7CFG                 (*(unsigned char volatile __FAR *)0x7efbba)
#define     T8T7M                   (*(unsigned char volatile __FAR *)0x7efbbb)
#define     TH8                     (*(unsigned char volatile __FAR *)0x7efbbc)
#define     TL8                     (*(unsigned char volatile __FAR *)0x7efbbd)
#define     TH7                     (*(unsigned char volatile __FAR *)0x7efbbe)
#define     TL7                     (*(unsigned char volatile __FAR *)0x7efbbf)
#define     T8H                     (*(unsigned char volatile __FAR *)0x7efbbc)
#define     T8L                     (*(unsigned char volatile __FAR *)0x7efbbd)
#define     T7H                     (*(unsigned char volatile __FAR *)0x7efbbe)
#define     T7L                     (*(unsigned char volatile __FAR *)0x7efbbf)
#define     T8                      (*(unsigned int  volatile __FAR *)0x7efbbc)
#define     T7                      (*(unsigned int  volatile __FAR *)0x7efbbe)

#define     TM9PS                   (*(unsigned char volatile __FAR *)0x7efbc0)
#define     TM10PS                  (*(unsigned char volatile __FAR *)0x7efbc1)
#define     T10T9CFG                (*(unsigned char volatile __FAR *)0x7efbc2)
#define     T10T9M                  (*(unsigned char volatile __FAR *)0x7efbc3)
#define     TH10                    (*(unsigned char volatile __FAR *)0x7efbc4)
#define     TL10                    (*(unsigned char volatile __FAR *)0x7efbc5)
#define     TH9                     (*(unsigned char volatile __FAR *)0x7efbc6)
#define     TL9                     (*(unsigned char volatile __FAR *)0x7efbc7)
#define     T10H                    (*(unsigned char volatile __FAR *)0x7efbc4)
#define     T10L                    (*(unsigned char volatile __FAR *)0x7efbc5)
#define     T9H                     (*(unsigned char volatile __FAR *)0x7efbc6)
#define     T9L                     (*(unsigned char volatile __FAR *)0x7efbc7)
#define     T9                      (*(unsigned int  volatile __FAR *)0x7efbc4)
#define     T10                     (*(unsigned int  volatile __FAR *)0x7efbc6)

#define     TM17PS                  (*(unsigned char volatile __FAR *)0x7efbc8)
#define     TM18PS                  (*(unsigned char volatile __FAR *)0x7efbc9)
#define     T18T17CFG               (*(unsigned char volatile __FAR *)0x7efbca)
#define     T18T17M                 (*(unsigned char volatile __FAR *)0x7efbcb)
#define     TH18                    (*(unsigned char volatile __FAR *)0x7efbcc)
#define     TL18                    (*(unsigned char volatile __FAR *)0x7efbcd)
#define     TH17                    (*(unsigned char volatile __FAR *)0x7efbce)
#define     TL17                    (*(unsigned char volatile __FAR *)0x7efbcf)
#define     T18H                    (*(unsigned char volatile __FAR *)0x7efbcc)
#define     T18L                    (*(unsigned char volatile __FAR *)0x7efbcd)
#define     T17H                    (*(unsigned char volatile __FAR *)0x7efbce)
#define     T17L                    (*(unsigned char volatile __FAR *)0x7efbcf)
#define     T18                     (*(unsigned int  volatile __FAR *)0x7efbcc)
#define     T17                     (*(unsigned int  volatile __FAR *)0x7efbce)

#define     CHIPIDX                 ( (unsigned char volatile __FAR *)0x7efbd0)

#define     CHIPIDX0                (*(unsigned char volatile __FAR *)0x7efbd0)
#define     CHIPIDX1                (*(unsigned char volatile __FAR *)0x7efbd1)
#define     CHIPIDX2                (*(unsigned char volatile __FAR *)0x7efbd2)
#define     CHIPIDX3                (*(unsigned char volatile __FAR *)0x7efbd3)
#define     CHIPIDX4                (*(unsigned char volatile __FAR *)0x7efbd4)
#define     CHIPIDX5                (*(unsigned char volatile __FAR *)0x7efbd5)
#define     CHIPIDX6                (*(unsigned char volatile __FAR *)0x7efbd6)
#define     CHIPIDX7                (*(unsigned char volatile __FAR *)0x7efbd7)
#define     CHIPIDX8                (*(unsigned char volatile __FAR *)0x7efbd8)
#define     CHIPIDX9                (*(unsigned char volatile __FAR *)0x7efbd9)
#define     CHIPIDX10               (*(unsigned char volatile __FAR *)0x7efbda)
#define     CHIPIDX11               (*(unsigned char volatile __FAR *)0x7efbdb)
#define     CHIPIDX12               (*(unsigned char volatile __FAR *)0x7efbdc)
#define     CHIPIDX13               (*(unsigned char volatile __FAR *)0x7efbdd)
#define     CHIPIDX14               (*(unsigned char volatile __FAR *)0x7efbde)
#define     CHIPIDX15               (*(unsigned char volatile __FAR *)0x7efbdf)
#define     CHIPIDX16               (*(unsigned char volatile __FAR *)0x7efbe0)
#define     CHIPIDX17               (*(unsigned char volatile __FAR *)0x7efbe1)
#define     CHIPIDX18               (*(unsigned char volatile __FAR *)0x7efbe2)
#define     CHIPIDX19               (*(unsigned char volatile __FAR *)0x7efbe3)
#define     CHIPIDX20               (*(unsigned char volatile __FAR *)0x7efbe4)
#define     CHIPIDX21               (*(unsigned char volatile __FAR *)0x7efbe5)
#define     CHIPIDX22               (*(unsigned char volatile __FAR *)0x7efbe6)
#define     CHIPIDX23               (*(unsigned char volatile __FAR *)0x7efbe7)
#define     CHIPIDX24               (*(unsigned char volatile __FAR *)0x7efbe8)
#define     CHIPIDX25               (*(unsigned char volatile __FAR *)0x7efbe9)
#define     CHIPIDX26               (*(unsigned char volatile __FAR *)0x7efbea)
#define     CHIPIDX27               (*(unsigned char volatile __FAR *)0x7efbeb)
#define     CHIPIDX28               (*(unsigned char volatile __FAR *)0x7efbec)
#define     CHIPIDX29               (*(unsigned char volatile __FAR *)0x7efbed)
#define     CHIPIDX30               (*(unsigned char volatile __FAR *)0x7efbee)
#define     CHIPIDX31               (*(unsigned char volatile __FAR *)0x7efbef)

#define     HSPWMA_CFG              (*(unsigned char volatile __FAR *)0x7efbf0)
#define     HSPWMA_ADR              (*(unsigned char volatile __FAR *)0x7efbf1)
#define     HSPWMA_DAT              (*(unsigned char volatile __FAR *)0x7efbf2)
#define     HSPWMA_ADRH             (*(unsigned char volatile __FAR *)0x7efbf3)
#define     HSPWMB_CFG              (*(unsigned char volatile __FAR *)0x7efbf4)
#define     HSPWMB_ADR              (*(unsigned char volatile __FAR *)0x7efbf5)
#define     HSPWMB_DAT              (*(unsigned char volatile __FAR *)0x7efbf6)
#define     HSPWMB_ADRH             (*(unsigned char volatile __FAR *)0x7efbf7)

#define     HSSPI_CFG               (*(unsigned char volatile __FAR *)0x7efbf8)
#define     HSSPI_CFG2              (*(unsigned char volatile __FAR *)0x7efbf9)
#define     HSSPI_STA               (*(unsigned char volatile __FAR *)0x7efbfa)
#define     HSSPI_PSCR              (*(unsigned char volatile __FAR *)0x7efbfb)

/////////////////////////////////////////////////
//7E:FA00H-7E:FAFFH
/////////////////////////////////////////////////

#define     DMA_M2M_CFG             (*(unsigned char volatile __FAR *)0x7efa00)
#define     DMA_M2M_CR              (*(unsigned char volatile __FAR *)0x7efa01)
#define     DMA_M2M_STA             (*(unsigned char volatile __FAR *)0x7efa02)
#define     DMA_M2M_AMT             (*(unsigned char volatile __FAR *)0x7efa03)
#define     DMA_M2M_DONE            (*(unsigned char volatile __FAR *)0x7efa04)
#define     DMA_M2M_TXAH            (*(unsigned char volatile __FAR *)0x7efa05)
#define     DMA_M2M_TXAL            (*(unsigned char volatile __FAR *)0x7efa06)
#define     DMA_M2M_RXAH            (*(unsigned char volatile __FAR *)0x7efa07)
#define     DMA_M2M_RXAL            (*(unsigned char volatile __FAR *)0x7efa08)

#define     DMA_ADC_CFG             (*(unsigned char volatile __FAR *)0x7efa10)
#define     DMA_ADC_CR              (*(unsigned char volatile __FAR *)0x7efa11)
#define     DMA_ADC_STA             (*(unsigned char volatile __FAR *)0x7efa12)
#define     DMA_ADC_AMT             (*(unsigned char volatile __FAR *)0x7efa13)
#define     DMA_ADC_DONE            (*(unsigned char volatile __FAR *)0x7efa14)
#define     DMA_ADC_RXAH            (*(unsigned char volatile __FAR *)0x7efa17)
#define     DMA_ADC_RXAL            (*(unsigned char volatile __FAR *)0x7efa18)
#define     DMA_ADC_CFG2            (*(unsigned char volatile __FAR *)0x7efa19)
#define     DMA_ADC_CHSW0           (*(unsigned char volatile __FAR *)0x7efa1a)
#define     DMA_ADC_CHSW1           (*(unsigned char volatile __FAR *)0x7efa1b)
#define     DMA_ADC_ITVH            (*(unsigned char volatile __FAR *)0x7efa1e)
#define     DMA_ADC_ITVL            (*(unsigned char volatile __FAR *)0x7efa1f)

#define     DMA_SPI_CFG             (*(unsigned char volatile __FAR *)0x7efa20)
#define     DMA_SPI_CR              (*(unsigned char volatile __FAR *)0x7efa21)
#define     DMA_SPI_STA             (*(unsigned char volatile __FAR *)0x7efa22)
#define     DMA_SPI_AMT             (*(unsigned char volatile __FAR *)0x7efa23)
#define     DMA_SPI_DONE            (*(unsigned char volatile __FAR *)0x7efa24)
#define     DMA_SPI_TXAH            (*(unsigned char volatile __FAR *)0x7efa25)
#define     DMA_SPI_TXAL            (*(unsigned char volatile __FAR *)0x7efa26)
#define     DMA_SPI_RXAH            (*(unsigned char volatile __FAR *)0x7efa27)
#define     DMA_SPI_RXAL            (*(unsigned char volatile __FAR *)0x7efa28)
#define     DMA_SPI_CFG2            (*(unsigned char volatile __FAR *)0x7efa29)
#define     DMA_SPI_ITVH            (*(unsigned char volatile __FAR *)0x7efa2e)
#define     DMA_SPI_ITVL            (*(unsigned char volatile __FAR *)0x7efa2f)

#define     DMA_UR1T_CFG            (*(unsigned char volatile __FAR *)0x7efa30)
#define     DMA_UR1T_CR             (*(unsigned char volatile __FAR *)0x7efa31)
#define     DMA_UR1T_STA            (*(unsigned char volatile __FAR *)0x7efa32)
#define     DMA_UR1T_AMT            (*(unsigned char volatile __FAR *)0x7efa33)
#define     DMA_UR1T_DONE           (*(unsigned char volatile __FAR *)0x7efa34)
#define     DMA_UR1T_TXAH           (*(unsigned char volatile __FAR *)0x7efa35)
#define     DMA_UR1T_TXAL           (*(unsigned char volatile __FAR *)0x7efa36)
#define     DMA_UR1R_CFG            (*(unsigned char volatile __FAR *)0x7efa38)
#define     DMA_UR1R_CR             (*(unsigned char volatile __FAR *)0x7efa39)
#define     DMA_UR1R_STA            (*(unsigned char volatile __FAR *)0x7efa3a)
#define     DMA_UR1R_AMT            (*(unsigned char volatile __FAR *)0x7efa3b)
#define     DMA_UR1R_DONE           (*(unsigned char volatile __FAR *)0x7efa3c)
#define     DMA_UR1R_RXAH           (*(unsigned char volatile __FAR *)0x7efa3d)
#define     DMA_UR1R_RXAL           (*(unsigned char volatile __FAR *)0x7efa3e)

#define     DMA_UR2T_CFG            (*(unsigned char volatile __FAR *)0x7efa40)
#define     DMA_UR2T_CR             (*(unsigned char volatile __FAR *)0x7efa41)
#define     DMA_UR2T_STA            (*(unsigned char volatile __FAR *)0x7efa42)
#define     DMA_UR2T_AMT            (*(unsigned char volatile __FAR *)0x7efa43)
#define     DMA_UR2T_DONE           (*(unsigned char volatile __FAR *)0x7efa44)
#define     DMA_UR2T_TXAH           (*(unsigned char volatile __FAR *)0x7efa45)
#define     DMA_UR2T_TXAL           (*(unsigned char volatile __FAR *)0x7efa46)
#define     DMA_UR2R_CFG            (*(unsigned char volatile __FAR *)0x7efa48)
#define     DMA_UR2R_CR             (*(unsigned char volatile __FAR *)0x7efa49)
#define     DMA_UR2R_STA            (*(unsigned char volatile __FAR *)0x7efa4a)
#define     DMA_UR2R_AMT            (*(unsigned char volatile __FAR *)0x7efa4b)
#define     DMA_UR2R_DONE           (*(unsigned char volatile __FAR *)0x7efa4c)
#define     DMA_UR2R_RXAH           (*(unsigned char volatile __FAR *)0x7efa4d)
#define     DMA_UR2R_RXAL           (*(unsigned char volatile __FAR *)0x7efa4e)

#define     DMA_UR3T_CFG            (*(unsigned char volatile __FAR *)0x7efa50)
#define     DMA_UR3T_CR             (*(unsigned char volatile __FAR *)0x7efa51)
#define     DMA_UR3T_STA            (*(unsigned char volatile __FAR *)0x7efa52)
#define     DMA_UR3T_AMT            (*(unsigned char volatile __FAR *)0x7efa53)
#define     DMA_UR3T_DONE           (*(unsigned char volatile __FAR *)0x7efa54)
#define     DMA_UR3T_TXAH           (*(unsigned char volatile __FAR *)0x7efa55)
#define     DMA_UR3T_TXAL           (*(unsigned char volatile __FAR *)0x7efa56)
#define     DMA_UR3R_CFG            (*(unsigned char volatile __FAR *)0x7efa58)
#define     DMA_UR3R_CR             (*(unsigned char volatile __FAR *)0x7efa59)
#define     DMA_UR3R_STA            (*(unsigned char volatile __FAR *)0x7efa5a)
#define     DMA_UR3R_AMT            (*(unsigned char volatile __FAR *)0x7efa5b)
#define     DMA_UR3R_DONE           (*(unsigned char volatile __FAR *)0x7efa5c)
#define     DMA_UR3R_RXAH           (*(unsigned char volatile __FAR *)0x7efa5d)
#define     DMA_UR3R_RXAL           (*(unsigned char volatile __FAR *)0x7efa5e)

#define     DMA_UR4T_CFG            (*(unsigned char volatile __FAR *)0x7efa60)
#define     DMA_UR4T_CR             (*(unsigned char volatile __FAR *)0x7efa61)
#define     DMA_UR4T_STA            (*(unsigned char volatile __FAR *)0x7efa62)
#define     DMA_UR4T_AMT            (*(unsigned char volatile __FAR *)0x7efa63)
#define     DMA_UR4T_DONE           (*(unsigned char volatile __FAR *)0x7efa64)
#define     DMA_UR4T_TXAH           (*(unsigned char volatile __FAR *)0x7efa65)
#define     DMA_UR4T_TXAL           (*(unsigned char volatile __FAR *)0x7efa66)
#define     DMA_UR4R_CFG            (*(unsigned char volatile __FAR *)0x7efa68)
#define     DMA_UR4R_CR             (*(unsigned char volatile __FAR *)0x7efa69)
#define     DMA_UR4R_STA            (*(unsigned char volatile __FAR *)0x7efa6a)
#define     DMA_UR4R_AMT            (*(unsigned char volatile __FAR *)0x7efa6b)
#define     DMA_UR4R_DONE           (*(unsigned char volatile __FAR *)0x7efa6c)
#define     DMA_UR4R_RXAH           (*(unsigned char volatile __FAR *)0x7efa6d)
#define     DMA_UR4R_RXAL           (*(unsigned char volatile __FAR *)0x7efa6e)

#define     DMA_LCM_CFG             (*(unsigned char volatile __FAR *)0x7efa70)
#define     DMA_LCM_CR              (*(unsigned char volatile __FAR *)0x7efa71)
#define     DMA_LCM_STA             (*(unsigned char volatile __FAR *)0x7efa72)
#define     DMA_LCM_AMT             (*(unsigned char volatile __FAR *)0x7efa73)
#define     DMA_LCM_DONE            (*(unsigned char volatile __FAR *)0x7efa74)
#define     DMA_LCM_TXAH            (*(unsigned char volatile __FAR *)0x7efa75)
#define     DMA_LCM_TXAL            (*(unsigned char volatile __FAR *)0x7efa76)
#define     DMA_LCM_RXAH            (*(unsigned char volatile __FAR *)0x7efa77)
#define     DMA_LCM_RXAL            (*(unsigned char volatile __FAR *)0x7efa78)
#define     DMA_LCM_ITVH            (*(unsigned char volatile __FAR *)0x7efa7e)
#define     DMA_LCM_ITVL            (*(unsigned char volatile __FAR *)0x7efa7f)

#define     DMA_M2M_AMTH            (*(unsigned char volatile __FAR *)0x7efa80)
#define     DMA_M2M_DONEH           (*(unsigned char volatile __FAR *)0x7efa81)
#define     DMA_ADC_AMTH            (*(unsigned char volatile __FAR *)0x7efa82)
#define     DMA_ADC_DONEH           (*(unsigned char volatile __FAR *)0x7efa83)
#define     DMA_SPI_AMTH            (*(unsigned char volatile __FAR *)0x7efa84)
#define     DMA_SPI_DONEH           (*(unsigned char volatile __FAR *)0x7efa85)
#define     DMA_LCM_AMTH            (*(unsigned char volatile __FAR *)0x7efa86)
#define     DMA_LCM_DONEH           (*(unsigned char volatile __FAR *)0x7efa87)
#define     DMA_UR1T_AMTH           (*(unsigned char volatile __FAR *)0x7efa88)
#define     DMA_UR1T_DONEH          (*(unsigned char volatile __FAR *)0x7efa89)
#define     DMA_UR1R_AMTH           (*(unsigned char volatile __FAR *)0x7efa8a)
#define     DMA_UR1R_DONEH          (*(unsigned char volatile __FAR *)0x7efa8b)
#define     DMA_UR2T_AMTH           (*(unsigned char volatile __FAR *)0x7efa8c)
#define     DMA_UR2T_DONEH          (*(unsigned char volatile __FAR *)0x7efa8d)
#define     DMA_UR2R_AMTH           (*(unsigned char volatile __FAR *)0x7efa8e)
#define     DMA_UR2R_DONEH          (*(unsigned char volatile __FAR *)0x7efa8f)
#define     DMA_UR3T_AMTH           (*(unsigned char volatile __FAR *)0x7efa90)
#define     DMA_UR3T_DONEH          (*(unsigned char volatile __FAR *)0x7efa91)
#define     DMA_UR3R_AMTH           (*(unsigned char volatile __FAR *)0x7efa92)
#define     DMA_UR3R_DONEH          (*(unsigned char volatile __FAR *)0x7efa93)
#define     DMA_UR4T_AMTH           (*(unsigned char volatile __FAR *)0x7efa94)
#define     DMA_UR4T_DONEH          (*(unsigned char volatile __FAR *)0x7efa95)
#define     DMA_UR4R_AMTH           (*(unsigned char volatile __FAR *)0x7efa96)
#define     DMA_UR4R_DONEH          (*(unsigned char volatile __FAR *)0x7efa97)

#define     DMA_I2CT_CFG            (*(unsigned char volatile __FAR *)0x7efa98)
#define     DMA_I2CT_CR             (*(unsigned char volatile __FAR *)0x7efa99)
#define     DMA_I2CT_STA            (*(unsigned char volatile __FAR *)0x7efa9a)
#define     DMA_I2CT_AMT            (*(unsigned char volatile __FAR *)0x7efa9b)
#define     DMA_I2CT_DONE           (*(unsigned char volatile __FAR *)0x7efa9c)
#define     DMA_I2CT_TXAH           (*(unsigned char volatile __FAR *)0x7efa9d)
#define     DMA_I2CT_TXAL           (*(unsigned char volatile __FAR *)0x7efa9e)
#define     DMA_I2CR_CFG            (*(unsigned char volatile __FAR *)0x7efaa0)
#define     DMA_I2CR_CR             (*(unsigned char volatile __FAR *)0x7efaa1)
#define     DMA_I2CR_STA            (*(unsigned char volatile __FAR *)0x7efaa2)
#define     DMA_I2CR_AMT            (*(unsigned char volatile __FAR *)0x7efaa3)
#define     DMA_I2CR_DONE           (*(unsigned char volatile __FAR *)0x7efaa4)
#define     DMA_I2CR_RXAH           (*(unsigned char volatile __FAR *)0x7efaa5)
#define     DMA_I2CR_RXAL           (*(unsigned char volatile __FAR *)0x7efaa6)

#define     DMA_I2CT_AMTH           (*(unsigned char volatile __FAR *)0x7efaa8)
#define     DMA_I2CT_DONEH          (*(unsigned char volatile __FAR *)0x7efaa9)
#define     DMA_I2CR_AMTH           (*(unsigned char volatile __FAR *)0x7efaaa)
#define     DMA_I2CR_DONEH          (*(unsigned char volatile __FAR *)0x7efaab)
#define     DMA_I2C_CR              (*(unsigned char volatile __FAR *)0x7efaad)
#define     DMA_I2C_ST1             (*(unsigned char volatile __FAR *)0x7efaae)
#define     DMA_I2C_ST2             (*(unsigned char volatile __FAR *)0x7efaaf)

#define     DMA_I2ST_CFG            (*(unsigned char volatile __FAR *)0x7efab0)
#define     DMA_I2ST_CR             (*(unsigned char volatile __FAR *)0x7efab1)
#define     DMA_I2ST_STA            (*(unsigned char volatile __FAR *)0x7efab2)
#define     DMA_I2ST_AMT            (*(unsigned char volatile __FAR *)0x7efab3)
#define     DMA_I2ST_DONE           (*(unsigned char volatile __FAR *)0x7efab4)
#define     DMA_I2ST_TXAH           (*(unsigned char volatile __FAR *)0x7efab5)
#define     DMA_I2ST_TXAL           (*(unsigned char volatile __FAR *)0x7efab6)
#define     DMA_I2SR_CFG            (*(unsigned char volatile __FAR *)0x7efab8)
#define     DMA_I2SR_CR             (*(unsigned char volatile __FAR *)0x7efab9)
#define     DMA_I2SR_STA            (*(unsigned char volatile __FAR *)0x7efaba)
#define     DMA_I2SR_AMT            (*(unsigned char volatile __FAR *)0x7efabb)
#define     DMA_I2SR_DONE           (*(unsigned char volatile __FAR *)0x7efabc)
#define     DMA_I2SR_RXAH           (*(unsigned char volatile __FAR *)0x7efabd)
#define     DMA_I2SR_RXAL           (*(unsigned char volatile __FAR *)0x7efabe)

#define     DMA_I2ST_AMTH           (*(unsigned char volatile __FAR *)0x7efac0)
#define     DMA_I2ST_DONEH          (*(unsigned char volatile __FAR *)0x7efac1)
#define     DMA_I2SR_AMTH           (*(unsigned char volatile __FAR *)0x7efac2)
#define     DMA_I2SR_DONEH          (*(unsigned char volatile __FAR *)0x7efac3)
#define     DMA_I2C_ITVH            (*(unsigned char volatile __FAR *)0x7efac4)
#define     DMA_I2C_ITVL            (*(unsigned char volatile __FAR *)0x7efac5)
#define     DMA_I2S_ITVH            (*(unsigned char volatile __FAR *)0x7efac6)
#define     DMA_I2S_ITVL            (*(unsigned char volatile __FAR *)0x7efac7)
#define     DMA_UR1_ITVH            (*(unsigned char volatile __FAR *)0x7efac8)
#define     DMA_UR1_ITVL            (*(unsigned char volatile __FAR *)0x7efac9)
#define     DMA_UR2_ITVH            (*(unsigned char volatile __FAR *)0x7efaca)
#define     DMA_UR2_ITVL            (*(unsigned char volatile __FAR *)0x7efacb)
#define     DMA_UR3_ITVH            (*(unsigned char volatile __FAR *)0x7efacc)
#define     DMA_UR3_ITVL            (*(unsigned char volatile __FAR *)0x7efacd)
#define     DMA_UR4_ITVH            (*(unsigned char volatile __FAR *)0x7eface)
#define     DMA_UR4_ITVL            (*(unsigned char volatile __FAR *)0x7efacf)

#define     DMA_QSPI_CFG            (*(unsigned char volatile __FAR *)0x7efad0)
#define     DMA_QSPI_CR             (*(unsigned char volatile __FAR *)0x7efad1)
#define     DMA_QSPI_STA            (*(unsigned char volatile __FAR *)0x7efad2)
#define     DMA_QSPI_AMT            (*(unsigned char volatile __FAR *)0x7efad3)
#define     DMA_QSPI_DONE           (*(unsigned char volatile __FAR *)0x7efad4)
#define     DMA_QSPI_TXAH           (*(unsigned char volatile __FAR *)0x7efad5)
#define     DMA_QSPI_TXAL           (*(unsigned char volatile __FAR *)0x7efad6)
#define     DMA_QSPI_RXAH           (*(unsigned char volatile __FAR *)0x7efad7)
#define     DMA_QSPI_RXAL           (*(unsigned char volatile __FAR *)0x7efad8)
#define     DMA_QSPI_AMTH           (*(unsigned char volatile __FAR *)0x7efadb)
#define     DMA_QSPI_DONEH          (*(unsigned char volatile __FAR *)0x7efadc)
#define     DMA_QSPI_ITVH           (*(unsigned char volatile __FAR *)0x7efade)
#define     DMA_QSPI_ITVL           (*(unsigned char volatile __FAR *)0x7efadf)

#define     DMA_ADC2_CFG            (*(unsigned char volatile __FAR *)0x7efae0)
#define     DMA_ADC2_CR             (*(unsigned char volatile __FAR *)0x7efae1)
#define     DMA_ADC2_STA            (*(unsigned char volatile __FAR *)0x7efae2)
#define     DMA_ADC2_CFG2           (*(unsigned char volatile __FAR *)0x7efae3)
#define     DMA_ADC2_AMTH           (*(unsigned char volatile __FAR *)0x7efae4)
#define     DMA_ADC2_AMT            (*(unsigned char volatile __FAR *)0x7efae5)
#define     DMA_ADC2_DONEH          (*(unsigned char volatile __FAR *)0x7efae6)
#define     DMA_ADC2_DONE           (*(unsigned char volatile __FAR *)0x7efae7)
#define     DMA_ADC2_RXAH           (*(unsigned char volatile __FAR *)0x7efae8)
#define     DMA_ADC2_RXAL           (*(unsigned char volatile __FAR *)0x7efae9)
#define     DMA_ADC2_CHSW0          (*(unsigned char volatile __FAR *)0x7efaea)
#define     DMA_ADC2_CHSW1          (*(unsigned char volatile __FAR *)0x7efaeb)
#define     DMA_ADC2_ITVH           (*(unsigned char volatile __FAR *)0x7efaee)
#define     DMA_ADC2_ITVL           (*(unsigned char volatile __FAR *)0x7efaef)

#define     DMA_P2P1_DEST           (*(unsigned char volatile __FAR *)0x7efaf0)
#define     DMA_P2P1_SRC            (*(unsigned char volatile __FAR *)0x7efaf1)
#define     DMA_P2P2_DEST           (*(unsigned char volatile __FAR *)0x7efaf2)
#define     DMA_P2P2_SRC            (*(unsigned char volatile __FAR *)0x7efaf3)

#define     P2P_SRC_UR1RX           0x01
#define     P2P_SRC_UR2RX           0x02
#define     P2P_SRC_UR3RX           0x03
#define     P2P_SRC_UR4RX           0x04
#define     P2P_SRC_SPI1RX          0x05
#define     P2P_SRC_I2C1RX          0x06
#define     P2P_SRC_LCMRX           0x07
#define     P2P_SRC_QSPIRX          0x08
#define     P2P_SRC_ADC1            0x09
#define     P2P_SRC_I2S1RX          0x0A
#define     P2P_SRC_UR5RX           0x0B
#define     P2P_SRC_UR6RX           0x0C
#define     P2P_SRC_UR7RX           0x0D
#define     P2P_SRC_UR8RX           0x0E
#define     P2P_SRC_SPI2RX          0x0F
#define     P2P_SRC_SPI3RX          0x10
#define     P2P_SRC_SPI4RX          0x11
#define     P2P_SRC_I2C2RX          0x12
#define     P2P_SRC_I2S2RX          0x13
#define     P2P_SRC_CAN1RX          0x16
#define     P2P_SRC_CAN2RX          0x17
#define     P2P_SRC_ADC2            0x18

#define     P2P_DEST_UR1TX          0x01
#define     P2P_DEST_UR2TX          0x02
#define     P2P_DEST_UR3TX          0x03
#define     P2P_DEST_UR4TX          0x04
#define     P2P_DEST_SPI1TX         0x05
#define     P2P_DEST_I2C1TX         0x06
#define     P2P_DEST_LCMTX          0x07
#define     P2P_DEST_QSPITX         0x08
#define     P2P_DEST_I2S1TX         0x0A
#define     P2P_DEST_UR5TX          0x0B
#define     P2P_DEST_UR6TX          0x0C
#define     P2P_DEST_UR7TX          0x0D
#define     P2P_DEST_UR8TX          0x0E
#define     P2P_DEST_SPI2TX         0x0F
#define     P2P_DEST_SPI3TX         0x10
#define     P2P_DEST_SPI4TX         0x11
#define     P2P_DEST_I2C2TX         0x12
#define     P2P_DEST_I2S2TX         0x13
#define     P2P_DEST_DAC1TX         0x14
#define     P2P_DEST_DAC2TX         0x15
#define     P2P_DEST_CAN1TX         0x16
#define     P2P_DEST_CAN2TX         0x17

#define     DMA_ARB_CFG             (*(unsigned char volatile __FAR *)0x7efaf8)
#define     DMA_ARB_STA             (*(unsigned char volatile __FAR *)0x7efaf9)

/////////////////////////////////////////////////
//7E:F900H-7E:F9FFH
/////////////////////////////////////////////////

#define     QSPI_CR1                (*(unsigned char volatile __FAR *)0x7ef900)
#define     QSPI_CR2                (*(unsigned char volatile __FAR *)0x7ef901)
#define     QSPI_CR3                (*(unsigned char volatile __FAR *)0x7ef902)
#define     QSPI_CR4                (*(unsigned char volatile __FAR *)0x7ef903)
#define     QSPI_DCR1               (*(unsigned char volatile __FAR *)0x7ef904)
#define     QSPI_DCR2               (*(unsigned char volatile __FAR *)0x7ef905)
#define     QSPI_SR1                (*(unsigned char volatile __FAR *)0x7ef906)
#define     QSPI_SR2                (*(unsigned char volatile __FAR *)0x7ef907)
#define     QSPI_FCR                (*(unsigned char volatile __FAR *)0x7ef908)
#define     QSPI_DLR1               (*(unsigned char volatile __FAR *)0x7ef910)
#define     QSPI_DLR2               (*(unsigned char volatile __FAR *)0x7ef911)
#define     QSPI_CCR1               (*(unsigned char volatile __FAR *)0x7ef914)
#define     QSPI_CCR2               (*(unsigned char volatile __FAR *)0x7ef915)
#define     QSPI_CCR3               (*(unsigned char volatile __FAR *)0x7ef916)
#define     QSPI_CCR4               (*(unsigned char volatile __FAR *)0x7ef917)
#define     QSPI_AR1                (*(unsigned char volatile __FAR *)0x7ef918)
#define     QSPI_AR2                (*(unsigned char volatile __FAR *)0x7ef919)
#define     QSPI_AR3                (*(unsigned char volatile __FAR *)0x7ef91a)
#define     QSPI_AR4                (*(unsigned char volatile __FAR *)0x7ef91b)
#define     QSPI_ABR                (*(unsigned char volatile __FAR *)0x7ef91c)
#define     QSPI_ABR1               (*(unsigned char volatile __FAR *)0x7ef91c)
#define     QSPI_ABR2               (*(unsigned char volatile __FAR *)0x7ef91d)
#define     QSPI_ABR3               (*(unsigned char volatile __FAR *)0x7ef91e)
#define     QSPI_ABR4               (*(unsigned char volatile __FAR *)0x7ef91f)
#define     QSPI_DR                 (*(unsigned char volatile __FAR *)0x7ef920)
#define     QSPI_PSMKR1             (*(unsigned char volatile __FAR *)0x7ef924)
#define     QSPI_PSMAR1             (*(unsigned char volatile __FAR *)0x7ef928)
#define     QSPI_PIR1               (*(unsigned char volatile __FAR *)0x7ef92c)
#define     QSPI_PIR2               (*(unsigned char volatile __FAR *)0x7ef92d)

#define     PWMA_ENO2               (*(unsigned char volatile __FAR *)0x7ef930)
#define     PWMA_IOAUX2             (*(unsigned char volatile __FAR *)0x7ef931)
#define     PWMA_CR3                (*(unsigned char volatile __FAR *)0x7ef932)
#define     PWMA_SR3                (*(unsigned char volatile __FAR *)0x7ef933)
#define     PWMA_CCER3              (*(unsigned char volatile __FAR *)0x7ef934)
#define     PWMA_CCMR1X             (*(unsigned char volatile __FAR *)0x7ef938)
#define     PWMA_CCMR2X             (*(unsigned char volatile __FAR *)0x7ef939)
#define     PWMA_CCMR3X             (*(unsigned char volatile __FAR *)0x7ef93a)
#define     PWMA_CCMR4X             (*(unsigned char volatile __FAR *)0x7ef93b)
#define     PWMA_CCMR5              (*(unsigned char volatile __FAR *)0x7ef93c)
#define     PWMA_CCMR5X             (*(unsigned char volatile __FAR *)0x7ef93d)
#define     PWMA_CCMR6              (*(unsigned char volatile __FAR *)0x7ef93e)
#define     PWMA_CCMR6X             (*(unsigned char volatile __FAR *)0x7ef93f)
#define     PWMA_CCR5H              (*(unsigned char volatile __FAR *)0x7ef940)
#define     PWMA_CCR5L              (*(unsigned char volatile __FAR *)0x7ef941)
#define     PWMA_CCR5X              (*(unsigned char volatile __FAR *)0x7ef942)
#define     PWMA_CCR6H              (*(unsigned char volatile __FAR *)0x7ef943)
#define     PWMA_CCR6L              (*(unsigned char volatile __FAR *)0x7ef944)
#define     PWMA_DER                (*(unsigned char volatile __FAR *)0x7ef948)
#define     PWMA_DBA                (*(unsigned char volatile __FAR *)0x7ef949)
#define     PWMA_DBL                (*(unsigned char volatile __FAR *)0x7ef94a)
#define     PWMA_DMACR              (*(unsigned char volatile __FAR *)0x7ef94b)

#define     PWMC_ENO2               (*(unsigned char volatile __FAR *)0x7ef950)
#define     PWMC_IOAUX2             (*(unsigned char volatile __FAR *)0x7ef951)
#define     PWMC_CR3                (*(unsigned char volatile __FAR *)0x7ef952)
#define     PWMC_SR3                (*(unsigned char volatile __FAR *)0x7ef953)
#define     PWMC_CCER3              (*(unsigned char volatile __FAR *)0x7ef954)
#define     PWMC_CCMR1X             (*(unsigned char volatile __FAR *)0x7ef958)
#define     PWMC_CCMR2X             (*(unsigned char volatile __FAR *)0x7ef959)
#define     PWMC_CCMR3X             (*(unsigned char volatile __FAR *)0x7ef95a)
#define     PWMC_CCMR4X             (*(unsigned char volatile __FAR *)0x7ef95b)
#define     PWMC_CCMR5              (*(unsigned char volatile __FAR *)0x7ef95c)
#define     PWMC_CCMR5X             (*(unsigned char volatile __FAR *)0x7ef95d)
#define     PWMC_CCMR6              (*(unsigned char volatile __FAR *)0x7ef95e)
#define     PWMC_CCMR6X             (*(unsigned char volatile __FAR *)0x7ef95f)
#define     PWMC_CCR5H              (*(unsigned char volatile __FAR *)0x7ef960)
#define     PWMC_CCR5L              (*(unsigned char volatile __FAR *)0x7ef961)
#define     PWMC_CCR5X              (*(unsigned char volatile __FAR *)0x7ef962)
#define     PWMC_CCR6H              (*(unsigned char volatile __FAR *)0x7ef963)
#define     PWMC_CCR6L              (*(unsigned char volatile __FAR *)0x7ef964)
#define     PWMC_DER                (*(unsigned char volatile __FAR *)0x7ef968)
#define     PWMC_DBA                (*(unsigned char volatile __FAR *)0x7ef969)
#define     PWMC_DBL                (*(unsigned char volatile __FAR *)0x7ef96a)
#define     PWMC_DMACR              (*(unsigned char volatile __FAR *)0x7ef96b)

#define     HSPWMC_CFG              (*(unsigned char volatile __FAR *)0x7ef970)
#define     HSPWMC_ADR              (*(unsigned char volatile __FAR *)0x7ef971)
#define     HSPWMC_DAT              (*(unsigned char volatile __FAR *)0x7ef972)
#define     HSPWMC_ADRH             (*(unsigned char volatile __FAR *)0x7ef973)
#define     HSPWMD_CFG              (*(unsigned char volatile __FAR *)0x7ef974)
#define     HSPWMD_ADR              (*(unsigned char volatile __FAR *)0x7ef975)
#define     HSPWMD_DAT              (*(unsigned char volatile __FAR *)0x7ef976)
#define     HSPWMD_ADRH             (*(unsigned char volatile __FAR *)0x7ef977)

#define     DMA_PWMAT_CFG           (*(unsigned char volatile __FAR *)0x7ef980)
#define     DMA_PWMAT_CR            (*(unsigned char volatile __FAR *)0x7ef981)
#define     DMA_PWMAT_STA           (*(unsigned char volatile __FAR *)0x7ef982)
#define     DMA_PWMAT_AMTH          (*(unsigned char volatile __FAR *)0x7ef984)
#define     DMA_PWMAT_AMT           (*(unsigned char volatile __FAR *)0x7ef985)
#define     DMA_PWMAT_DONEH         (*(unsigned char volatile __FAR *)0x7ef986)
#define     DMA_PWMAT_DONE          (*(unsigned char volatile __FAR *)0x7ef987)
#define     DMA_PWMAT_TXAH          (*(unsigned char volatile __FAR *)0x7ef988)
#define     DMA_PWMAT_TXAL          (*(unsigned char volatile __FAR *)0x7ef989)
#define     DMA_PWMA_ITVH           (*(unsigned char volatile __FAR *)0x7ef98e)
#define     DMA_PWMA_ITVL           (*(unsigned char volatile __FAR *)0x7ef98f)

#define     DMA_PWMAR_CFG           (*(unsigned char volatile __FAR *)0x7ef990)
#define     DMA_PWMAR_CR            (*(unsigned char volatile __FAR *)0x7ef991)
#define     DMA_PWMAR_STA           (*(unsigned char volatile __FAR *)0x7ef992)
#define     DMA_PWMAR_AMTH          (*(unsigned char volatile __FAR *)0x7ef994)
#define     DMA_PWMAR_AMT           (*(unsigned char volatile __FAR *)0x7ef995)
#define     DMA_PWMAR_DONEH         (*(unsigned char volatile __FAR *)0x7ef996)
#define     DMA_PWMAR_DONE          (*(unsigned char volatile __FAR *)0x7ef997)
#define     DMA_PWMAR_RXAH          (*(unsigned char volatile __FAR *)0x7ef998)
#define     DMA_PWMAR_RXAL          (*(unsigned char volatile __FAR *)0x7ef999)

#define     DMA_PWMCT_CFG           (*(unsigned char volatile __FAR *)0x7ef9a0)
#define     DMA_PWMCT_CR            (*(unsigned char volatile __FAR *)0x7ef9a1)
#define     DMA_PWMCT_STA           (*(unsigned char volatile __FAR *)0x7ef9a2)
#define     DMA_PWMCT_AMTH          (*(unsigned char volatile __FAR *)0x7ef9a4)
#define     DMA_PWMCT_AMT           (*(unsigned char volatile __FAR *)0x7ef9a5)
#define     DMA_PWMCT_DONEH         (*(unsigned char volatile __FAR *)0x7ef9a6)
#define     DMA_PWMCT_DONE          (*(unsigned char volatile __FAR *)0x7ef9a7)
#define     DMA_PWMCT_TXAH          (*(unsigned char volatile __FAR *)0x7ef9a8)
#define     DMA_PWMCT_TXAL          (*(unsigned char volatile __FAR *)0x7ef9a9)
#define     DMA_PWMC_ITVH           (*(unsigned char volatile __FAR *)0x7ef9ae)
#define     DMA_PWMC_ITVL           (*(unsigned char volatile __FAR *)0x7ef9af)

#define     DMA_PWMCR_CFG           (*(unsigned char volatile __FAR *)0x7ef9b0)
#define     DMA_PWMCR_CR            (*(unsigned char volatile __FAR *)0x7ef9b1)
#define     DMA_PWMCR_STA           (*(unsigned char volatile __FAR *)0x7ef9b2)
#define     DMA_PWMCR_AMTH          (*(unsigned char volatile __FAR *)0x7ef9b4)
#define     DMA_PWMCR_AMT           (*(unsigned char volatile __FAR *)0x7ef9b5)
#define     DMA_PWMCR_DONEH         (*(unsigned char volatile __FAR *)0x7ef9b6)
#define     DMA_PWMCR_DONE          (*(unsigned char volatile __FAR *)0x7ef9b7)
#define     DMA_PWMCR_RXAH          (*(unsigned char volatile __FAR *)0x7ef9b8)
#define     DMA_PWMCR_RXAL          (*(unsigned char volatile __FAR *)0x7ef9b9)

#define     P8PU                    (*(unsigned char volatile __FAR *)0x7ef9c0)
#define     P9PU                    (*(unsigned char volatile __FAR *)0x7ef9c1)
#define     PAPU                    (*(unsigned char volatile __FAR *)0x7ef9c2)
#define     PBPU                    (*(unsigned char volatile __FAR *)0x7ef9c3)
#define     PCPU                    (*(unsigned char volatile __FAR *)0x7ef9c4)
#define     PDPU                    (*(unsigned char volatile __FAR *)0x7ef9c5)
#define     PEPU                    (*(unsigned char volatile __FAR *)0x7ef9c6)
#define     PFPU                    (*(unsigned char volatile __FAR *)0x7ef9c7)

#define     P8NCS                   (*(unsigned char volatile __FAR *)0x7ef9c8)
#define     P9NCS                   (*(unsigned char volatile __FAR *)0x7ef9c9)
#define     PANCS                   (*(unsigned char volatile __FAR *)0x7ef9ca)
#define     PBNCS                   (*(unsigned char volatile __FAR *)0x7ef9cb)
#define     PCNCS                   (*(unsigned char volatile __FAR *)0x7ef9cc)
#define     PDNCS                   (*(unsigned char volatile __FAR *)0x7ef9cd)
#define     PENCS                   (*(unsigned char volatile __FAR *)0x7ef9ce)
#define     PFNCS                   (*(unsigned char volatile __FAR *)0x7ef9cf)

#define     P8SR                    (*(unsigned char volatile __FAR *)0x7ef9d0)
#define     P9SR                    (*(unsigned char volatile __FAR *)0x7ef9d1)
#define     PASR                    (*(unsigned char volatile __FAR *)0x7ef9d2)
#define     PBSR                    (*(unsigned char volatile __FAR *)0x7ef9d3)
#define     PCSR                    (*(unsigned char volatile __FAR *)0x7ef9d4)
#define     PDSR                    (*(unsigned char volatile __FAR *)0x7ef9d5)
#define     PESR                    (*(unsigned char volatile __FAR *)0x7ef9d6)
#define     PFSR                    (*(unsigned char volatile __FAR *)0x7ef9d7)

#define     P8DR                    (*(unsigned char volatile __FAR *)0x7ef9d8)
#define     P9DR                    (*(unsigned char volatile __FAR *)0x7ef9d9)
#define     PADR                    (*(unsigned char volatile __FAR *)0x7ef9da)
#define     PBDR                    (*(unsigned char volatile __FAR *)0x7ef9db)
#define     PCDR                    (*(unsigned char volatile __FAR *)0x7ef9dc)
#define     PDDR                    (*(unsigned char volatile __FAR *)0x7ef9dd)
#define     PEDR                    (*(unsigned char volatile __FAR *)0x7ef9de)
#define     PFDR                    (*(unsigned char volatile __FAR *)0x7ef9df)

#define     P8IE                    (*(unsigned char volatile __FAR *)0x7ef9e0)
#define     P9IE                    (*(unsigned char volatile __FAR *)0x7ef9e1)
#define     PAIE                    (*(unsigned char volatile __FAR *)0x7ef9e2)
#define     PBIE                    (*(unsigned char volatile __FAR *)0x7ef9e3)
#define     PCIE                    (*(unsigned char volatile __FAR *)0x7ef9e4)
#define     PDIE                    (*(unsigned char volatile __FAR *)0x7ef9e5)
#define     PEIE                    (*(unsigned char volatile __FAR *)0x7ef9e6)
#define     PFIE                    (*(unsigned char volatile __FAR *)0x7ef9e7)

#define     P8PD                    (*(unsigned char volatile __FAR *)0x7ef9f0)
#define     P9PD                    (*(unsigned char volatile __FAR *)0x7ef9f1)
#define     PAPD                    (*(unsigned char volatile __FAR *)0x7ef9f2)
#define     PBPD                    (*(unsigned char volatile __FAR *)0x7ef9f3)
#define     PCPD                    (*(unsigned char volatile __FAR *)0x7ef9f4)
#define     PDPD                    (*(unsigned char volatile __FAR *)0x7ef9f5)
#define     PEPD                    (*(unsigned char volatile __FAR *)0x7ef9f6)
#define     PFPD                    (*(unsigned char volatile __FAR *)0x7ef9f7)

#define     P8BP                    (*(unsigned char volatile __FAR *)0x7ef9f8)
#define     P9BP                    (*(unsigned char volatile __FAR *)0x7ef9f9)
#define     PABP                    (*(unsigned char volatile __FAR *)0x7ef9fa)
#define     PBBP                    (*(unsigned char volatile __FAR *)0x7ef9fb)
#define     PCBP                    (*(unsigned char volatile __FAR *)0x7ef9fc)
#define     PDBP                    (*(unsigned char volatile __FAR *)0x7ef9fd)
#define     PEBP                    (*(unsigned char volatile __FAR *)0x7ef9fe)
#define     PFBP                    (*(unsigned char volatile __FAR *)0x7ef9ff)

/////////////////////////////////////////////////
//7E:F800H-7E:F8FFH
/////////////////////////////////////////////////

#define     SPI2CTL                 (*(unsigned char volatile __FAR *)0x7ef800)
#define     SPI2STAT                (*(unsigned char volatile __FAR *)0x7ef801)
#define     SPI2DAT                 (*(unsigned char volatile __FAR *)0x7ef802)
#define     SPI2TOTE                (*(unsigned char volatile __FAR *)0x7ef803)
#define     SPI2TOCR                (*(unsigned char volatile __FAR *)0x7ef804)
#define     SPI2TOSR                (*(unsigned char volatile __FAR *)0x7ef805)
#define     SPI2TOTH                (*(unsigned char volatile __FAR *)0x7ef806)
#define     SPI2TOTL                (*(unsigned char volatile __FAR *)0x7ef807)
#define     SPI2_CLKDIV             (*(unsigned char volatile __FAR *)0x7ef808)
#define     HSSPI2_CFG              (*(unsigned char volatile __FAR *)0x7ef809)
#define     HSSPI2_CFG2             (*(unsigned char volatile __FAR *)0x7ef80a)
#define     HSSPI2_STA              (*(unsigned char volatile __FAR *)0x7ef80b)
#define     HSSPI2_PSCR             (*(unsigned char volatile __FAR *)0x7ef80c)
#define     SPI2INTR                (*(unsigned char volatile __FAR *)0x7ef80f)

#define     DMA_SPI2_CFG            (*(unsigned char volatile __FAR *)0x7ef810)
#define     DMA_SPI2_CR             (*(unsigned char volatile __FAR *)0x7ef811)
#define     DMA_SPI2_STA            (*(unsigned char volatile __FAR *)0x7ef812)
#define     DMA_SPI2_CFG2           (*(unsigned char volatile __FAR *)0x7ef813)
#define     DMA_SPI2_AMTH           (*(unsigned char volatile __FAR *)0x7ef814)
#define     DMA_SPI2_AMT            (*(unsigned char volatile __FAR *)0x7ef815)
#define     DMA_SPI2_DONEH          (*(unsigned char volatile __FAR *)0x7ef816)
#define     DMA_SPI2_DONE           (*(unsigned char volatile __FAR *)0x7ef817)
#define     DMA_SPI2_TXAH           (*(unsigned char volatile __FAR *)0x7ef818)
#define     DMA_SPI2_TXAL           (*(unsigned char volatile __FAR *)0x7ef819)
#define     DMA_SPI2_RXAH           (*(unsigned char volatile __FAR *)0x7ef81a)
#define     DMA_SPI2_RXAL           (*(unsigned char volatile __FAR *)0x7ef81b)
#define     DMA_SPI2_ITVH           (*(unsigned char volatile __FAR *)0x7ef81e)
#define     DMA_SPI2_ITVL           (*(unsigned char volatile __FAR *)0x7ef81f)

#define     SPI3CTL                 (*(unsigned char volatile __FAR *)0x7ef820)
#define     SPI3STAT                (*(unsigned char volatile __FAR *)0x7ef821)
#define     SPI3DAT                 (*(unsigned char volatile __FAR *)0x7ef822)
#define     SPI3TOTE                (*(unsigned char volatile __FAR *)0x7ef823)
#define     SPI3TOCR                (*(unsigned char volatile __FAR *)0x7ef824)
#define     SPI3TOSR                (*(unsigned char volatile __FAR *)0x7ef825)
#define     SPI3TOTH                (*(unsigned char volatile __FAR *)0x7ef826)
#define     SPI3TOTL                (*(unsigned char volatile __FAR *)0x7ef827)
#define     SPI3_CLKDIV             (*(unsigned char volatile __FAR *)0x7ef828)
#define     HSSPI3_CFG              (*(unsigned char volatile __FAR *)0x7ef829)
#define     HSSPI3_CFG2             (*(unsigned char volatile __FAR *)0x7ef82a)
#define     HSSPI3_STA              (*(unsigned char volatile __FAR *)0x7ef82b)
#define     HSSPI3_PSCR             (*(unsigned char volatile __FAR *)0x7ef82c)
#define     SPI3INTR                (*(unsigned char volatile __FAR *)0x7ef82f)

#define     DMA_SPI3_CFG            (*(unsigned char volatile __FAR *)0x7ef830)
#define     DMA_SPI3_CR             (*(unsigned char volatile __FAR *)0x7ef831)
#define     DMA_SPI3_STA            (*(unsigned char volatile __FAR *)0x7ef832)
#define     DMA_SPI3_CFG2           (*(unsigned char volatile __FAR *)0x7ef833)
#define     DMA_SPI3_AMTH           (*(unsigned char volatile __FAR *)0x7ef834)
#define     DMA_SPI3_AMT            (*(unsigned char volatile __FAR *)0x7ef835)
#define     DMA_SPI3_DONEH          (*(unsigned char volatile __FAR *)0x7ef836)
#define     DMA_SPI3_DONE           (*(unsigned char volatile __FAR *)0x7ef837)
#define     DMA_SPI3_TXAH           (*(unsigned char volatile __FAR *)0x7ef838)
#define     DMA_SPI3_TXAL           (*(unsigned char volatile __FAR *)0x7ef839)
#define     DMA_SPI3_RXAH           (*(unsigned char volatile __FAR *)0x7ef83a)
#define     DMA_SPI3_RXAL           (*(unsigned char volatile __FAR *)0x7ef83b)
#define     DMA_SPI3_ITVH           (*(unsigned char volatile __FAR *)0x7ef83e)
#define     DMA_SPI3_ITVL           (*(unsigned char volatile __FAR *)0x7ef83f)

#define     I2C2CFG                 (*(unsigned char volatile __FAR *)0x7ef860)
#define     I2C2MSCR                (*(unsigned char volatile __FAR *)0x7ef861)
#define     I2C2MSST                (*(unsigned char volatile __FAR *)0x7ef862)
#define     I2C2SLCR                (*(unsigned char volatile __FAR *)0x7ef863)
#define     I2C2SLST                (*(unsigned char volatile __FAR *)0x7ef864)
#define     I2C2SLADR               (*(unsigned char volatile __FAR *)0x7ef865)
#define     I2C2TXD                 (*(unsigned char volatile __FAR *)0x7ef866)
#define     I2C2RXD                 (*(unsigned char volatile __FAR *)0x7ef867)
#define     I2C2MSAUX               (*(unsigned char volatile __FAR *)0x7ef868)
#define     I2C2PSCR                (*(unsigned char volatile __FAR *)0x7ef869)
#define     I2C2TOTE                (*(unsigned char volatile __FAR *)0x7ef86b)
#define     I2C2TOCR                (*(unsigned char volatile __FAR *)0x7ef86c)
#define     I2C2TOSR                (*(unsigned char volatile __FAR *)0x7ef86d)
#define     I2C2TOTH                (*(unsigned char volatile __FAR *)0x7ef86e)
#define     I2C2TOTL                (*(unsigned char volatile __FAR *)0x7ef86f)

#define     DMA_I2C2T_CFG           (*(unsigned char volatile __FAR *)0x7ef870)
#define     DMA_I2C2T_CR            (*(unsigned char volatile __FAR *)0x7ef871)
#define     DMA_I2C2T_STA           (*(unsigned char volatile __FAR *)0x7ef872)
#define     DMA_I2C2T_AMTH          (*(unsigned char volatile __FAR *)0x7ef874)
#define     DMA_I2C2T_AMT           (*(unsigned char volatile __FAR *)0x7ef875)
#define     DMA_I2C2T_DONEH         (*(unsigned char volatile __FAR *)0x7ef876)
#define     DMA_I2C2T_DONE          (*(unsigned char volatile __FAR *)0x7ef877)
#define     DMA_I2C2T_TXAH          (*(unsigned char volatile __FAR *)0x7ef878)
#define     DMA_I2C2T_TXAL          (*(unsigned char volatile __FAR *)0x7ef879)

#define     DMA_I2C2_CR             (*(unsigned char volatile __FAR *)0x7ef87b)
#define     DMA_I2C2_ST1            (*(unsigned char volatile __FAR *)0x7ef87c)
#define     DMA_I2C2_ST2            (*(unsigned char volatile __FAR *)0x7ef87d)
#define     DMA_I2C2_ITVH           (*(unsigned char volatile __FAR *)0x7ef87e)
#define     DMA_I2C2_ITVL           (*(unsigned char volatile __FAR *)0x7ef87f)

#define     DMA_I2C2R_CFG           (*(unsigned char volatile __FAR *)0x7ef880)
#define     DMA_I2C2R_CR            (*(unsigned char volatile __FAR *)0x7ef881)
#define     DMA_I2C2R_STA           (*(unsigned char volatile __FAR *)0x7ef882)
#define     DMA_I2C2R_AMTH          (*(unsigned char volatile __FAR *)0x7ef884)
#define     DMA_I2C2R_AMT           (*(unsigned char volatile __FAR *)0x7ef885)
#define     DMA_I2C2R_DONEH         (*(unsigned char volatile __FAR *)0x7ef886)
#define     DMA_I2C2R_DONE          (*(unsigned char volatile __FAR *)0x7ef887)
#define     DMA_I2C2R_RXAH          (*(unsigned char volatile __FAR *)0x7ef888)
#define     DMA_I2C2R_RXAL          (*(unsigned char volatile __FAR *)0x7ef889)

#define     DMA_I2S2T_CFG           (*(unsigned char volatile __FAR *)0x7ef890)
#define     DMA_I2S2T_CR            (*(unsigned char volatile __FAR *)0x7ef891)
#define     DMA_I2S2T_STA           (*(unsigned char volatile __FAR *)0x7ef892)
#define     DMA_I2S2T_AMTH          (*(unsigned char volatile __FAR *)0x7ef894)
#define     DMA_I2S2T_AMT           (*(unsigned char volatile __FAR *)0x7ef895)
#define     DMA_I2S2T_DONEH         (*(unsigned char volatile __FAR *)0x7ef896)
#define     DMA_I2S2T_DONE          (*(unsigned char volatile __FAR *)0x7ef897)
#define     DMA_I2S2T_TXAH          (*(unsigned char volatile __FAR *)0x7ef898)
#define     DMA_I2S2T_TXAL          (*(unsigned char volatile __FAR *)0x7ef899)
#define     DMA_I2S2_ITVH           (*(unsigned char volatile __FAR *)0x7ef89e)
#define     DMA_I2S2_ITVL           (*(unsigned char volatile __FAR *)0x7ef89f)

#define     DMA_I2S2R_CFG           (*(unsigned char volatile __FAR *)0x7ef8a0)
#define     DMA_I2S2R_CR            (*(unsigned char volatile __FAR *)0x7ef8a1)
#define     DMA_I2S2R_STA           (*(unsigned char volatile __FAR *)0x7ef8a2)
#define     DMA_I2S2R_AMTH          (*(unsigned char volatile __FAR *)0x7ef8a4)
#define     DMA_I2S2R_AMT           (*(unsigned char volatile __FAR *)0x7ef8a5)
#define     DMA_I2S2R_DONEH         (*(unsigned char volatile __FAR *)0x7ef8a6)
#define     DMA_I2S2R_DONE          (*(unsigned char volatile __FAR *)0x7ef8a7)
#define     DMA_I2S2R_RXAH          (*(unsigned char volatile __FAR *)0x7ef8a8)
#define     DMA_I2S2R_RXAL          (*(unsigned char volatile __FAR *)0x7ef8a9)

#define     PWMC_ETRPS              (*(unsigned char volatile __FAR *)0x7ef8b0)
#define     PWMC_ENO                (*(unsigned char volatile __FAR *)0x7ef8b1)
#define     PWMC_PS                 (*(unsigned char volatile __FAR *)0x7ef8b2)
#define     PWMC_IOAUX              (*(unsigned char volatile __FAR *)0x7ef8b3)
#define     PWMD_ETRPS              (*(unsigned char volatile __FAR *)0x7ef8b4)
#define     PWMD_ENO                (*(unsigned char volatile __FAR *)0x7ef8b5)
#define     PWMD_PS                 (*(unsigned char volatile __FAR *)0x7ef8b6)
#define     PWMD_IOAUX              (*(unsigned char volatile __FAR *)0x7ef8b7)
#define     PWMC_PS2                (*(unsigned char volatile __FAR *)0x7ef8b8)
#define     PWMC_RCRH               (*(unsigned char volatile __FAR *)0x7ef8b9)
#define     PWMD_RCRH               (*(unsigned char volatile __FAR *)0x7ef8ba)

#define     PWMC_CR1                (*(unsigned char volatile __FAR *)0x7ef8c0)
#define     PWMC_CR2                (*(unsigned char volatile __FAR *)0x7ef8c1)
#define     PWMC_SMCR               (*(unsigned char volatile __FAR *)0x7ef8c2)
#define     PWMC_ETR                (*(unsigned char volatile __FAR *)0x7ef8c3)
#define     PWMC_IER                (*(unsigned char volatile __FAR *)0x7ef8c4)
#define     PWMC_SR1                (*(unsigned char volatile __FAR *)0x7ef8c5)
#define     PWMC_SR2                (*(unsigned char volatile __FAR *)0x7ef8c6)
#define     PWMC_EGR                (*(unsigned char volatile __FAR *)0x7ef8c7)
#define     PWMC_CCMR1              (*(unsigned char volatile __FAR *)0x7ef8c8)
#define     PWMC_CCMR2              (*(unsigned char volatile __FAR *)0x7ef8c9)
#define     PWMC_CCMR3              (*(unsigned char volatile __FAR *)0x7ef8ca)
#define     PWMC_CCMR4              (*(unsigned char volatile __FAR *)0x7ef8cb)
#define     PWMC_CCER1              (*(unsigned char volatile __FAR *)0x7ef8cc)
#define     PWMC_CCER2              (*(unsigned char volatile __FAR *)0x7ef8cd)
#define     PWMC_CNTRH              (*(unsigned char volatile __FAR *)0x7ef8ce)
#define     PWMC_CNTRL              (*(unsigned char volatile __FAR *)0x7ef8cf)
#define     PWMC_PSCRH              (*(unsigned char volatile __FAR *)0x7ef8d0)
#define     PWMC_PSCRL              (*(unsigned char volatile __FAR *)0x7ef8d1)
#define     PWMC_ARRH               (*(unsigned char volatile __FAR *)0x7ef8d2)
#define     PWMC_ARRL               (*(unsigned char volatile __FAR *)0x7ef8d3)
#define     PWMC_RCR                (*(unsigned char volatile __FAR *)0x7ef8d4)
#define     PWMC_CCR1H              (*(unsigned char volatile __FAR *)0x7ef8d5)
#define     PWMC_CCR1L              (*(unsigned char volatile __FAR *)0x7ef8d6)
#define     PWMC_CCR2H              (*(unsigned char volatile __FAR *)0x7ef8d7)
#define     PWMC_CCR2L              (*(unsigned char volatile __FAR *)0x7ef8d8)
#define     PWMC_CCR3H              (*(unsigned char volatile __FAR *)0x7ef8d9)
#define     PWMC_CCR3L              (*(unsigned char volatile __FAR *)0x7ef8da)
#define     PWMC_CCR4H              (*(unsigned char volatile __FAR *)0x7ef8db)
#define     PWMC_CCR4L              (*(unsigned char volatile __FAR *)0x7ef8dc)
#define     PWMC_BKR                (*(unsigned char volatile __FAR *)0x7ef8dd)
#define     PWMC_DTR                (*(unsigned char volatile __FAR *)0x7ef8de)
#define     PWMC_OISR               (*(unsigned char volatile __FAR *)0x7ef8df)

#define     PWMD_CR1                (*(unsigned char volatile __FAR *)0x7ef8e0)
#define     PWMD_CR2                (*(unsigned char volatile __FAR *)0x7ef8e1)
#define     PWMD_SMCR               (*(unsigned char volatile __FAR *)0x7ef8e2)
#define     PWMD_ETR                (*(unsigned char volatile __FAR *)0x7ef8e3)
#define     PWMD_IER                (*(unsigned char volatile __FAR *)0x7ef8e4)
#define     PWMD_SR1                (*(unsigned char volatile __FAR *)0x7ef8e5)
#define     PWMD_SR2                (*(unsigned char volatile __FAR *)0x7ef8e6)
#define     PWMD_EGR                (*(unsigned char volatile __FAR *)0x7ef8e7)
#define     PWMD_CCMR1              (*(unsigned char volatile __FAR *)0x7ef8e8)
#define     PWMD_CCMR2              (*(unsigned char volatile __FAR *)0x7ef8e9)
#define     PWMD_CCMR3              (*(unsigned char volatile __FAR *)0x7ef8ea)
#define     PWMD_CCMR4              (*(unsigned char volatile __FAR *)0x7ef8eb)
#define     PWMD_CCER1              (*(unsigned char volatile __FAR *)0x7ef8ec)
#define     PWMD_CCER2              (*(unsigned char volatile __FAR *)0x7ef8ed)
#define     PWMD_CNTRH              (*(unsigned char volatile __FAR *)0x7ef8ee)
#define     PWMD_CNTRL              (*(unsigned char volatile __FAR *)0x7ef8ef)
#define     PWMD_PSCRH              (*(unsigned char volatile __FAR *)0x7ef8f0)
#define     PWMD_PSCRL              (*(unsigned char volatile __FAR *)0x7ef8f1)
#define     PWMD_ARRH               (*(unsigned char volatile __FAR *)0x7ef8f2)
#define     PWMD_ARRL               (*(unsigned char volatile __FAR *)0x7ef8f3)
#define     PWMD_RCR                (*(unsigned char volatile __FAR *)0x7ef8f4)
#define     PWMD_CCR5H              (*(unsigned char volatile __FAR *)0x7ef8f5)
#define     PWMD_CCR5L              (*(unsigned char volatile __FAR *)0x7ef8f6)
#define     PWMD_CCR6H              (*(unsigned char volatile __FAR *)0x7ef8f7)
#define     PWMD_CCR6L              (*(unsigned char volatile __FAR *)0x7ef8f8)
#define     PWMD_CCR7H              (*(unsigned char volatile __FAR *)0x7ef8f9)
#define     PWMD_CCR7L              (*(unsigned char volatile __FAR *)0x7ef8fa)
#define     PWMD_CCR8H              (*(unsigned char volatile __FAR *)0x7ef8fb)
#define     PWMD_CCR8L              (*(unsigned char volatile __FAR *)0x7ef8fc)
#define     PWMD_BKR                (*(unsigned char volatile __FAR *)0x7ef8fd)
#define     PWMD_DTR                (*(unsigned char volatile __FAR *)0x7ef8fe)
#define     PWMD_OISR               (*(unsigned char volatile __FAR *)0x7ef8ff)


/////////////////////////////////////////////////
//7E:F700H-7E:F7FFH
/////////////////////////////////////////////////

#define     P8OUT                   (*(unsigned char volatile __FAR *)0x7ef700)
#define     P9OUT                   (*(unsigned char volatile __FAR *)0x7ef701)
#define     PAOUT                   (*(unsigned char volatile __FAR *)0x7ef702)
#define     PBOUT                   (*(unsigned char volatile __FAR *)0x7ef703)
#define     PCOUT                   (*(unsigned char volatile __FAR *)0x7ef704)
#define     PDOUT                   (*(unsigned char volatile __FAR *)0x7ef705)
#define     PEOUT                   (*(unsigned char volatile __FAR *)0x7ef706)
#define     PFOUT                   (*(unsigned char volatile __FAR *)0x7ef707)

#define     P8IN                    (*(unsigned char volatile __FAR *)0x7ef708)
#define     P9IN                    (*(unsigned char volatile __FAR *)0x7ef709)
#define     PAIN                    (*(unsigned char volatile __FAR *)0x7ef70a)
#define     PBIN                    (*(unsigned char volatile __FAR *)0x7ef70b)
#define     PCIN                    (*(unsigned char volatile __FAR *)0x7ef70c)
#define     PDIN                    (*(unsigned char volatile __FAR *)0x7ef70d)
#define     PEIN                    (*(unsigned char volatile __FAR *)0x7ef70e)
#define     PFIN                    (*(unsigned char volatile __FAR *)0x7ef70f)

#define     P8M0                    (*(unsigned char volatile __FAR *)0x7ef710)
#define     P9M0                    (*(unsigned char volatile __FAR *)0x7ef711)
#define     PAM0                    (*(unsigned char volatile __FAR *)0x7ef712)
#define     PBM0                    (*(unsigned char volatile __FAR *)0x7ef713)
#define     PCM0                    (*(unsigned char volatile __FAR *)0x7ef714)
#define     PDM0                    (*(unsigned char volatile __FAR *)0x7ef715)
#define     PEM0                    (*(unsigned char volatile __FAR *)0x7ef716)
#define     PFM0                    (*(unsigned char volatile __FAR *)0x7ef717)

#define     P8M1                    (*(unsigned char volatile __FAR *)0x7ef718)
#define     P9M1                    (*(unsigned char volatile __FAR *)0x7ef719)
#define     PAM1                    (*(unsigned char volatile __FAR *)0x7ef71a)
#define     PBM1                    (*(unsigned char volatile __FAR *)0x7ef71b)
#define     PCM1                    (*(unsigned char volatile __FAR *)0x7ef71c)
#define     PDM1                    (*(unsigned char volatile __FAR *)0x7ef71d)
#define     PEM1                    (*(unsigned char volatile __FAR *)0x7ef71e)
#define     PFM1                    (*(unsigned char volatile __FAR *)0x7ef71f)

#define     P8SETB                  (*(unsigned char volatile __FAR *)0x7ef720)
#define     P9SETB                  (*(unsigned char volatile __FAR *)0x7ef721)
#define     PASETB                  (*(unsigned char volatile __FAR *)0x7ef722)
#define     PBSETB                  (*(unsigned char volatile __FAR *)0x7ef723)
#define     PCSETB                  (*(unsigned char volatile __FAR *)0x7ef724)
#define     PDSETB                  (*(unsigned char volatile __FAR *)0x7ef725)
#define     PESETB                  (*(unsigned char volatile __FAR *)0x7ef726)
#define     PFSETB                  (*(unsigned char volatile __FAR *)0x7ef727)

#define     P8CLRB                  (*(unsigned char volatile __FAR *)0x7ef728)
#define     P9CLRB                  (*(unsigned char volatile __FAR *)0x7ef729)
#define     PACLRB                  (*(unsigned char volatile __FAR *)0x7ef72a)
#define     PBCLRB                  (*(unsigned char volatile __FAR *)0x7ef72b)
#define     PCCLRB                  (*(unsigned char volatile __FAR *)0x7ef72c)
#define     PDCLRB                  (*(unsigned char volatile __FAR *)0x7ef72d)
#define     PECLRB                  (*(unsigned char volatile __FAR *)0x7ef72e)
#define     PFCLRB                  (*(unsigned char volatile __FAR *)0x7ef72f)

#define     S5CON                   (*(unsigned char volatile __FAR *)0x7ef740)
#define     S5BUF                   (*(unsigned char volatile __FAR *)0x7ef741)
#define     S5INTR                  (*(unsigned char volatile __FAR *)0x7ef742)
#define     UR5TOTE                 (*(unsigned char volatile __FAR *)0x7ef743)
#define     UR5TOCR                 (*(unsigned char volatile __FAR *)0x7ef744)
#define     UR5TOSR                 (*(unsigned char volatile __FAR *)0x7ef745)
#define     UR5TOTH                 (*(unsigned char volatile __FAR *)0x7ef746)
#define     UR5TOTL                 (*(unsigned char volatile __FAR *)0x7ef747)

#define     USART5CR1               (*(unsigned char volatile __FAR *)0x7ef748)
#define     USART5CR2               (*(unsigned char volatile __FAR *)0x7ef749)
#define     USART5CR3               (*(unsigned char volatile __FAR *)0x7ef74a)
#define     USART5CR4               (*(unsigned char volatile __FAR *)0x7ef74b)
#define     USART5CR5               (*(unsigned char volatile __FAR *)0x7ef74c)
#define     USART5GTR               (*(unsigned char volatile __FAR *)0x7ef74d)
#define     USART5BR1               (*(unsigned char volatile __FAR *)0x7ef74e)
#define     USART5BR2               (*(unsigned char volatile __FAR *)0x7ef74f)

#define     DMA_UR5T_CFG            (*(unsigned char volatile __FAR *)0x7ef750)
#define     DMA_UR5T_CR             (*(unsigned char volatile __FAR *)0x7ef751)
#define     DMA_UR5T_STA            (*(unsigned char volatile __FAR *)0x7ef752)
#define     DMA_UR5T_AMTH           (*(unsigned char volatile __FAR *)0x7ef754)
#define     DMA_UR5T_AMT            (*(unsigned char volatile __FAR *)0x7ef755)
#define     DMA_UR5T_DONEH          (*(unsigned char volatile __FAR *)0x7ef756)
#define     DMA_UR5T_DONE           (*(unsigned char volatile __FAR *)0x7ef757)
#define     DMA_UR5T_TXAH           (*(unsigned char volatile __FAR *)0x7ef758)
#define     DMA_UR5T_TXAL           (*(unsigned char volatile __FAR *)0x7ef759)
#define     DMA_UR5_ITVH            (*(unsigned char volatile __FAR *)0x7ef75e)
#define     DMA_UR5_ITVL            (*(unsigned char volatile __FAR *)0x7ef75f)

#define     DMA_UR5R_CFG            (*(unsigned char volatile __FAR *)0x7ef760)
#define     DMA_UR5R_CR             (*(unsigned char volatile __FAR *)0x7ef761)
#define     DMA_UR5R_STA            (*(unsigned char volatile __FAR *)0x7ef762)
#define     DMA_UR5R_AMTH           (*(unsigned char volatile __FAR *)0x7ef764)
#define     DMA_UR5R_AMT            (*(unsigned char volatile __FAR *)0x7ef765)
#define     DMA_UR5R_DONEH          (*(unsigned char volatile __FAR *)0x7ef766)
#define     DMA_UR5R_DONE           (*(unsigned char volatile __FAR *)0x7ef767)
#define     DMA_UR5R_RXAH           (*(unsigned char volatile __FAR *)0x7ef768)
#define     DMA_UR5R_RXAL           (*(unsigned char volatile __FAR *)0x7ef769)

#define     S5CFG                   (*(unsigned char volatile __FAR *)0x7ef76d)
#define     S5ADDR                  (*(unsigned char volatile __FAR *)0x7ef76e)
#define     S5ADEN                  (*(unsigned char volatile __FAR *)0x7ef76f)

#define     S6CON                   (*(unsigned char volatile __FAR *)0x7ef770)
#define     S6BUF                   (*(unsigned char volatile __FAR *)0x7ef771)
#define     S6INTR                  (*(unsigned char volatile __FAR *)0x7ef772)
#define     UR6TOTE                 (*(unsigned char volatile __FAR *)0x7ef773)
#define     UR6TOCR                 (*(unsigned char volatile __FAR *)0x7ef774)
#define     UR6TOSR                 (*(unsigned char volatile __FAR *)0x7ef775)
#define     UR6TOTH                 (*(unsigned char volatile __FAR *)0x7ef776)
#define     UR6TOTL                 (*(unsigned char volatile __FAR *)0x7ef777)

#define     USART6CR1               (*(unsigned char volatile __FAR *)0x7ef778)
#define     USART6CR2               (*(unsigned char volatile __FAR *)0x7ef779)
#define     USART6CR3               (*(unsigned char volatile __FAR *)0x7ef77a)
#define     USART6CR4               (*(unsigned char volatile __FAR *)0x7ef77b)
#define     USART6CR5               (*(unsigned char volatile __FAR *)0x7ef77c)
#define     USART6GTR               (*(unsigned char volatile __FAR *)0x7ef77d)
#define     USART6BR1               (*(unsigned char volatile __FAR *)0x7ef77e)
#define     USART6BR2               (*(unsigned char volatile __FAR *)0x7ef77f)

#define     DMA_UR6T_CFG            (*(unsigned char volatile __FAR *)0x7ef780)
#define     DMA_UR6T_CR             (*(unsigned char volatile __FAR *)0x7ef781)
#define     DMA_UR6T_STA            (*(unsigned char volatile __FAR *)0x7ef782)
#define     DMA_UR6T_AMTH           (*(unsigned char volatile __FAR *)0x7ef784)
#define     DMA_UR6T_AMT            (*(unsigned char volatile __FAR *)0x7ef785)
#define     DMA_UR6T_DONEH          (*(unsigned char volatile __FAR *)0x7ef786)
#define     DMA_UR6T_DONE           (*(unsigned char volatile __FAR *)0x7ef787)
#define     DMA_UR6T_TXAH           (*(unsigned char volatile __FAR *)0x7ef788)
#define     DMA_UR6T_TXAL           (*(unsigned char volatile __FAR *)0x7ef789)
#define     DMA_UR6_ITVH            (*(unsigned char volatile __FAR *)0x7ef78e)
#define     DMA_UR6_ITVL            (*(unsigned char volatile __FAR *)0x7ef78f)

#define     DMA_UR6R_CFG            (*(unsigned char volatile __FAR *)0x7ef790)
#define     DMA_UR6R_CR             (*(unsigned char volatile __FAR *)0x7ef791)
#define     DMA_UR6R_STA            (*(unsigned char volatile __FAR *)0x7ef792)
#define     DMA_UR6R_AMTH           (*(unsigned char volatile __FAR *)0x7ef794)
#define     DMA_UR6R_AMT            (*(unsigned char volatile __FAR *)0x7ef795)
#define     DMA_UR6R_DONEH          (*(unsigned char volatile __FAR *)0x7ef796)
#define     DMA_UR6R_DONE           (*(unsigned char volatile __FAR *)0x7ef797)
#define     DMA_UR6R_RXAH           (*(unsigned char volatile __FAR *)0x7ef798)
#define     DMA_UR6R_RXAL           (*(unsigned char volatile __FAR *)0x7ef799)

#define     S6CFG                   (*(unsigned char volatile __FAR *)0x7ef79d)
#define     S6ADDR                  (*(unsigned char volatile __FAR *)0x7ef79e)
#define     S6ADEN                  (*(unsigned char volatile __FAR *)0x7ef79f)

#define     S7CON                   (*(unsigned char volatile __FAR *)0x7ef7a0)
#define     S7BUF                   (*(unsigned char volatile __FAR *)0x7ef7a1)
#define     S7INTR                  (*(unsigned char volatile __FAR *)0x7ef7a2)
#define     UR7TOTE                 (*(unsigned char volatile __FAR *)0x7ef7a3)
#define     UR7TOCR                 (*(unsigned char volatile __FAR *)0x7ef7a4)
#define     UR7TOSR                 (*(unsigned char volatile __FAR *)0x7ef7a5)
#define     UR7TOTH                 (*(unsigned char volatile __FAR *)0x7ef7a6)
#define     UR7TOTL                 (*(unsigned char volatile __FAR *)0x7ef7a7)

#define     USART7CR1               (*(unsigned char volatile __FAR *)0x7ef7a8)
#define     USART7CR2               (*(unsigned char volatile __FAR *)0x7ef7a9)
#define     USART7CR3               (*(unsigned char volatile __FAR *)0x7ef7aa)
#define     USART7CR4               (*(unsigned char volatile __FAR *)0x7ef7ab)
#define     USART7CR5               (*(unsigned char volatile __FAR *)0x7ef7ac)
#define     USART7GTR               (*(unsigned char volatile __FAR *)0x7ef7ad)
#define     USART7BR1               (*(unsigned char volatile __FAR *)0x7ef7ae)
#define     USART7BR2               (*(unsigned char volatile __FAR *)0x7ef7af)

#define     DMA_UR7T_CFG            (*(unsigned char volatile __FAR *)0x7ef7b0)
#define     DMA_UR7T_CR             (*(unsigned char volatile __FAR *)0x7ef7b1)
#define     DMA_UR7T_STA            (*(unsigned char volatile __FAR *)0x7ef7b2)
#define     DMA_UR7T_AMTH           (*(unsigned char volatile __FAR *)0x7ef7b4)
#define     DMA_UR7T_AMT            (*(unsigned char volatile __FAR *)0x7ef7b5)
#define     DMA_UR7T_DONEH          (*(unsigned char volatile __FAR *)0x7ef7b6)
#define     DMA_UR7T_DONE           (*(unsigned char volatile __FAR *)0x7ef7b7)
#define     DMA_UR7T_TXAH           (*(unsigned char volatile __FAR *)0x7ef7b8)
#define     DMA_UR7T_TXAL           (*(unsigned char volatile __FAR *)0x7ef7b9)
#define     DMA_UR7_ITVH            (*(unsigned char volatile __FAR *)0x7ef7be)
#define     DMA_UR7_ITVL            (*(unsigned char volatile __FAR *)0x7ef7bf)

#define     DMA_UR7R_CFG            (*(unsigned char volatile __FAR *)0x7ef7c0)
#define     DMA_UR7R_CR             (*(unsigned char volatile __FAR *)0x7ef7c1)
#define     DMA_UR7R_STA            (*(unsigned char volatile __FAR *)0x7ef7c2)
#define     DMA_UR7R_AMTH           (*(unsigned char volatile __FAR *)0x7ef7c4)
#define     DMA_UR7R_AMT            (*(unsigned char volatile __FAR *)0x7ef7c5)
#define     DMA_UR7R_DONEH          (*(unsigned char volatile __FAR *)0x7ef7c6)
#define     DMA_UR7R_DONE           (*(unsigned char volatile __FAR *)0x7ef7c7)
#define     DMA_UR7R_RXAH           (*(unsigned char volatile __FAR *)0x7ef7c8)
#define     DMA_UR7R_RXAL           (*(unsigned char volatile __FAR *)0x7ef7c9)

#define     S7CFG                   (*(unsigned char volatile __FAR *)0x7ef7cd)
#define     S7ADDR                  (*(unsigned char volatile __FAR *)0x7ef7ce)
#define     S7ADEN                  (*(unsigned char volatile __FAR *)0x7ef7cf)

#define     S8CON                   (*(unsigned char volatile __FAR *)0x7ef7d0)
#define     S8BUF                   (*(unsigned char volatile __FAR *)0x7ef7d1)
#define     S8INTR                  (*(unsigned char volatile __FAR *)0x7ef7d2)
#define     UR8TOTE                 (*(unsigned char volatile __FAR *)0x7ef7d3)
#define     UR8TOCR                 (*(unsigned char volatile __FAR *)0x7ef7d4)
#define     UR8TOSR                 (*(unsigned char volatile __FAR *)0x7ef7d5)
#define     UR8TOTH                 (*(unsigned char volatile __FAR *)0x7ef7d6)
#define     UR8TOTL                 (*(unsigned char volatile __FAR *)0x7ef7d7)

#define     USART8CR1               (*(unsigned char volatile __FAR *)0x7ef7d8)
#define     USART8CR2               (*(unsigned char volatile __FAR *)0x7ef7d9)
#define     USART8CR3               (*(unsigned char volatile __FAR *)0x7ef7da)
#define     USART8CR4               (*(unsigned char volatile __FAR *)0x7ef7db)
#define     USART8CR5               (*(unsigned char volatile __FAR *)0x7ef7dc)
#define     USART8GTR               (*(unsigned char volatile __FAR *)0x7ef7dd)
#define     USART8BR1               (*(unsigned char volatile __FAR *)0x7ef7de)
#define     USART8BR2               (*(unsigned char volatile __FAR *)0x7ef7df)

#define     DMA_UR8T_CFG            (*(unsigned char volatile __FAR *)0x7ef7e0)
#define     DMA_UR8T_CR             (*(unsigned char volatile __FAR *)0x7ef7e1)
#define     DMA_UR8T_STA            (*(unsigned char volatile __FAR *)0x7ef7e2)
#define     DMA_UR8T_AMTH           (*(unsigned char volatile __FAR *)0x7ef7e4)
#define     DMA_UR8T_AMT            (*(unsigned char volatile __FAR *)0x7ef7e5)
#define     DMA_UR8T_DONEH          (*(unsigned char volatile __FAR *)0x7ef7e6)
#define     DMA_UR8T_DONE           (*(unsigned char volatile __FAR *)0x7ef7e7)
#define     DMA_UR8T_TXAH           (*(unsigned char volatile __FAR *)0x7ef7e8)
#define     DMA_UR8T_TXAL           (*(unsigned char volatile __FAR *)0x7ef7e9)
#define     DMA_UR8_ITVH            (*(unsigned char volatile __FAR *)0x7ef7ee)
#define     DMA_UR8_ITVL            (*(unsigned char volatile __FAR *)0x7ef7ef)

#define     DMA_UR8R_CFG            (*(unsigned char volatile __FAR *)0x7ef7f0)
#define     DMA_UR8R_CR             (*(unsigned char volatile __FAR *)0x7ef7f1)
#define     DMA_UR8R_STA            (*(unsigned char volatile __FAR *)0x7ef7f2)
#define     DMA_UR8R_AMTH           (*(unsigned char volatile __FAR *)0x7ef7f4)
#define     DMA_UR8R_AMT            (*(unsigned char volatile __FAR *)0x7ef7f5)
#define     DMA_UR8R_DONEH          (*(unsigned char volatile __FAR *)0x7ef7f6)
#define     DMA_UR8R_DONE           (*(unsigned char volatile __FAR *)0x7ef7f7)
#define     DMA_UR8R_RXAH           (*(unsigned char volatile __FAR *)0x7ef7f8)
#define     DMA_UR8R_RXAL           (*(unsigned char volatile __FAR *)0x7ef7f9)

#define     S8CFG                   (*(unsigned char volatile __FAR *)0x7ef7fd)
#define     S8ADDR                  (*(unsigned char volatile __FAR *)0x7ef7fe)
#define     S8ADEN                  (*(unsigned char volatile __FAR *)0x7ef7ff)

/////////////////////////////////////////////////
//7E:F600H-7E:F6FFH
/////////////////////////////////////////////////

#define     PGA1_CR1                (*(unsigned char volatile __FAR *)0x7ef600)
#define     PGA1_CR2                (*(unsigned char volatile __FAR *)0x7ef601)
#define     PGA2_CR1                (*(unsigned char volatile __FAR *)0x7ef604)
#define     PGA2_CR2                (*(unsigned char volatile __FAR *)0x7ef605)
#define     PGA3_CR1                (*(unsigned char volatile __FAR *)0x7ef608)
#define     PGA3_CR2                (*(unsigned char volatile __FAR *)0x7ef609)
#define     PGA4_CR1                (*(unsigned char volatile __FAR *)0x7ef60c)
#define     PGA4_CR2                (*(unsigned char volatile __FAR *)0x7ef60d)
#define     PGA1_CR                 (*(unsigned int  volatile __FAR *)0x7ef600)
#define     PGA2_CR                 (*(unsigned int  volatile __FAR *)0x7ef604)
#define     PGA3_CR                 (*(unsigned int  volatile __FAR *)0x7ef608)
#define     PGA4_CR                 (*(unsigned int  volatile __FAR *)0x7ef60c)

#define     DAC1_CR                 (*(unsigned char volatile __FAR *)0x7ef610)
#define     DAC1_STA                (*(unsigned char volatile __FAR *)0x7ef611)
#define     DAC1_DATH               (*(unsigned char volatile __FAR *)0x7ef612)
#define     DAC1_DATL               (*(unsigned char volatile __FAR *)0x7ef613)
#define     DAC1_DIVH               (*(unsigned char volatile __FAR *)0x7ef614)
#define     DAC1_DIVL               (*(unsigned char volatile __FAR *)0x7ef615)
#define     DAC1_DAT                (*(unsigned int  volatile __FAR *)0x7ef612)
#define     DAC1_DIV                (*(unsigned int  volatile __FAR *)0x7ef614)

#define     DMA_DAC1_CFG            (*(unsigned char volatile __FAR *)0x7ef618)
#define     DMA_DAC1_CR             (*(unsigned char volatile __FAR *)0x7ef619)
#define     DMA_DAC1_STA            (*(unsigned char volatile __FAR *)0x7ef61a)
#define     DMA_DAC1_AMTH           (*(unsigned char volatile __FAR *)0x7ef61c)
#define     DMA_DAC1_AMT            (*(unsigned char volatile __FAR *)0x7ef61d)
#define     DMA_DAC1_DONEH          (*(unsigned char volatile __FAR *)0x7ef61e)
#define     DMA_DAC1_DONE           (*(unsigned char volatile __FAR *)0x7ef61f)
#define     DMA_DAC1_TXAH           (*(unsigned char volatile __FAR *)0x7ef620)
#define     DMA_DAC1_TXAL           (*(unsigned char volatile __FAR *)0x7ef621)
#define     DMA_DAC1_CR1            (*(unsigned char volatile __FAR *)0x7ef623)
#define     DMA_DAC1_ITVH           (*(unsigned char volatile __FAR *)0x7ef626)
#define     DMA_DAC1_ITVL           (*(unsigned char volatile __FAR *)0x7ef627)

#define     DAC2_CR                 (*(unsigned char volatile __FAR *)0x7ef628)
#define     DAC2_STA                (*(unsigned char volatile __FAR *)0x7ef629)
#define     DAC2_DATH               (*(unsigned char volatile __FAR *)0x7ef62a)
#define     DAC2_DATL               (*(unsigned char volatile __FAR *)0x7ef62b)
#define     DAC2_DIVH               (*(unsigned char volatile __FAR *)0x7ef62c)
#define     DAC2_DIVL               (*(unsigned char volatile __FAR *)0x7ef62d)
#define     DAC2_DAT                (*(unsigned int  volatile __FAR *)0x7ef62a)
#define     DAC2_DIV                (*(unsigned int  volatile __FAR *)0x7ef62c)

#define     DMA_DAC2_CFG            (*(unsigned char volatile __FAR *)0x7ef630)
#define     DMA_DAC2_CR             (*(unsigned char volatile __FAR *)0x7ef631)
#define     DMA_DAC2_STA            (*(unsigned char volatile __FAR *)0x7ef632)
#define     DMA_DAC2_AMTH           (*(unsigned char volatile __FAR *)0x7ef634)
#define     DMA_DAC2_AMT            (*(unsigned char volatile __FAR *)0x7ef635)
#define     DMA_DAC2_DONEH          (*(unsigned char volatile __FAR *)0x7ef636)
#define     DMA_DAC2_DONE           (*(unsigned char volatile __FAR *)0x7ef637)
#define     DMA_DAC2_TXAH           (*(unsigned char volatile __FAR *)0x7ef638)
#define     DMA_DAC2_TXAL           (*(unsigned char volatile __FAR *)0x7ef639)
#define     DMA_DAC2_CR1            (*(unsigned char volatile __FAR *)0x7ef63b)
#define     DMA_DAC2_ITVH           (*(unsigned char volatile __FAR *)0x7ef63e)
#define     DMA_DAC2_ITVL           (*(unsigned char volatile __FAR *)0x7ef63f)

#define     DMA_PWMET_CFG           (*(unsigned char volatile __FAR *)0x7ef668)
#define     DMA_PWMET_CR            (*(unsigned char volatile __FAR *)0x7ef669)
#define     DMA_PWMET_STA           (*(unsigned char volatile __FAR *)0x7ef66a)
#define     DMA_PWMET_AMTH          (*(unsigned char volatile __FAR *)0x7ef66c)
#define     DMA_PWMET_AMT           (*(unsigned char volatile __FAR *)0x7ef66d)
#define     DMA_PWMET_DONEH         (*(unsigned char volatile __FAR *)0x7ef66e)
#define     DMA_PWMET_DONE          (*(unsigned char volatile __FAR *)0x7ef66f)
#define     DMA_PWMET_TXAH          (*(unsigned char volatile __FAR *)0x7ef670)
#define     DMA_PWMET_TXAL          (*(unsigned char volatile __FAR *)0x7ef671)
#define     DMA_PWME_ITVH           (*(unsigned char volatile __FAR *)0x7ef676)
#define     DMA_PWME_ITVL           (*(unsigned char volatile __FAR *)0x7ef677)

#define     DMA_PWMER_CFG           (*(unsigned char volatile __FAR *)0x7ef678)
#define     DMA_PWMER_CR            (*(unsigned char volatile __FAR *)0x7ef679)
#define     DMA_PWMER_STA           (*(unsigned char volatile __FAR *)0x7ef67a)
#define     DMA_PWMER_AMTH          (*(unsigned char volatile __FAR *)0x7ef67c)
#define     DMA_PWMER_AMT           (*(unsigned char volatile __FAR *)0x7ef67d)
#define     DMA_PWMER_DONEH         (*(unsigned char volatile __FAR *)0x7ef67e)
#define     DMA_PWMER_DONE          (*(unsigned char volatile __FAR *)0x7ef67f)
#define     DMA_PWMER_RXAH          (*(unsigned char volatile __FAR *)0x7ef680)
#define     DMA_PWMER_RXAL          (*(unsigned char volatile __FAR *)0x7ef681)

#define     HSPWME_CFG              (*(unsigned char volatile __FAR *)0x7ef688)
#define     HSPWME_ADR              (*(unsigned char volatile __FAR *)0x7ef689)
#define     HSPWME_DAT              (*(unsigned char volatile __FAR *)0x7ef68a)
#define     PWME_CLKDIV             (*(unsigned char volatile __FAR *)0x7ef68b)
#define     HSPWMF_CFG              (*(unsigned char volatile __FAR *)0x7ef68c)
#define     HSPWMF_ADR              (*(unsigned char volatile __FAR *)0x7ef68d)
#define     HSPWMF_DAT              (*(unsigned char volatile __FAR *)0x7ef68e)
#define     PWMF_CLKDIV             (*(unsigned char volatile __FAR *)0x7ef68f)

#define     PWME_ENO2               (*(unsigned char volatile __FAR *)0x7ef690)
#define     PWME_IOAUX2             (*(unsigned char volatile __FAR *)0x7ef691)
#define     PWME_CR3                (*(unsigned char volatile __FAR *)0x7ef692)
#define     PWME_SR3                (*(unsigned char volatile __FAR *)0x7ef693)
#define     PWME_CCER3              (*(unsigned char volatile __FAR *)0x7ef694)
#define     PWME_CCMR1X             (*(unsigned char volatile __FAR *)0x7ef698)
#define     PWME_CCMR2X             (*(unsigned char volatile __FAR *)0x7ef699)
#define     PWME_CCMR3X             (*(unsigned char volatile __FAR *)0x7ef69a)
#define     PWME_CCMR4X             (*(unsigned char volatile __FAR *)0x7ef69b)
#define     PWME_CCMR5              (*(unsigned char volatile __FAR *)0x7ef69c)
#define     PWME_CCMR5X             (*(unsigned char volatile __FAR *)0x7ef69d)
#define     PWME_CCMR6              (*(unsigned char volatile __FAR *)0x7ef69e)
#define     PWME_CCMR6X             (*(unsigned char volatile __FAR *)0x7ef69f)
#define     PWME_CCR5H              (*(unsigned char volatile __FAR *)0x7ef6a0)
#define     PWME_CCR5L              (*(unsigned char volatile __FAR *)0x7ef6a1)
#define     PWME_CCR5X              (*(unsigned char volatile __FAR *)0x7ef6a2)
#define     PWME_CCR6H              (*(unsigned char volatile __FAR *)0x7ef6a3)
#define     PWME_CCR6L              (*(unsigned char volatile __FAR *)0x7ef6a4)
#define     PWME_DER                (*(unsigned char volatile __FAR *)0x7ef6a8)
#define     PWME_DBA                (*(unsigned char volatile __FAR *)0x7ef6a9)
#define     PWME_DBL                (*(unsigned char volatile __FAR *)0x7ef6aa)
#define     PWME_DMACR              (*(unsigned char volatile __FAR *)0x7ef6ab)

#define     PWME_ETRPS              (*(unsigned char volatile __FAR *)0x7ef6b0)
#define     PWME_ENO                (*(unsigned char volatile __FAR *)0x7ef6b1)
#define     PWME_PS                 (*(unsigned char volatile __FAR *)0x7ef6b2)
#define     PWME_IOAUX              (*(unsigned char volatile __FAR *)0x7ef6b3)
#define     PWMF_ETRPS              (*(unsigned char volatile __FAR *)0x7ef6b4)
#define     PWMF_ENO                (*(unsigned char volatile __FAR *)0x7ef6b5)
#define     PWMF_PS                 (*(unsigned char volatile __FAR *)0x7ef6b6)
#define     PWMF_IOAUX              (*(unsigned char volatile __FAR *)0x7ef6b7)
#define     PWME_PS2                (*(unsigned char volatile __FAR *)0x7ef6b8)
#define     PWME_RCRH               (*(unsigned char volatile __FAR *)0x7ef6b9)
#define     PWMF_RCRH               (*(unsigned char volatile __FAR *)0x7ef6ba)

#define     PWME_CR1                (*(unsigned char volatile __FAR *)0x7ef6c0)
#define     PWME_CR2                (*(unsigned char volatile __FAR *)0x7ef6c1)
#define     PWME_SMCR               (*(unsigned char volatile __FAR *)0x7ef6c2)
#define     PWME_ETR                (*(unsigned char volatile __FAR *)0x7ef6c3)
#define     PWME_IER                (*(unsigned char volatile __FAR *)0x7ef6c4)
#define     PWME_SR1                (*(unsigned char volatile __FAR *)0x7ef6c5)
#define     PWME_SR2                (*(unsigned char volatile __FAR *)0x7ef6c6)
#define     PWME_EGR                (*(unsigned char volatile __FAR *)0x7ef6c7)
#define     PWME_CCMR1              (*(unsigned char volatile __FAR *)0x7ef6c8)
#define     PWME_CCMR2              (*(unsigned char volatile __FAR *)0x7ef6c9)
#define     PWME_CCMR3              (*(unsigned char volatile __FAR *)0x7ef6ca)
#define     PWME_CCMR4              (*(unsigned char volatile __FAR *)0x7ef6cb)
#define     PWME_CCER1              (*(unsigned char volatile __FAR *)0x7ef6cc)
#define     PWME_CCER2              (*(unsigned char volatile __FAR *)0x7ef6cd)
#define     PWME_CNTRH              (*(unsigned char volatile __FAR *)0x7ef6ce)
#define     PWME_CNTRL              (*(unsigned char volatile __FAR *)0x7ef6cf)
#define     PWME_PSCRH              (*(unsigned char volatile __FAR *)0x7ef6d0)
#define     PWME_PSCRL              (*(unsigned char volatile __FAR *)0x7ef6d1)
#define     PWME_ARRH               (*(unsigned char volatile __FAR *)0x7ef6d2)
#define     PWME_ARRL               (*(unsigned char volatile __FAR *)0x7ef6d3)
#define     PWME_RCR                (*(unsigned char volatile __FAR *)0x7ef6d4)
#define     PWME_CCR1H              (*(unsigned char volatile __FAR *)0x7ef6d5)
#define     PWME_CCR1L              (*(unsigned char volatile __FAR *)0x7ef6d6)
#define     PWME_CCR2H              (*(unsigned char volatile __FAR *)0x7ef6d7)
#define     PWME_CCR2L              (*(unsigned char volatile __FAR *)0x7ef6d8)
#define     PWME_CCR3H              (*(unsigned char volatile __FAR *)0x7ef6d9)
#define     PWME_CCR3L              (*(unsigned char volatile __FAR *)0x7ef6da)
#define     PWME_CCR4H              (*(unsigned char volatile __FAR *)0x7ef6db)
#define     PWME_CCR4L              (*(unsigned char volatile __FAR *)0x7ef6dc)
#define     PWME_BKR                (*(unsigned char volatile __FAR *)0x7ef6dd)
#define     PWME_DTR                (*(unsigned char volatile __FAR *)0x7ef6de)
#define     PWME_OISR               (*(unsigned char volatile __FAR *)0x7ef6df)

#define     PWMF_CR1                (*(unsigned char volatile __FAR *)0x7ef6e0)
#define     PWMF_CR2                (*(unsigned char volatile __FAR *)0x7ef6e1)
#define     PWMF_SMCR               (*(unsigned char volatile __FAR *)0x7ef6e2)
#define     PWMF_ETR                (*(unsigned char volatile __FAR *)0x7ef6e3)
#define     PWMF_IER                (*(unsigned char volatile __FAR *)0x7ef6e4)
#define     PWMF_SR1                (*(unsigned char volatile __FAR *)0x7ef6e5)
#define     PWMF_SR2                (*(unsigned char volatile __FAR *)0x7ef6e6)
#define     PWMF_EGR                (*(unsigned char volatile __FAR *)0x7ef6e7)
#define     PWMF_CCMR1              (*(unsigned char volatile __FAR *)0x7ef6e8)
#define     PWMF_CCMR2              (*(unsigned char volatile __FAR *)0x7ef6e9)
#define     PWMF_CCMR3              (*(unsigned char volatile __FAR *)0x7ef6ea)
#define     PWMF_CCMR4              (*(unsigned char volatile __FAR *)0x7ef6eb)
#define     PWMF_CCER1              (*(unsigned char volatile __FAR *)0x7ef6ec)
#define     PWMF_CCER2              (*(unsigned char volatile __FAR *)0x7ef6ed)
#define     PWMF_CNTRH              (*(unsigned char volatile __FAR *)0x7ef6ee)
#define     PWMF_CNTRL              (*(unsigned char volatile __FAR *)0x7ef6ef)
#define     PWMF_PSCRH              (*(unsigned char volatile __FAR *)0x7ef6f0)
#define     PWMF_PSCRL              (*(unsigned char volatile __FAR *)0x7ef6f1)
#define     PWMF_ARRH               (*(unsigned char volatile __FAR *)0x7ef6f2)
#define     PWMF_ARRL               (*(unsigned char volatile __FAR *)0x7ef6f3)
#define     PWMF_RCR                (*(unsigned char volatile __FAR *)0x7ef6f4)
#define     PWMF_CCR5H              (*(unsigned char volatile __FAR *)0x7ef6f5)
#define     PWMF_CCR5L              (*(unsigned char volatile __FAR *)0x7ef6f6)
#define     PWMF_CCR6H              (*(unsigned char volatile __FAR *)0x7ef6f7)
#define     PWMF_CCR6L              (*(unsigned char volatile __FAR *)0x7ef6f8)
#define     PWMF_CCR7H              (*(unsigned char volatile __FAR *)0x7ef6f9)
#define     PWMF_CCR7L              (*(unsigned char volatile __FAR *)0x7ef6fa)
#define     PWMF_CCR8H              (*(unsigned char volatile __FAR *)0x7ef6fb)
#define     PWMF_CCR8L              (*(unsigned char volatile __FAR *)0x7ef6fc)
#define     PWMF_BKR                (*(unsigned char volatile __FAR *)0x7ef6fd)
#define     PWMF_DTR                (*(unsigned char volatile __FAR *)0x7ef6fe)
#define     PWMF_OISR               (*(unsigned char volatile __FAR *)0x7ef6ff)

/////////////////////////////////////////////////
//7E:F500H-7E:F5FFH
/////////////////////////////////////////////////

#define     P0OS                    (*(unsigned char volatile __FAR *)0x7ef500)
#define     P1OS                    (*(unsigned char volatile __FAR *)0x7ef501)
#define     P2OS                    (*(unsigned char volatile __FAR *)0x7ef502)
#define     P3OS                    (*(unsigned char volatile __FAR *)0x7ef503)
#define     P4OS                    (*(unsigned char volatile __FAR *)0x7ef504)
#define     P5OS                    (*(unsigned char volatile __FAR *)0x7ef505)
#define     P6OS                    (*(unsigned char volatile __FAR *)0x7ef506)
#define     P7OS                    (*(unsigned char volatile __FAR *)0x7ef507)
#define     P8OS                    (*(unsigned char volatile __FAR *)0x7ef508)
#define     P9OS                    (*(unsigned char volatile __FAR *)0x7ef509)
#define     PAOS                    (*(unsigned char volatile __FAR *)0x7ef50a)
#define     PBOS                    (*(unsigned char volatile __FAR *)0x7ef50b)
#define     PCOS                    (*(unsigned char volatile __FAR *)0x7ef50c)
#define     PDOS                    (*(unsigned char volatile __FAR *)0x7ef50d)
#define     PEOS                    (*(unsigned char volatile __FAR *)0x7ef50e)
#define     PFOS                    (*(unsigned char volatile __FAR *)0x7ef50f)

#define     P0OD                    (*(unsigned char volatile __FAR *)0x7ef510)
#define     P1OD                    (*(unsigned char volatile __FAR *)0x7ef511)
#define     P2OD                    (*(unsigned char volatile __FAR *)0x7ef512)
#define     P3OD                    (*(unsigned char volatile __FAR *)0x7ef513)
#define     P4OD                    (*(unsigned char volatile __FAR *)0x7ef514)
#define     P5OD                    (*(unsigned char volatile __FAR *)0x7ef515)
#define     P6OD                    (*(unsigned char volatile __FAR *)0x7ef516)
#define     P7OD                    (*(unsigned char volatile __FAR *)0x7ef517)
#define     P8OD                    (*(unsigned char volatile __FAR *)0x7ef518)
#define     P9OD                    (*(unsigned char volatile __FAR *)0x7ef519)
#define     PAOD                    (*(unsigned char volatile __FAR *)0x7ef51a)
#define     PBOD                    (*(unsigned char volatile __FAR *)0x7ef51b)
#define     PCOD                    (*(unsigned char volatile __FAR *)0x7ef51c)
#define     PDOD                    (*(unsigned char volatile __FAR *)0x7ef51d)
#define     PEOD                    (*(unsigned char volatile __FAR *)0x7ef51e)
#define     PFOD                    (*(unsigned char volatile __FAR *)0x7ef51f)

#define     DMA_CAN1T_CFG           (*(unsigned char volatile __FAR *)0x7ef520)
#define     DMA_CAN1T_CR            (*(unsigned char volatile __FAR *)0x7ef521)
#define     DMA_CAN1T_STA           (*(unsigned char volatile __FAR *)0x7ef522)
#define     DMA_CAN1T_AMTH          (*(unsigned char volatile __FAR *)0x7ef524)
#define     DMA_CAN1T_AMT           (*(unsigned char volatile __FAR *)0x7ef525)
#define     DMA_CAN1T_DONEH         (*(unsigned char volatile __FAR *)0x7ef526)
#define     DMA_CAN1T_DONE          (*(unsigned char volatile __FAR *)0x7ef527)
#define     DMA_CAN1T_TXAH          (*(unsigned char volatile __FAR *)0x7ef528)
#define     DMA_CAN1T_TXAL          (*(unsigned char volatile __FAR *)0x7ef529)
#define     DMA_CAN1T_FRM           (*(unsigned char volatile __FAR *)0x7ef52b)
#define     DMA_CAN1T_FCNTH         (*(unsigned char volatile __FAR *)0x7ef52c)
#define     DMA_CAN1T_FCNTL         (*(unsigned char volatile __FAR *)0x7ef52d)
#define     DMA_CAN1_ITVH           (*(unsigned char volatile __FAR *)0x7ef52e)
#define     DMA_CAN1_ITVL           (*(unsigned char volatile __FAR *)0x7ef52f)

#define     DMA_CAN1R_CFG           (*(unsigned char volatile __FAR *)0x7ef530)
#define     DMA_CAN1R_CR            (*(unsigned char volatile __FAR *)0x7ef531)
#define     DMA_CAN1R_STA           (*(unsigned char volatile __FAR *)0x7ef532)
#define     CAN1_AUX_CR             (*(unsigned char volatile __FAR *)0x7ef533)
#define     DMA_CAN1R_AMTH          (*(unsigned char volatile __FAR *)0x7ef534)
#define     DMA_CAN1R_AMT           (*(unsigned char volatile __FAR *)0x7ef535)
#define     DMA_CAN1R_DONEH         (*(unsigned char volatile __FAR *)0x7ef536)
#define     DMA_CAN1R_DONE          (*(unsigned char volatile __FAR *)0x7ef537)
#define     DMA_CAN1R_RXAH          (*(unsigned char volatile __FAR *)0x7ef538)
#define     DMA_CAN1R_RXAL          (*(unsigned char volatile __FAR *)0x7ef539)
#define     DMA_CAN1R_FRM           (*(unsigned char volatile __FAR *)0x7ef53b)
#define     DMA_CAN1R_FCNTH         (*(unsigned char volatile __FAR *)0x7ef53c)
#define     DMA_CAN1R_FCNTL         (*(unsigned char volatile __FAR *)0x7ef53d)

#define     DMA_CAN2T_CFG           (*(unsigned char volatile __FAR *)0x7ef540)
#define     DMA_CAN2T_CR            (*(unsigned char volatile __FAR *)0x7ef541)
#define     DMA_CAN2T_STA           (*(unsigned char volatile __FAR *)0x7ef542)
#define     DMA_CAN2T_AMTH          (*(unsigned char volatile __FAR *)0x7ef544)
#define     DMA_CAN2T_AMT           (*(unsigned char volatile __FAR *)0x7ef545)
#define     DMA_CAN2T_DONEH         (*(unsigned char volatile __FAR *)0x7ef546)
#define     DMA_CAN2T_DONE          (*(unsigned char volatile __FAR *)0x7ef547)
#define     DMA_CAN2T_TXAH          (*(unsigned char volatile __FAR *)0x7ef548)
#define     DMA_CAN2T_TXAL          (*(unsigned char volatile __FAR *)0x7ef549)
#define     DMA_CAN2T_FRM           (*(unsigned char volatile __FAR *)0x7ef54b)
#define     DMA_CAN2T_FCNTH         (*(unsigned char volatile __FAR *)0x7ef54c)
#define     DMA_CAN2T_FCNTL         (*(unsigned char volatile __FAR *)0x7ef54d)
#define     DMA_CAN2_ITVH           (*(unsigned char volatile __FAR *)0x7ef54e)
#define     DMA_CAN2_ITVL           (*(unsigned char volatile __FAR *)0x7ef54f)

#define     DMA_CAN2R_CFG           (*(unsigned char volatile __FAR *)0x7ef550)
#define     DMA_CAN2R_CR            (*(unsigned char volatile __FAR *)0x7ef551)
#define     CAN2_AUX_CR             (*(unsigned char volatile __FAR *)0x7ef553)
#define     DMA_CAN2R_STA           (*(unsigned char volatile __FAR *)0x7ef552)
#define     DMA_CAN2R_AMTH          (*(unsigned char volatile __FAR *)0x7ef554)
#define     DMA_CAN2R_AMT           (*(unsigned char volatile __FAR *)0x7ef555)
#define     DMA_CAN2R_DONEH         (*(unsigned char volatile __FAR *)0x7ef556)
#define     DMA_CAN2R_DONE          (*(unsigned char volatile __FAR *)0x7ef557)
#define     DMA_CAN2R_RXAH          (*(unsigned char volatile __FAR *)0x7ef558)
#define     DMA_CAN2R_RXAL          (*(unsigned char volatile __FAR *)0x7ef559)
#define     DMA_CAN2R_FRM           (*(unsigned char volatile __FAR *)0x7ef55b)
#define     DMA_CAN2R_FCNTH         (*(unsigned char volatile __FAR *)0x7ef55c)
#define     DMA_CAN2R_FCNTL         (*(unsigned char volatile __FAR *)0x7ef55d)

#define     IAP_XDATA               ( (unsigned char volatile __FAR *)0x7ef5f0)
#define     IAP_XDATA0              (*(unsigned char volatile __FAR *)0x7ef5f0)
#define     IAP_XDATA1              (*(unsigned char volatile __FAR *)0x7ef5f1)
#define     IAP_XDATA2              (*(unsigned char volatile __FAR *)0x7ef5f2)
#define     IAP_XDATA3              (*(unsigned char volatile __FAR *)0x7ef5f3)
#define     IAP_XDATA4              (*(unsigned char volatile __FAR *)0x7ef5f4)
#define     IAP_XDATA5              (*(unsigned char volatile __FAR *)0x7ef5f5)
#define     IAP_XDATA6              (*(unsigned char volatile __FAR *)0x7ef5f6)
#define     IAP_XDATA7              (*(unsigned char volatile __FAR *)0x7ef5f7)
#define     IAP_XDATA8              (*(unsigned char volatile __FAR *)0x7ef5f8)
#define     IAP_XDATA9              (*(unsigned char volatile __FAR *)0x7ef5f9)
#define     IAP_XDATAA              (*(unsigned char volatile __FAR *)0x7ef5fa)
#define     IAP_XDATAB              (*(unsigned char volatile __FAR *)0x7ef5fb)
#define     IAP_XDATAC              (*(unsigned char volatile __FAR *)0x7ef5fc)
#define     IAP_XDATAD              (*(unsigned char volatile __FAR *)0x7ef5fd)
#define     IAP_XDATAE              (*(unsigned char volatile __FAR *)0x7ef5fe)
#define     IAP_XDATAF              (*(unsigned char volatile __FAR *)0x7ef5ff)

/////////////////////////////////////////////////
//7E:F400H-7E:F4FFH
/////////////////////////////////////////////////

#define     CAN_RBUF                ( (unsigned char volatile __FAR *)0x7ef400)
#define     CAN_TBUF                ( (unsigned char volatile __FAR *)0x7ef450)
#define     CAN_TTS                 ( (unsigned char volatile __FAR *)0x7ef498)
#define     CAN_CFG_STAT            (*(unsigned char volatile __FAR *)0x7ef4a0)
#define     CAN_TCMD                (*(unsigned char volatile __FAR *)0x7ef4a1)
#define     CAN_TCTRL               (*(unsigned char volatile __FAR *)0x7ef4a2)
#define     CAN_RCTRL               (*(unsigned char volatile __FAR *)0x7ef4a3)
#define     CAN_RTIE                (*(unsigned char volatile __FAR *)0x7ef4a4)
#define     CAN_RTIF                (*(unsigned char volatile __FAR *)0x7ef4a5)
#define     CAN_ERRINT              (*(unsigned char volatile __FAR *)0x7ef4a6)
#define     CAN_LIMIT               (*(unsigned char volatile __FAR *)0x7ef4a7)
#define     CAN_S_SEG1              (*(unsigned char volatile __FAR *)0x7ef4a8)
#define     CAN_S_SEG2              (*(unsigned char volatile __FAR *)0x7ef4a9)
#define     CAN_S_SJW               (*(unsigned char volatile __FAR *)0x7ef4aa)
#define     CAN_S_PRESC             (*(unsigned char volatile __FAR *)0x7ef4ab)
#define     CAN_F_SEG1              (*(unsigned char volatile __FAR *)0x7ef4ac)
#define     CAN_F_SEG2              (*(unsigned char volatile __FAR *)0x7ef4ad)
#define     CAN_F_SJW               (*(unsigned char volatile __FAR *)0x7ef4ae)
#define     CAN_F_PRESC             (*(unsigned char volatile __FAR *)0x7ef4af)
#define     CAN_EALCAP              (*(unsigned char volatile __FAR *)0x7ef4b0)
#define     CAN_TDC                 (*(unsigned char volatile __FAR *)0x7ef4b1)
#define     CAN_RECNT               (*(unsigned char volatile __FAR *)0x7ef4b2)
#define     CAN_TECNT               (*(unsigned char volatile __FAR *)0x7ef4b3)
#define     CAN_ACFCTRL             (*(unsigned char volatile __FAR *)0x7ef4b4)
#define     CAN_TIMECFG             (*(unsigned char volatile __FAR *)0x7ef4b5)
#define     CAN_ACF_EN              ( (unsigned char volatile __FAR *)0x7ef4b6)
#define     CAN_ACF_EN0             (*(unsigned char volatile __FAR *)0x7ef4b6)
#define     CAN_ACF_EN1             (*(unsigned char volatile __FAR *)0x7ef4b7)
#define     CAN_ACF0                (*(unsigned char volatile __FAR *)0x7ef4b8)
#define     CAN_ACF1                (*(unsigned char volatile __FAR *)0x7ef4b9)
#define     CAN_ACF2                (*(unsigned char volatile __FAR *)0x7ef4ba)
#define     CAN_ACF3                (*(unsigned char volatile __FAR *)0x7ef4bb)
#define     CAN_VER0                (*(unsigned char volatile __FAR *)0x7ef4bc)
#define     CAN_VER1                (*(unsigned char volatile __FAR *)0x7ef4bd)
#define     CAN_TBSLOT              (*(unsigned char volatile __FAR *)0x7ef4be)
#define     CAN_TTCFG               (*(unsigned char volatile __FAR *)0x7ef4bf)
#define     CAN_REF_MSG0            (*(unsigned char volatile __FAR *)0x7ef4c0)
#define     CAN_REF_MSG1            (*(unsigned char volatile __FAR *)0x7ef4c1)
#define     CAN_REF_MSG2            (*(unsigned char volatile __FAR *)0x7ef4c2)
#define     CAN_REF_MSG3            (*(unsigned char volatile __FAR *)0x7ef4c3)
#define     CAN_TRIG_CFG0           (*(unsigned char volatile __FAR *)0x7ef4c4)
#define     CAN_TRIG_CFG1           (*(unsigned char volatile __FAR *)0x7ef4c5)
#define     CAN_TT_CFG0             (*(unsigned char volatile __FAR *)0x7ef4c6)
#define     CAN_TT_CFG1             (*(unsigned char volatile __FAR *)0x7ef4c7)
#define     CAN_TT_WTRIG0           (*(unsigned char volatile __FAR *)0x7ef4c8)
#define     CAN_TT_WTRIG1           (*(unsigned char volatile __FAR *)0x7ef4c9)

#define     P0IM2                   (*(unsigned char volatile __FAR *)0x7ef4e0)
#define     P1IM2                   (*(unsigned char volatile __FAR *)0x7ef4e1)
#define     P2IM2                   (*(unsigned char volatile __FAR *)0x7ef4e2)
#define     P3IM2                   (*(unsigned char volatile __FAR *)0x7ef4e3)
#define     P4IM2                   (*(unsigned char volatile __FAR *)0x7ef4e4)
#define     P5IM2                   (*(unsigned char volatile __FAR *)0x7ef4e5)
#define     P6IM2                   (*(unsigned char volatile __FAR *)0x7ef4e6)
#define     P7IM2                   (*(unsigned char volatile __FAR *)0x7ef4e7)
#define     P8IM2                   (*(unsigned char volatile __FAR *)0x7ef4e8)
#define     P9IM2                   (*(unsigned char volatile __FAR *)0x7ef4e9)
#define     PAIM2                   (*(unsigned char volatile __FAR *)0x7ef4ea)
#define     PBIM2                   (*(unsigned char volatile __FAR *)0x7ef4eb)
#define     PCIM2                   (*(unsigned char volatile __FAR *)0x7ef4ec)
#define     PDIM2                   (*(unsigned char volatile __FAR *)0x7ef4ed)
#define     PEIM2                   (*(unsigned char volatile __FAR *)0x7ef4ee)
#define     PFIM2                   (*(unsigned char volatile __FAR *)0x7ef4ef)

#define     CPU_CRR_CFG             (*(unsigned char volatile __FAR *)0x7ef4f0)
#define     CPU_CRR_KEY0            (*(unsigned char volatile __FAR *)0x7ef4f1)
#define     CPU_CRR_KEY1            (*(unsigned char volatile __FAR *)0x7ef4f2)
#define     CPU_CRR_KEY2            (*(unsigned char volatile __FAR *)0x7ef4f3)
#define     CRR_READ_SELH           (*(unsigned char volatile __FAR *)0x7ef4f4)
#define     CRR_READ_SELL           (*(unsigned char volatile __FAR *)0x7ef4f5)
#define     CRR_READ_DATA           (*(unsigned char volatile __FAR *)0x7ef4f6)

#define     IO_WUP_PRD              (*(unsigned char volatile __FAR *)0x7ef4f8)
#define     CPU_WUP_PRD             (*(unsigned char volatile __FAR *)0x7ef4f9)
#define     CPU_STOP_CNTH           (*(unsigned char volatile __FAR *)0x7ef4fa)
#define     CPU_STOP_CNTL           (*(unsigned char volatile __FAR *)0x7ef4fb)

/////////////////////////////////////////////////
//7E:F300H-7E:F3FFH
/////////////////////////////////////////////////

#define     CAN2_RBUF               ( (unsigned char volatile __FAR *)0x7ef300)
#define     CAN2_TBUF               ( (unsigned char volatile __FAR *)0x7ef350)
#define     CAN2_TTS                ( (unsigned char volatile __FAR *)0x7ef398)
#define     CAN2_CFG_STAT           (*(unsigned char volatile __FAR *)0x7ef3a0)
#define     CAN2_TCMD               (*(unsigned char volatile __FAR *)0x7ef3a1)
#define     CAN2_TCTRL              (*(unsigned char volatile __FAR *)0x7ef3a2)
#define     CAN2_RCTRL              (*(unsigned char volatile __FAR *)0x7ef3a3)
#define     CAN2_RTIE               (*(unsigned char volatile __FAR *)0x7ef3a4)
#define     CAN2_RTIF               (*(unsigned char volatile __FAR *)0x7ef3a5)
#define     CAN2_ERRINT             (*(unsigned char volatile __FAR *)0x7ef3a6)
#define     CAN2_LIMIT              (*(unsigned char volatile __FAR *)0x7ef3a7)
#define     CAN2_S_SEG1             (*(unsigned char volatile __FAR *)0x7ef3a8)
#define     CAN2_S_SEG2             (*(unsigned char volatile __FAR *)0x7ef3a9)
#define     CAN2_S_SJW              (*(unsigned char volatile __FAR *)0x7ef3aa)
#define     CAN2_S_PRESC            (*(unsigned char volatile __FAR *)0x7ef3ab)
#define     CAN2_F_SEG1             (*(unsigned char volatile __FAR *)0x7ef3ac)
#define     CAN2_F_SEG2             (*(unsigned char volatile __FAR *)0x7ef3ad)
#define     CAN2_F_SJW              (*(unsigned char volatile __FAR *)0x7ef3ae)
#define     CAN2_F_PRESC            (*(unsigned char volatile __FAR *)0x7ef3af)
#define     CAN2_EALCAP             (*(unsigned char volatile __FAR *)0x7ef3b0)
#define     CAN2_TDC                (*(unsigned char volatile __FAR *)0x7ef3b1)
#define     CAN2_RECNT              (*(unsigned char volatile __FAR *)0x7ef3b2)
#define     CAN2_TECNT              (*(unsigned char volatile __FAR *)0x7ef3b3)
#define     CAN2_ACFCTRL            (*(unsigned char volatile __FAR *)0x7ef3b4)
#define     CAN2_TIMECFG            (*(unsigned char volatile __FAR *)0x7ef3b5)
#define     CAN2_ACF_EN             ( (unsigned char volatile __FAR *)0x7ef3b6)
#define     CAN2_ACF_EN0            (*(unsigned char volatile __FAR *)0x7ef3b6)
#define     CAN2_ACF_EN1            (*(unsigned char volatile __FAR *)0x7ef3b7)
#define     CAN2_ACF0               (*(unsigned char volatile __FAR *)0x7ef3b8)
#define     CAN2_ACF1               (*(unsigned char volatile __FAR *)0x7ef3b9)
#define     CAN2_ACF2               (*(unsigned char volatile __FAR *)0x7ef3ba)
#define     CAN2_ACF3               (*(unsigned char volatile __FAR *)0x7ef3bb)
#define     CAN2_VER0               (*(unsigned char volatile __FAR *)0x7ef3bc)
#define     CAN2_VER1               (*(unsigned char volatile __FAR *)0x7ef3bd)
#define     CAN2_TBSLOT             (*(unsigned char volatile __FAR *)0x7ef3be)
#define     CAN2_TTCFG              (*(unsigned char volatile __FAR *)0x7ef3bf)
#define     CAN2_REF_MSG0           (*(unsigned char volatile __FAR *)0x7ef3c0)
#define     CAN2_REF_MSG1           (*(unsigned char volatile __FAR *)0x7ef3c1)
#define     CAN2_REF_MSG2           (*(unsigned char volatile __FAR *)0x7ef3c2)
#define     CAN2_REF_MSG3           (*(unsigned char volatile __FAR *)0x7ef3c3)
#define     CAN2_TRIG_CFG0          (*(unsigned char volatile __FAR *)0x7ef3c4)
#define     CAN2_TRIG_CFG1          (*(unsigned char volatile __FAR *)0x7ef3c5)
#define     CAN2_TT_CFG0            (*(unsigned char volatile __FAR *)0x7ef3c6)
#define     CAN2_TT_CFG1            (*(unsigned char volatile __FAR *)0x7ef3c7)
#define     CAN2_TT_WTRIG0          (*(unsigned char volatile __FAR *)0x7ef3c8)
#define     CAN2_TT_WTRIG1          (*(unsigned char volatile __FAR *)0x7ef3c9)

/////////////////////////////////////////////////
//LIN Control Regiter
/////////////////////////////////////////////////

#define     LBUF                    0x00
#define     LSEL                    0x01
#define     LID                     0x02
#define     LER                     0x03
#define     LIE                     0x04
#define     LSR                     0x05
#define     LCR                     0x05
#define     DLL                     0x06
#define     DLH                     0x07
#define     HDRL                    0x08
#define     HDRH                    0x09
#define     HDP                     0x0A

/////////////////////////////////////////////////
//USB Control Regiter
/////////////////////////////////////////////////

#define     USBBASE                 0
#define     FADDR                   (USBBASE + 0)
#define     UPDATE                  0x80
#define     POWER                   (USBBASE + 1)
#define     ISOUD                   0x80
#define     USBRST                  0x08
#define     USBRSU                  0x04
#define     USBSUS                  0x02
#define     ENSUS                   0x01
#define     INTRIN1                 (USBBASE + 2)
#define     EP7INIF                 0x80
#define     EP6INIF                 0x40
#define     EP5INIF                 0x20
#define     EP4INIF                 0x10
#define     EP3INIF                 0x08
#define     EP2INIF                 0x04
#define     EP1INIF                 0x02
#define     EP0IF                   0x01
#define     INTRIN2                 (USBBASE + 3)
#define     EP15INIF                0x80
#define     EP14INIF                0x40
#define     EP13INIF                0x20
#define     EP12INIF                0x10
#define     EP11INIF                0x08
#define     EP10INIF                0x04
#define     EP9INIF                 0x02
#define     EP8INIF                 0x01
#define     INTROUT1                (USBBASE + 4)
#define     EP7OUTIF                0x80
#define     EP6OUTIF                0x40
#define     EP5OUTIF                0x20
#define     EP4OUTIF                0x10
#define     EP3OUTIF                0x08
#define     EP2OUTIF                0x04
#define     EP1OUTIF                0x02
#define     INTROUT2                (USBBASE + 5)
#define     EP15OUTIF               0x80
#define     EP14OUTIF               0x40
#define     EP13OUTIF               0x20
#define     EP12OUTIF               0x10
#define     EP11OUTIF               0x08
#define     EP10OUTIF               0x04
#define     EP9OUTIF                0x02
#define     EP8OUTIF                0x01
#define     INTRUSB                 (USBBASE + 6)
#define     SOFIF                   0x08
#define     RSTIF                   0x04
#define     RSUIF                   0x02
#define     SUSIF                   0x01
#define     INTRIN1E                (USBBASE + 7)
#define     EP7INIE                 0x80
#define     EP6INIE                 0x40
#define     EP5INIE                 0x20
#define     EP4INIE                 0x10
#define     EP3INIE                 0x08
#define     EP2INIE                 0x04
#define     EP1INIE                 0x02
#define     EP0IE                   0x01
#define     INTRIN2E                (USBBASE + 8)
#define     EP15INIE                0x80
#define     EP14INIE                0x40
#define     EP13INIE                0x20
#define     EP12INIE                0x10
#define     EP11INIE                0x08
#define     EP10INIE                0x04
#define     EP9INIE                 0x02
#define     EP8INIE                 0x01
#define     INTROUT1E               (USBBASE + 9)
#define     EP7OUTIE                0x80
#define     EP6OUTIE                0x40
#define     EP5OUTIE                0x20
#define     EP4OUTIE                0x10
#define     EP3OUTIE                0x08
#define     EP2OUTIE                0x04
#define     EP1OUTIE                0x02
#define     INTROUT2E               (USBBASE + 10)
#define     EP15OUTIE               0x80
#define     EP14OUTIE               0x40
#define     EP13OUTIE               0x20
#define     EP12OUTIE               0x10
#define     EP11OUTIE               0x08
#define     EP10OUTIE               0x04
#define     EP9OUTIE                0x02
#define     EP8OUTIE                0x01
#define     INTRUSBE                (USBBASE + 11)
#define     SOFIE                   0x08
#define     RSTIE                   0x04
#define     RSUIE                   0x02
#define     SUSIE                   0x01
#define     FRAME1                  (USBBASE + 12)
#define     FRAME2                  (USBBASE + 13)
#define     INDEX                   (USBBASE + 14)
#define     INMAXP                  (USBBASE + 16)
#define     CSR0                    (USBBASE + 17)
#define     SSUEND                  0x80
#define     SOPRDY                  0x40
#define     SDSTL                   0x20
#define     SUEND                   0x10
#define     DATEND                  0x08
#define     STSTL                   0x04
#define     IPRDY                   0x02
#define     OPRDY                   0x01
#define     INCSR1                  (USBBASE + 17)
#define     INCLRDT                 0x40
#define     INSTSTL                 0x20
#define     INSDSTL                 0x10
#define     INFLUSH                 0x08
#define     INUNDRUN                0x04
#define     INFIFONE                0x02
#define     INIPRDY                 0x01
#define     INCSR2                  (USBBASE + 18)
#define     INAUTOSET               0x80
#define     INISO                   0x40
#define     INMODEIN                0x20
#define     INMODEOUT               0x00
#define     INENDMA                 0x10
#define     INFCDT                  0x08
#define     OUTMAXP                 (USBBASE + 19)
#define     OUTCSR1                 (USBBASE + 20)
#define     OUTCLRDT                0x80
#define     OUTSTSTL                0x40
#define     OUTSDSTL                0x20
#define     OUTFLUSH                0x10
#define     OUTDATERR               0x08
#define     OUTOVRRUN               0x04
#define     OUTFIFOFUL              0x02
#define     OUTOPRDY                0x01
#define     OUTCSR2                 (USBBASE + 21)
#define     OUTAUTOCLR              0x80
#define     OUTISO                  0x40
#define     OUTENDMA                0x20
#define     OUTDMAMD                0x10
#define     COUNT0                  (USBBASE + 22)
#define     OUTCOUNT1               (USBBASE + 22)
#define     OUTCOUNT2               (USBBASE + 23)
#define     FIFO0                   (USBBASE + 32)
#define     FIFO1                   (USBBASE + 33)
#define     FIFO2                   (USBBASE + 34)
#define     FIFO3                   (USBBASE + 35)
#define     FIFO4                   (USBBASE + 36)
#define     FIFO5                   (USBBASE + 37)
#define     FIFO6                   (USBBASE + 38)
#define     FIFO7                   (USBBASE + 39)
#define     FIFO8                   (USBBASE + 40)
#define     FIFO9                   (USBBASE + 41)
#define     FIFO10                  (USBBASE + 42)
#define     FIFO11                  (USBBASE + 43)
#define     FIFO12                  (USBBASE + 44)
#define     FIFO13                  (USBBASE + 45)
#define     FIFO14                  (USBBASE + 46)
#define     FIFO15                  (USBBASE + 47)
#define     UTRKCTL                 (USBBASE + 48)
#define     UTRKSTS                 (USBBASE + 49)

/////////////////////////////////////////////////
//Interrupt Vector
/////////////////////////////////////////////////

#define     INT0_VECTOR             0       //0003H
#define     TMR0_VECTOR             1       //000BH
#define     INT1_VECTOR             2       //0013H
#define     TMR1_VECTOR             3       //001BH
#define     UART1_VECTOR            4       //0023H
#define     ADC_VECTOR              5       //002BH
#define     ADC1_VECTOR             5       //002BH
#define     LVD_VECTOR              6       //0033H
#define     PCA_VECTOR              7       //003BH
#define     UART2_VECTOR            8       //0043H
#define     SPI_VECTOR              9       //004BH
#define     SPI1_VECTOR             9       //004BH
#define     INT2_VECTOR             10      //0053H
#define     INT3_VECTOR             11      //005BH
#define     TMR2_VECTOR             12      //0063H
#define     USER_VECTOR             13      //006BH
#define     INT4_VECTOR             16      //0083H
#define     UART3_VECTOR            17      //008BH
#define     UART4_VECTOR            18      //0093H
#define     TMR3_VECTOR             19      //009BH
#define     TMR4_VECTOR             20      //00A3H
#define     CMP_VECTOR              21      //00ABH
#define     CMP1_VECTOR             21      //00ABH
#define     I2C_VECTOR              24      //00C3H
#define     I2C1_VECTOR             24      //00C3H
#define     USB_VECTOR              25      //00CBH
#define     PWMA_VECTOR             26      //00D3H
#define     PWMB_VECTOR             27      //00DBH
#define     CAN1_VECTOR             28      //00E3H
#define     CAN2_VECTOR             29      //00EBH
#define     LIN1_VECTOR             30      //00F3H
#define     LIN2_VECTOR             31      //00FBH

#define     RTC_VECTOR              36      //0123H
#define     P0INT_VECTOR            37      //012BH
#define     P1INT_VECTOR            38      //0133H
#define     P2INT_VECTOR            39      //013BH
#define     P3INT_VECTOR            40      //0143H
#define     P4INT_VECTOR            41      //014BH
#define     P5INT_VECTOR            42      //0153H
#define     P6INT_VECTOR            43      //015BH
#define     P7INT_VECTOR            44      //0163H
#define     P8INT_VECTOR            45      //016BH
#define     P9INT_VECTOR            46      //0173H
#define     DMA_M2M_VECTOR          47      //017BH
#define     DMA_ADC_VECTOR          48      //0183H
#define     DMA_ADC1_VECTOR         48      //0183H
#define     DMA_SPI_VECTOR          49      //018BH
#define     DMA_SPI1_VECTOR         49      //018BH
#define     DMA_UR1T_VECTOR         50      //0193H
#define     DMA_UR1R_VECTOR         51      //019BH
#define     DMA_UR2T_VECTOR         52      //01A3H
#define     DMA_UR2R_VECTOR         53      //01ABH
#define     DMA_UR3T_VECTOR         54      //01B3H
#define     DMA_UR3R_VECTOR         55      //01BBH
#define     DMA_UR4T_VECTOR         56      //01C3H
#define     DMA_UR4R_VECTOR         57      //01CBH
#define     DMA_LCM_VECTOR          58      //01D3H
#define     LCM_VECTOR              59      //01DBH
#define     DMA_I2CT_VECTOR         60      //01E3H
#define     DMA_I2C1T_VECTOR        60      //01E3H
#define     DMA_I2CR_VECTOR         61      //01EBH
#define     DMA_I2C1R_VECTOR        61      //01EBH
#define     I2S_VECTOR              62      //01F3H
#define     I2S1_VECTOR             62      //01F3H
#define     DMA_I2ST_VECTOR         63      //01FBH
#define     DMA_I2S1T_VECTOR        63      //01FBH
#define     DMA_I2SR_VECTOR         64      //0203H
#define     DMA_I2S1R_VECTOR        64      //0203H
#define     DMA_QSPI_VECTOR         65      //020BH
#define     QSPI_VECTOR             66      //0213H
#define     TMR11_VECTOR            67      //021BH
#define     DMA_I2C2T_VECTOR        68      //0223H
#define     DMA_I2C2R_VECTOR        69      //022BH
#define     DMA_I2S2T_VECTOR        70      //0233H
#define     DMA_I2S2R_VECTOR        71      //023BH
#define     DMA_PWMAT_VECTOR        72      //0243H
#define     DMA_PWMAR_VECTOR        73      //024BH
#define     DMA_PWMCT_VECTOR        74      //0253H
#define     DMA_PWMCR_VECTOR        75      //025BH
#define     DMA_ADC2_VECTOR         76      //0263H
#define     DMA_DAC_VECTOR          77      //026BH
#define     DMA_DAC1_VECTOR         77      //026BH
#define     DMA_DAC2_VECTOR         78      //0273H
#define     DMA_SPI2_VECTOR         79      //027BH
#define     DMA_SPI3_VECTOR         80      //0283H
#define     DMA_SPI4_VECTOR         81      //028BH
#define     DMA_UR5T_VECTOR         82      //0293H
#define     DMA_UR5R_VECTOR         83      //029BH
#define     DMA_UR6T_VECTOR         84      //02A3H
#define     DMA_UR6R_VECTOR         85      //02ABH
#define     DMA_UR7T_VECTOR         86      //02B3H
#define     DMA_UR7R_VECTOR         87      //02BBH
#define     DMA_UR8T_VECTOR         88      //02C3H
#define     DMA_UR8R_VECTOR         89      //02CBH
#define     PAINT_VECTOR            90      //02D3H
#define     PBINT_VECTOR            91      //02DBH
#define     PCINT_VECTOR            92      //02E3H
#define     PDINT_VECTOR            93      //02EBH
#define     PEINT_VECTOR            94      //02F3H
#define     PFINT_VECTOR            95      //02FBH
#define     TMR5_TMR6_VECTOR        96      //0303H
#define     TMR7_TMR8_VECTOR        97      //030BH
#define     TMR9_TMR10_VECTOR       98      //0313H
#define     TMR17_TMR18_VECTOR      99      //031BH
#define     UART5_VECTOR            102     //0333H
#define     UART6_VECTOR            103     //033BH
#define     UART7_VECTOR            104     //0343H
#define     UART8_VECTOR            105     //034BH
#define     ADC2_VECTOR             106     //0353H
#define     DAC_VECTOR              107     //035BH
#define     DAC1_VECTOR             107     //035BH
#define     DAC2_VECTOR             108     //0363H
#define     I2C2_VECTOR             109     //036BH
#define     I2S2_VECTOR             110     //0373H
#define     SPI2_VECTOR             111     //037BH
#define     SPI3_VECTOR             112     //0383H
#define     SPI4_VECTOR             113     //038BH
#define     CMP2_VECTOR             114     //0393H
#define     CMP3_VECTOR             115     //039BH
#define     CMP4_VECTOR             116     //03A3H
#define     DMA_CANT_VECTOR         117     //03ABH
#define     DMA_CAN1T_VECTOR        117     //03ABH
#define     DMA_CANR_VECTOR         118     //03B3H
#define     DMA_CAN1R_VECTOR        118     //03B3H
#define     DMA_CAN2T_VECTOR        119     //03BBH
#define     DMA_CAN2R_VECTOR        120     //03C3H
#define     PWMC_VECTOR             121     //03CBH
#define     PWMD_VECTOR             122     //03D3H
#define     PWME_VECTOR             123     //03DBH
#define     PWMF_VECTOR             124     //03E3H
#define     DMA_PWMET_VECTOR        125     //03EBH
#define     DMA_PWMER_VECTOR        126     //03F3H

/////////////////////////////////////////////////

#define EAXSFR() do { P_SW2 |= 0x80U; } while (0)
#define EAXRAM() do { P_SW2 &= (unsigned char)~0x80U; } while (0)

/////////////////////////////////////////////////



/////////////////////////////////////////////////


#endif
