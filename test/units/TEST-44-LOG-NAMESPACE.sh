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

journalctl --list-namespaces -o json | jq .

systemd-run --wait -p LogNamespace=foobar echo "hello world"
systemd-run --wait -p LogNamespace=foobaz echo "hello world"

journalctl --namespace=foobar --sync
journalctl --namespace=foobaz --sync
ls -l /var/log/journal/
journalctl --list-namespaces

journalctl -o cat --namespace=foobar >/tmp/hello-world
journalctl -o cat >/tmp/no-hello-world

journalctl --list-namespaces | grep foobar
journalctl --list-namespaces | grep foobaz
journalctl --list-namespaces -o json | jq .
[[ "$(journalctl --root=/tmp --list-namespaces --quiet)" == "" ]]

grep "^hello world$" /tmp/hello-world
(! grep "^hello world$" /tmp/no-hello-world)

touch /testok
