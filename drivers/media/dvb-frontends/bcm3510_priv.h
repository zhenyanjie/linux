/*
 * Support for the Broadcom BCM3510 ATSC demodulator (1st generation Air2PC)
 *
 *  Copyright (C) 2001-5, B2C2 inc.
 *
 *  GPL/Linux driver written by Patrick Boettcher <patrick.boettcher@desy.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#ifndef __BCM3510_PRIV_H__
#define __BCM3510_PRIV_H__

#define PACKED __attribute__((packed))

#undef err
#define err(format, arg...)  printk(KERN_ERR     "bcm3510: " format "\n" , ## arg)
#undef info
#define info(format, arg...) printk(KERN_INFO    "bcm3510: " format "\n" , ## arg)
#undef warn
#define warn(format, arg...) printk(KERN_WARNING "bcm3510: " format "\n" , ## arg)


#define PANASONIC_FIRST_IF_BASE_IN_KHz  1407500
#define BCM3510_SYMBOL_RATE             5381000

typedef union {
	u8 raw;

	struct {
		u8 CTL   ;
	} TSTCTL_2e;

	u8 LDCERC_4e;
	u8 LDUERC_4f;
	u8 LD_BER0_65;
	u8 LD_BER1_66;
	u8 LD_BER2_67;
	u8 LD_BER3_68;

	struct {
		u8 RESET ;
		u8 IDLE  ;
		u8 STOP  ;
		u8 HIRQ0 ;
		u8 HIRQ1 ;
		u8 na0   ;
		u8 HABAV ;
		u8 na1   ;
	} HCTL1_a0;

	struct {
		u8 na0    ;
		u8 IDLMSK ;
		u8 STMSK  ;
		u8 I0MSK  ;
		u8 I1MSK  ;
		u8 na1    ;
		u8 HABMSK ;
		u8 na2    ;
	} HCTLMSK_a1;

	struct {
		u8 RESET  ;
		u8 IDLE   ;
		u8 STOP   ;
		u8 RUN    ;
		u8 HABAV  ;
		u8 MEMAV  ;
		u8 ALDONE ;
		u8 REIRQ  ;
	} APSTAT1_a2;

	struct {
		u8 RSTMSK ;
		u8 IMSK   ;
		u8 SMSK   ;
		u8 RMSK   ;
		u8 HABMSK ;
		u8 MAVMSK ;
		u8 ALDMSK ;
		u8 REMSK  ;
	} APMSK1_a3;

	u8 APSTAT2_a4;
	u8 APMSK2_a5;

	struct {
		u8 HABADR ;
		u8 na     ;
	} HABADR_a6;

	u8 HABDATA_a7;

	struct {
		u8 HABR   ;
		u8 LDHABR ;
		u8 APMSK  ;
		u8 HMSK   ;
		u8 LDMSK  ;
		u8 na     ;
	} HABSTAT_a8;

	u8 MADRH_a9;
	u8 MADRL_aa;
	u8 MDATA_ab;

	struct {
#define JDEC_WAIT_AT_RAM      0x7
#define JDEC_EEPROM_LOAD_WAIT 0x4
		u8 JDEC   ;
		u8 na     ;
	} JDEC_ca;

	struct {
		u8 REV   ;
		u8 LAYER ;
	} REVID_e0;

	struct {
		u8 unk0   ;
		u8 CNTCTL ;
		u8 BITCNT ;
		u8 unk1   ;
		u8 RESYNC ;
		u8 unk2   ;
	} BERCTL_fa;

	struct {
		u8 CSEL0  ;
		u8 CLKED0 ;
		u8 CSEL1  ;
		u8 CLKED1 ;
		u8 CLKLEV ;
		u8 SPIVAR ;
		u8 na     ;
	} TUNSET_fc;

	struct {
		u8 CLK    ;
		u8 DATA   ;
		u8 CS0    ;
		u8 CS1    ;
		u8 AGCSEL ;
		u8 na0    ;
		u8 TUNSEL ;
		u8 na1    ;
	} TUNCTL_fd;

	u8 TUNSEL0_fe;
	u8 TUNSEL1_ff;

} bcm3510_register_value;

/* HAB commands */

/* version */
#define CMD_GET_VERSION_INFO   0x3D
#define MSGID_GET_VERSION_INFO 0x15
struct bcm3510_hab_cmd_get_version_info {
	u8 microcode_version;
	u8 script_version;
	u8 config_version;
	u8 demod_version;
} PACKED;

#define BCM3510_DEF_MICROCODE_VERSION 0x0E
#define BCM3510_DEF_SCRIPT_VERSION    0x06
#define BCM3510_DEF_CONFIG_VERSION    0x01
#define BCM3510_DEF_DEMOD_VERSION     0xB1

/* acquire */
#define CMD_ACQUIRE            0x38

#define MSGID_EXT_TUNER_ACQUIRE 0x0A
struct bcm3510_hab_cmd_ext_acquire {
	struct {
		u8 MODE      ;
		u8 BW        ;
		u8 FA        ;
		u8 NTSCSWEEP ;
		u8 OFFSET    ;
	} PACKED ACQUIRE0; /* control_byte */

	struct {
		u8 IF_FREQ  ;
		u8 zero0    ;
		u8 SYM_RATE ;
		u8 zero1    ;
	} PACKED ACQUIRE1; /* sym_if */

	u8 IF_OFFSET0;   /* IF_Offset_10hz */
	u8 IF_OFFSET1;
	u8 SYM_OFFSET0;  /* SymbolRateOffset */
	u8 SYM_OFFSET1;
	u8 NTSC_OFFSET0; /* NTSC_Offset_10hz */
	u8 NTSC_OFFSET1;
} PACKED;

#define MSGID_INT_TUNER_ACQUIRE 0x0B
struct bcm3510_hab_cmd_int_acquire {
	struct {
		u8 MODE      ;
		u8 BW        ;
		u8 FA        ;
		u8 NTSCSWEEP ;
		u8 OFFSET    ;
	} PACKED ACQUIRE0; /* control_byte */

	struct {
		u8 IF_FREQ  ;
		u8 zero0    ;
		u8 SYM_RATE ;
		u8 zero1    ;
	} PACKED ACQUIRE1; /* sym_if */

	u8 TUNER_FREQ0;
	u8 TUNER_FREQ1;
	u8 TUNER_FREQ2;
	u8 TUNER_FREQ3;
	u8 IF_OFFSET0;   /* IF_Offset_10hz */
	u8 IF_OFFSET1;
	u8 SYM_OFFSET0;  /* SymbolRateOffset */
	u8 SYM_OFFSET1;
	u8 NTSC_OFFSET0; /* NTSC_Offset_10hz */
	u8 NTSC_OFFSET1;
} PACKED;

/* modes */
#define BCM3510_QAM16           =   0x01
#define BCM3510_QAM32           =   0x02
#define BCM3510_QAM64           =   0x03
#define BCM3510_QAM128          =   0x04
#define BCM3510_QAM256          =   0x05
#define BCM3510_8VSB            =   0x0B
#define BCM3510_16VSB           =   0x0D

/* IF_FREQS */
#define BCM3510_IF_TERRESTRIAL 0x0
#define BCM3510_IF_CABLE       0x1
#define BCM3510_IF_USE_CMD     0x7

/* SYM_RATE */
#define BCM3510_SR_8VSB        0x0 /* 5381119 s/sec */
#define BCM3510_SR_256QAM      0x1 /* 5360537 s/sec */
#define BCM3510_SR_16QAM       0x2 /* 5056971 s/sec */
#define BCM3510_SR_MISC        0x3 /* 5000000 s/sec */
#define BCM3510_SR_USE_CMD     0x7

/* special symbol rate */
#define CMD_SET_VALUE_NOT_LISTED  0x2d
#define MSGID_SET_SYMBOL_RATE_NOT_LISTED 0x0c
struct bcm3510_hab_cmd_set_sr_not_listed {
	u8 HOST_SYM_RATE0;
	u8 HOST_SYM_RATE1;
	u8 HOST_SYM_RATE2;
	u8 HOST_SYM_RATE3;
} PACKED;

/* special IF */
#define MSGID_SET_IF_FREQ_NOT_LISTED 0x0d
struct bcm3510_hab_cmd_set_if_freq_not_listed {
	u8 HOST_IF_FREQ0;
	u8 HOST_IF_FREQ1;
	u8 HOST_IF_FREQ2;
	u8 HOST_IF_FREQ3;
} PACKED;

/* auto reacquire */
#define CMD_AUTO_PARAM       0x2a
#define MSGID_AUTO_REACQUIRE 0x0e
struct bcm3510_hab_cmd_auto_reacquire {
	u8 ACQ    ; /* on/off*/
	u8 unused ;
} PACKED;

#define MSGID_SET_RF_AGC_SEL 0x12
struct bcm3510_hab_cmd_set_agc {
	u8 LVL    ;
	u8 unused ;
	u8 SEL    ;
} PACKED;

#define MSGID_SET_AUTO_INVERSION 0x14
struct bcm3510_hab_cmd_auto_inversion {
	u8 AI     ;
	u8 unused ;
} PACKED;


/* bert control */
#define CMD_STATE_CONTROL  0x12
#define MSGID_BERT_CONTROL 0x0e
#define MSGID_BERT_SET     0xfa
struct bcm3510_hab_cmd_bert_control {
	u8 BE     ;
	u8 unused ;
} PACKED;

#define MSGID_TRI_STATE 0x2e
struct bcm3510_hab_cmd_tri_state {
	u8 RE ; /* a/d ram port pins */
	u8 PE ; /* baud clock pin */
	u8 AC ; /* a/d clock pin */
	u8 BE ; /* baud clock pin */
	u8 unused ;
} PACKED;


/* tune */
#define CMD_TUNE   0x38
#define MSGID_TUNE 0x16
struct bcm3510_hab_cmd_tune_ctrl_data_pair {
	struct {
#define BITS_8 0x07
#define BITS_7 0x06
#define BITS_6 0x05
#define BITS_5 0x04
#define BITS_4 0x03
#define BITS_3 0x02
#define BITS_2 0x01
#define BITS_1 0x00
		u8 size    ;
		u8 unk     ;
		u8 clk_off ;
		u8 cs0     ;
		u8 cs1     ;

	} PACKED ctrl;

	u8 data;
} PACKED;

struct bcm3510_hab_cmd_tune {
	u8 length;
	u8 clock_width;
	u8 misc;
	u8 TUNCTL_state;

	struct bcm3510_hab_cmd_tune_ctrl_data_pair ctl_dat[16];
} PACKED;

#define CMD_STATUS    0x38
#define MSGID_STATUS1 0x08
struct bcm3510_hab_cmd_status1 {
	struct {
		u8 EQ_MODE       ;
		u8 reserved      ;
		u8 QRE           ; /* if QSE and the spectrum is inversed */
		u8 QSE           ; /* automatic spectral inversion */
	} PACKED STATUS0;

	struct {
		u8 RECEIVER_LOCK ;
		u8 FEC_LOCK      ;
		u8 OUT_PLL_LOCK  ;
		u8 reserved      ;
	} PACKED STATUS1;

	struct {
		u8 reserved      ;
		u8 BW            ;
		u8 NTE           ; /* NTSC filter sweep enabled */
		u8 AQI           ; /* currently acquiring */
		u8 FA            ; /* fast acquisition */
		u8 ARI           ; /* auto reacquire */
		u8 TI            ; /* programming the tuner */
	} PACKED STATUS2;
	u8 STATUS3;
	u8 SNR_EST0;
	u8 SNR_EST1;
	u8 TUNER_FREQ0;
	u8 TUNER_FREQ1;
	u8 TUNER_FREQ2;
	u8 TUNER_FREQ3;
	u8 SYM_RATE0;
	u8 SYM_RATE1;
	u8 SYM_RATE2;
	u8 SYM_RATE3;
	u8 SYM_OFFSET0;
	u8 SYM_OFFSET1;
	u8 SYM_ERROR0;
	u8 SYM_ERROR1;
	u8 IF_FREQ0;
	u8 IF_FREQ1;
	u8 IF_FREQ2;
	u8 IF_FREQ3;
	u8 IF_OFFSET0;
	u8 IF_OFFSET1;
	u8 IF_ERROR0;
	u8 IF_ERROR1;
	u8 NTSC_FILTER0;
	u8 NTSC_FILTER1;
	u8 NTSC_FILTER2;
	u8 NTSC_FILTER3;
	u8 NTSC_OFFSET0;
	u8 NTSC_OFFSET1;
	u8 NTSC_ERROR0;
	u8 NTSC_ERROR1;
	u8 INT_AGC_LEVEL0;
	u8 INT_AGC_LEVEL1;
	u8 EXT_AGC_LEVEL0;
	u8 EXT_AGC_LEVEL1;
} PACKED;

#define MSGID_STATUS2 0x14
struct bcm3510_hab_cmd_status2 {
	struct {
		u8 EQ_MODE  ;
		u8 reserved ;
		u8 QRE      ;
		u8 QSR      ;
	} PACKED STATUS0;
	struct {
		u8 RL       ;
		u8 FL       ;
		u8 OL       ;
		u8 reserved ;
	} PACKED STATUS1;
	u8 SYMBOL_RATE0;
	u8 SYMBOL_RATE1;
	u8 SYMBOL_RATE2;
	u8 SYMBOL_RATE3;
	u8 LDCERC0;
	u8 LDCERC1;
	u8 LDCERC2;
	u8 LDCERC3;
	u8 LDUERC0;
	u8 LDUERC1;
	u8 LDUERC2;
	u8 LDUERC3;
	u8 LDBER0;
	u8 LDBER1;
	u8 LDBER2;
	u8 LDBER3;
	struct {
		u8 MODE_TYPE ; /* acquire mode 0 */
		u8 reservd   ;
	} MODE_TYPE;
	u8 SNR_EST0;
	u8 SNR_EST1;
	u8 SIGNAL;
} PACKED;

#define CMD_SET_RF_BW_NOT_LISTED   0x3f
#define MSGID_SET_RF_BW_NOT_LISTED 0x11
/* TODO */

#endif
