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

#include "resolved-forward.h"

typedef void (HookCompleteCallback)(HookQuery *q, int rcode, DnsAnswer *answer, void *userdata);

int manager_hook_query(Manager *m, DnsQuestion *question_idna, DnsQuestion *question_utf8, HookCompleteCallback complete_cb, void *userdata, HookQuery **ret);

HookQuery* hook_query_free(HookQuery *hq);
