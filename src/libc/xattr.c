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

#include <sys/syscall.h>
#include <sys/xattr.h>
#include <unistd.h>

#if !HAVE_SETXATTRAT
int missing_setxattrat(int fd, const char *path, int at_flags, const char *name, const struct xattr_args *args, size_t size) {
        return syscall(__NR_setxattrat, fd, path, at_flags, name, args, size);
}
#endif

#if !HAVE_REMOVEXATTRAT
int missing_removexattrat(int fd, const char *path, int at_flags, const char *name) {
        return syscall(__NR_removexattrat, fd, path, at_flags, name);
}
#endif
