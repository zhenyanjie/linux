/*
 * board initialization code should put one of these into dev->platform_data
 * and place the isp1362 onto platform_bus.
 */

#ifndef __LINUX_USB_ISP1362_H__
#define __LINUX_USB_ISP1362_H__

struct isp1362_platform_data {
	/* Enable internal pulldown resistors on downstream ports */
	unsigned sel15Kres;
	/* Clock cannot be stopped */
	unsigned clknotstop;
	/* On-chip overcurrent protection */
	unsigned oc_enable;
	/* INT output polarity */
	unsigned int_act_high;
	/* INT edge or level triggered */
	unsigned int_edge_triggered;
	/* DREQ output polarity */
	unsigned dreq_act_high;
	/* DACK input polarity */
	unsigned dack_act_high;
	/* chip can be resumed via H_WAKEUP pin */
	unsigned remote_wakeup_connected;
	/* Switch or not to switch (keep always powered) */
	unsigned no_power_switching;
	/* Ganged port power switching (0) or individual port power switching (1) */
	unsigned power_switching_mode;
	/* Given port_power, msec/2 after power on till power good */
	u8 potpg;
	/* Hardware reset set/clear */
	void (*reset) (struct device *dev, int set);
	/* Clock start/stop */
	void (*clock) (struct device *dev, int start);
	/* Inter-io delay (ns). The chip is picky about access timings; it
	 * expects at least:
	 * 110ns delay between consecutive accesses to DATA_REG,
	 * 300ns delay between access to ADDR_REG and DATA_REG (registers)
	 * 462ns delay between access to ADDR_REG and DATA_REG (buffer memory)
	 * WE MUST NOT be activated during these intervals (even without CS!)
	 */
	void (*delay) (struct device *dev, unsigned int delay);
};

#endif
