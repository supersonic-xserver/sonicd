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

int fsync_directory_of_file(int fd);
int fsync_full(int fd);

int fsync_path_at(int at_fd, const char *path);
int fsync_parent_at(int at_fd, const char *path);
int fsync_path_and_parent_at(int at_fd, const char *path);

int syncfs_path(int at_fd, const char *path);
