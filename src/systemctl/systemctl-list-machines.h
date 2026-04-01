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

#include "bus-map-properties.h"
#include "shared-forward.h"

int verb_list_machines(int argc, char *argv[], uintptr_t _data, void *userdata);

struct machine_info {
        bool is_host;
        char *name;
        char *version;
        char *tainted;
        uint64_t timestamp;
        uint32_t n_names;
        uint32_t n_failed_units;
        uint32_t n_jobs;
        char *control_group;
        char *state;
};

void machine_info_clear(struct machine_info *info);

extern const struct bus_properties_map machine_info_property_map[];
