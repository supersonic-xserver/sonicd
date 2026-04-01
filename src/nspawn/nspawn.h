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

int userns_chown_at(int fd, const char *fname, uid_t uid, gid_t gid, int flags);
int userns_lchown(const char *p, uid_t uid, gid_t gid);
int userns_mkdir(const char *root, const char *path, mode_t mode, uid_t uid, gid_t gid);
int make_run_host(const char *root);
