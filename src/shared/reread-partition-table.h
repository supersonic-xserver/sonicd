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

#include "sd-forward.h"

#include "shared-forward.h"

typedef enum RereadPartitionTableFlags {
        REREADPT_FORCE_UEVENT = 1 << 0, /* Force a "change" uevent out on partitions we didn't resize/remove/add */
        REREADPT_BSD_LOCK     = 1 << 1, /* Take a BSD lock on the device around the rescan operation */
} RereadPartitionTableFlags;

int reread_partition_table_fd(int fd, RereadPartitionTableFlags flags);
int reread_partition_table(sd_device *dev, RereadPartitionTableFlags flags);
