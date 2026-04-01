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

#include "netdev.h"

typedef enum IPoIBMode {
        IP_OVER_INFINIBAND_MODE_DATAGRAM,
        IP_OVER_INFINIBAND_MODE_CONNECTED,
        _IP_OVER_INFINIBAND_MODE_MAX,
        _IP_OVER_INFINIBAND_MODE_INVALID = -EINVAL,
} IPoIBMode;

typedef struct IPoIB {
        NetDev meta;

        uint16_t pkey;
        IPoIBMode mode;
        int umcast;
} IPoIB;

DEFINE_NETDEV_CAST(IPOIB, IPoIB);
extern const NetDevVTable ipoib_vtable;

int ipoib_set_netlink_message(Link *link, sd_netlink_message *m);

CONFIG_PARSER_PROTOTYPE(config_parse_ipoib_pkey);
CONFIG_PARSER_PROTOTYPE(config_parse_ipoib_mode);
