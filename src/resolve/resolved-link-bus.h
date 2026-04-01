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

extern const BusObjectImplementation link_object;

char* link_bus_path(const Link *link);

int bus_link_method_set_dns_servers(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_link_method_set_dns_servers_ex(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_link_method_set_domains(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_link_method_set_default_route(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_link_method_set_llmnr(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_link_method_set_mdns(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_link_method_set_dns_over_tls(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_link_method_set_dnssec(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_link_method_set_dnssec_negative_trust_anchors(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_link_method_revert(sd_bus_message *message, void *userdata, sd_bus_error *error);
