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

#include "basic-forward.h"

typedef struct RateLimit {
        usec_t interval; /* Keep those two fields first so they can be initialized easily: */
        unsigned burst;  /* RateLimit rl = { INTERVAL, BURST }; */
        unsigned num;
        usec_t begin;
} RateLimit;

#define RATELIMIT_OFF (const RateLimit) { .interval = USEC_INFINITY, .burst = UINT_MAX }

static inline void ratelimit_reset(RateLimit *rl) {
        rl->num = rl->begin = 0;
}

static inline bool ratelimit_configured(const RateLimit *rl) {
        return rl->interval > 0 && rl->burst > 0;
}

bool ratelimit_below(RateLimit *rl);

unsigned ratelimit_num_dropped(const RateLimit *rl);

usec_t ratelimit_end(const RateLimit *rl);
usec_t ratelimit_left(const RateLimit *rl);
