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

#include "ipvlan-util.h"
#include "string-table.h"

static const char* const ipvlan_mode_table[_NETDEV_IPVLAN_MODE_MAX] = {
        [NETDEV_IPVLAN_MODE_L2] = "L2",
        [NETDEV_IPVLAN_MODE_L3] = "L3",
        [NETDEV_IPVLAN_MODE_L3S] = "L3S",
};

DEFINE_STRING_TABLE_LOOKUP(ipvlan_mode, IPVlanMode);

static const char* const ipvlan_flags_table[_NETDEV_IPVLAN_FLAGS_MAX] = {
        [NETDEV_IPVLAN_FLAGS_BRIGDE] = "bridge",
        [NETDEV_IPVLAN_FLAGS_PRIVATE] = "private",
        [NETDEV_IPVLAN_FLAGS_VEPA] = "vepa",
};

DEFINE_STRING_TABLE_LOOKUP(ipvlan_flags, IPVlanFlags);
