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

#include "hashmap.h"

int fetch_batteries_capacity_by_name(Hashmap **ret_current_capacity);
int get_capacity_by_name(Hashmap *capacities_by_name, const char *name);

int get_total_suspend_interval(Hashmap *last_capacity, usec_t *ret);

int estimate_battery_discharge_rate_per_hour(
                Hashmap *last_capacity,
                Hashmap *current_capacity,
                usec_t before_timestamp,
                usec_t after_timestamp);

int battery_trip_point_alarm_exists(void);
