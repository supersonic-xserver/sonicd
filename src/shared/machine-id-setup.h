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

#include "sd-id128.h"

#include "shared-forward.h"

typedef enum MachineIdSetupFlags {
        MACHINE_ID_SETUP_FORCE_TRANSIENT = 1 << 0,
        MACHINE_ID_SETUP_FORCE_FIRMWARE  = 1 << 1,
} MachineIdSetupFlags;

int machine_id_commit(const char *root);
int machine_id_setup(const char *root, sd_id128_t machine_id, MachineIdSetupFlags flags, sd_id128_t *ret);
