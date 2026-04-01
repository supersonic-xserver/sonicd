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

/* Default interval is 10sec. The speed meter periodically make networkd
 * to be woke up. So, too small interval value is not desired.
 * We set the minimum value 100msec = 0.1sec. */
#define SPEED_METER_DEFAULT_TIME_INTERVAL (10 * USEC_PER_SEC)
#define SPEED_METER_MINIMUM_TIME_INTERVAL (100 * USEC_PER_MSEC)

void link_get_bit_rates(Link *link, uint64_t *ret_tx, uint64_t *ret_rx);
int manager_start_speed_meter(Manager *m);
