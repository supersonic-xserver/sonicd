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

aged_bypass_sources = files(
        'aged_bypass.c',
)

agectl_sources = files(
        'agectl.c',
)

# Create a static library for integration with the main daemon
libaged_bypass = static_library(
        'aged-bypass',
        aged_bypass_sources,
        include_directories : includes,
)

# Add to global sources for linking with daemon
sources += libaged_bypass

# Keep the standalone executable for testing
executables += [
        executable_template + {
                'name' : 'aged-bypass',
                'public' : true,
                'sources' : aged_bypass_sources,
        },
        executable_template + {
                'name' : 'agectl',
                'public' : true,
                'sources' : agectl_sources,
        },
]
