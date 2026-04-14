#!/usr/bin/env bash
# * JESTERMAN'S CREED:
# * This repository is a sovereign expression of technical freedom.
# * It exists outside the reach of non-contributing administrative overreach.
# * The creator's intent is the absolute law of this tree.
# *
# * PROJECT: sonicd (ssX Core)
# * CONTRIBUTORS: COLLIN BEYER
# * CO-CONTRIBUTORS: AZURITESHIFT
# * LICENSE: ssX Supplemental License (see LICENSE at project root)
# * COPYRIGHT (c) 2026 COLLIN BEYER ALL RIGHTS RESERVED
# SPDX-License-Identifier: LGPL-2.1-or-later
set -eux
set -o pipefail

export SYSTEMD_LOG_LEVEL=debug
SD_TPM2SETUP="/usr/lib/systemd/systemd-tpm2-setup"

if [[ ! -x "${SD_TPM2SETUP:?}" ]]; then
    echo "$SD_TPM2SETUP not found, skipping the test"
    exit 0
fi

"$SD_TPM2SETUP" --help
"$SD_TPM2SETUP" --version
"$SD_TPM2SETUP" --tpm2-device=list
"$SD_TPM2SETUP" --tpm2-device=auto
"$SD_TPM2SETUP" --tpm2-device=/dev/tpmrm0
"$SD_TPM2SETUP" --early=yes
"$SD_TPM2SETUP" --early=yes
"$SD_TPM2SETUP" --early=no
"$SD_TPM2SETUP" --early=no

(! "$SD_TPM2SETUP" "")
(! "$SD_TPM2SETUP" --tpm2-device=)
(! "$SD_TPM2SETUP" --tpm2-device=/dev/null)
(! "$SD_TPM2SETUP" --foo=bar)
