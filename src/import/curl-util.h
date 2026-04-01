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

#include <curl/curl.h>

#include "shared-forward.h"

typedef struct CurlGlue CurlGlue;

typedef struct CurlGlue {
        sd_event *event;
        CURLM *curl;
        sd_event_source *timer;
        Hashmap *ios;
        sd_event_source *defer;

        void (*on_finished)(CurlGlue *g, CURL *curl, CURLcode code);
        void *userdata;
} CurlGlue;

int curl_glue_new(CurlGlue **glue, sd_event *event);
CurlGlue* curl_glue_unref(CurlGlue *glue);

DEFINE_TRIVIAL_CLEANUP_FUNC(CurlGlue*, curl_glue_unref);

int curl_glue_make(CURL **ret, const char *url, void *userdata);
int curl_glue_add(CurlGlue *g, CURL *c);
void curl_glue_remove_and_free(CurlGlue *g, CURL *c);

struct curl_slist *curl_slist_new(const char *first, ...) _sentinel_;
int curl_header_strdup(const void *contents, size_t sz, const char *field, char **value);
int curl_parse_http_time(const char *t, usec_t *ret);

DEFINE_TRIVIAL_CLEANUP_FUNC_FULL(CURL*, curl_easy_cleanup, NULL);
DEFINE_TRIVIAL_CLEANUP_FUNC_FULL(CURLM*, curl_multi_cleanup, NULL);
DEFINE_TRIVIAL_CLEANUP_FUNC_FULL(struct curl_slist*, curl_slist_free_all, NULL);
