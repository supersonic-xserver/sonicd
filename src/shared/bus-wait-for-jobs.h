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

typedef struct BusWaitForJobs BusWaitForJobs;

typedef enum WaitJobsFlags {
        BUS_WAIT_JOBS_LOG_ERROR   = 1 << 0,
        BUS_WAIT_JOBS_LOG_SUCCESS = 1 << 1,
} WaitJobsFlags;

BusWaitForJobs* bus_wait_for_jobs_free(BusWaitForJobs *d);
DEFINE_TRIVIAL_CLEANUP_FUNC(BusWaitForJobs*, bus_wait_for_jobs_free);

int bus_wait_for_jobs_new(sd_bus *bus, BusWaitForJobs **ret);
int bus_wait_for_jobs_add(BusWaitForJobs *d, const char *path);
int bus_wait_for_jobs(BusWaitForJobs *d, WaitJobsFlags flags, const char* const* extra_args);
int bus_wait_for_jobs_one(BusWaitForJobs *d, const char *path, WaitJobsFlags flags, const char* const* extra_args);
