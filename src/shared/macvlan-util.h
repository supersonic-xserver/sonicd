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

#include <linux/if_link.h>

#include "shared-forward.h"

typedef enum MacVlanMode {
        NETDEV_MACVLAN_MODE_PRIVATE = MACVLAN_MODE_PRIVATE,
        NETDEV_MACVLAN_MODE_VEPA = MACVLAN_MODE_VEPA,
        NETDEV_MACVLAN_MODE_BRIDGE = MACVLAN_MODE_BRIDGE,
        NETDEV_MACVLAN_MODE_PASSTHRU = MACVLAN_MODE_PASSTHRU,
        NETDEV_MACVLAN_MODE_SOURCE = MACVLAN_MODE_SOURCE,
        _NETDEV_MACVLAN_MODE_MAX,
        _NETDEV_MACVLAN_MODE_INVALID = -EINVAL,
} MacVlanMode;

DECLARE_STRING_TABLE_LOOKUP(macvlan_mode, MacVlanMode);
