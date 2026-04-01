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

#include "shared-forward.h"

typedef struct ExecCommand ExecCommand;
typedef struct Unit Unit;

typedef enum RecursiveErrors {
        RECURSIVE_ERRORS_YES,               /* Look for errors in all associated units */
        RECURSIVE_ERRORS_NO,                /* Don't look for errors in any but the selected unit */
        RECURSIVE_ERRORS_ONE,               /* Look for errors in the selected unit and its direct dependencies */
        _RECURSIVE_ERRORS_MAX,
        _RECURSIVE_ERRORS_INVALID = -EINVAL,
} RecursiveErrors;

int verify_set_unit_path(char **filenames);
int verify_prepare_filename(const char *filename, char **ret);
int verify_executable(Unit *u, const ExecCommand *exec, const char *root);
int verify_units(char **filenames, RuntimeScope scope, bool check_man, bool run_generators, RecursiveErrors recursive_errors, const char *root);

DECLARE_STRING_TABLE_LOOKUP(recursive_errors, RecursiveErrors);
