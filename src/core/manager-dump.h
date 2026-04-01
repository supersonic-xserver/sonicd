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

void manager_dump_jobs(Manager *m, FILE *f, char **patterns, const char *prefix);
int manager_get_dump_jobs_string(Manager *m, char **patterns, const char *prefix, char **ret);
void manager_dump_units(Manager *m, FILE *f, char **patterns, const char *prefix);
void manager_dump(Manager *m, FILE *f, char **patterns, const char *prefix);
int manager_get_dump_string(Manager *m, char **patterns, char **ret);
void manager_test_summary(Manager *m);
