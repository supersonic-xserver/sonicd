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

#include "timesyncd-forward.h"

const struct ConfigPerfItem* timesyncd_gperf_lookup(const char *str, GPERF_LEN_TYPE length);

int manager_parse_server_string(Manager *m, ServerType type, const char *string);

CONFIG_PARSER_PROTOTYPE(config_parse_servers);

int manager_parse_config_file(Manager *m);
int manager_parse_fallback_string(Manager *m, const char *string);
