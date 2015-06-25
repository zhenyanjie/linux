#ifndef __LINUX_TC_EM_CMP_H
#define __LINUX_TC_EM_CMP_H

#include <linux/types.h>
#include <linux/pkt_cls.h>

struct tcf_em_cmp {
	__u32		val;
	__u32		mask;
	__u16		off;
	__u8		align;
	__u8		flags;
	__u8		layer;
	__u8		opnd;
};

enum {
	TCF_EM_ALIGN_U8  = 1,
	TCF_EM_ALIGN_U16 = 2,
	TCF_EM_ALIGN_U32 = 4
};

#define TCF_EM_CMP_TRANS	1

#endif
