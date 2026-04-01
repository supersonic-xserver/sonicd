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
#include "nspawn-settings.h"

int create_subcgroup(
                const PidRef *pid,
                bool keep_unit,
                uid_t uid_shift,
                int userns_fd,
                UserNamespaceMode userns_mode);

int mount_cgroups(const char *dest, bool accept_existing);
int bind_mount_cgroup_hierarchy(void);
