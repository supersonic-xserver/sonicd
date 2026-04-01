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

#include <sys/pidfd.h>
#include <sys/syscall.h>
#include <unistd.h>

#if !HAVE_PIDFD_OPEN
int missing_pidfd_open(pid_t pid, unsigned flags) {
        return syscall(__NR_pidfd_open, pid, flags);
}
#endif

#if !HAVE_PIDFD_SEND_SIGNAL
int missing_pidfd_send_signal(int fd, int sig, siginfo_t *info, unsigned flags) {
        return syscall(__NR_pidfd_send_signal, fd, sig, info, flags);
}
#endif
