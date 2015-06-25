/*
 * Thunderbolt Cactus Ridge driver - Port/Switch config area registers
 *
 * Every thunderbolt device consists (logically) of a switch with multiple
 * ports. Every port contains up to four config regions (HOPS, PORT, SWITCH,
 * COUNTERS) which are used to configure the device.
 *
 * Copyright (c) 2014 Andreas Noever <andreas.noever@gmail.com>
 */

#ifndef _TB_REGS
#define _TB_REGS

#include <linux/types.h>


#define TB_ROUTE_SHIFT 8  /* number of bits in a port entry of a route */


/*
 * TODO: should be 63? But we do not know how to receive frames larger than 256
 * bytes at the frame level. (header + checksum = 16, 60*4 = 240)
 */
#define TB_MAX_CONFIG_RW_LENGTH 60

enum tb_cap {
	TB_CAP_PHY		= 0x0001,
	TB_CAP_TIME1		= 0x0003,
	TB_CAP_PCIE		= 0x0004,
	TB_CAP_I2C		= 0x0005,
	TB_CAP_PLUG_EVENTS	= 0x0105, /* also EEPROM */
	TB_CAP_TIME2		= 0x0305,
	TB_CAL_IECS		= 0x0405,
	TB_CAP_LINK_CONTROLLER	= 0x0605, /* also IECS */
};

enum tb_port_state {
	TB_PORT_DISABLED	= 0, /* tb_cap_phy.disable == 1 */
	TB_PORT_CONNECTING	= 1, /* retry */
	TB_PORT_UP		= 2,
	TB_PORT_UNPLUGGED	= 7,
};

/* capability headers */

struct tb_cap_basic {
	u8 next;
	/* enum tb_cap cap; prevent "narrower than values of its type" */
	u8 cap; /* if cap == 0x05 then we have a extended capability */
} __packed;

struct tb_cap_extended_short {
	u8 next; /* if next and length are zero then we have a long cap */
	enum tb_cap cap;
	u8 length;
} __packed;

struct tb_cap_extended_long {
	u8 zero1;
	enum tb_cap cap;
	u8 zero2;
	u16 next;
	u16 length;
} __packed;

/* capabilities */

struct tb_cap_link_controller {
	struct tb_cap_extended_long cap_header;
	u32 count; /* number of link controllers */
	u32 unknown1;
	u32 base_offset; /*
			    * offset (into this capability) of the configuration
			    * area of the first link controller
			    */
	u32 length; /* link controller configuration area length */
	u32 unknown2; /* TODO check that length is correct */
} __packed;

struct tb_cap_phy {
	struct tb_cap_basic cap_header;
	u32 unknown1;
	u32 unknown2;
	bool disable;
	u32 unknown3;
	enum tb_port_state state;
	u32 unknown4;
} __packed;

struct tb_eeprom_ctl {
	bool clock; /* send pulse to transfer one bit */
	bool access_low; /* set to 0 before access */
	bool data_out; /* to eeprom */
	bool data_in; /* from eeprom */
	bool access_high; /* set to 1 before access */
	bool not_present; /* should be 0 */
	bool unknown1;
	bool present; /* should be 1 */
	u32 unknown2;
} __packed;

struct tb_cap_plug_events {
	struct tb_cap_extended_short cap_header;
	u32 __unknown1;
	u32 plug_events;
	u32 __unknown2;
	u32 __unknown3;
	u32 __unknown4;
	struct tb_eeprom_ctl eeprom_ctl;
	u32 __unknown5[7];
	u32 drom_offset; /* 32 bit register, but eeprom addresses are 16 bit */
} __packed;

/* device headers */

/* Present on port 0 in TB_CFG_SWITCH at address zero. */
struct tb_regs_switch_header {
	/* DWORD 0 */
	u16 vendor_id;
	u16 device_id;
	/* DWORD 1 */
	u32 first_cap_offset;
	u32 upstream_port_number;
	u32 max_port_number;
	u32 depth;
	u32 __unknown1;
	u32 revision;
	/* DWORD 2 */
	u32 route_lo;
	/* DWORD 3 */
	u32 route_hi;
	bool enabled;
	/* DWORD 4 */
	u32 plug_events_delay; /*
				  * RW, pause between plug events in
				  * milliseconds. Writing 0x00 is interpreted
				  * as 255ms.
				  */
	u32 __unknown4;
	u32 thunderbolt_version;
} __packed;

enum tb_port_type {
	TB_TYPE_INACTIVE	= 0x000000,
	TB_TYPE_PORT		= 0x000001,
	TB_TYPE_NHI		= 0x000002,
	/* TB_TYPE_ETHERNET	= 0x020000, lower order bits are not known */
	/* TB_TYPE_SATA		= 0x080000, lower order bits are not known */
	TB_TYPE_DP_HDMI_IN	= 0x0e0101,
	TB_TYPE_DP_HDMI_OUT	= 0x0e0102,
	TB_TYPE_PCIE_DOWN	= 0x100101,
	TB_TYPE_PCIE_UP		= 0x100102,
	/* TB_TYPE_USB		= 0x200000, lower order bits are not known */
};

/* Present on every port in TB_CF_PORT at address zero. */
struct tb_regs_port_header {
	/* DWORD 0 */
	u16 vendor_id;
	u16 device_id;
	/* DWORD 1 */
	u32 first_cap_offset;
	u32 max_counters;
	u32 __unknown1;
	u32 revision;
	/* DWORD 2 */
	enum tb_port_type type;
	u32 thunderbolt_version;
	/* DWORD 3 */
	u32 __unknown2;
	u32 port_number;
	u32 __unknown3;
	/* DWORD 4 */
	u32 nfc_credits;
	/* DWORD 5 */
	u32 max_in_hop_id;
	u32 max_out_hop_id;
	u32 __unkown4;
	/* DWORD 6 */
	u32 __unknown5;
	/* DWORD 7 */
	u32 __unknown6;

} __packed;

/* Hop register from TB_CFG_HOPS. 8 byte per entry. */
struct tb_regs_hop {
	/* DWORD 0 */
	u32 next_hop; /*
			  * hop to take after sending the packet through
			  * out_port (on the incoming port of the next switch)
			  */
	u32 out_port; /* next port of the path (on the same switch) */
	u32 initial_credits;
	u32 unknown1; /* set to zero */
	bool enable;

	/* DWORD 1 */
	u32 weight;
	u32 unknown2; /* set to zero */
	u32 priority;
	bool drop_packages;
	u32 counter; /* index into TB_CFG_COUNTERS on this port */
	bool counter_enable;
	bool ingress_fc;
	bool egress_fc;
	bool ingress_shared_buffer;
	bool egress_shared_buffer;
	u32 unknown3; /* set to zero */
} __packed;


#endif
