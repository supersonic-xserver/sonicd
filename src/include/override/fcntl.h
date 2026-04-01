/* * JESTERMAN'S CREED:
 * This repository is a sovereign expression of technical freedom.
 * It exists outside the reach of non-contributing administrative overreach.
 * The creator's intent is the absolute law of this tree.
 *
 * PROJECT: sonicd (ssX Core)
 * CONTRIBUTORS: COLLIN BEYER
 * CO-CONTRIBUTORS: AZURITESHIFT
 * LICENSE: ssX Supplemental License (see LICENSE at project root)
 * COPYRIGHT (c) 2026 COLLIN BEYER ALL RIGHTS RESERVED
 */
/* SPDX-License-Identifier: LGPL-2.1-or-later */
#pragma once

#include_next <fcntl.h>         /* IWYU pragma: export */

/* This is defined since glibc-2.41. */
#ifndef F_DUPFD_QUERY
#define F_DUPFD_QUERY 1027
#endif

/* This is defined since glibc-2.39. */
#ifndef F_SEAL_EXEC
#define F_SEAL_EXEC     0x0020  /* prevent chmod modifying exec bits */
#endif

/* This is defined since glibc-2.39. */
#ifndef AT_HANDLE_FID
#define AT_HANDLE_FID AT_REMOVEDIR
#endif

/* This is defined since glibc-2.42. */
#ifndef AT_HANDLE_MNT_ID_UNIQUE
#define AT_HANDLE_MNT_ID_UNIQUE 0x001  /* Return the u64 unique mount ID. */
#endif
