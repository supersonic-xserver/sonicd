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
/*
 * Port to systemd-boot
 * Copyright © 2017 Max Resch <resch.max@gmail.com>
 *
 * Security Policy Handling
 * Copyright © 2012 <James.Bottomley@HansenPartnership.com>
 * https://github.com/mjg59/efitools
 */
#pragma once

#include "efi.h"

bool shim_loaded(void);
bool shim_loader_available(void);
EFI_STATUS shim_load_image(EFI_HANDLE parent, const EFI_DEVICE_PATH *device_path, bool boot_policy, EFI_HANDLE *ret_image);
void shim_retain_protocol(void);
