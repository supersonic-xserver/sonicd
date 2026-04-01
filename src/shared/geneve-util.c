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

#include "geneve-util.h"
#include "string-table.h"

static const char* const geneve_df_table[_NETDEV_GENEVE_DF_MAX] = {
        [NETDEV_GENEVE_DF_UNSET]   = "unset",
        [NETDEV_GENEVE_DF_SET]     = "set",
        [NETDEV_GENEVE_DF_INHERIT] = "inherit",
};

DEFINE_STRING_TABLE_LOOKUP(geneve_df, GeneveDF);
