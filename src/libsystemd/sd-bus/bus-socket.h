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

void bus_socket_setup(sd_bus *b);

int bus_socket_connect(sd_bus *b);
int bus_socket_exec(sd_bus *b);
int bus_socket_take_fd(sd_bus *b);
int bus_socket_start_auth(sd_bus *b);

int bus_socket_write_message(sd_bus *bus, sd_bus_message *m, size_t *idx);
int bus_socket_read_message(sd_bus *bus);

int bus_socket_process_opening(sd_bus *b);
int bus_socket_process_authenticating(sd_bus *b);
int bus_socket_process_watch_bind(sd_bus *b);

bool bus_socket_auth_needs_write(sd_bus *b);
