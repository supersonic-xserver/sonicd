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

int dlopen_dw(void);
int dlopen_elf(void);

/* Parse an ELF object in a forked process, so that errors while iterating over
 * untrusted and potentially malicious data do not propagate to the main caller's process.
 * If fork_disable_dump, the child process will not dump core if it crashes. */
int parse_elf_object(
                int fd,
                const char *executable,
                const char *root,
                bool fork_disable_dump,
                char **ret,
                sd_json_variant **ret_package_metadata,
                sd_json_variant **ret_dlopen_metadata);
