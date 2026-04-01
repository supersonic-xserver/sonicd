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

#include "sd-forward.h"

int update_match_strv(Hashmap **match_strv, const char *key, const char *value, bool clear_on_null);
bool device_match_sysattr(sd_device *device, Hashmap *match_sysattr, Hashmap *nomatch_sysattr);
bool device_match_parent(sd_device *device, Set *match_parent, Set *nomatch_parent);
