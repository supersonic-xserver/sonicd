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

#include "shared-forward.h"

#if HAVE_LIBIDN2
#include <idn2.h>

#include "dlfcn-util.h"

extern DLSYM_PROTOTYPE(idn2_lookup_u8);
extern const char *(*sym_idn2_strerror)(int rc) _const_;
extern DLSYM_PROTOTYPE(idn2_to_unicode_8z8z);

int dlopen_idn(void);
#else
static inline int dlopen_idn(void) {
        return -EOPNOTSUPP;
}
#endif
