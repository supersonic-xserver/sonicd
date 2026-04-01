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

#include "constants.h"
#include "shared-forward.h"

#define PORTABLE_PROFILE_DIRS CONF_PATHS_NULSTR("systemd/portable/profile")

int portable_profile_dirs(RuntimeScope scope, char ***ret);
int find_portable_profile(RuntimeScope scope, const char *name, const char *unit, char **ret_path);
