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
#include "networkd-util.h"

typedef enum UseDomains {
        USE_DOMAINS_NO,
        USE_DOMAINS_YES,
        USE_DOMAINS_ROUTE,
        _USE_DOMAINS_MAX,
        _USE_DOMAINS_INVALID = -EINVAL,
} UseDomains;

UseDomains link_get_use_domains(Link *link, NetworkConfigSource proto);
bool link_get_use_dns(Link *link, NetworkConfigSource proto);
bool link_get_use_dnr(Link *link, NetworkConfigSource proto);

DECLARE_STRING_TABLE_LOOKUP(use_domains, UseDomains);

CONFIG_PARSER_PROTOTYPE(config_parse_domains);
CONFIG_PARSER_PROTOTYPE(config_parse_dns);
CONFIG_PARSER_PROTOTYPE(config_parse_dnssec_negative_trust_anchors);
CONFIG_PARSER_PROTOTYPE(config_parse_dhcp_use_dns);
CONFIG_PARSER_PROTOTYPE(config_parse_use_domains);
