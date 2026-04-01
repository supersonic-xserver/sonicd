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

#include "ether-addr-util.h"
#include "in-addr-util.h"
#include "networkd-forward.h"
#include "networkd-util.h"

typedef struct Neighbor {
        Network *network;
        Link *link;
        ConfigSection *section;
        NetworkConfigSource source;
        NetworkConfigState state;

        unsigned n_ref;

        struct in_addr_data dst_addr;
        struct hw_addr_data ll_addr;
} Neighbor;

DECLARE_TRIVIAL_REF_UNREF_FUNC(Neighbor, neighbor);

int neighbor_get(Link *link, const Neighbor *in, Neighbor **ret);
int neighbor_remove(Neighbor *neighbor, Link *link);

int network_drop_invalid_neighbors(Network *network);

int link_drop_static_neighbors(Link *link);
int link_drop_unmanaged_neighbors(Link *link);

int link_request_static_neighbors(Link *link);

int manager_rtnl_process_neighbor(sd_netlink *rtnl, sd_netlink_message *message, Manager *m);

DEFINE_NETWORK_CONFIG_STATE_FUNCTIONS(Neighbor, neighbor);

typedef enum NeighborConfParserType {
        NEIGHBOR_DESTINATION_ADDRESS,
        NEIGHBOR_LINK_LAYER_ADDRESS,
        _NEIGHBOR_CONF_PARSER_MAX,
        _NEIGHBOR_CONF_PARSER_INVALID = -EINVAL,
} NeighborConfParserType;

CONFIG_PARSER_PROTOTYPE(config_parse_neighbor_section);
