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

int parse_boolean_argument(const char *optname, const char *s, bool *ret);
int parse_tristate_argument_with_auto(const char *optname, const char *s, int *ret);
int parse_json_argument(const char *s, sd_json_format_flags_t *ret);
int parse_path_argument(const char *path, bool suppress_root, char **arg);
int parse_signal_argument(const char *s, int *ret);
int parse_machine_argument(const char *s, const char **ret_host, BusTransport *ret_transport);
int parse_background_argument(const char *s, char **arg);
