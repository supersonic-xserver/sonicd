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

#include "resolved-forward.h"

#define MDNS_PORT 5353
#define MDNS_ANNOUNCE_DELAY (1 * USEC_PER_SEC)

int manager_mdns_ipv4_fd(Manager *m);
int manager_mdns_ipv6_fd(Manager *m);

void manager_mdns_stop(Manager *m);
void manager_mdns_maybe_stop(Manager *m);
int manager_mdns_start(Manager *m);
