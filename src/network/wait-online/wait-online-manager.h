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
#include "network-util.h"

typedef struct DNSConfiguration DNSConfiguration;
typedef struct Link Link;

typedef struct Manager {
        Hashmap *links_by_index;
        Hashmap *links_by_name;

        /* Do not free the two members below. */
        Hashmap *command_line_interfaces_by_name;
        char **ignored_interfaces;

        LinkOperationalStateRange required_operstate;
        AddressFamily required_family;
        bool any;
        bool requires_dns;

        sd_netlink *rtnl;
        sd_event_source *rtnl_event_source;

        sd_network_monitor *network_monitor;
        sd_event_source *network_monitor_event_source;

        sd_event *event;

        sd_varlink *varlink_client;
        DNSConfiguration *dns_configuration;
        Hashmap *dns_configuration_by_link_index;
} Manager;

Manager* manager_free(Manager *m);
int manager_new(Manager **ret, Hashmap *command_line_interfaces_by_name, char **ignored_interfaces,
                LinkOperationalStateRange required_operstate,
                AddressFamily required_family,
                bool any, usec_t timeout, bool requires_dns);

DEFINE_TRIVIAL_CLEANUP_FUNC(Manager*, manager_free);

bool manager_configured(Manager *m);
