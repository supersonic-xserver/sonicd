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

typedef enum UpdateSetFlags {
        UPDATE_NEWEST     = 1 << 0,
        UPDATE_AVAILABLE  = 1 << 1,
        UPDATE_INSTALLED  = 1 << 2,
        UPDATE_OBSOLETE   = 1 << 3,
        UPDATE_PROTECTED  = 1 << 4,
        UPDATE_INCOMPLETE = 1 << 5,
        UPDATE_PARTIAL    = 1 << 6,
        UPDATE_PENDING    = 1 << 7,
} UpdateSetFlags;

const char* update_set_flags_to_color(UpdateSetFlags flags);
const char* update_set_flags_to_glyph(UpdateSetFlags flags);
const char* update_set_flags_to_string(UpdateSetFlags flags);
