/*
 * Copyright (C) 2001,2002,2003 Philippe Gerum <rpm@xenomai.org>.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef _XENO_ASM_SIM_BITS_THREAD_H
#define _XENO_ASM_SIM_BITS_THREAD_H

static inline void xnarch_init_tcb (xnarchtcb_t *tcb)
{
    tcb->vmthread = NULL;
}

#define xnarch_alloc_stack(tcb,stacksize) 0
#define xnarch_free_stack(tcb)            do { } while(0)

#endif /* !_XENO_ASM_SIM_BITS_THREAD_H */
