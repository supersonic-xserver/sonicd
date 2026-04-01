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

#include "networkd-forward.h"

#define IPV4LL_ROUTE_METRIC 2048

bool link_ipv4ll_enabled(Link *link);

int ipv4ll_configure(Link *link);
int ipv4ll_start(Link *link);
int link_drop_ipv4ll_config(Link *link, Network *network);
int ipv4ll_update_mac(Link *link);

CONFIG_PARSER_PROTOTYPE(config_parse_ipv4ll);
CONFIG_PARSER_PROTOTYPE(config_parse_ipv4ll_address);
