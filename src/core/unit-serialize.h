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

/* These functions serialize state for our own usage, i.e.: across a reload/reexec, rather than for being
 * passed to a child process. */

int unit_serialize_state(Unit *u, FILE *f, FDSet *fds, bool switching_root);
int unit_deserialize_state(Unit *u, FILE *f, FDSet *fds);
int unit_deserialize_state_skip(FILE *f);

void unit_dump(Unit *u, FILE *f, const char *prefix);
