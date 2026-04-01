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

#include "homework-forward.h"

int home_mount_node(const char *node, const char *fstype, bool discard, unsigned long flags, const char *extra_mount_options);
int home_unshare_and_mkdir(void);
int home_unshare_and_mount(const char *node, const char *fstype, bool discard, unsigned long flags, const char *extra_mount_options);
int home_move_mount(const char *mount_suffix, const char *target);
int home_shift_uid(int dir_fd, const char *target, uid_t stored_uid, uid_t exposed_uid, int *ret_mount_fd);
