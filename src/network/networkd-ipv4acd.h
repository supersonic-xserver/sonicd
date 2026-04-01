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

bool link_ipv4acd_supported(Link *link);
bool link_ipv4acd_enabled(Link *link);
bool ipv4acd_bound(Link *link, const Address *address);
int ipv4acd_configure(Link *link, const Address *address);
void ipv4acd_detach(Link *link, const Address *address);
int ipv4acd_update_mac(Link *link);
int ipv4acd_start(Link *link);
int ipv4acd_stop(Link *link);
int ipv4acd_set_ifname(Link *link);
