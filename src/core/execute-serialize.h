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

#include "core-forward.h"

/* These functions serialize/deserialize for invocation purposes (i.e.: serialized object is passed to a
 * child process) rather than to save state across reload/reexec. */

int exec_serialize_invocation(FILE *f,
        FDSet *fds,
        const ExecContext *ctx,
        const ExecCommand *cmd,
        const ExecParameters *p,
        const ExecRuntime *rt,
        const CGroupContext *cg);

int exec_deserialize_invocation(FILE *f,
        FDSet *fds,
        ExecContext *ctx,
        ExecCommand *cmd,
        ExecParameters *p,
        ExecRuntime *rt,
        CGroupContext *cg);
