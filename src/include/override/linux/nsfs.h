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
/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <linux/nsfs.h>    /* IWYU pragma: export */

/* Root namespace inode numbers, as per include/linux/proc_ns.h in the kernel source tree, since v3.8:
 * https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=98f842e675f96ffac96e6c50315790912b2812be */

#define PROC_IPC_INIT_INO    ((ino_t) UINT32_C(0xEFFFFFFF))
#define PROC_UTS_INIT_INO    ((ino_t) UINT32_C(0xEFFFFFFE))
#define PROC_USER_INIT_INO   ((ino_t) UINT32_C(0xEFFFFFFD))
#define PROC_PID_INIT_INO    ((ino_t) UINT32_C(0xEFFFFFFC))
#define PROC_CGROUP_INIT_INO ((ino_t) UINT32_C(0xEFFFFFFB))
#define PROC_TIME_INIT_INO   ((ino_t) UINT32_C(0xEFFFFFFA))
