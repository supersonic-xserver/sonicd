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

#define EFI_SHELL_PARAMETERS_PROTOCOL_GUID \
        GUID_DEF(0x752f3136, 0x4e16, 0x4fdc, 0xa2, 0x2a, 0xe5, 0xf4, 0x68, 0x12, 0xf4, 0xca)

typedef struct {
        char16_t **Argv;
        size_t Argc;
        void *StdIn;
        void *StdOut;
        void *StdErr;
} EFI_SHELL_PARAMETERS_PROTOCOL;
