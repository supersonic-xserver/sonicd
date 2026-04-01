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

int verb_link_delete(int argc, char *argv[], uintptr_t _data, void *userdata);
int verb_link_varlink_simple_method(int argc, char *argv[], uintptr_t _data, void *userdata);
int verb_reload(int argc, char *argv[], uintptr_t _data, void *userdata);
int verb_persistent_storage(int argc, char *argv[], uintptr_t _data, void *userdata);
