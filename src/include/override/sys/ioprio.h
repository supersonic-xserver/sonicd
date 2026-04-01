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

#include <linux/ioprio.h>       /* IWYU pragma: export */

#if !HAVE_IOPRIO_GET
int missing_ioprio_get(int which, int who);
#  define ioprio_get missing_ioprio_get
#endif

#if !HAVE_IOPRIO_SET
int missing_ioprio_set(int which, int who, int ioprio);
#  define ioprio_set missing_ioprio_set
#endif
