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

#include <linux/if_arp.h>

#include "dummy.h"

static bool dummy_can_set_mac(NetDev *netdev, const struct hw_addr_data *hw_addr) {
        return true;
}

const NetDevVTable dummy_vtable = {
        .object_size = sizeof(Dummy),
        .sections = NETDEV_COMMON_SECTIONS,
        .create_type = NETDEV_CREATE_INDEPENDENT,
        .can_set_mac = dummy_can_set_mac,
        .iftype = ARPHRD_ETHER,
        .generate_mac = true,
};
