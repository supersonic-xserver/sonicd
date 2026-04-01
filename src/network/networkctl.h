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
#include "pager.h"

extern PagerFlags arg_pager_flags;
extern bool arg_legend;
extern bool arg_no_reload;
extern bool arg_all;
extern bool arg_stats;
extern bool arg_full;
extern bool arg_runtime;
extern bool arg_stdin;
extern unsigned arg_lines;
extern char *arg_drop_in;
extern sd_json_format_flags_t arg_json_format_flags;
extern bool arg_ask_password;
