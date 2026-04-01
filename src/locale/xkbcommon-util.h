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

#include "dlfcn-util.h"
#include "shared-forward.h"

#if HAVE_XKBCOMMON
#include <xkbcommon/xkbcommon.h>

extern DLSYM_PROTOTYPE(xkb_context_new);
extern DLSYM_PROTOTYPE(xkb_context_unref);
extern DLSYM_PROTOTYPE(xkb_context_set_log_fn);
extern DLSYM_PROTOTYPE(xkb_keymap_new_from_names);
extern DLSYM_PROTOTYPE(xkb_keymap_unref);

int verify_xkb_rmlvo(const char *model, const char *layout, const char *variant, const char *options);

#else

static inline int verify_xkb_rmlvo(const char *model, const char *layout, const char *variant, const char *options) {
        return 0;
}

#endif
