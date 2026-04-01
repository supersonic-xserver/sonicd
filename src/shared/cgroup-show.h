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

int show_cgroup_by_path(const char *path, const char *prefix, size_t n_columns, OutputFlags flags);
int show_cgroup(const char *path, const char *prefix, size_t n_columns, OutputFlags flags);
int show_cgroup_and_extra(
                const char *path,
                const char *prefix,
                size_t n_columns,
                const pid_t extra_pids[],
                size_t n_extra_pids,
                OutputFlags flags);

int show_cgroup_get_unit_path_and_warn(
                sd_bus *bus,
                const char *unit,
                char **ret);
int show_cgroup_get_path_and_warn(
                const char *machine,
                const char *prefix,
                char **ret);
