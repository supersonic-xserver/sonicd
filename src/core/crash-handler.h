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

typedef enum CrashAction {
        CRASH_FREEZE,
        CRASH_REBOOT,
        CRASH_POWEROFF,
        _CRASH_ACTION_MAX,
        _CRASH_ACTION_INVALID = -EINVAL,
} CrashAction;

DECLARE_STRING_TABLE_LOOKUP(crash_action, CrashAction);

_noreturn_ void freeze_or_exit_or_reboot(void);
void install_crash_handler(void);
