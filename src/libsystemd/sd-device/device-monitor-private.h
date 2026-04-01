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

typedef enum MonitorNetlinkGroup {
        MONITOR_GROUP_NONE,
        MONITOR_GROUP_KERNEL,
        MONITOR_GROUP_UDEV,
        _MONITOR_NETLINK_GROUP_MAX,
        _MONITOR_NETLINK_GROUP_INVALID = -EINVAL,
} MonitorNetlinkGroup;

int device_monitor_new_full(sd_device_monitor **ret, MonitorNetlinkGroup group, int fd);
int device_monitor_get_address(sd_device_monitor *m, union sockaddr_union *ret);
int device_monitor_allow_unicast_sender(sd_device_monitor *m, sd_device_monitor *sender);
int device_monitor_send(sd_device_monitor *m, const union sockaddr_union *destination, sd_device *device);
