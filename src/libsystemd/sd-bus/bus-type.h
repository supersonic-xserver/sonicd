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

bool bus_type_is_valid(char c) _const_;
bool bus_type_is_basic(char c) _const_;
/* "trivial" is systemd's term for what the D-Bus Specification calls
 * a "fixed type": that is, a basic type of fixed length */
bool bus_type_is_trivial(char c) _const_;
bool bus_type_is_container(char c) _const_;

int bus_type_get_alignment(char c) _const_;
int bus_type_get_size(char c) _const_;
