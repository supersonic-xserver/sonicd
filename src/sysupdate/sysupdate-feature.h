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

#include "sysupdate-forward.h"

typedef struct Feature {
        unsigned n_ref;

        char *id;

        char *description;
        char *documentation;
        char *appstream;

        bool enabled;
} Feature;

Feature *feature_new(void);

DECLARE_TRIVIAL_REF_UNREF_FUNC(Feature, feature);
DEFINE_TRIVIAL_CLEANUP_FUNC(Feature*, feature_unref);

extern const struct hash_ops feature_hash_ops;

int feature_read_definition(Feature *f, const char *path, const char *const *conf_file_dirs);
