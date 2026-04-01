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

#include <linux/pkt_sched.h>

#include "shared-forward.h"
#include "qdisc.h"

typedef struct EnhancedTransmissionSelection {
        QDisc meta;

        uint8_t n_bands;
        uint8_t n_strict;
        unsigned n_quanta;
        uint32_t quanta[TCQ_ETS_MAX_BANDS];
        unsigned n_prio;
        uint8_t prio[TC_PRIO_MAX + 1];
} EnhancedTransmissionSelection;

DEFINE_QDISC_CAST(ETS, EnhancedTransmissionSelection);
extern const QDiscVTable ets_vtable;

CONFIG_PARSER_PROTOTYPE(config_parse_ets_u8);
CONFIG_PARSER_PROTOTYPE(config_parse_ets_quanta);
CONFIG_PARSER_PROTOTYPE(config_parse_ets_prio);
