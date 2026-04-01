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

#include <sys/quota.h>
#include <sys/syscall.h>
#include <unistd.h>

#if !HAVE_QUOTACTL_FD
int missing_quotactl_fd(int fd, int cmd, int id, void *addr) {
        return syscall(__NR_quotactl_fd, fd, cmd, id, addr);
}
#endif
