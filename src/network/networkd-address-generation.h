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

DECLARE_TRIVIAL_REF_UNREF_FUNC(IPv6Token, ipv6_token);

int dhcp_pd_generate_addresses(Link *link, const struct in6_addr *prefix, Hashmap **ret);
int ndisc_generate_addresses(Link *link, const struct in6_addr *prefix, uint8_t prefixlen, Hashmap **ret);
int radv_generate_addresses(Link *link, Set *tokens, const struct in6_addr *prefix, uint8_t prefixlen, Hashmap **ret);

int regenerate_address(Address *address, Link *link);

CONFIG_PARSER_PROTOTYPE(config_parse_address_generation_type);
