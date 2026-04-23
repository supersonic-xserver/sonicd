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

# Static version - bypass VCS querying to prevent build hangs
VERSION_STRING = 'sonicd-261-custom'

# Generate version.h using custom_target to create a proper Target
# Use a wrapper script or direct command approach
version_h = custom_target(
        'version.h',
        output : 'version.h',
        input : 'version.h.in',
        command : [
                'sh', '-c',
                'VERSION_STRING=sonicd-261-custom && sed "s/@VERSION_STRING@/$VERSION_STRING/g" < @INPUT@ > @OUTPUT@',
        ],
)

version_include = include_directories('.')
userspace_sources += [version_h]