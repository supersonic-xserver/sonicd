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

typedef struct MachineCredential {
        char *id;
        char *data;
        size_t size;
} MachineCredential;

typedef struct MachineCredentialContext {
        MachineCredential *credentials;
        size_t n_credentials;
} MachineCredentialContext;

void machine_credential_context_done(MachineCredentialContext *ctx);

MachineCredential* machine_credential_find(MachineCredentialContext *ctx, const char *id);

int machine_credential_add(MachineCredentialContext *ctx, const char *id, const char *value, size_t size);
int machine_credential_set(MachineCredentialContext *ctx, const char *cred_str);
int machine_credential_load(MachineCredentialContext *ctx, const char *cred_path);
