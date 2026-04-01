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
# VM-specific auxiliary tests. Container-based ones go in TEST-74-AUX-UTILS.

integration_tests += [
        integration_test_template + {
                'name' : fs.name(meson.current_source_dir()),
                'storage': 'persistent',
                'coredump-exclude-regex' : '/(test-usr-dump|test-dump|test-stacktrace(-not)?-symbolized|bash)$',
                'vm' : true,
                'firmware' : 'auto',
        },
]
