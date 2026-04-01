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

#include <sys/bpf.h>
#include <sys/syscall.h>
#include <unistd.h>

#if !HAVE_BPF
int missing_bpf(int cmd, union bpf_attr *attr, size_t size) {
        return syscall(__NR_bpf, cmd, attr, size);
}
#endif
