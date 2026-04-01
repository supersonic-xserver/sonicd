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

#include "basic-forward.h"

int parse_env_filev(FILE *f, const char *fname, va_list ap);
int parse_env_file_fdv(int fd, const char *fname, va_list ap);
int parse_env_file_sentinel(FILE *f, const char *fname, ...) _sentinel_;
#define parse_env_file(f, fname, ...) parse_env_file_sentinel(f, fname, __VA_ARGS__, NULL)
int parse_env_file_fd_sentinel(int fd, const char *fname, ...) _sentinel_;
#define parse_env_file_fd(fd, fname, ...) parse_env_file_fd_sentinel(fd, fname, __VA_ARGS__, NULL)

int parse_env_datav(const char *data, size_t size, const char *fname, va_list ap);
int parse_env_data_sentinel(const char *data, size_t size, const char *fname, ...) _sentinel_;
#define parse_env_data(text, size, fname, ...) parse_env_data_sentinel(text, size, fname, __VA_ARGS__, NULL)

int load_env_file(FILE *f, const char *fname, char ***ret);
int load_env_file_pairs(FILE *f, const char *fname, char ***ret);
int load_env_file_pairs_fd(int fd, const char *fname, char ***ret);

int merge_env_file(char ***env, FILE *f, const char *fname);

typedef enum WriteEnvFileFlags {
        WRITE_ENV_FILE_LABEL = 1 << 0,
} WriteEnvFileFlags;

int write_env_file(int dir_fd, const char *fname, char **headers, char **l, WriteEnvFileFlags flags);

int write_vconsole_conf(int dir_fd, const char *fname, char **l);

void env_file_fputs_assignment(FILE *f, const char *k, const char *v);
