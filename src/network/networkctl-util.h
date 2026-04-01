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

#include "shared-forward.h"

int varlink_connect_networkd(sd_varlink **ret_varlink);
int reload_networkd(void);
int reload_udevd(void);
bool networkd_is_running(void);

void operational_state_to_color(const char *name, const char *state, const char **on, const char **off);
void setup_state_to_color(const char *state, const char **on, const char **off);
void online_state_to_color(const char *state, const char **on, const char **off);

int acquire_link_description(sd_varlink *vl, int ifindex, sd_json_variant **ret);
int json_variant_find_object(sd_json_variant *v, char * const *object_names, sd_json_variant **ret);
