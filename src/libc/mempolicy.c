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

#include <sys/mempolicy.h>
#include <sys/syscall.h>
#include <unistd.h>

#if !HAVE_SET_MEMPOLICY
int missing_set_mempolicy(int mode, const unsigned long *nodemask, unsigned long maxnode) {
        return syscall(__NR_set_mempolicy, mode, nodemask, maxnode);
}
#endif

#if !HAVE_GET_MEMPOLICY
int missing_get_mempolicy(int *mode, unsigned long *nodemask, unsigned long maxnode, void *addr, unsigned long flags) {
        return syscall(__NR_get_mempolicy, mode, nodemask, maxnode, addr, flags);
}
#endif
