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

#include "homework-forward.h"

int home_setup_directory(UserRecord *h, HomeSetup *setup);
int home_activate_directory(UserRecord *h, HomeSetupFlags flags, HomeSetup *setup, PasswordCache *cache, UserRecord **ret_home);
int home_create_directory_or_subvolume(UserRecord *h, HomeSetup *setup, UserRecord **ret_home);
int home_resize_directory(UserRecord *h, HomeSetupFlags flags, HomeSetup *setup, PasswordCache *cache, UserRecord **ret_home);
