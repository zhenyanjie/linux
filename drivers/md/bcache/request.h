#ifndef _BCACHE_REQUEST_H_
#define _BCACHE_REQUEST_H_

struct data_insert_op {
	struct closure		cl;
	struct cache_set	*c;
	struct bio		*bio;
	struct workqueue_struct *wq;

	unsigned		inode;
	uint16_t		write_point;
	uint16_t		write_prio;
	short			error;

	union {
		uint16_t	flags;

	struct {
		unsigned	bypass;
		unsigned	writeback;
		unsigned	flush_journal;
		unsigned	csum;

		unsigned	replace;
		unsigned	replace_collision;

		unsigned	insert_data_done;
	};
	};

	struct keylist		insert_keys;
	BKEY_PADDED(replace_key);
};

unsigned bch_get_congested(struct cache_set *);
void bch_data_insert(struct closure *cl);

void bch_cached_dev_request_init(struct cached_dev *dc);
void bch_flash_dev_request_init(struct bcache_device *d);

extern struct kmem_cache *bch_search_cache, *bch_passthrough_cache;

#endif /* _BCACHE_REQUEST_H_ */
