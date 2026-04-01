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

int dump_list(Table *table, const char *key, char * const *l);
int ieee_oui(sd_hwdb *hwdb, const struct ether_addr *mac, char **ret);
int dump_gateways(sd_netlink *rtnl, sd_hwdb *hwdb, Table *table, int ifindex);
int dump_addresses(sd_netlink *rtnl, sd_dhcp_lease *lease, Table *table, int ifindex);
