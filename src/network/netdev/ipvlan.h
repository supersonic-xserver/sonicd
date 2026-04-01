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


#include "ipvlan-util.h"
#include "netdev.h"

typedef struct IPVlan {
        NetDev meta;

        IPVlanMode mode;
        IPVlanFlags flags;
} IPVlan;

DEFINE_NETDEV_CAST(IPVLAN, IPVlan);
DEFINE_NETDEV_CAST(IPVTAP, IPVlan);
extern const NetDevVTable ipvlan_vtable;
extern const NetDevVTable ipvtap_vtable;

CONFIG_PARSER_PROTOTYPE(config_parse_ipvlan_mode);
CONFIG_PARSER_PROTOTYPE(config_parse_ipvlan_flags);

IPVlanMode link_get_ipvlan_mode(Link *link);
