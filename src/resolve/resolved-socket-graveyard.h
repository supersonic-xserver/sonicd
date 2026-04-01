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

#include "list.h"
#include "resolved-forward.h"

typedef struct SocketGraveyard {
        Manager *manager;
        usec_t deadline;
        sd_event_source *io_event_source;
        LIST_FIELDS(SocketGraveyard, graveyard);
} SocketGraveyard;

void manager_socket_graveyard_process(Manager *m);
void manager_socket_graveyard_clear(Manager *m);

int manager_add_socket_to_graveyard(Manager *m, int fd);
