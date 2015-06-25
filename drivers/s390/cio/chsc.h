#ifndef S390_CHSC_H
#define S390_CHSC_H

#include <linux/types.h>
#include <linux/device.h>
#include <asm/css_chars.h>
#include <asm/chpid.h>
#include <asm/chsc.h>
#include <asm/schid.h>
#include <asm/qdio.h>

#define CHSC_SDA_OC_MSS   0x2

#define NR_MEASUREMENT_CHARS 5
struct cmg_chars {
	u32 values[NR_MEASUREMENT_CHARS];
} __attribute__ ((packed));

#define NR_MEASUREMENT_ENTRIES 8
struct cmg_entry {
	u32 values[NR_MEASUREMENT_ENTRIES];
} __attribute__ ((packed));

struct channel_path_desc_fmt1 {
	u8 flags;
	u8 lsn;
	u8 desc;
	u8 chpid;
	u32:8;
	u8 chpp;
	u32 unused[2];
	u16 chid;
	u32:8;
	u16 mdc;
	u16;
	u8 r;
	u8 s;
	u8 f;
	u32 zeros[2];
} __attribute__ ((packed));

struct channel_path;

struct css_chsc_char {
	u64 res;
	u64 : 20;
	u32 secm : 1; /* bit 84 */
	u32 : 1;
	u32 scmc : 1; /* bit 86 */
	u32 : 20;
	u32 scssc : 1;  /* bit 107 */
	u32 scsscf : 1; /* bit 108 */
	u32:8;
	u32 pnso; /* bit 116 */
	u32:8;
}__attribute__((packed));

extern struct css_chsc_char css_chsc_characteristics;

struct chsc_ssd_info {
	u8 path_mask;
	u8 fla_valid_mask;
	struct chp_id chpid[8];
	u16 fla[8];
};

struct chsc_ssqd_area {
	struct chsc_header request;
	u16;
	u8 ssid;
	u8 fmt;
	u16 first_sch;
	u16;
	u16 last_sch;
	u32:8;
	struct chsc_header response;
	u32:8;
	struct qdio_ssqd_desc qdio_ssqd;
} __packed;

struct chsc_scssc_area {
	struct chsc_header request;
	u16 operation_code;
	u16;
	u32:8;
	u32:8;
	u64 summary_indicator_addr;
	u64 subchannel_indicator_addr;
	u32 ks;
	u32 kc;
	u32:8;
	u32 isc;
	u32 word_with_d_bit;
	u32:8;
	struct subchannel_id schid;
	u32 reserved[1004];
	struct chsc_header response;
	u32:8;
} __packed;

struct chsc_scpd {
	struct chsc_header request;
	u32:8;
	u32 m;
	u32 c;
	u32 fmt;
	u32 cssid;
	u32:8;
	u32 rfmt;
	u32 first_chpid;
	u32:8;
	u32 last_chpid;
	u32 zeroes1;
	struct chsc_header response;
	u8 data[PAGE_SIZE - 20];
} __attribute__ ((packed));


extern int chsc_get_ssd_info(struct subchannel_id schid,
			     struct chsc_ssd_info *ssd);
extern int chsc_determine_css_characteristics(void);
extern int chsc_init(void);
extern void chsc_init_cleanup(void);

extern int chsc_enable_facility(int);
struct channel_subsystem;
extern int chsc_secm(struct channel_subsystem *, int);
int __chsc_do_secm(struct channel_subsystem *css, int enable);

int chsc_chp_vary(struct chp_id chpid, int on);
int chsc_determine_channel_path_desc(struct chp_id chpid, int fmt, int rfmt,
				     int c, int m, void *page);
int chsc_determine_base_channel_path_desc(struct chp_id chpid,
					  struct channel_path_desc *desc);
int chsc_determine_fmt1_channel_path_desc(struct chp_id chpid,
					  struct channel_path_desc_fmt1 *desc);
void chsc_chp_online(struct chp_id chpid);
void chsc_chp_offline(struct chp_id chpid);
int chsc_get_channel_measurement_chars(struct channel_path *chp);
int chsc_ssqd(struct subchannel_id schid, struct chsc_ssqd_area *ssqd);
int chsc_sadc(struct subchannel_id schid, struct chsc_scssc_area *scssc,
	      u64 summary_indicator_addr, u64 subchannel_indicator_addr);
int chsc_error_from_response(int response);

int chsc_siosl(struct subchannel_id schid);

/* Functions and definitions to query storage-class memory. */
struct sale {
	u64 sa;
	u32 p;
	u32 op_state;
	u32 data_state;
	u32 rank;
	u32 r;
	u32:8;
	u32 rid;
	u32:8;
} __packed;

struct chsc_scm_info {
	struct chsc_header request;
	u32:8;
	u64 reqtok;
	u32 reserved1[4];
	struct chsc_header response;
	u64:8;
	u8 rq;
	u32 mbc;
	u64 msa;
	u16 is;
	u16 mmc;
	u32 mci;
	u64 nr_scm_ini;
	u64 nr_scm_unini;
	u32 reserved2[10];
	u64 restok;
	struct sale scmal[248];
} __packed;

int chsc_scm_info(struct chsc_scm_info *scm_area, u64 token);

struct chsc_brinfo_resume_token {
	u64 t1;
	u64 t2;
} __packed;

struct chsc_brinfo_naihdr {
	struct chsc_brinfo_resume_token resume_token;
	u32:8;
	u32 instance;
	u32:8;
	u8 naids;
	u32 reserved[3];
} __packed;

struct chsc_pnso_area {
	struct chsc_header request;
	u8:8;
	u8 m;
	u8:8;
	u8:8;
	u8 ssid;
	u8 fmt;
	u16 sch;
	u8:8;
	u8 cssid;
	u16;
	u8 oc;
	u32:8;
	struct chsc_brinfo_resume_token resume_token;
	u32 n;
	u32:8;
	u32 reserved[3];
	struct chsc_header response;
	u32:8;
	struct chsc_brinfo_naihdr naihdr;
	union {
		struct qdio_brinfo_entry_l3_ipv6 l3_ipv6[0];
		struct qdio_brinfo_entry_l3_ipv4 l3_ipv4[0];
		struct qdio_brinfo_entry_l2	 l2[0];
	} entries;
} __packed;

int chsc_pnso_brinfo(struct subchannel_id schid,
		struct chsc_pnso_area *brinfo_area,
		struct chsc_brinfo_resume_token resume_token,
		int cnc);

#ifdef CONFIG_SCM_BUS
int scm_update_information(void);
int scm_process_availability_information(void);
#else /* CONFIG_SCM_BUS */
static inline int scm_update_information(void) { return 0; }
static inline int scm_process_availability_information(void) { return 0; }
#endif /* CONFIG_SCM_BUS */


#endif
