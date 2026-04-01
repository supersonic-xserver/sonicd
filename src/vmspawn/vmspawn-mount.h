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

typedef struct RuntimeMount {
        bool read_only;
        char *source;
        uid_t source_uid;
        char *target;
        uid_t target_uid;
} RuntimeMount;

typedef struct RuntimeMountContext {
        RuntimeMount *mounts;
        size_t n_mounts;
} RuntimeMountContext;

void runtime_mount_done(RuntimeMount *mount);
void runtime_mount_context_done(RuntimeMountContext *ctx);
int runtime_mount_parse(RuntimeMountContext *ctx, const char *s, bool read_only);
