/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Numascale NumaConnect-Specific Header file
 *
 * Copyright (C) 2011 Numascale AS. All rights reserved.
 *
 * Send feedback to <support@numascale.com>
 *
 */

#ifndef _ASM_X86_NUMACHIP_NUMACHIP_CSR_H
#define _ASM_X86_NUMACHIP_NUMACHIP_CSR_H

#include <linux/numa.h>
#include <linux/percpu.h>
#include <linux/io.h>
#include <linux/swab.h>
#include <asm/types.h>
#include <asm/processor.h>

#define CSR_NODE_SHIFT		16
#define CSR_NODE_BITS(p)	(((unsigned long)(p)) << CSR_NODE_SHIFT)
#define CSR_NODE_MASK		0x0fff		/* 4K nodes */

/* 32K CSR space, b15 indicates geo/non-geo */
#define CSR_OFFSET_MASK	0x7fffUL

/* Global CSR space covers all 4K possible nodes with 64K CSR space per node */
#define NUMACHIP_GCSR_BASE	0x3fff00000000ULL
#define NUMACHIP_GCSR_LIM	0x3fff0fffffffULL
#define NUMACHIP_GCSR_SIZE	(NUMACHIP_GCSR_LIM - NUMACHIP_GCSR_BASE + 1)

/*
 * Local CSR space starts in global CSR space with "nodeid" = 0xfff0, however
 * when using the direct mapping on x86_64, both start and size needs to be
 * aligned with PMD_SIZE which is 2M
 */
#define NUMACHIP_LCSR_BASE	0x3ffffe000000ULL
#define NUMACHIP_LCSR_LIM	0x3fffffffffffULL
#define NUMACHIP_LCSR_SIZE	(NUMACHIP_LCSR_LIM - NUMACHIP_LCSR_BASE + 1)

static inline void *gcsr_address(int node, unsigned long offset)
{
	return __va(NUMACHIP_GCSR_BASE | (1UL << 15) |
		CSR_NODE_BITS(node & CSR_NODE_MASK) | (offset & CSR_OFFSET_MASK));
}

static inline void *lcsr_address(unsigned long offset)
{
	return __va(NUMACHIP_LCSR_BASE | (1UL << 15) |
		CSR_NODE_BITS(0xfff0) | (offset & CSR_OFFSET_MASK));
}

static inline unsigned int read_gcsr(int node, unsigned long offset)
{
	return swab32(readl(gcsr_address(node, offset)));
}

static inline void write_gcsr(int node, unsigned long offset, unsigned int val)
{
	writel(swab32(val), gcsr_address(node, offset));
}

static inline unsigned int read_lcsr(unsigned long offset)
{
	return swab32(readl(lcsr_address(offset)));
}

static inline void write_lcsr(unsigned long offset, unsigned int val)
{
	writel(swab32(val), lcsr_address(offset));
}

/* ========================================================================= */
/*                   CSR_G0_STATE_CLEAR                                      */
/* ========================================================================= */

#define CSR_G0_STATE_CLEAR (0x000 + (0 << 12))
union numachip_csr_g0_state_clear {
	unsigned int v;
	struct numachip_csr_g0_state_clear_s {
		unsigned int _state;
		unsigned int _rsvd_2_6;
		unsigned int _lost;
		unsigned int _rsvd_8_31;
	} s;
};

/* ========================================================================= */
/*                   CSR_G0_NODE_IDS                                         */
/* ========================================================================= */

#define CSR_G0_NODE_IDS (0x008 + (0 << 12))
union numachip_csr_g0_node_ids {
	unsigned int v;
	struct numachip_csr_g0_node_ids_s {
		unsigned int _initialid;
		unsigned int _nodeid;
		unsigned int _rsvd_28_31;
	} s;
};

/* ========================================================================= */
/*                   CSR_G3_EXT_IRQ_GEN                                      */
/* ========================================================================= */

#define CSR_G3_EXT_IRQ_GEN (0x030 + (3 << 12))
union numachip_csr_g3_ext_irq_gen {
	unsigned int v;
	struct numachip_csr_g3_ext_irq_gen_s {
		unsigned int _vector;
		unsigned int _msgtype;
		unsigned int _index;
		unsigned int _destination_apic_id;
	} s;
};

/* ========================================================================= */
/*                   CSR_G3_EXT_IRQ_STATUS                                   */
/* ========================================================================= */

#define CSR_G3_EXT_IRQ_STATUS (0x034 + (3 << 12))
union numachip_csr_g3_ext_irq_status {
	unsigned int v;
	struct numachip_csr_g3_ext_irq_status_s {
		unsigned int _result;
	} s;
};

/* ========================================================================= */
/*                   CSR_G3_EXT_IRQ_DEST                                     */
/* ========================================================================= */

#define CSR_G3_EXT_IRQ_DEST (0x038 + (3 << 12))
union numachip_csr_g3_ext_irq_dest {
	unsigned int v;
	struct numachip_csr_g3_ext_irq_dest_s {
		unsigned int _irq;
		unsigned int _rsvd_8_31;
	} s;
};

/* ========================================================================= */
/*                   CSR_G3_NC_ATT_MAP_SELECT                                */
/* ========================================================================= */

#define CSR_G3_NC_ATT_MAP_SELECT (0x7fc + (3 << 12))
union numachip_csr_g3_nc_att_map_select {
	unsigned int v;
	struct numachip_csr_g3_nc_att_map_select_s {
		unsigned int _upper_address_bits;
		unsigned int _select_ram;
		unsigned int _rsvd_8_31;
	} s;
};

/* ========================================================================= */
/*                   CSR_G3_NC_ATT_MAP_SELECT_0-255                          */
/* ========================================================================= */

#define CSR_G3_NC_ATT_MAP_SELECT_0 (0x800 + (3 << 12))

#endif /* _ASM_X86_NUMACHIP_NUMACHIP_CSR_H */

