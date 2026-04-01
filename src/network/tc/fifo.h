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

typedef struct FirstInFirstOut {
        QDisc meta;

        uint32_t limit;
} FirstInFirstOut;

DEFINE_QDISC_CAST(PFIFO, FirstInFirstOut);
DEFINE_QDISC_CAST(BFIFO, FirstInFirstOut);
DEFINE_QDISC_CAST(PFIFO_HEAD_DROP, FirstInFirstOut);
DEFINE_QDISC_CAST(PFIFO_FAST, FirstInFirstOut);

extern const QDiscVTable pfifo_vtable;
extern const QDiscVTable bfifo_vtable;
extern const QDiscVTable pfifo_head_drop_vtable;
extern const QDiscVTable pfifo_fast_vtable;

CONFIG_PARSER_PROTOTYPE(config_parse_pfifo_size);
CONFIG_PARSER_PROTOTYPE(config_parse_bfifo_size);
