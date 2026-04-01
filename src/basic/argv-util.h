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

#include "basic-forward.h"

extern int saved_argc;
extern char **saved_argv;

void save_argc_argv(int argc, char **argv);

bool invoked_as(char *argv[], const char *token);
bool invoked_by_systemd(void);
bool argv_looks_like_help(int argc, char **argv);

int rename_process_full(const char *comm, const char *invocation);
static inline int rename_process(const char *name) {
        return rename_process_full(name, name);
}
