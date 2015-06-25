/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 ******************************************************************************/
#ifndef __RTL8723A_XMIT_H__
#define __RTL8723A_XMIT_H__

/*  */
/*  Queue Select Value in TxDesc */
/*  */
#define QSLT_BK							0x2/* 0x01 */
#define QSLT_BE							0x0
#define QSLT_VI							0x5/* 0x4 */
#define QSLT_VO							0x7/* 0x6 */
#define QSLT_BEACON						0x10
#define QSLT_HIGH						0x11
#define QSLT_MGNT						0x12
#define QSLT_CMD						0x13

/*  */
/* defined for TX DESC Operation */
/*  */

#define MAX_TID (15)

/* OFFSET 0 */
#define OFFSET_SZ	0
#define OFFSET_SHT	16
#define BMC		BIT(24)
#define LSG		BIT(26)
#define FSG		BIT(27)
#define OWN		BIT(31)


/* OFFSET 4 */
#define PKT_OFFSET_SZ	0
#define BK		BIT(6)
#define QSEL_SHT	8
#define Rate_ID_SHT	16
#define NAVUSEHDR	BIT(20)
#define PKT_OFFSET_SHT	26
#define HWPC		BIT(31)

/* OFFSET 8 */
#define AGG_EN		BIT(29)

/* OFFSET 12 */
#define SEQ_SHT		16

/* OFFSET 16 */
#define QoS		BIT(6)
#define HW_SEQ_EN	BIT(7)
#define USERATE		BIT(8)
#define DISDATAFB	BIT(10)
#define DATA_SHORT	BIT(24)
#define DATA_BW		BIT(25)

/* OFFSET 20 */
#define SGI		BIT(6)

struct txdesc_8723a {
	u32 pktlen;
	u32 offset;
	u32 bmc;
	u32 htc;
	u32 ls;
	u32 fs;
	u32 linip;
	u32 noacm;
	u32 gf;
	u32 own;

	u32 macid;
	u32 agg_en;
	u32 bk;
	u32 rd_en;
	u32 qsel;
	u32 rd_nav_ext;
	u32 lsig_txop_en;
	u32 pifs;
	u32 rate_id;
	u32 navusehdr;
	u32 en_desc_id;
	u32 sectype;
	u32 rsvd0424;
	u32 pkt_offset;	/*  unit: 8 bytes */
	u32 rsvd0431;

	u32 rts_rc;
	u32 data_rc;
	u32 rsvd0812;
	u32 bar_rty_th;
	u32 rsvd0816;
	u32 morefrag;
	u32 raw;
	u32 ccx;
	u32 ampdu_density;
	u32 bt_null;
	u32 ant_sel_a;
	u32 ant_sel_b;
	u32 tx_ant_cck;
	u32 tx_antl;
	u32 tx_ant_ht;

	u32 nextheadpage;
	u32 tailpage;
	u32 seq;
	u32 cpu_handle;
	u32 tag1;
	u32 trigger_int;
	u32 hwseq_en;

	u32 rtsrate;
	u32 ap_dcfe;
	u32 hwseq_sel;
	u32 userate;
	u32 disrtsfb;
	u32 disdatafb;
	u32 cts2self;
	u32 rtsen;
	u32 hw_rts_en;
	u32 port_id;
	u32 rsvd1615;
	u32 wait_dcts;
	u32 cts2ap_en;
	u32 data_sc;
	u32 data_stbc;
	u32 data_short;
	u32 data_bw;
	u32 rts_short;
	u32 rts_bw;
	u32 rts_sc;
	u32 vcs_stbc;

	u32 datarate;
	u32 sgi;
	u32 try_rate;
	u32 data_ratefb_lmt;
	u32 rts_ratefb_lmt;
	u32 rty_lmt_en;
	u32 data_rt_lmt;
	u32 usb_txagg_num;

	u32 txagg_a;
	u32 txagg_b;
	u32 use_max_len;
	u32 max_agg_num;
	u32 mcsg1_max_len;
	u32 mcsg2_max_len;
	u32 mcsg3_max_len;
	u32 mcs7_sgi_max_len;

	u32 checksum;	/*  TxBuffSize(PCIe)/CheckSum(USB) */
	u32 mcsg4_max_len;
	u32 mcsg5_max_len;
	u32 mcsg6_max_len;
	u32 mcs15_sgi_max_len;
};

#define txdesc_set_ccx_sw_8723a(txdesc, value) \
	do { \
		((struct txdesc_8723a *)(txdesc))->mcsg4_max_len = (((value)>>8) & 0x0f); \
		((struct txdesc_8723a *)(txdesc))->mcs15_sgi_max_len= (((value)>>4) & 0x0f); \
		((struct txdesc_8723a *)(txdesc))->mcsg6_max_len = ((value) & 0x0f); \
	} while (0)

struct txrpt_ccx_8723a {
	/* offset 0 */
	u8 tag1;
	u8 rsvd;
	u8 int_bt;
	u8 int_tri;
	u8 int_ccx;

	/* offset 1 */
	u8 mac_id;
	u8 pkt_drop;
	u8 pkt_ok;
	u8 bmc;

	/* offset 2 */
	u8 retry_cnt;
	u8 lifetime_over;
	u8 retry_over;

	/* offset 3 */
	u8 ccx_qtime0;
	u8 ccx_qtime1;

	/* offset 5 */
	u8 final_data_rate;

	/* offset 6 */
	u8 sw1;
	u8 qsel;

	/* offset 7 */
	u8 sw0;
};

#define txrpt_ccx_sw_8723a(txrpt_ccx) ((txrpt_ccx)->sw0 + ((txrpt_ccx)->sw1<<8))
#define txrpt_ccx_qtime_8723a(txrpt_ccx) ((txrpt_ccx)->ccx_qtime0+((txrpt_ccx)->ccx_qtime1<<8))

void handle_txrpt_ccx_8723a(struct rtw_adapter *adapter, void *buf);
void rtl8723a_update_txdesc(struct xmit_frame *pxmitframe, u8 *pmem);
void rtl8723a_fill_fake_txdesc(struct rtw_adapter *padapter, u8 *pDesc, u32 BufferLen, u8 IsPsPoll, u8 IsBTQosNull);

int rtl8723au_hal_xmitframe_enqueue(struct rtw_adapter *padapter, struct xmit_frame *pxmitframe);
s32 rtl8723au_xmit_buf_handler(struct rtw_adapter *padapter);
#define hal_xmit_handler rtl8723au_xmit_buf_handler
bool rtl8723au_hal_xmit(struct rtw_adapter *padapter, struct xmit_frame *pxmitframe);
int rtl8723au_mgnt_xmit(struct rtw_adapter *padapter, struct xmit_frame *pmgntframe);
bool rtl8723au_xmitframe_complete(struct rtw_adapter *padapter, struct xmit_priv *pxmitpriv, struct xmit_buf *pxmitbuf);


#endif
