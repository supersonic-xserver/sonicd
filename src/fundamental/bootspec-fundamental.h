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

#include "string-util-fundamental.h"

bool bootspec_pick_name_version_sort_key(
                const sd_char *os_pretty_name,
                const sd_char *os_image_id,
                const sd_char *os_name,
                const sd_char *os_id,
                const sd_char *os_image_version,
                const sd_char *os_version,
                const sd_char *os_version_id,
                const sd_char *os_build_id,
                const sd_char **ret_name,
                const sd_char **ret_version,
                const sd_char **ret_sort_key);
