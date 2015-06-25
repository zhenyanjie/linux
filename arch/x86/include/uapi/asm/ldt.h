/*
 * ldt.h
 *
 * Definitions of structures used with the modify_ldt system call.
 */
#ifndef _ASM_X86_LDT_H
#define _ASM_X86_LDT_H

/* Maximum number of LDT entries supported. */
#define LDT_ENTRIES	8192
/* The size of each LDT entry. */
#define LDT_ENTRY_SIZE	8

#ifndef __ASSEMBLY__
/*
 * Note on 64bit base and limit is ignored and you cannot set DS/ES/CS
 * not to the default values if you still want to do syscalls. This
 * call is more for 32bit mode therefore.
 */
struct user_desc {
	unsigned int  entry_number;
	unsigned int  base_addr;
	unsigned int  limit;
	unsigned int  seg_32bit;
	unsigned int  contents;
	unsigned int  read_exec_only;
	unsigned int  limit_in_pages;
	unsigned int  seg_not_present;
	unsigned int  useable;
#ifdef __x86_64__
	unsigned int  lm;
#endif
};

#define MODIFY_LDT_CONTENTS_DATA	0
#define MODIFY_LDT_CONTENTS_STACK	1
#define MODIFY_LDT_CONTENTS_CODE	2

#endif /* !__ASSEMBLY__ */
#endif /* _ASM_X86_LDT_H */
