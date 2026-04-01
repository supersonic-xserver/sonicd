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

#include "dns-resolver-internal.h"
#include "networkd-forward.h"

typedef enum IPv6AcceptRAStartDHCP6Client {
        IPV6_ACCEPT_RA_START_DHCP6_CLIENT_NO,
        IPV6_ACCEPT_RA_START_DHCP6_CLIENT_ALWAYS,
        IPV6_ACCEPT_RA_START_DHCP6_CLIENT_YES,
        _IPV6_ACCEPT_RA_START_DHCP6_CLIENT_MAX,
        _IPV6_ACCEPT_RA_START_DHCP6_CLIENT_INVALID = -EINVAL,
} IPv6AcceptRAStartDHCP6Client;

typedef struct NDiscRDNSS {
        struct in6_addr router;
        /* This is an absolute point in time, and NOT a timespan/duration.
         * Must be specified with CLOCK_BOOTTIME. */
        usec_t lifetime_usec;
        struct in6_addr address;
} NDiscRDNSS;

typedef struct NDiscDNSSL {
        struct in6_addr router;
        /* This is an absolute point in time, and NOT a timespan/duration.
         * Must be specified with CLOCK_BOOTTIME. */
        usec_t lifetime_usec;
        /* The domain name follows immediately. */
} NDiscDNSSL;

typedef struct NDiscCaptivePortal {
        struct in6_addr router;
        /* This is an absolute point in time, and NOT a timespan/duration.
         * Must be specified with CLOCK_BOOTTIME. */
        usec_t lifetime_usec;
        char *captive_portal;
} NDiscCaptivePortal;

typedef struct NDiscPREF64 {
        struct in6_addr router;
        /* This is an absolute point in time, and NOT a timespan/duration.
         * Must be specified with CLOCK_BOOTTIME. */
        usec_t lifetime_usec;
        uint8_t prefix_len;
        struct in6_addr prefix;
} NDiscPREF64;

typedef struct NDiscDNR {
        struct in6_addr router;
        usec_t lifetime_usec;
        sd_dns_resolver resolver;
} NDiscDNR;

char* ndisc_dnssl_domain(const NDiscDNSSL *n);

bool link_ndisc_enabled(Link *link);

void network_adjust_ndisc(Network *network);

int ndisc_start(Link *link);
int ndisc_stop(Link *link);
void ndisc_flush(Link *link);

int link_request_ndisc(Link *link);
int link_drop_ndisc_config(Link *link, Network *network);
int ndisc_reconfigure_address(Address *address, Link *link);

CONFIG_PARSER_PROTOTYPE(config_parse_ndisc_start_dhcp6_client);
