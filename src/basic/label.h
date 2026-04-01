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

#include "basic-forward.h"

typedef struct LabelOps {
        int (*pre)(int dir_fd, const char *path, mode_t mode);
        int (*post)(int dir_fd, const char *path, bool created);
} LabelOps;

int label_ops_set(const LabelOps *label_ops);
void label_ops_reset(void);

int label_ops_pre(int dir_fd, const char *path, mode_t mode);
int label_ops_post(int dir_fd, const char *path, bool created);
