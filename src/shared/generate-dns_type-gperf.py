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
#!/usr/bin/env python3
# SPDX-License-Identifier: LGPL-2.1-or-later

"""Generate %-from-name.gperf from %-list.txt
"""

import sys

name, prefix, input = sys.argv[1:]

print("""\
%{
_Pragma("GCC diagnostic ignored \\"-Wimplicit-fallthrough\\"")
#if __GNUC__ >= 15
_Pragma("GCC diagnostic ignored \\"-Wzero-as-null-pointer-constant\\"")
#endif
%}""")
print("""\
struct {}_name {{ const char* name; int id; }};
%null-strings
%%""".format(name))

for line in open(input):
    line = line.rstrip()
    s = line.replace('_', '-')
    print("{}, {}{}".format(s, prefix, line))
