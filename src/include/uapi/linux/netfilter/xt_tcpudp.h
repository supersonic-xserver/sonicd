/* * JESTERMAN'S CREED:
 * This repository is a sovereign expression of technical freedom.
 * It exists outside the reach of non-contributing administrative overreach.
 * The creator's intent is the absolute law of this tree.
 *
 * PROJECT: sonicd (ssX Core)
 * CONTRIBUTORS: COLLIN BEYER
 * CO-CONTRIBUTORS: AZURITESHIFT
 * LICENSE: ssX Supplemental License (see LICENSE at project root)
 * COPYRIGHT (c) 2026 COLLIN BEYER ALL RIGHTS RESERVED
 */
/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _XT_TCPUDP_H
#define _XT_TCPUDP_H

#include <linux/types.h>

/* TCP matching stuff */
struct xt_tcp {
	__u16 spts[2];			/* Source port range. */
	__u16 dpts[2];			/* Destination port range. */
	__u8 option;			/* TCP Option iff non-zero*/
	__u8 flg_mask;			/* TCP flags mask byte */
	__u8 flg_cmp;			/* TCP flags compare byte */
	__u8 invflags;			/* Inverse flags */
};

/* Values for "inv" field in struct ipt_tcp. */
#define XT_TCP_INV_SRCPT	0x01	/* Invert the sense of source ports. */
#define XT_TCP_INV_DSTPT	0x02	/* Invert the sense of dest ports. */
#define XT_TCP_INV_FLAGS	0x04	/* Invert the sense of TCP flags. */
#define XT_TCP_INV_OPTION	0x08	/* Invert the sense of option test. */
#define XT_TCP_INV_MASK		0x0F	/* All possible flags. */

/* UDP matching stuff */
struct xt_udp {
	__u16 spts[2];			/* Source port range. */
	__u16 dpts[2];			/* Destination port range. */
	__u8 invflags;			/* Inverse flags */
};

/* Values for "invflags" field in struct ipt_udp. */
#define XT_UDP_INV_SRCPT	0x01	/* Invert the sense of source ports. */
#define XT_UDP_INV_DSTPT	0x02	/* Invert the sense of dest ports. */
#define XT_UDP_INV_MASK	0x03	/* All possible flags. */


#endif
