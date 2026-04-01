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

typedef enum KernelImageType {
        KERNEL_IMAGE_TYPE_UNKNOWN,
        KERNEL_IMAGE_TYPE_UKI,
        KERNEL_IMAGE_TYPE_ADDON,
        KERNEL_IMAGE_TYPE_PE,
        _KERNEL_IMAGE_TYPE_MAX,
        _KERNEL_IMAGE_TYPE_INVALID = -EINVAL,
} KernelImageType;

DECLARE_STRING_TABLE_LOOKUP_TO_STRING(kernel_image_type, KernelImageType);

int inspect_kernel(
                int dir_fd,
                const char *filename,
                KernelImageType *ret_type,
                char **ret_cmdline,
                char **ret_uname,
                char **ret_pretty_name);
