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

#include "systemctl.h"

int logind_reboot(enum action a);
int logind_check_inhibitors(enum action a);

int prepare_firmware_setup(void);
int prepare_boot_loader_menu(void);
int prepare_boot_loader_entry(void);

int logind_schedule_shutdown(enum action a);
int logind_cancel_shutdown(void);
int logind_show_shutdown(void);

int help_boot_loader_entry(void);
