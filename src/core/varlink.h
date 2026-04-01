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

#include "core-forward.h"

int manager_setup_varlink_server(Manager *m);
int manager_setup_varlink_metrics_server(Manager *m);

int manager_varlink_init(Manager *m);
void manager_varlink_done(Manager *m);

/* The manager is expected to send an update to systemd-oomd if one of the following occurs:
 * - The value of ManagedOOM*= properties change
 * - A unit with ManagedOOM*= properties changes unit active state */
int manager_varlink_send_managed_oom_update(Unit *u);

void manager_varlink_send_pending_reload_message(Manager *m);
