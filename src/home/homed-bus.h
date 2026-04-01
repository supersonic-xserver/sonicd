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

#include "homed-forward.h"

int bus_message_read_secret(sd_bus_message *m, UserRecord **ret, sd_bus_error *error);
int bus_message_read_home_record(sd_bus_message *m, UserRecordLoadFlags flags, UserRecord **ret, sd_bus_error *error);
int bus_message_read_blobs(sd_bus_message *m, Hashmap **ret, sd_bus_error *error);
