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

#include <sched.h>
#include <sys/syscall.h>
#include <unistd.h>

#if !HAVE_SCHED_SETATTR
int missing_sched_setattr(pid_t pid, struct sched_attr *attr, unsigned flags) {
        return syscall(__NR_sched_setattr, pid, attr, flags);
}
#endif
