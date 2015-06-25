/*******************************************************************************
  Header File to describe the DMA descriptors.
  Enhanced descriptors have been in case of DWMAC1000 Cores.

  This program is free software; you can redistribute it and/or modify it
  under the terms and conditions of the GNU General Public License,
  version 2, as published by the Free Software Foundation.

  This program is distributed in the hope it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.

  The full GNU General Public License is included in this distribution in
  the file called "COPYING".

  Author: Giuseppe Cavallaro <peppe.cavallaro@st.com>
*******************************************************************************/

#ifndef __DESCS_H__
#define __DESCS_H__

/* Basic descriptor structure for normal and alternate descriptors */
struct dma_desc {
	/* Receive descriptor */
	union {
		struct {
			/* RDES0 */
			u32 payload_csum_error;
			u32 crc_error;
			u32 dribbling;
			u32 mii_error;
			u32 receive_watchdog;
			u32 frame_type;
			u32 collision;
			u32 ipc_csum_error;
			u32 last_descriptor;
			u32 first_descriptor;
			u32 vlan_tag;
			u32 overflow_error;
			u32 length_error;
			u32 sa_filter_fail;
			u32 descriptor_error;
			u32 error_summary;
			u32 frame_length;
			u32 da_filter_fail;
			u32 own;
			/* RDES1 */
			u32 buffer1_size;
			u32 buffer2_size;
			u32 reserved1;
			u32 second_address_chained;
			u32 end_ring;
			u32 reserved2;
			u32 disable_ic;

		} rx;
		struct {
			/* RDES0 */
			u32 rx_mac_addr;
			u32 crc_error;
			u32 dribbling;
			u32 error_gmii;
			u32 receive_watchdog;
			u32 frame_type;
			u32 late_collision;
			u32 ipc_csum_error;
			u32 last_descriptor;
			u32 first_descriptor;
			u32 vlan_tag;
			u32 overflow_error;
			u32 length_error;
			u32 sa_filter_fail;
			u32 descriptor_error;
			u32 error_summary;
			u32 frame_length;
			u32 da_filter_fail;
			u32 own;
			/* RDES1 */
			u32 buffer1_size;
			u32 reserved1;
			u32 second_address_chained;
			u32 end_ring;
			u32 buffer2_size;
			u32 reserved2;
			u32 disable_ic;
		} erx;		/* -- enhanced -- */

		/* Transmit descriptor */
		struct {
			/* TDES0 */
			u32 deferred;
			u32 underflow_error;
			u32 excessive_deferral;
			u32 collision_count;
			u32 vlan_frame;
			u32 excessive_collisions;
			u32 late_collision;
			u32 no_carrier;
			u32 loss_carrier;
			u32 payload_error;
			u32 frame_flushed;
			u32 jabber_timeout;
			u32 error_summary;
			u32 ip_header_error;
			u32 time_stamp_status;
			u32 reserved1;
			u32 own;
			/* TDES1 */
			u32 buffer1_size;
			u32 buffer2_size;
			u32 time_stamp_enable;
			u32 disable_padding;
			u32 second_address_chained;
			u32 end_ring;
			u32 crc_disable;
			u32 checksum_insertion;
			u32 first_segment;
			u32 last_segment;
			u32 interrupt;
		} tx;
		struct {
			/* TDES0 */
			u32 deferred;
			u32 underflow_error;
			u32 excessive_deferral;
			u32 collision_count;
			u32 vlan_frame;
			u32 excessive_collisions;
			u32 late_collision;
			u32 no_carrier;
			u32 loss_carrier;
			u32 payload_error;
			u32 frame_flushed;
			u32 jabber_timeout;
			u32 error_summary;
			u32 ip_header_error;
			u32 time_stamp_status;
			u32 reserved1;
			u32 second_address_chained;
			u32 end_ring;
			u32 checksum_insertion;
			u32 reserved2;
			u32 time_stamp_enable;
			u32 disable_padding;
			u32 crc_disable;
			u32 first_segment;
			u32 last_segment;
			u32 interrupt;
			u32 own;
			/* TDES1 */
			u32 buffer1_size;
			u32 reserved3;
			u32 buffer2_size;
			u32 reserved4;
		} etx;		/* -- enhanced -- */
	} des01;
	unsigned int des2;
	unsigned int des3;
};

/* Extended descriptor structure (supported by new SYNP GMAC generations) */
struct dma_extended_desc {
	struct dma_desc basic;
	union {
		struct {
			u32 ip_payload_type;
			u32 ip_hdr_err;
			u32 ip_payload_err;
			u32 ip_csum_bypassed;
			u32 ipv4_pkt_rcvd;
			u32 ipv6_pkt_rcvd;
			u32 msg_type;
			u32 ptp_frame_type;
			u32 ptp_ver;
			u32 timestamp_dropped;
			u32 reserved;
			u32 av_pkt_rcvd;
			u32 av_tagged_pkt_rcvd;
			u32 vlan_tag_priority_val;
			u32 reserved3;
			u32 l3_filter_match;
			u32 l4_filter_match;
			u32 l3_l4_filter_no_match;
			u32 reserved4;
		} erx;
		struct {
			u32 reserved;
		} etx;
	} des4;
	unsigned int des5;	/* Reserved */
	unsigned int des6;	/* Tx/Rx Timestamp Low */
	unsigned int des7;	/* Tx/Rx Timestamp High */
};

/* Transmit checksum insertion control */
enum tdes_csum_insertion {
	cic_disabled = 0,	/* Checksum Insertion Control */
	cic_only_ip = 1,	/* Only IP header */
	/* IP header but pseudoheader is not calculated */
	cic_no_pseudoheader = 2,
	cic_full = 3,		/* IP header and pseudoheader */
};

/* Extended RDES4 definitions */
#define RDES_EXT_NO_PTP			0
#define RDES_EXT_SYNC			0x1
#define RDES_EXT_FOLLOW_UP		0x2
#define RDES_EXT_DELAY_REQ		0x3
#define RDES_EXT_DELAY_RESP		0x4
#define RDES_EXT_PDELAY_REQ		0x5
#define RDES_EXT_PDELAY_RESP		0x6
#define RDES_EXT_PDELAY_FOLLOW_UP	0x7

#endif /* __DESCS_H__ */
