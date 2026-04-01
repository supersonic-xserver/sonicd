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

#include "machine-forward.h"

typedef enum ImageCleanPoolMode {
        IMAGE_CLEAN_POOL_REMOVE_ALL,
        IMAGE_CLEAN_POOL_REMOVE_HIDDEN,
        _IMAGE_CLEAN_POOL_MAX,
        _IMAGE_CLEAN_POOL_INVALID = -EINVAL,
} ImageCleanPoolMode;

DECLARE_STRING_TABLE_LOOKUP(image_clean_pool_mode, ImageCleanPoolMode);

int image_clean_pool_operation(Manager *manager, ImageCleanPoolMode mode, Operation **ret_operation);
int clean_pool_read_first_entry(FILE *file, int child_error, sd_bus_error *error);
int clean_pool_read_next_entry(FILE *file, char **ret_name, uint64_t *ret_usage);
