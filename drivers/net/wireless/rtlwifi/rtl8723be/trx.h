/******************************************************************************
 *
 * Copyright(c) 2009-2014  Realtek Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * The full GNU General Public License is included in this distribution in the
 * file called LICENSE.
 *
 * Contact Information:
 * wlanfae <wlanfae@realtek.com>
 * Realtek Corporation, No. 2, Innovation Road II, Hsinchu Science Park,
 * Hsinchu 300, Taiwan.
 *
 * Larry Finger <Larry.Finger@lwfinger.net>
 *
 *****************************************************************************/

#ifndef __RTL8723BE_TRX_H__
#define __RTL8723BE_TRX_H__

#define TX_DESC_SIZE				40
#define TX_DESC_AGGR_SUBFRAME_SIZE		32

#define RX_DESC_SIZE				32
#define RX_DRV_INFO_SIZE_UNIT			8

#define	TX_DESC_NEXT_DESC_OFFSET		40
#define USB_HWDESC_HEADER_LEN			40
#define CRCLENGTH				4

#define SET_TX_DESC_PKT_SIZE(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc, 0, 16, __val)
#define SET_TX_DESC_OFFSET(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc, 16, 8, __val)
#define SET_TX_DESC_BMC(__pdesc, __val)			\
	SET_BITS_TO_LE_4BYTE(__pdesc, 24, 1, __val)
#define SET_TX_DESC_HTC(__pdesc, __val)			\
	SET_BITS_TO_LE_4BYTE(__pdesc, 25, 1, __val)
#define SET_TX_DESC_LAST_SEG(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc, 26, 1, __val)
#define SET_TX_DESC_FIRST_SEG(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc, 27, 1, __val)
#define SET_TX_DESC_LINIP(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc, 28, 1, __val)
#define SET_TX_DESC_NO_ACM(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc, 29, 1, __val)
#define SET_TX_DESC_GF(__pdesc, __val)			\
	SET_BITS_TO_LE_4BYTE(__pdesc, 30, 1, __val)
#define SET_TX_DESC_OWN(__pdesc, __val)			\
	SET_BITS_TO_LE_4BYTE(__pdesc, 31, 1, __val)

#define GET_TX_DESC_PKT_SIZE(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 0, 16)
#define GET_TX_DESC_OFFSET(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 16, 8)
#define GET_TX_DESC_BMC(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 24, 1)
#define GET_TX_DESC_HTC(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 25, 1)
#define GET_TX_DESC_LAST_SEG(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 26, 1)
#define GET_TX_DESC_FIRST_SEG(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 27, 1)
#define GET_TX_DESC_LINIP(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 28, 1)
#define GET_TX_DESC_NO_ACM(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 29, 1)
#define GET_TX_DESC_GF(__pdesc)				\
	LE_BITS_TO_4BYTE(__pdesc, 30, 1)
#define GET_TX_DESC_OWN(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 31, 1)

#define SET_TX_DESC_MACID(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+4, 0, 7, __val)
#define SET_TX_DESC_QUEUE_SEL(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+4, 8, 5, __val)
#define SET_TX_DESC_RDG_NAV_EXT(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+4, 13, 1, __val)
#define SET_TX_DESC_LSIG_TXOP_EN(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+4, 14, 1, __val)
#define SET_TX_DESC_PIFS(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+4, 15, 1, __val)
#define SET_TX_DESC_RATE_ID(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+4, 16, 5, __val)
#define SET_TX_DESC_EN_DESC_ID(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+4, 21, 1, __val)
#define SET_TX_DESC_SEC_TYPE(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+4, 22, 2, __val)
#define SET_TX_DESC_PKT_OFFSET(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+4, 24, 5, __val)


#define SET_TX_DESC_PAID(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+8, 0, 9, __val)
#define SET_TX_DESC_CCA_RTS(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+8, 10, 2, __val)
#define SET_TX_DESC_AGG_ENABLE(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+8, 12, 1, __val)
#define SET_TX_DESC_RDG_ENABLE(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+8, 13, 1, __val)
#define SET_TX_DESC_BAR_RTY_TH(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+8, 14, 2, __val)
#define SET_TX_DESC_AGG_BREAK(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+8, 16, 1, __val)
#define SET_TX_DESC_MORE_FRAG(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+8, 17, 1, __val)
#define SET_TX_DESC_RAW(__pdesc, __val)			\
	SET_BITS_TO_LE_4BYTE(__pdesc+8, 18, 1, __val)
#define SET_TX_DESC_SPE_RPT(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+8, 19, 1, __val)
#define SET_TX_DESC_AMPDU_DENSITY(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+8, 20, 3, __val)
#define SET_TX_DESC_BT_INT(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+8, 23, 1, __val)
#define SET_TX_DESC_GID(__pdesc, __val)			\
	SET_BITS_TO_LE_4BYTE(__pdesc+8, 24, 6, __val)


#define SET_TX_DESC_WHEADER_LEN(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 0, 4, __val)
#define SET_TX_DESC_CHK_EN(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 4, 1, __val)
#define SET_TX_DESC_EARLY_MODE(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 5, 1, __val)
#define SET_TX_DESC_HWSEQ_SEL(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 6, 2, __val)
#define SET_TX_DESC_USE_RATE(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 8, 1, __val)
#define SET_TX_DESC_DISABLE_RTS_FB(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 9, 1, __val)
#define SET_TX_DESC_DISABLE_FB(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 10, 1, __val)
#define SET_TX_DESC_CTS2SELF(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 11, 1, __val)
#define SET_TX_DESC_RTS_ENABLE(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 12, 1, __val)
#define SET_TX_DESC_HW_RTS_ENABLE(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 13, 1, __val)
#define SET_TX_DESC_NAV_USE_HDR(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 15, 1, __val)
#define SET_TX_DESC_USE_MAX_LEN(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 16, 1, __val)
#define SET_TX_DESC_MAX_AGG_NUM(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 17, 5, __val)
#define SET_TX_DESC_NDPA(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 22, 2, __val)
#define SET_TX_DESC_AMPDU_MAX_TIME(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+12, 24, 8, __val)


#define SET_TX_DESC_TX_RATE(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+16, 0, 7, __val)
#define SET_TX_DESC_DATA_RATE_FB_LIMIT(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+16, 8, 5, __val)
#define SET_TX_DESC_RTS_RATE_FB_LIMIT(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+16, 13, 4, __val)
#define SET_TX_DESC_RETRY_LIMIT_ENABLE(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+16, 17, 1, __val)
#define SET_TX_DESC_DATA_RETRY_LIMIT(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+16, 18, 6, __val)
#define SET_TX_DESC_RTS_RATE(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+16, 24, 5, __val)


#define SET_TX_DESC_TX_SUB_CARRIER(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+20, 0, 4, __val)
#define SET_TX_DESC_DATA_SHORTGI(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+20, 4, 1, __val)
#define SET_TX_DESC_DATA_BW(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+20, 5, 2, __val)
#define SET_TX_DESC_DATA_LDPC(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+20, 7, 1, __val)
#define SET_TX_DESC_DATA_STBC(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+20, 8, 2, __val)
#define SET_TX_DESC_CTROL_STBC(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+20, 10, 2, __val)
#define SET_TX_DESC_RTS_SHORT(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+20, 12, 1, __val)
#define SET_TX_DESC_RTS_SC(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+20, 13, 4, __val)


#define SET_TX_DESC_TX_BUFFER_SIZE(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+28, 0, 16, __val)

#define GET_TX_DESC_TX_BUFFER_SIZE(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+28, 0, 16)

#define SET_TX_DESC_HWSEQ_EN(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+32, 15, 1, __val)

#define SET_TX_DESC_SEQ(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+36, 12, 12, __val)

#define SET_TX_DESC_TX_BUFFER_ADDRESS(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+40, 0, 32, __val)

#define GET_TX_DESC_TX_BUFFER_ADDRESS(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+40, 0, 32)


#define SET_TX_DESC_NEXT_DESC_ADDRESS(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+48, 0, 32, __val)

#define GET_TX_DESC_NEXT_DESC_ADDRESS(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+48, 0, 32)

#define GET_RX_DESC_PKT_LEN(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 0, 14)
#define GET_RX_DESC_CRC32(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 14, 1)
#define GET_RX_DESC_ICV(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 15, 1)
#define GET_RX_DESC_DRV_INFO_SIZE(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc, 16, 4)
#define GET_RX_DESC_SECURITY(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 20, 3)
#define GET_RX_DESC_QOS(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 23, 1)
#define GET_RX_DESC_SHIFT(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 24, 2)
#define GET_RX_DESC_PHYST(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 26, 1)
#define GET_RX_DESC_SWDEC(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 27, 1)
#define GET_RX_DESC_LS(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 28, 1)
#define GET_RX_DESC_FS(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 29, 1)
#define GET_RX_DESC_EOR(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 30, 1)
#define GET_RX_DESC_OWN(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc, 31, 1)

#define SET_RX_DESC_PKT_LEN(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc, 0, 14, __val)
#define SET_RX_DESC_EOR(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc, 30, 1, __val)
#define SET_RX_DESC_OWN(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc, 31, 1, __val)

#define GET_RX_DESC_MACID(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 0, 7)
#define GET_RX_DESC_TID(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 8, 4)
#define GET_RX_DESC_AMSDU(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 13, 1)
#define GET_RX_STATUS_DESC_RXID_MATCH(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+4, 14, 1)
#define GET_RX_DESC_PAGGR(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 15, 1)
#define GET_RX_DESC_A1_FIT(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 16, 4)
#define GET_RX_DESC_CHKERR(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 20, 1)
#define GET_RX_DESC_IPVER(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 21, 1)
#define GET_RX_STATUS_DESC_IS_TCPUDP(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+4, 22, 1)
#define GET_RX_STATUS_DESC_CHK_VLD(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+4, 23, 1)
#define GET_RX_DESC_PAM(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 24, 1)
#define GET_RX_DESC_PWR(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 25, 1)
#define GET_RX_DESC_MD(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 26, 1)
#define GET_RX_DESC_MF(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 27, 1)
#define GET_RX_DESC_TYPE(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 28, 2)
#define GET_RX_DESC_MC(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 30, 1)
#define GET_RX_DESC_BC(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+4, 31, 1)


#define GET_RX_DESC_SEQ(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+8, 0, 12)
#define GET_RX_DESC_FRAG(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+8, 12, 4)
#define GET_RX_STATUS_DESC_RX_IS_QOS(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+8, 16, 1)
#define GET_RX_STATUS_DESC_WLANHD_IV_LEN(__pdesc)	\
	LE_BITS_TO_4BYTE(__pdesc+8, 18, 6)
#define GET_RX_STATUS_DESC_RPT_SEL(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+8, 28, 1)


#define GET_RX_DESC_RXMCS(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+12, 0, 7)
#define GET_RX_DESC_RXHT(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+12, 6, 1)
#define GET_RX_STATUS_DESC_RX_GF(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+12, 7, 1)
#define GET_RX_DESC_HTC(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+12, 10, 1)
#define GET_RX_STATUS_DESC_EOSP(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+12, 11, 1)
#define GET_RX_STATUS_DESC_BSSID_FIT(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+12, 12, 2)

#define GET_RX_STATUS_DESC_PATTERN_MATCH(__pdesc)	\
	LE_BITS_TO_4BYTE(__pdesc+12, 29, 1)
#define GET_RX_STATUS_DESC_UNICAST_MATCH(__pdesc)	\
	LE_BITS_TO_4BYTE(__pdesc+12, 30, 1)
#define GET_RX_STATUS_DESC_MAGIC_MATCH(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+12, 31, 1)

#define GET_RX_DESC_SPLCP(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+16, 0, 1)
#define GET_RX_STATUS_DESC_LDPC(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+16, 1, 1)
#define GET_RX_STATUS_DESC_STBC(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+16, 2, 1)
#define GET_RX_DESC_BW(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+16, 4, 2)

#define GET_RX_DESC_TSFL(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+20, 0, 32)

#define GET_RX_DESC_BUFF_ADDR(__pdesc)			\
	LE_BITS_TO_4BYTE(__pdesc+24, 0, 32)
#define GET_RX_DESC_BUFF_ADDR64(__pdesc)		\
	LE_BITS_TO_4BYTE(__pdesc+28, 0, 32)

#define SET_RX_DESC_BUFF_ADDR(__pdesc, __val)		\
	SET_BITS_TO_LE_4BYTE(__pdesc+24, 0, 32, __val)
#define SET_RX_DESC_BUFF_ADDR64(__pdesc, __val)	\
	SET_BITS_TO_LE_4BYTE(__pdesc+28, 0, 32, __val)


/* TX report 2 format in Rx desc*/

#define GET_RX_RPT2_DESC_PKT_LEN(__rxstatusdesc)	\
	LE_BITS_TO_4BYTE(__rxstatusdesc, 0, 9)
#define GET_RX_RPT2_DESC_MACID_VALID_1(__rxstatusdesc)	\
	LE_BITS_TO_4BYTE(__rxstatusdesc+16, 0, 32)
#define GET_RX_RPT2_DESC_MACID_VALID_2(__rxstatusdesc)	\
	LE_BITS_TO_4BYTE(__rxstatusdesc+20, 0, 32)

#define SET_EARLYMODE_PKTNUM(__paddr, __value)		\
	SET_BITS_TO_LE_4BYTE(__paddr, 0, 4, __value)
#define SET_EARLYMODE_LEN0(__paddr, __value)		\
	SET_BITS_TO_LE_4BYTE(__paddr, 4, 12, __value)
#define SET_EARLYMODE_LEN1(__paddr, __value)		\
	SET_BITS_TO_LE_4BYTE(__paddr, 16, 12, __value)
#define SET_EARLYMODE_LEN2_1(__paddr, __value)		\
	SET_BITS_TO_LE_4BYTE(__paddr, 28, 4, __value)
#define SET_EARLYMODE_LEN2_2(__paddr, __value)		\
	SET_BITS_TO_LE_4BYTE(__paddr+4, 0, 8, __value)
#define SET_EARLYMODE_LEN3(__paddr, __value)		\
	SET_BITS_TO_LE_4BYTE(__paddr+4, 8, 12, __value)
#define SET_EARLYMODE_LEN4(__paddr, __value)		\
	SET_BITS_TO_LE_4BYTE(__paddr+4, 20, 12, __value)

#define CLEAR_PCI_TX_DESC_CONTENT(__pdesc, _size)		\
do {								\
	if (_size > TX_DESC_NEXT_DESC_OFFSET)			\
		memset(__pdesc, 0, TX_DESC_NEXT_DESC_OFFSET);	\
	else							\
		memset(__pdesc, 0, _size);			\
} while (0)

struct phy_rx_agc_info_t {
	#ifdef __LITTLE_ENDIAN
		u8 gain:7, trsw;
	#else
		u8 trsw:1, gain;
	#endif
};
struct phy_status_rpt {
	struct phy_rx_agc_info_t path_agc[2];
	u8 ch_corr[2];
	u8 cck_sig_qual_ofdm_pwdb_all;
	u8 cck_agc_rpt_ofdm_cfosho_a;
	u8 cck_rpt_b_ofdm_cfosho_b;
	u8 rsvd_1;/* ch_corr_msb; */
	u8 noise_power_db_msb;
	char path_cfotail[2];
	u8 pcts_mask[2];
	char stream_rxevm[2];
	u8 path_rxsnr[2];
	u8 noise_power_db_lsb;
	u8 rsvd_2[3];
	u8 stream_csi[2];
	u8 stream_target_csi[2];
	u8 sig_evm;
	u8 rsvd_3;
#ifdef __LITTLE_ENDIAN
	u8 antsel_rx_keep_2;	/*ex_intf_flg;*/
	u8 sgi_en;
	u8 rxsc;
	u8 idle_long;
	u8 r_ant_train_en;
	u8 ant_sel_b;
	u8 ant_sel;
#else	/* _BIG_ENDIAN_	*/
	u8 ant_sel;
	u8 ant_sel_b;
	u8 r_ant_train_en;
	u8 idle_long;
	u8 rxsc;
	u8 sgi_en;
	u8 antsel_rx_keep_2;	/*ex_intf_flg;*/
#endif
} __packed;

struct rx_fwinfo_8723be {
	u8 gain_trsw[4];
	u8 pwdb_all;
	u8 cfosho[4];
	u8 cfotail[4];
	char rxevm[2];
	char rxsnr[4];
	u8 pdsnr[2];
	u8 csi_current[2];
	u8 csi_target[2];
	u8 sigevm;
	u8 max_ex_pwr;
	u8 ex_intf_flag;
	u8 sgi_en;
	u8 rxsc;
	u8 reserve;
} __packed;

struct tx_desc_8723be {
	u32 pktsize;
	u32 offset;
	u32 bmc;
	u32 htc;
	u32 lastseg;
	u32 firstseg;
	u32 linip;
	u32 noacm;
	u32 gf;
	u32 own;

	u32 macid;
	u32 rsvd0;
	u32 queuesel;
	u32 rd_nav_ext;
	u32 lsig_txop_en;
	u32 pifs;
	u32 rateid;
	u32 nav_usehdr;
	u32 en_descid;
	u32 sectype;
	u32 pktoffset;

	u32 rts_rc;
	u32 data_rc;
	u32 agg_en;
	u32 rdg_en;
	u32 bar_retryht;
	u32 agg_break;
	u32 morefrag;
	u32 raw;
	u32 ccx;
	u32 ampdudensity;
	u32 bt_int;
	u32 ant_sela;
	u32 ant_selb;
	u32 txant_cck;
	u32 txant_l;
	u32 txant_ht;

	u32 nextheadpage;
	u32 tailpage;
	u32 seq;
	u32 cpu_handle;
	u32 tag1;
	u32 trigger_int;
	u32 hwseq_en;

	u32 rtsrate;
	u32 apdcfe;
	u32 qos;
	u32 hwseq_ssn;
	u32 userrate;
	u32 dis_rtsfb;
	u32 dis_datafb;
	u32 cts2self;
	u32 rts_en;
	u32 hwrts_en;
	u32 portid;
	u32 pwr_status;
	u32 waitdcts;
	u32 cts2ap_en;
	u32 txsc;
	u32 stbc;
	u32 txshort;
	u32 txbw;
	u32 rtsshort;
	u32 rtsbw;
	u32 rtssc;
	u32 rtsstbc;

	u32 txrate;
	u32 shortgi;
	u32 ccxt;
	u32 txrate_fb_lmt;
	u32 rtsrate_fb_lmt;
	u32 retrylmt_en;
	u32 txretrylmt;
	u32 usb_txaggnum;

	u32 txagca;
	u32 txagcb;
	u32 usemaxlen;
	u32 maxaggnum;
	u32 mcsg1maxlen;
	u32 mcsg2maxlen;
	u32 mcsg3maxlen;
	u32 mcs7sgimaxlen;

	u32 txbuffersize;
	u32 sw_offset30;
	u32 sw_offset31;
	u32 rsvd1;
	u32 antsel_c;
	u32 null_0;
	u32 null_1;

	u32 txbuffaddr;
	u32 txbufferaddr64;
	u32 nextdescaddress;
	u32 nextdescaddress64;

	u32 reserve_pass_pcie_mm_limit[4];
} __packed;

struct rx_desc_8723be {
	u32 length;
	u32 crc32;
	u32 icverror;
	u32 drv_infosize;
	u32 security;
	u32 qos;
	u32 shift;
	u32 phystatus;
	u32 swdec;
	u32 lastseg;
	u32 firstseg;
	u32 eor;
	u32 own;

	u32 macid;
	u32 tid;
	u32 hwrsvd;
	u32 paggr;
	u32 faggr;
	u32 a1_fit;
	u32 a2_fit;
	u32 pam;
	u32 pwr;
	u32 moredata;
	u32 morefrag;
	u32 type;
	u32 mc;
	u32 bc;

	u32 seq;
	u32 frag;
	u32 nextpktlen;
	u32 nextind;
	u32 rsvd;

	u32 rxmcs;
	u32 rxht;
	u32 amsdu;
	u32 splcp;
	u32 bandwidth;
	u32 htc;
	u32 tcpchk_rpt;
	u32 ipcchk_rpt;
	u32 tcpchk_valid;
	u32 hwpcerr;
	u32 hwpcind;
	u32 iv0;

	u32 iv1;

	u32 tsfl;

	u32 bufferaddress;
	u32 bufferaddress64;

} __packed;

void rtl8723be_tx_fill_desc(struct ieee80211_hw *hw,
			    struct ieee80211_hdr *hdr, u8 *pdesc,
			    u8 *pbd_desc_tx, struct ieee80211_tx_info *info,
			    struct ieee80211_sta *sta, struct sk_buff *skb,
			    u8 hw_queue, struct rtl_tcb_desc *ptcb_desc);
bool rtl8723be_rx_query_desc(struct ieee80211_hw *hw,
			     struct rtl_stats *status,
			     struct ieee80211_rx_status *rx_status,
			     u8 *pdesc, struct sk_buff *skb);
void rtl8723be_set_desc(struct ieee80211_hw *hw, u8 *pdesc, bool istx,
			u8 desc_name, u8 *val);
u32 rtl8723be_get_desc(u8 *pdesc, bool istx, u8 desc_name);
bool rtl8723be_is_tx_desc_closed(struct ieee80211_hw *hw,
				 u8 hw_queue, u16 index);
void rtl8723be_tx_polling(struct ieee80211_hw *hw, u8 hw_queue);
void rtl8723be_tx_fill_cmddesc(struct ieee80211_hw *hw, u8 *pdesc,
			       bool b_firstseg, bool b_lastseg,
			       struct sk_buff *skb);
#endif
