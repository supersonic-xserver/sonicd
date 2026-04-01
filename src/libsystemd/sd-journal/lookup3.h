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
/* SPDX-License-Identifier: LicenseRef-lookup3-public-domain */
#pragma once

#include "sd-forward.h"

uint32_t jenkins_hashword(const uint32_t *k, size_t length, uint32_t initval) _pure_;
void jenkins_hashword2(const uint32_t *k, size_t length, uint32_t *pc, uint32_t *pb);

uint32_t jenkins_hashlittle(const void *key, size_t length, uint32_t initval) _pure_;
void jenkins_hashlittle2(const void *key, size_t length, uint32_t *pc, uint32_t *pb);

uint32_t jenkins_hashbig(const void *key, size_t length, uint32_t initval) _pure_;

static inline uint64_t jenkins_hash64(const void *data, size_t length) {
        uint32_t a = 0, b = 0;

        jenkins_hashlittle2(data, length, &a, &b);

        return ((uint64_t) a << 32ULL) | (uint64_t) b;
}
