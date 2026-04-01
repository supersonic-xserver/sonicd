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

simple_fuzzers += files(
        'fuzz-bootspec.c',
        'fuzz-bus-label.c',
        'fuzz-calendarspec.c',
        'fuzz-catalog.c',
        'fuzz-env-file.c',
        'fuzz-hostname-setup.c',
        'fuzz-json.c',
        'fuzz-time-util.c',
        'fuzz-udev-database.c',
        'fuzz-user-record.c',
        'fuzz-varlink.c',
        'fuzz-varlink-idl.c',
)

# The following fuzzers do not work on oss-fuzz. See #11018.
if not want_ossfuzz
        simple_fuzzers += files('fuzz-compress.c')
endif
