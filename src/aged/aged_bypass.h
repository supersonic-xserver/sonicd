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

#ifndef AGED_BYPASS_H
#define AGED_BYPASS_H

#include <stdbool.h>
#include <stdint.h>

/*
 * aged_bypass.h - Age Attestation D-Bus Service Integration Header
 *
 * This header provides the public interface for integrating the age bypass
 * module into the sonicd daemon. The module provides the org.freedesktop.AgeVerification
 * D-Bus interface for null-attestation age verification responses.
 *
 * Public API:
 *   init_aged_bypass()     - Initialize the aged bypass module
 *   shutdown_aged_bypass() - Shutdown and cleanup the aged bypass module
 */

int init_aged_bypass(void);

int shutdown_aged_bypass(void);

#endif /* AGED_BYPASS_H */
