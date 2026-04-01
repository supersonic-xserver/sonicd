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
#include "import-common.h"

typedef struct OciPull OciPull;

typedef void (*OciPullFinished)(OciPull *pull, int error, void *userdata);

int oci_pull_new(OciPull **ret, sd_event *event, const char *image_root, OciPullFinished on_finished, void *userdata);
OciPull* oci_pull_unref(OciPull *i);

DEFINE_TRIVIAL_CLEANUP_FUNC(OciPull*, oci_pull_unref);

int oci_pull_start(OciPull *i, const char *ref, const char *local, ImportFlags flags);
