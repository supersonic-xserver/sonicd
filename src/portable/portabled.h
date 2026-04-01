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

#include "list.h"
#include "portabled-forward.h"
#include "runtime-scope.h"

typedef struct Manager {
        sd_event *event;
        sd_bus *bus;

        Hashmap *polkit_registry;

        Hashmap *image_cache;
        sd_event_source *image_cache_defer_event;

        LIST_HEAD(Operation, operations);
        unsigned n_operations;

        RuntimeScope runtime_scope;
        char *state_dir;
} Manager;

extern const BusObjectImplementation manager_object;
