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

#include "machine-forward.h"

extern const BusObjectImplementation image_object;

char* image_bus_path(const char *name);

int bus_image_method_remove(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_image_method_rename(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_image_method_clone(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_image_method_mark_read_only(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_image_method_set_limit(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_image_method_get_hostname(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_image_method_get_machine_id(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_image_method_get_machine_info(sd_bus_message *message, void *userdata, sd_bus_error *error);
int bus_image_method_get_os_release(sd_bus_message *message, void *userdata, sd_bus_error *error);
