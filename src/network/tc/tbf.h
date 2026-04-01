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

typedef struct TokenBucketFilter {
        QDisc meta;

        uint64_t rate;
        uint64_t peak_rate;
        uint32_t burst;
        uint32_t mtu;
        usec_t latency;
        size_t limit;
        size_t mpu;
} TokenBucketFilter;

DEFINE_QDISC_CAST(TBF, TokenBucketFilter);
extern const QDiscVTable tbf_vtable;

CONFIG_PARSER_PROTOTYPE(config_parse_tbf_latency);
CONFIG_PARSER_PROTOTYPE(config_parse_tbf_size);
CONFIG_PARSER_PROTOTYPE(config_parse_tbf_rate);
