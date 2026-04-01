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

#include "sd-forward.h"

int catalog_import_file(OrderedHashmap **h, int fd, const char *path);
int catalog_update(const char *database, const char *root, const char* const *dirs);
int catalog_get(const char *database, sd_id128_t id, char **ret_text);
int catalog_list(FILE *f, const char *database, bool oneline);
int catalog_list_items(FILE *f, const char *database, bool oneline, char **items);
int catalog_file_lang(const char *filename, char **ret);
