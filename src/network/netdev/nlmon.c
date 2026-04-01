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

#include "nlmon.h"

static int netdev_nlmon_verify(NetDev *netdev, const char *filename) {
        assert(netdev);
        assert(filename);

        if (netdev->hw_addr.length > 0) {
                log_netdev_warning(netdev, "%s: MACAddress= is not supported. Ignoring", filename);
                netdev->hw_addr = HW_ADDR_NULL;
        }

        return 0;
}

const NetDevVTable nlmon_vtable = {
        .object_size = sizeof(NLMon),
        .sections = NETDEV_COMMON_SECTIONS,
        .create_type = NETDEV_CREATE_INDEPENDENT,
        .config_verify = netdev_nlmon_verify,
        .iftype = ARPHRD_NETLINK,
};
