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

int drop_in_file(
                const char *dir,
                const char *unit,
                unsigned level,
                const char *name,
                char **ret_unit_dir,
                char **ret_path);

int write_drop_in(
                const char *dir,
                const char *unit,
                unsigned level,
                const char *name,
                const char *data);
int write_drop_in_format(
                const char *dir,
                const char *unit,
                unsigned level,
                const char *name,
                const char *format, ...) _printf_(5, 6);

int unit_file_find_dropin_paths(
                const char *original_root,
                char **lookup_path,
                Set *unit_path_cache,
                const char *dir_suffix,
                const char *file_suffix,
                const char *name,
                const Set *aliases,
                char ***ret);
