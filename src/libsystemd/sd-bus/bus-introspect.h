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

#include "bus-forward.h"
#include "memstream-util.h"

typedef struct BusIntrospect {
        MemStream m;
        char *interface_name;
        bool trusted;
} BusIntrospect;

int introspect_begin(BusIntrospect *i, bool trusted);
int introspect_write_default_interfaces(BusIntrospect *i, bool object_manager);
int introspect_write_child_nodes(BusIntrospect *i, OrderedSet *s, const char *prefix);
int introspect_write_interface(
                BusIntrospect *i,
                const char *interface_name,
                const sd_bus_vtable *v);
int introspect_finish(BusIntrospect *i, char **ret);
void introspect_done(BusIntrospect *i);
