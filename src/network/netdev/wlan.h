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

#include <linux/nl80211.h>

#include "shared-forward.h"
#include "netdev.h"

typedef struct WLan {
        NetDev meta;

        char *wiphy_name;
        uint32_t wiphy_index;
        enum nl80211_iftype iftype;
        int wds; /* tristate */
} WLan;

DEFINE_NETDEV_CAST(WLAN, WLan);
extern const NetDevVTable wlan_vtable;

CONFIG_PARSER_PROTOTYPE(config_parse_wiphy);
CONFIG_PARSER_PROTOTYPE(config_parse_wlan_iftype);
