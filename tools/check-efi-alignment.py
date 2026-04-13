#!/usr/bin/env python3
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
# vi: set tw=110 sw=4 ts=4 et:

import sys

try:
    import pefile
except ImportError as e:
    print(str(e), file=sys.stderr)
    sys.exit(77)


def main():
    pe = pefile.PE(sys.argv[1], fast_load=True)

    for section in pe.sections:
        name = section.Name.rstrip(b"\x00").decode()
        file_addr = section.PointerToRawData
        virt_addr = section.VirtualAddress
        print(f"{name:10s} file=0x{file_addr:08x} virt=0x{virt_addr:08x}")

        if file_addr % 512 != 0:
            print(f"File address of {name} section is not aligned to 512 bytes", file=sys.stderr)
            return 1

        if virt_addr % 512 != 0:
            print(f"Virt address of {name} section is not aligned to 512 bytes", file=sys.stderr)
            return 1

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} pe-image")
        sys.exit(1)

    sys.exit(main())
