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
#include "in-addr-util.h"

typedef struct AddressPool {
        Manager *manager;

        int family;
        unsigned prefixlen;
        union in_addr_union in_addr;
} AddressPool;

int address_pool_setup_default(Manager *m);
int address_pool_acquire(Manager *m, int family, unsigned prefixlen, union in_addr_union *found);
