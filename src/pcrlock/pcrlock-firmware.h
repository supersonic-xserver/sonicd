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
#include "tpm2-event-log.h"

int validate_firmware_event(
                const TCG_PCR_EVENT2 *event,
                size_t left,
                const TCG_EfiSpecIdEventAlgorithmSize *algorithms,
                size_t n_algorithms,
                const TCG_PCR_EVENT2 **ret_next_event,
                size_t *ret_left,
                const void **ret_payload,
                size_t *ret_payload_size);

int validate_firmware_header(
                const void *start,
                size_t size,
                const TCG_EfiSpecIdEventAlgorithmSize **ret_algorithms,
                size_t *ret_n_algorithms,
                const TCG_PCR_EVENT2 **ret_first,
                size_t *ret_left);
