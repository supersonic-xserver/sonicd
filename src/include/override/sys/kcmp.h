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

#include <linux/kcmp.h>         /* IWYU pragma: export */
#include <sys/types.h>

/* Supported since kernel v3.5 (d97b46a64674a267bc41c9e16132ee2a98c3347d). */
#if !HAVE_KCMP
int missing_kcmp(pid_t pid1, pid_t pid2, int type, unsigned long idx1, unsigned long idx2);
#  define kcmp missing_kcmp
#endif
