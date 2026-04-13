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
#!/usr/bin/python3
# SPDX-License-Identifier: LGPL-2.1-or-later

import socket
import sys

data = sys.stdin.buffer.read()
s = socket.create_connection(("localhost", 12345), timeout=15)
s.settimeout(15)
s.sendall(data)
received = b""
while len(received) < len(data):
    chunk = s.recv(65536)
    if not chunk:
        break
    received += chunk
sys.stdout.buffer.write(received)
s.close()
