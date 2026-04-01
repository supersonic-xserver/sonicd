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

EFI_STATUS initrd_register(
                const struct iovec *initrd,
                EFI_HANDLE *ret_initrd_handle);

EFI_STATUS initrd_unregister(EFI_HANDLE initrd_handle);

static inline void cleanup_initrd(EFI_HANDLE *initrd_handle) {
        (void) initrd_unregister(*initrd_handle);
        *initrd_handle = NULL;
}
