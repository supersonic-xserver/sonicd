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

int rlimit_build_json(sd_json_variant **ret, const char *name, void *userdata);
int rlimit_table_build_json(sd_json_variant **ret, const char *name, void *userdata);
int cpuset_build_json(sd_json_variant **ret, const char *name, void *userdata);

const char* varlink_error_id_from_bus_error(const sd_bus_error *e);
