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

int clean_ipc_internal(uid_t uid, gid_t gid, bool rm);

/* Remove all IPC objects owned by the specified UID or GID */
int clean_ipc_by_uid(uid_t uid);
int clean_ipc_by_gid(gid_t gid);

/* Check if any IPC object owned by the specified UID or GID exists, returns > 0 if so, == 0 if not */
static inline int search_ipc(uid_t uid, gid_t gid) {
        return clean_ipc_internal(uid, gid, false);
}
