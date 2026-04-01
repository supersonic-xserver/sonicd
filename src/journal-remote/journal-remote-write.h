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

#include "journal-file.h"

typedef struct RemoteServer RemoteServer;

typedef struct Writer {
        JournalFile *journal;
        JournalMetrics metrics;
        char *output;          /* directory where we write, for vacuuming */

        MMapCache *mmap;
        RemoteServer *server;
        char *hashmap_key;

        uint64_t seqnum;

        unsigned n_ref;
} Writer;

int writer_new(RemoteServer *server, Writer **ret);
DECLARE_TRIVIAL_REF_UNREF_FUNC(Writer, writer);

DEFINE_TRIVIAL_CLEANUP_FUNC(Writer*, writer_unref);

int writer_write(Writer *w,
                 const struct iovec_wrapper *iovw,
                 const dual_timestamp *ts,
                 const sd_id128_t *boot_id,
                 JournalFileFlags file_flags);

typedef enum JournalWriteSplitMode {
        JOURNAL_WRITE_SPLIT_NONE,
        JOURNAL_WRITE_SPLIT_HOST,
        _JOURNAL_WRITE_SPLIT_MAX,
        _JOURNAL_WRITE_SPLIT_INVALID = -EINVAL,
} JournalWriteSplitMode;
