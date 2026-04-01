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

vcs_tag = get_option('vcs-tag')
version_h = custom_target('version',
        build_always_stale : vcs_tag,
        input : 'version.h.in',
        output : 'version.h',
        capture : true,
        command : [
                vcs_tag_sh,
                '@INPUT@',
                get_option('mode'),
                vcs_tag ? '1' : '0',
        ])
version_include = include_directories('.')
userspace_sources += [version_h]
