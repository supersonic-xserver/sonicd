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

typedef enum NetDevLocalAddressType {
        NETDEV_LOCAL_ADDRESS_IPV4LL,
        NETDEV_LOCAL_ADDRESS_IPV6LL,
        NETDEV_LOCAL_ADDRESS_DHCP4,
        NETDEV_LOCAL_ADDRESS_DHCP6,
        NETDEV_LOCAL_ADDRESS_SLAAC,
        NETDEV_LOCAL_ADDRESS_DHCP_PD,
        _NETDEV_LOCAL_ADDRESS_TYPE_MAX,
        _NETDEV_LOCAL_ADDRESS_TYPE_INVALID = -EINVAL,
} NetDevLocalAddressType;

DECLARE_STRING_TABLE_LOOKUP(netdev_local_address_type, NetDevLocalAddressType);

int link_get_local_address(
                Link *link,
                NetDevLocalAddressType type,
                int family,
                int *ret_family,
                union in_addr_union *ret_address);
