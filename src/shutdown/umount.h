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

/***
  Copyright © 2010 ProFUSION embedded systems
***/

#include "shared-forward.h"
#include "list.h"

int umount_all(bool *changed, bool last_try);

/* This is exported just for testing */
typedef struct MountPoint {
        char *path;
        char *remount_options;
        unsigned long remount_flags;
        bool try_remount_ro;
        bool umount_lazily;
        bool umount_move_if_busy;
        LIST_FIELDS(struct MountPoint, mount_point);
} MountPoint;

int mount_points_list_get(FILE *f, MountPoint **head);
void mount_points_list_free(MountPoint **head);
