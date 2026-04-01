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

#include "journald-forward.h"

void manager_process_native_message(
                Manager *m,
                const char *buffer,
                size_t buffer_size,
                const struct ucred *ucred,
                const struct timeval *tv,
                const char *label);

int manager_process_native_file(
                Manager *m,
                int fd,
                const struct ucred *ucred,
                const struct timeval *tv,
                const char *label);

int manager_open_native_socket(Manager *m, const char *native_socket);
