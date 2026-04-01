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

#include "shared-forward.h"

int register_machine(
                sd_bus *bus,
                const char *machine_name,
                sd_id128_t uuid,
                const char *service,
                const PidRef *pidref,
                const char *directory,
                unsigned cid,
                const char *address,
                const char *key_path,
                bool allocate_unit,
                RuntimeScope scope);

int unregister_machine(sd_bus *bus, const char *machine_name);
