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

integration_tests += [
        integration_test_template + {
                'name' : fs.name(meson.current_source_dir()),
                'configuration' : integration_test_template['configuration'] + {
                        'unit' : integration_test_template['configuration']['unit'] + {
                                'Wants' : ' '.join([
                                        'success-all.service',
                                        'success-start.service',
                                        'success-runtime.service',
                                        'success-stop.service',
                                        'fail-start.service',
                                        'fail-stop.service',
                                        'fail-runtime.service',
                                ]),
                                'StopWhenUnneeded' : 'yes',
                        },
                },
                'coredump-exclude-regex' : '/(bash|coreutils|gnusleep|sleep)$',
        },
]
