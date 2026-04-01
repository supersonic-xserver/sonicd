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

typedef struct XMLIntrospectOps {
        int (*on_path)(const char *path, void *userdata);
        int (*on_interface)(const char *name, uint64_t flags, void *userdata);
        int (*on_method)(const char *interface, const char *name, const char *signature, const char *result, uint64_t flags, void *userdata);
        int (*on_signal)(const char *interface, const char *name, const char *signature, uint64_t flags, void *userdata);
        int (*on_property)(const char *interface, const char *name, const char *signature, bool writable, uint64_t flags, void *userdata);
} XMLIntrospectOps;

int parse_xml_introspect(const char *prefix, const char *xml, const XMLIntrospectOps *ops, void *userdata);
