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

#define EFI_RNG_PROTOCOL_GUID \
        GUID_DEF(0x3152bca5, 0xeade, 0x433d, 0x86, 0x2e, 0xc0, 0x1c, 0xdc, 0x29, 0x1f, 0x44)

typedef struct EFI_RNG_PROTOCOL EFI_RNG_PROTOCOL;
struct EFI_RNG_PROTOCOL {
        EFI_STATUS (EFIAPI *GetInfo)(
                        EFI_RNG_PROTOCOL *This,
                        size_t *RNGAlgorithmListSize,
                        EFI_GUID *RNGAlgorithmList);
        EFI_STATUS (EFIAPI *GetRNG)(
                        EFI_RNG_PROTOCOL *This,
                        EFI_GUID *RNGAlgorithm,
                        size_t RNGValueLength,
                        uint8_t *RNGValue);
};
