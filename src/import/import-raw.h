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

typedef struct RawImport RawImport;

typedef void (*RawImportFinished)(RawImport *i, int error, void *userdata);

int raw_import_new(RawImport **ret, sd_event *event, const char *image_root, RawImportFinished on_finished, void *userdata);
RawImport* raw_import_unref(RawImport *i);

DEFINE_TRIVIAL_CLEANUP_FUNC(RawImport*, raw_import_unref);

int raw_import_start(RawImport *i, int fd, const char *local, uint64_t offset, uint64_t size_max, ImportFlags flags);
