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

#define EFI_CONSOLE_CONTROL_PROTOCOL_GUID \
        GUID_DEF(0xf42f7782, 0x12e, 0x4c12, 0x99, 0x56, 0x49, 0xf9, 0x43, 0x4, 0xf7, 0x21)

typedef enum {
        EfiConsoleControlScreenText,
        EfiConsoleControlScreenGraphics,
        EfiConsoleControlScreenMaxValue,
} EFI_CONSOLE_CONTROL_SCREEN_MODE;

typedef struct EFI_CONSOLE_CONTROL_PROTOCOL EFI_CONSOLE_CONTROL_PROTOCOL;
struct EFI_CONSOLE_CONTROL_PROTOCOL {
        EFI_STATUS (EFIAPI *GetMode)(
                        EFI_CONSOLE_CONTROL_PROTOCOL *This,
                        EFI_CONSOLE_CONTROL_SCREEN_MODE *Mode,
                        bool *UgaExists,
                        bool *StdInLocked);
        EFI_STATUS (EFIAPI *SetMode)(
                        EFI_CONSOLE_CONTROL_PROTOCOL *This,
                        EFI_CONSOLE_CONTROL_SCREEN_MODE Mode);
        EFI_STATUS(EFIAPI *LockStdIn)(
                        EFI_CONSOLE_CONTROL_PROTOCOL *This,
                        char16_t *Password);
};
