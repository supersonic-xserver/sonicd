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

int manager_open_dev_kmsg(Manager *m);
int manager_flush_dev_kmsg(Manager *m);
int manager_reopen_dev_kmsg(Manager *m, bool old_read_kmsg);

void manager_forward_kmsg(Manager *m, int priority, const char *identifier, const char *message, const struct ucred *ucred);

int manager_open_kernel_seqnum(Manager *m);
void manager_close_kernel_seqnum(Manager *m);

void dev_kmsg_record(Manager *m, char *p, size_t l);
