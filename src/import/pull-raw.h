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
#include "import-util.h"

typedef struct RawPull RawPull;

typedef void (*RawPullFinished)(RawPull *p, int error, void *userdata);

int raw_pull_new(RawPull **ret, sd_event *event, const char *image_root, RawPullFinished on_finished, void *userdata);
RawPull* raw_pull_unref(RawPull *p);

DEFINE_TRIVIAL_CLEANUP_FUNC(RawPull*, raw_pull_unref);

int raw_pull_start(RawPull *p, const char *url, const char *local, uint64_t offset, uint64_t size_max, ImportFlags flags, ImportVerify verify, const struct iovec *checksum);
