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

#include "varlink-io.systemd.PCRLock.h"

static SD_VARLINK_DEFINE_METHOD_FULL(
                ReadEventLog,
                SD_VARLINK_REQUIRES_MORE,
                SD_VARLINK_DEFINE_OUTPUT(record, SD_VARLINK_OBJECT, 0));

static SD_VARLINK_DEFINE_METHOD(
                MakePolicy,
                SD_VARLINK_DEFINE_INPUT(force, SD_VARLINK_BOOL, SD_VARLINK_NULLABLE));

static SD_VARLINK_DEFINE_METHOD(
                RemovePolicy);

static SD_VARLINK_DEFINE_ERROR(
                NoChange);

SD_VARLINK_DEFINE_INTERFACE(
                io_systemd_PCRLock,
                "io.systemd.PCRLock",
                &vl_method_ReadEventLog,
                &vl_method_MakePolicy,
                &vl_method_RemovePolicy,
                &vl_error_NoChange);
