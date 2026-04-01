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

#include_next <sys/stat.h>      /* IWYU pragma: export */

/* Supported since kernel v6.6 (78252deb023cf0879256fcfbafe37022c390762b). */
#if !HAVE_FCHMODAT2
int missing_fchmodat2(int dirfd, const char *path, mode_t mode, int flags);
#  define fchmodat2 missing_fchmodat2
#endif
