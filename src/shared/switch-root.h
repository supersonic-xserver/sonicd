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

typedef enum SwitchRootFlags {
        SWITCH_ROOT_DESTROY_OLD_ROOT      = 1 << 0, /* rm -rf old root when switching – under the condition
                                                     * that it is backed by non-persistent tmpfs/ramfs/… */
        SWITCH_ROOT_DONT_SYNC             = 1 << 1, /* don't call sync() immediately before switching root */
        SWITCH_ROOT_RECURSIVE_RUN         = 1 << 2, /* move /run/ with MS_REC from old to new root */
} SwitchRootFlags;

int switch_root(const char *new_root, const char *old_root_after, SwitchRootFlags flags);
