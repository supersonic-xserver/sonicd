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

#include "systemctl.h"

int verb_start(int argc, char *argv[], uintptr_t _data, void *userdata);

struct action_metadata {
        const char *target;
        const char *verb;
        const char *mode;
};

extern const struct action_metadata action_table[_ACTION_MAX];

enum action verb_to_action(const char *verb);
