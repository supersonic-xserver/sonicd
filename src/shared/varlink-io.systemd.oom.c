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

#include "varlink-io.systemd.oom.h"

/* This is oomd's Varlink service, where oomd is server and systemd --user is the client.
 *
 * Compare with io.systemd.ManagedOOM where the client/server roles of the service manager and oomd are
 * swapped! */

SD_VARLINK_DEFINE_STRUCT_TYPE(
                ControlGroup,
                SD_VARLINK_DEFINE_FIELD(mode, SD_VARLINK_STRING, 0),
                SD_VARLINK_DEFINE_FIELD(path, SD_VARLINK_STRING, 0),
                SD_VARLINK_DEFINE_FIELD(property, SD_VARLINK_STRING, 0),
                SD_VARLINK_DEFINE_FIELD(limit, SD_VARLINK_INT, SD_VARLINK_NULLABLE),
                SD_VARLINK_DEFINE_FIELD(duration, SD_VARLINK_INT, SD_VARLINK_NULLABLE));

static SD_VARLINK_DEFINE_METHOD(
                ReportManagedOOMCGroups,
                SD_VARLINK_DEFINE_INPUT_BY_TYPE(cgroups, ControlGroup, SD_VARLINK_ARRAY));

SD_VARLINK_DEFINE_INTERFACE(
                io_systemd_oom,
                "io.systemd.oom",
                &vl_method_ReportManagedOOMCGroups,
                &vl_type_ControlGroup);
