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
set -eu
set -o pipefail

# In kernel's arch/parisc/include/uapi/asm/errno.h, The following aliases are defined:
# ECANCELLED → ECANCELED
# EREFUSED → ECONNREFUSED
# EFSBADCRC → EBADMSG
# EFSCORRUPTED → EUCLEAN
# Let's drop them.

CC=${1:?}
shift

$CC -dM -include errno.h "$@" - </dev/null | \
       grep -Ev '^#define[[:space:]]+(ECANCELLED|EREFUSED|EFSBADCRC|EFSCORRUPTED)' | \
       awk '/^#define[ \t]+E[^ _]+[ \t]+/ { print $2; }'
