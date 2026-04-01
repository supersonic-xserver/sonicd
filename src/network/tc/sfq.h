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

#include "shared-forward.h"
#include "qdisc.h"

typedef struct StochasticFairnessQueueing {
        QDisc meta;

        usec_t perturb_period;
} StochasticFairnessQueueing;

DEFINE_QDISC_CAST(SFQ, StochasticFairnessQueueing);
extern const QDiscVTable sfq_vtable;

CONFIG_PARSER_PROTOTYPE(config_parse_sfq_perturb_period);
