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

#define DESTROY_IPC_FLAG (UINT32_C(1) << 31)

int manager_open_serialization(Manager *m, FILE **ret_f);
int manager_serialize(Manager *m, FILE *f, FDSet *fds, bool switching_root);
int manager_deserialize(Manager *m, FILE *f, FDSet *fds);
