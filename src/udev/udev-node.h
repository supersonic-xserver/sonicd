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
/* SPDX-License-Identifier: GPL-2.0-or-later */
#pragma once

#include "udev-forward.h"

int udev_node_apply_permissions(
                sd_device *dev,
                bool apply_mac,
                mode_t mode,
                uid_t uid,
                gid_t gid,
                OrderedHashmap *seclabel_list);
int static_node_apply_permissions(
                const char *name,
                mode_t mode,
                uid_t uid,
                gid_t gid,
                char **tags);

int udev_node_remove(sd_device *dev);
int udev_node_update(sd_device *dev, sd_device *dev_old);

size_t udev_node_escape_path(const char *src, char *dest, size_t size);
