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
 * Copyright © 2019 VMware, Inc. */
#pragma once

#include "qdisc.h"

typedef struct ControlledDelay {
        QDisc meta;

        uint32_t packet_limit;
        usec_t interval_usec;
        usec_t target_usec;
        usec_t ce_threshold_usec;
        int ecn;
} ControlledDelay;

DEFINE_QDISC_CAST(CODEL, ControlledDelay);
extern const QDiscVTable codel_vtable;

CONFIG_PARSER_PROTOTYPE(config_parse_codel_u32);
CONFIG_PARSER_PROTOTYPE(config_parse_codel_usec);
CONFIG_PARSER_PROTOTYPE(config_parse_codel_bool);
