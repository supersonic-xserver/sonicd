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
/* SPDX-License-Identifier: GPL-2.0-or-later */
#pragma once

#include "udev-forward.h"

int device_add_errno(sd_device *dev, int error);
int device_add_exit_status(sd_device *dev, int status);
int device_add_signal(sd_device *dev, int signo);
int device_broadcast_on_error(sd_device *dev, sd_device_monitor *monitor);
