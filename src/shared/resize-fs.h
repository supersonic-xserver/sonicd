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
#include "stat-util.h"

int resize_fs(int fd, uint64_t sz, uint64_t *ret_size);

#define BTRFS_MINIMAL_SIZE (256U*U64_MB)
#define XFS_MINIMAL_SIZE (300U*U64_MB)
#define EXT4_MINIMAL_SIZE (32U*U64_MB)

uint64_t minimal_size_by_fs_magic(statfs_f_type_t magic);
uint64_t minimal_size_by_fs_name(const char *name);

bool fs_can_online_shrink_and_grow(statfs_f_type_t magic);
