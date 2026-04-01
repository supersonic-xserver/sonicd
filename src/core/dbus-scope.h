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

#include "sd-bus-vtable.h"

#include "core-forward.h"

extern const sd_bus_vtable bus_scope_vtable[];

int bus_scope_set_property(
                Unit *u,
                const char *name,
                sd_bus_message *message,
                UnitWriteFlags flags,
                sd_bus_error *reterr_error);
int bus_scope_commit_properties(Unit *u);

int bus_scope_send_request_stop(Scope *s);

int bus_scope_method_abandon(sd_bus_message *message, void *userdata, sd_bus_error *reterr_error);

int bus_scope_track_controller(Scope *s);
