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

#if HAVE_LIBBPF

#include <bpf/libbpf.h>

#include "shared-forward.h"

bool bpf_can_link_program(struct bpf_program *prog);

int bpf_serialize_link(FILE *f, FDSet *fds, const char *key, struct bpf_link *link);

struct bpf_link* bpf_link_free(struct bpf_link *link);
DEFINE_TRIVIAL_CLEANUP_FUNC(struct bpf_link *, bpf_link_free);

struct ring_buffer* bpf_ring_buffer_free(struct ring_buffer *rb);
DEFINE_TRIVIAL_CLEANUP_FUNC(struct ring_buffer *, bpf_ring_buffer_free);

#endif
