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

#include <netinet/in.h>

#include "networkd-forward.h"

typedef struct DHCPStaticLease {
        Network *network;
        ConfigSection *section;

        struct in_addr address;
        uint8_t *client_id;
        size_t client_id_size;
        char *hostname;
} DHCPStaticLease;

void network_drop_invalid_static_leases(Network *network);

CONFIG_PARSER_PROTOTYPE(config_parse_dhcp_static_lease_address);
CONFIG_PARSER_PROTOTYPE(config_parse_dhcp_static_lease_hwaddr);
CONFIG_PARSER_PROTOTYPE(config_parse_dhcp_static_lease_hostname);
