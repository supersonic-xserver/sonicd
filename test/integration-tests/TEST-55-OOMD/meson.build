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
                'credentials' : integration_test_template['credentials'] + [
                        files('systemd.unit-dropin.init.scope'),
                        # OpenSUSE disables all controller delegation for the user manager template. Mask the
                        # dropin to make TEST-55-OOMD pass on OpenSUSE.
                        'systemd.unit-dropin.user@.service~20-defaults-SUSE=',
                ],
                'vm' : true,
        },
]
