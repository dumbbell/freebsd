/*-
 * Copyright (c) 2010 Isilon Systems, Inc.
 * Copyright (c) 2010 iX Systems, Inc.
 * Copyright (c) 2010 Panasas, Inc.
 * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice unmodified, this list of conditions, and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef	_ASM_ATOMIC_H_
#define	_ASM_ATOMIC_H_

#include <linux/_linuxapi_shim.h>

#include <sys/cdefs.h>
#include <sys/types.h>
#include <machine/atomic.h>

typedef struct {
	volatile u_int counter;
} atomic_t;

#define	atomic_add(i, v)		atomic_add_return((i), (v))
#define	atomic_sub(i, v)		atomic_sub_return((i), (v))
#define	atomic_inc_return(v)		atomic_add_return(1, (v))
#define	atomic_add_negative(i, v)	(atomic_add_return((i), (v)) < 0)
#define	atomic_sub_and_test(i, v)	(atomic_sub_return((i), (v)) == 0)
#define	atomic_dec_and_test(v)		(atomic_sub_return(1, (v)) == 0)
#define	atomic_inc_and_test(v)		(atomic_add_return(1, (v)) == 0)
#define atomic_dec_return(v)             atomic_sub_return(1, (v))

#define atomic_add_return LINUXAPI_PREFIXED_SYM(atomic_add_return)
#define atomic_add_return LINUXAPI_PREFIXED_SYM(atomic_add_return)
static inline int
atomic_add_return(int i, atomic_t *v)
{
	return i + atomic_fetchadd_int(&v->counter, i);
}

#define atomic_sub_return LINUXAPI_PREFIXED_SYM(atomic_sub_return)
#define atomic_sub_return LINUXAPI_PREFIXED_SYM(atomic_sub_return)
static inline int
atomic_sub_return(int i, atomic_t *v)
{
	return atomic_fetchadd_int(&v->counter, -i) - i;
}

#define atomic_set LINUXAPI_PREFIXED_SYM(atomic_set)
#define atomic_set LINUXAPI_PREFIXED_SYM(atomic_set)
static inline void
atomic_set(atomic_t *v, int i)
{
	atomic_store_rel_int(&v->counter, i);
}

#define atomic_read LINUXAPI_PREFIXED_SYM(atomic_read)
#define atomic_read LINUXAPI_PREFIXED_SYM(atomic_read)
static inline int
atomic_read(atomic_t *v)
{
	return atomic_load_acq_int(&v->counter);
}

#define atomic_inc LINUXAPI_PREFIXED_SYM(atomic_inc)
#define atomic_inc LINUXAPI_PREFIXED_SYM(atomic_inc)
static inline int
atomic_inc(atomic_t *v)
{
	return atomic_fetchadd_int(&v->counter, 1) + 1;
}

#define atomic_dec LINUXAPI_PREFIXED_SYM(atomic_dec)
#define atomic_dec LINUXAPI_PREFIXED_SYM(atomic_dec)
static inline int
atomic_dec(atomic_t *v)
{
	return atomic_fetchadd_int(&v->counter, -1) - 1;
}

#define atomic_add_unless LINUXAPI_PREFIXED_SYM(atomic_add_unless)
#define atomic_add_unless LINUXAPI_PREFIXED_SYM(atomic_add_unless)
static inline int atomic_add_unless(atomic_t *v, int a, int u)
{
        int c, old;
        c = atomic_read(v);
        for (;;) {
                if (unlikely(c == (u)))
                        break;
                old = atomic_cmpset_int(&v->counter, c, c + (a));
                if (likely(old == c))
                        break;
                c = old;
        }
        return c != (u);
}

#define atomic_inc_not_zero(v) atomic_add_unless((v), 1, 0)




#endif	/* _ASM_ATOMIC_H_ */
