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

#include_next <sys/mman.h>      /* IWYU pragma: export */

#include <assert.h>

/* since glibc-2.38 */
#ifndef MFD_NOEXEC_SEAL
#  define MFD_NOEXEC_SEAL 0x0008U
#else
static_assert(MFD_NOEXEC_SEAL == 0x0008U, "");
#endif

/* since glibc-2.38 */
#ifndef MFD_EXEC
#  define MFD_EXEC 0x0010U
#else
static_assert(MFD_EXEC == 0x0010U, "");
#endif
