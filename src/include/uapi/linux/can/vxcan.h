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
/* SPDX-License-Identifier: GPL-2.0-only WITH Linux-syscall-note */
#ifndef _CAN_VXCAN_H
#define _CAN_VXCAN_H

enum {
	VXCAN_INFO_UNSPEC,
	VXCAN_INFO_PEER,

	__VXCAN_INFO_MAX
#define VXCAN_INFO_MAX	(__VXCAN_INFO_MAX - 1)
};

#endif
