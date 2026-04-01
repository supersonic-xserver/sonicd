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

#include <linux/if_link.h>

#include "shared-forward.h"

typedef enum GeneveDF {
        NETDEV_GENEVE_DF_UNSET    = GENEVE_DF_UNSET,
        NETDEV_GENEVE_DF_SET      = GENEVE_DF_SET,
        NETDEV_GENEVE_DF_INHERIT  = GENEVE_DF_INHERIT,
        _NETDEV_GENEVE_DF_MAX,
        _NETDEV_GENEVE_DF_INVALID = -EINVAL,
} GeneveDF;

DECLARE_STRING_TABLE_LOOKUP(geneve_df, GeneveDF);
