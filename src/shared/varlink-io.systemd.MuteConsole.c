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

#include "varlink-io.systemd.MuteConsole.h"

static SD_VARLINK_DEFINE_METHOD_FULL(
                Mute,
                SD_VARLINK_REQUIRES_MORE,
                SD_VARLINK_FIELD_COMMENT("Whether to mute the kernel's output to the console (defaults to true)."),
                SD_VARLINK_DEFINE_INPUT(kernel, SD_VARLINK_BOOL, SD_VARLINK_NULLABLE),
                SD_VARLINK_FIELD_COMMENT("Whether to mute PID1's output to the console (defaults to true)."),
                SD_VARLINK_DEFINE_INPUT(pid1, SD_VARLINK_BOOL, SD_VARLINK_NULLABLE));

SD_VARLINK_DEFINE_INTERFACE(
                io_systemd_MuteConsole,
                "io.systemd.MuteConsole",
                SD_VARLINK_INTERFACE_COMMENT("API for temporarily muting noisy output to the main kernel console"),
                SD_VARLINK_SYMBOL_COMMENT("Mute kernel and PID 1 output to the main kernel console"),
                &vl_method_Mute);
