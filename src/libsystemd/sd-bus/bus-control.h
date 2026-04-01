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

#include "sd-forward.h"

int bus_add_match_internal(sd_bus *bus, const char *match, uint64_t timeout_usec, uint64_t *ret_counter);
int bus_add_match_internal_async(sd_bus *bus, sd_bus_slot **ret, const char *match, sd_bus_message_handler_t callback, void *userdata, uint64_t timeout_usec);

int bus_remove_match_internal(sd_bus *bus, const char *match);
