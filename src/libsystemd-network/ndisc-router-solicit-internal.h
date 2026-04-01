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

#include "sd-forward.h"

typedef struct sd_ndisc_router_solicit {
        unsigned n_ref;

        ICMP6Packet *packet;

        Set *options;
} sd_ndisc_router_solicit;

sd_ndisc_router_solicit* ndisc_router_solicit_new(ICMP6Packet *packet);
int ndisc_router_solicit_parse(sd_radv *ra, sd_ndisc_router_solicit *rs);
