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

/* create_ephemeral_snapshot - create a snapshot of the given directory.
 *
 * It will use a btrfs snapshot when available with fallback to traditional dir copy. It will set the global
 * and local lock files based on the passed runtime scope. On success the new directory path is returned via
 * `ret_new_path`.
 *
 * The caller is responsible for the cleanup of the directory, using `_cleanup_(rm_rf_subvolume_and_freep)`
 * is recommended.
 */
int create_ephemeral_snapshot(
                const char *directory,
                RuntimeScope scope,
                bool read_only,
                LockFile *tree_global_lock,
                LockFile *tree_local_lock,
                char **ret_new_path);
