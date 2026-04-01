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

typedef struct WebCacheItem {
        char *url;
        bool verified;
        size_t size;
        uint8_t data[];
} WebCacheItem;

/* A simple in-memory cache for downloaded manifests. Very likely multiple transfers will use the same
 * manifest URLs, hence let's make sure we only download them once within each sysupdate invocation. */

int web_cache_add_item(Hashmap **cache, const char *url, bool verified, const void *data, size_t size);

WebCacheItem* web_cache_get_item(Hashmap *cache, const char *url, bool verified);
