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

extern const BusObjectImplementation manager_object;

int manager_connect_bus(Manager *m);
int manager_send_changed_strv(Manager *manager, char **properties);
#define manager_send_changed(manager, ...) manager_send_changed_strv(manager, STRV_MAKE(__VA_ARGS__));
int bus_dns_server_append(sd_bus_message *reply, DnsServer *s, bool with_ifindex, bool extended);
int bus_property_get_resolve_support(sd_bus *bus, const char *path, const char *interface,
                                     const char *property, sd_bus_message *reply,
                                     void *userdata, sd_bus_error *error);

void bus_client_log(sd_bus_message *m, const char *what);
