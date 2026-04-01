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

#include "sysupdate-forward.h"
#include "sysupdate-update-set-flags.h"

typedef struct UpdateSet {
        UpdateSetFlags flags;
        char *version;
        Instance **instances;
        size_t n_instances;
} UpdateSet;

UpdateSet* update_set_free(UpdateSet *us);
int update_set_cmp(UpdateSet *const*a, UpdateSet *const*b);
