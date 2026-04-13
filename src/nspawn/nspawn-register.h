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
#include "nspawn-settings.h"

typedef enum AllocateScopeFlags {
        ALLOCATE_SCOPE_ALLOW_PIDFD = 1 << 0,
} AllocateScopeFlags;

int allocate_scope(
                sd_bus *bus,
                const char *machine_name,
                const PidRef *pid,
                const char *slice,
                CustomMount *mounts, unsigned n_mounts,
                int kill_signal,
                char **properties,
                sd_bus_message *properties_message,
                StartMode start_mode,
                AllocateScopeFlags flags);
int terminate_scope(sd_bus *bus, const char *machine_name);
