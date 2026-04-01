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
                                'DefaultDependencies' : 'no',
                        },
                        'service' : integration_test_template['configuration']['service'] + {
                                'FileDescriptorStoreMax' : '3',
                                'NotifyAccess' : 'all',
                        },
                },
                'cmdline' : ['systemd.set_credential=kernelcmdlinecred:uff'],
                'storage' : 'persistent',
                'vm' : true,
        },
]
