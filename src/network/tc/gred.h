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
/* SPDX-License-Identifier: LGPL-2.1-or-later
 * Copyright © 2020 VMware, Inc. */
#pragma once

#include "shared-forward.h"
#include "qdisc.h"

typedef struct GenericRandomEarlyDetection {
        QDisc meta;

        uint32_t virtual_queues;
        uint32_t default_virtual_queue;
        int grio;
} GenericRandomEarlyDetection;

DEFINE_QDISC_CAST(GRED, GenericRandomEarlyDetection);
extern const QDiscVTable gred_vtable;

CONFIG_PARSER_PROTOTYPE(config_parse_gred_u32);
CONFIG_PARSER_PROTOTYPE(config_parse_gred_bool);
