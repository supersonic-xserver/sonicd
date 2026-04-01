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

int bpf_devices_cgroup_init(BPFProgram **ret, CGroupDevicePolicy policy, bool allow_list);
int bpf_devices_apply_policy(
                BPFProgram **prog,
                CGroupDevicePolicy policy,
                bool allow_list,
                const char *cgroup_path,
                BPFProgram **prog_installed);

int bpf_devices_allow_list_device(BPFProgram *prog, const char *path, const char *node, CGroupDevicePermissions p);
int bpf_devices_allow_list_major(BPFProgram *prog, const char *path, const char *name, char type, CGroupDevicePermissions p);
int bpf_devices_allow_list_static(BPFProgram *prog, const char *path);
