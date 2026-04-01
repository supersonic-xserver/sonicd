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

#include <linux/in6.h>

#include "sd-forward.h"

typedef struct sd_ndisc_neighbor {
        unsigned n_ref;

        ICMP6Packet *packet;

        uint32_t flags;
        struct in6_addr target_address;

        Set *options;
} sd_ndisc_neighbor;

sd_ndisc_neighbor* ndisc_neighbor_new(ICMP6Packet *packet);
int ndisc_neighbor_parse(sd_ndisc *nd, sd_ndisc_neighbor *na);
