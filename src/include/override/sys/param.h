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

/* sys/param.h from glibc unconditionally overrides the MIN() and MAX() macros which interferes with our own
 * MAX() macro. It also includes a bunch of other headers transitively so we don't want to include
 * sys/param.h in macro-fundamental.h unconditionally. We'd like to make including this file an error but
 * unfortunately <resolv.h> includes it. However, <resolv.h> doesn't actually make use of anything from
 * sys/param.h, so we override it with an empty file so it can't mess with our macros. */
