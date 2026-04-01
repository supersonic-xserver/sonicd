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

if conf.get('HAVE_LIBMOUNT') != 1
        subdir_done()
endif

executables += [
        generator_template + {
                'name' : 'systemd-fstab-generator',
                'sources' : files('fstab-generator.c'),
                'dependencies' : libmount_cflags,
        },
]

assert(libexecdir / fs.name(systemgeneratordir) == systemgeneratordir)
install_symlink('systemd-sysroot-fstab-check',
                pointing_to : fs.name(systemgeneratordir) / 'systemd-fstab-generator',
                install_dir : libexecdir)
