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

/* IWYU pragma: always_keep */

#include "conf-parser-forward.h"    /* IWYU pragma: export */
#include "shared-forward.h"         /* IWYU pragma: export */

typedef enum Storage Storage;
typedef enum SplitMode SplitMode;
typedef enum AuditSetMode AuditSetMode;
typedef struct JournalCompressOptions JournalCompressOptions;
typedef struct JournalConfig JournalConfig;

typedef struct Manager Manager;
typedef struct StreamSyncReq StreamSyncReq;
typedef struct SyncReq SyncReq;
typedef struct ClientContext ClientContext;
typedef struct StdoutStream StdoutStream;
