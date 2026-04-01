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

typedef enum InstallFileFlags {
        INSTALL_REPLACE    = 1 << 0, /* Replace an existing inode */
        INSTALL_READ_ONLY  = 1 << 1, /* Call fs_make_very_read_only() to make the inode comprehensively read-only */
        INSTALL_FSYNC      = 1 << 2, /* fsync() file contents before moving file in */
        INSTALL_FSYNC_FULL = 1 << 3, /* like INSTALL_FSYNC, but also fsync() parent dir before+after moving file in */
        INSTALL_SYNCFS     = 1 << 4, /* syncfs() before moving file in, fsync() parent dir after moving file in */
        INSTALL_GRACEFUL   = 1 << 5, /* don't fail if we cannot sync or mark read-only */
} InstallFileFlags;

int install_file(int source_atfd, const char *source_name, int target_atfd, const char *target_name, InstallFileFlags flags);

usec_t parse_source_date_epoch(void);
usec_t source_date_epoch_or_now(void);
