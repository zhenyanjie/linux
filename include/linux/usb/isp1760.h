/*
 * board initialization should put one of these into dev->platform_data
 * and place the isp1760 onto platform_bus named "isp1760-hcd".
 */

#ifndef __LINUX_USB_ISP1760_H
#define __LINUX_USB_ISP1760_H

struct isp1760_platform_data {
	unsigned is_isp1761;			/* Chip is ISP1761 */
	unsigned bus_width_16;		/* 16/32-bit data bus width */
	unsigned port1_otg;			/* Port 1 supports OTG */
	unsigned analog_oc;			/* Analog overcurrent */
	unsigned dack_polarity_high;		/* DACK active high */
	unsigned dreq_polarity_high;		/* DREQ active high */
};

#endif /* __LINUX_USB_ISP1760_H */
