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
#!/usr/bin/env bash
# SPDX-License-Identifier: LGPL-2.1-or-later
set -eux
set -o pipefail

export SYSTEMD_LOG_LEVEL=debug

# Ensure that sandboxing doesn't stop creds from being accessible
echo "test" >/tmp/testdata
systemd-creds encrypt /tmp/testdata /tmp/testdata.encrypted --with-key=tpm2
# LoadCredentialEncrypted
systemd-run -p PrivateDevices=yes -p LoadCredentialEncrypted=testdata.encrypted:/tmp/testdata.encrypted --pipe --wait systemd-creds cat testdata.encrypted | cmp - /tmp/testdata
# SetCredentialEncrypted
systemd-run -p PrivateDevices=yes -p SetCredentialEncrypted=testdata.encrypted:"$(cat /tmp/testdata.encrypted)" --pipe --wait systemd-creds cat testdata.encrypted | cmp - /tmp/testdata

rm -f /tmp/testdata
