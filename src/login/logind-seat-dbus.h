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

#include "logind-forward.h"

extern const BusObjectImplementation seat_object;

char* seat_bus_path(Seat *s);

int seat_send_signal(Seat *s, bool new_seat);
int seat_send_changed_strv(Seat *s, char **properties);
#define seat_send_changed(s, ...) seat_send_changed_strv(s, STRV_MAKE(__VA_ARGS__))

int bus_seat_method_terminate(sd_bus_message *message, void *userdata, sd_bus_error *error);
