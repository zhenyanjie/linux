/*
 * Orb related data structures.
 *
 * Copyright IBM Corp. 2007, 2011
 *
 * Author(s): Cornelia Huck <cornelia.huck@de.ibm.com>
 *	      Peter Oberparleiter <peter.oberparleiter@de.ibm.com>
 *	      Sebastian Ott <sebott@linux.vnet.ibm.com>
 */

#ifndef S390_ORB_H
#define S390_ORB_H

/*
 * Command-mode operation request block
 */
struct cmd_orb {
	u32 intparm;	/* interruption parameter */
	u32 key;	/* flags, like key, suspend control, etc. */
	u32 spnd;	/* suspend control */
	u32 res1;	/* reserved */
	u32 mod;	/* modification control */
	u32 sync;	/* synchronize control */
	u32 fmt;	/* format control */
	u32 pfch;	/* prefetch control */
	u32 isic;	/* initial-status-interruption control */
	u32 alcc;	/* address-limit-checking control */
	u32 ssic;	/* suppress-suspended-interr. control */
	u32 res2;	/* reserved */
	u32 c64;	/* IDAW/QDIO 64 bit control  */
	u32 i2k;	/* IDAW 2/4kB block size control */
	u32 lpm;	/* logical path mask */
	u32 ils;	/* incorrect length */
	u32 zero;	/* reserved zeros */
	u32 orbx;	/* ORB extension control */
	u32 cpa;	/* channel program address */
}  __packed __aligned(4);

/*
 * Transport-mode operation request block
 */
struct tm_orb {
	u32 intparm;
	u32 key;
	u32:8;
	u32 b;
	u32:8;
	u32 lpm;
	u32:8;
	u32 x;
	u32 tcw;
	u32 prio;
	u32:8;
	u32 rsvpgm;
	u32:8;
	u32:8;
	u32:8;
	u32:8;
	u32:8;
}  __packed __aligned(4);

/*
 * eadm operation request block
 */
struct eadm_orb {
	u32 intparm;
	u32 key;
	u32:8;
	u32 compat1;
	u32 compat2;
	u32:8;
	u32 x;
	u32 aob;
	u32 css_prio;
	u32:8;
	u32 scm_prio;
	u32:8;
	u32:8;
	u32 fmt;
	u32:8;
	u32:8;
	u32:8;
}  __packed __aligned(4);

union orb {
	struct cmd_orb cmd;
	struct tm_orb tm;
	struct eadm_orb eadm;
}  __packed __aligned(4);

#endif /* S390_ORB_H */
