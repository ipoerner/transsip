/*
 * netyack
 * By Daniel Borkmann <daniel@netyack.org>
 * Copyright 2009, 2010 Daniel Borkmann.
 * Subject to the GPL.
 */

#ifndef XMALLOC_H
#define XMALLOC_H

#include "compiler.h"

extern __hidden void *xmalloc(size_t size);
extern __hidden void *xalloca(size_t size);
extern __hidden void *xvalloc(size_t size);
extern __hidden void *xzmalloc(size_t size);
extern __hidden void *xmallocz(size_t size);
extern __hidden void *xmalloc_aligned(size_t size, size_t alignment);
extern __hidden void *xmemdupz(const void *data, size_t len);
extern __hidden void *xcalloc(size_t nmemb, size_t size);
extern __hidden void *xrealloc(void *ptr, size_t nmemb, size_t size);
extern __hidden void xfree(void *ptr);
extern __hidden char *xstrdup(const char *str);
extern __hidden char *xstrndup(const char *str, size_t size);
extern __hidden int xdup(int fd);
extern __hidden void muntrace_handler(int signal);
extern __hidden int xmem_used(void);
extern __hidden int xmem_free(void);
extern __hidden int xmem_totalarena(void);

#endif /* XMALLOC_H */
