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

#include "efi.h"
#include "iovec-util-fundamental.h"

EFI_STATUS linux_exec(
                EFI_HANDLE parent,
                const char16_t *cmdline,
                const struct iovec *kernel,
                const struct iovec *initrd);
EFI_STATUS linux_exec_efi_handover(
                EFI_HANDLE parent,
                const char16_t *cmdline,
                const struct iovec *kernel,
                const struct iovec *initrd,
                size_t kernel_size_in_memory);
