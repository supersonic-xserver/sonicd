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

#include <sys/ioprio.h>
#include <sys/syscall.h>
#include <unistd.h>

#if !HAVE_IOPRIO_GET
int missing_ioprio_get(int which, int who) {
        return syscall(__NR_ioprio_get, which, who);
}
#endif

#if !HAVE_IOPRIO_SET
int missing_ioprio_set(int which, int who, int ioprio) {
        return syscall(__NR_ioprio_set, which, who, ioprio);
}
#endif
