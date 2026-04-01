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

/***
  Copyright © 2014 Axis Communications AB. All rights reserved.
***/

#include "sd-forward.h"

int arp_update_filter(int fd, const struct in_addr *a, const struct ether_addr *mac);
int arp_network_bind_raw_socket(int ifindex, const struct in_addr *a, const struct ether_addr *mac);

int arp_send_packet(
                int fd,
                int ifindex,
                const struct in_addr *pa,
                const struct ether_addr *ha,
                bool announce);
static inline int arp_send_probe(
                int fd,
                int ifindex,
                const struct in_addr *pa,
                const struct ether_addr *ha) {
        return arp_send_packet(fd, ifindex, pa, ha, false);
}
static inline int arp_send_announcement(
                int fd,
                int ifindex,
                const struct in_addr *pa,
                const struct ether_addr *ha) {
        return arp_send_packet(fd, ifindex, pa, ha, true);
}
