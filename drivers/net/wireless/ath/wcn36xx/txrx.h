/*
 * Copyright (c) 2013 Eugene Krasnikov <k.eugene.e@gmail.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION
 * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _TXRX_H_
#define _TXRX_H_

#include <linux/etherdevice.h>
#include "wcn36xx.h"

/* TODO describe all properties */
#define WCN36XX_802_11_HEADER_LEN	24
#define WCN36XX_BMU_WQ_TX		25
#define WCN36XX_TID			7
/* broadcast wq ID */
#define WCN36XX_TX_B_WQ_ID		0xA
#define WCN36XX_TX_U_WQ_ID		0x9
/* bd_rate */
#define WCN36XX_BD_RATE_DATA 0
#define WCN36XX_BD_RATE_MGMT 2
#define WCN36XX_BD_RATE_CTRL 3

struct wcn36xx_pdu {
	u32	dpu_fb;
	u32	adu_fb;
	u32	pdu_id;

	/* 0x04*/
	u32	tail_pdu_idx;
	u32	head_pdu_idx;

	/* 0x08*/
	u32	pdu_count;
	u32	mpdu_data_off;
	u32	mpdu_header_off;
	u32	mpdu_header_len;

	/* 0x0c*/
	u32	reserved4;
	u32	tid;
	u32	reserved3;
	u32	mpdu_len;
};

struct wcn36xx_rx_bd {
	u32	bdt;
	u32	ft;
	u32	dpu_ne;
	u32	rx_key_id;
	u32	ub;
	u32	rmf;
	u32	uma_bypass;
	u32	csr11;
	u32	reserved0;
	u32	scan_learn;
	u32	rx_ch;
	u32	rtsf;
	u32	bsf;
	u32	a2hf;
	u32	st_auf;
	u32	dpu_sign;
	u32	dpu_rf;

	struct wcn36xx_pdu pdu;

	/* 0x14*/
	u32	addr3;
	u32	addr2;
	u32	addr1;
	u32	dpu_desc_idx;

	/* 0x18*/
	u32	rxp_flags;
	u32	rate_id;

	u32	phy_stat0;
	u32	phy_stat1;

	/* 0x24 */
	u32	rx_times;

	u32	pmi_cmd[6];

	/* 0x40 */
	u32	reserved7;
	u32	reorder_slot_id;
	u32	reorder_fwd_id;
	u32	reserved6;
	u32	reorder_code;

	/* 0x44 */
	u32	exp_seq_num;
	u32	cur_seq_num;
	u32	fr_type_subtype;

	/* 0x48 */
	u32	msdu_size;
	u32	sub_fr_id;
	u32	proc_order;
	u32	reserved9;
	u32	aef;
	u32	lsf;
	u32	esf;
	u32	asf;
};

struct wcn36xx_tx_bd {
	u32	bdt;
	u32	ft;
	u32	dpu_ne;
	u32	fw_tx_comp;
	u32	tx_comp;
	u32	reserved1;
	u32	ub;
	u32	rmf;
	u32	reserved0;
	u32	dpu_sign;
	u32	dpu_rf;

	struct wcn36xx_pdu pdu;

	/* 0x14*/
	u32	reserved5;
	u32	queue_id;
	u32	bd_rate;
	u32	ack_policy;
	u32	sta_index;
	u32	dpu_desc_idx;

	u32	tx_bd_sign;
	u32	reserved6;
	u32	dxe_start_time;
	u32	dxe_end_time;

	/*u32	tcp_udp_start_off;
	u32	header_cks;
	u32	reserved7;*/
};

struct wcn36xx_sta;
struct wcn36xx;

int  wcn36xx_rx_skb(struct wcn36xx *wcn, struct sk_buff *skb);
int wcn36xx_start_tx(struct wcn36xx *wcn,
		     struct wcn36xx_sta *sta_priv,
		     struct sk_buff *skb);

#endif	/* _TXRX_H_ */
