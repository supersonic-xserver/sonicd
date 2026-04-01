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

typedef enum PagerFlags {
        PAGER_DISABLE     = 1 << 0,
        PAGER_JUMP_TO_END = 1 << 1,
} PagerFlags;

void pager_open(PagerFlags flags);
void pager_close(void);
bool pager_have(void) _pure_;

int show_man_page(const char *desc, bool null_stdio);
