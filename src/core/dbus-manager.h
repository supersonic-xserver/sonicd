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

extern const sd_bus_vtable bus_manager_vtable[];
extern const sd_bus_vtable bus_manager_log_control_vtable[];

void bus_manager_send_finished(
                Manager *m,
                usec_t firmware_usec,
                usec_t loader_usec,
                usec_t kernel_usec,
                usec_t initrd_usec,
                usec_t userspace_usec,
                usec_t total_usec);

void bus_manager_send_reloading(Manager *m, bool active);
void bus_manager_send_change_signal(Manager *m);

int bus_property_get_oom_policy(
                sd_bus *bus,
                const char *path,
                const char *interface,
                const char *property,
                sd_bus_message *reply,
                void *userdata,
                sd_bus_error *reterr_error);

int bus_property_get_emergency_action(
                sd_bus *bus,
                const char *path,
                const char *interface,
                const char *property,
                sd_bus_message *reply,
                void *userdata,
                sd_bus_error *reterr_error);
