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

int clock_is_localtime(const char *adjtime_path);
int clock_set_timezone(int *ret_minutesdelta);

#define EPOCH_CLOCK_FILE "/usr/lib/clock-epoch"
#define TIMESYNCD_CLOCK_FILE_DIR "/var/lib/systemd/timesync/"
#define TIMESYNCD_CLOCK_FILE TIMESYNCD_CLOCK_FILE_DIR "clock"
