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

#include "time-util.h"

int verb_list_units(int argc, char *argv[], uintptr_t _data, void *userdata);
int verb_list_sockets(int argc, char *argv[], uintptr_t _data, void *userdata);
int verb_list_timers(int argc, char *argv[], uintptr_t _data, void *userdata);
int verb_list_automounts(int argc, char *argv[], uintptr_t _data, void *userdata);
int verb_list_paths(int argc, char *argv[], uintptr_t _data, void *userdata);

usec_t calc_next_elapse(const dual_timestamp *nw, const dual_timestamp *next);
