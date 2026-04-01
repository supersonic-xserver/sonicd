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

#include "bridge-util.h"
#include "string-table.h"

static const char* const bridge_state_table[_NETDEV_BRIDGE_STATE_MAX] = {
        [NETDEV_BRIDGE_STATE_DISABLED]   = "disabled",
        [NETDEV_BRIDGE_STATE_LISTENING]  = "listening",
        [NETDEV_BRIDGE_STATE_LEARNING]   = "learning",
        [NETDEV_BRIDGE_STATE_FORWARDING] = "forwarding",
};

DEFINE_STRING_TABLE_LOOKUP(bridge_state, BridgeState);
