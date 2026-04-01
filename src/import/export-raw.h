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
#include "import-compress.h"

typedef struct RawExport RawExport;

typedef void (*RawExportFinished)(RawExport *e, int error, void *userdata);

int raw_export_new(RawExport **ret, sd_event *event, RawExportFinished on_finished, void *userdata);
RawExport* raw_export_unref(RawExport *e);

DEFINE_TRIVIAL_CLEANUP_FUNC(RawExport*, raw_export_unref);

int raw_export_start(RawExport *e, const char *path, int fd, ImportCompressType compress);
