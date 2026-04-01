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

#include "sd-hwdb.h" /* IWYU pragma: export */

#include "shared-forward.h"

bool hwdb_should_reload(sd_hwdb *hwdb);
int hwdb_update(const char *root, const char *hwdb_bin_dir, bool strict, bool compat);
int hwdb_query(const char *modalias, const char *root);
int hwdb_bypass(void);
