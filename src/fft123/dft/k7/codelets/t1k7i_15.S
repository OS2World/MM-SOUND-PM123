/*
 * Copyright (c) 2003 Matteo Frigo
 * Copyright (c) 2003 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sat Jul  5 21:52:30 EDT 2003 */

#include "config.h"



/* cheap-mode: VECTGRADE_FULL succeeded. (207 steps) */
/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft-k7/gen_twiddle -no-randomized-cse -n 15 -sign 1 -name t1k7i_15 */

/*
 * Generator Id's : 
 * $Id: t1k7i_15.S,v 1.1 2005/07/26 17:36:58 glass Exp $
 * $Id: t1k7i_15.S,v 1.1 2005/07/26 17:36:58 glass Exp $
 * $Id: t1k7i_15.S,v 1.1 2005/07/26 17:36:58 glass Exp $
 */

/* The following asm code is Copyright (c) 2000-2001 Stefan Kral */
.section .rodata
	.balign 64
KP500000000KP500000000: .float +0.500000000000000000000000000000000000000000000, +0.500000000000000000000000000000000000000000000
KP866025403KP866025403: .float +0.866025403784438646763723170752936183471402627, +0.866025403784438646763723170752936183471402627
KN866025403KN866025403: .float -0.866025403784438646763723170752936183471402627, -0.866025403784438646763723170752936183471402627
KP587785252KP951056516: .float +0.587785252292473129168705954639072768597652438, +0.951056516295153572116439333379382143405698634
KP951056516KP587785252: .float +0.951056516295153572116439333379382143405698634, +0.587785252292473129168705954639072768597652438
KP250000000KP250000000: .float +0.250000000000000000000000000000000000000000000, +0.250000000000000000000000000000000000000000000
chs_lo: .long 0x80000000, 0x00000000
KP559016994KP559016994: .float +0.559016994374947424102293417182819058860154590, +0.559016994374947424102293417182819058860154590
.text
.text
	.balign 64
t1k7i_15:
	subl $212, %esp
	femms 
	movl %ebx, 208(%esp)
	movl 228(%esp), %edx
	movl 236(%esp), %ebx
	movl %esi, 204(%esp)
	movl %edi, 200(%esp)
	movl 220(%esp), %ecx
	movl %ebp, 196(%esp)
	movl 224(%esp), %eax
	movl 232(%esp), %esi
	leal (,%edx,4), %edx
	leal (,%ebx,4), %ebx
	.p2align 4,,7
.L0:
	/* promise simd cell size = 8 */ 
	leal (%edx,%edx,4), %edi
	movq 32(%eax), %mm0
	movq 72(%eax), %mm3
	leal (%edx,%edx,2), %ebp
	movq 16(%eax), %mm6
	movq (%ecx,%edi), %mm1
	movq (%ecx,%edi,2), %mm4
	movq (%ecx,%ebp), %mm7
	leal (%ebp,%edx,8), %edi
	pswapd %mm1, %mm2
	pswapd %mm4, %mm5
	pfmul %mm0, %mm1
	pfmul %mm3, %mm4
	pfmul %mm0, %mm2
	pswapd %mm7, %mm0
	pfmul %mm3, %mm5
	movq 88(%eax), %mm3
	pfmul %mm6, %mm7
	pfnacc %mm4, %mm1
	movq (%ecx,%ebp,4), %mm4
	pfmul %mm6, %mm0
	pfacc %mm2, %mm5
	movq %mm1, %mm2
	pswapd %mm4, %mm6
	pfmul %mm3, %mm4
	pfacc %mm5, %mm1
	pfmul %mm3, %mm6
	movq 80(%eax), %mm3
	pfnacc %mm2, %mm5
	movq (%ecx,%edi), %mm2
	leal (%ebp,%edx,4), %edi
	pfnacc %mm4, %mm7
	movq %mm1, 16(%esp)
	pfmul KP500000000KP500000000, %mm1
	pfacc %mm6, %mm0
	pfmul KP866025403KP866025403, %mm5
	pswapd %mm2, %mm4
	movq 24(%eax), %mm6
	pfmul %mm3, %mm2
	pfmul %mm3, %mm4
	movq %mm0, 24(%esp)
	movq %mm1, 8(%esp)
	movq %mm5, 0(%esp)
	movq (%ecx,%edx,4), %mm3
	movq (%eax), %mm1
	movq (%ecx,%edx), %mm5
	pswapd %mm3, %mm0
	pfmul %mm6, %mm3
	pfmul %mm6, %mm0
	pswapd %mm5, %mm6
	pfmul %mm1, %mm5
	pfmul %mm1, %mm6
	movq 104(%eax), %mm1
	pfnacc %mm5, %mm2
	movq (%ecx,%edi,2), %mm5
	pfacc %mm6, %mm4
	pswapd %mm5, %mm6
	pfmul %mm1, %mm5
	pfmul %mm1, %mm6
	movq %mm4, 56(%esp)
	movq 40(%eax), %mm1
	movq %mm2, %mm4
	pfnacc %mm3, %mm5
	movq (%ecx,%ebp,2), %mm3
	leal (%edx,%edx,8), %ebp
	pfacc %mm0, %mm6
	pfnacc %mm5, %mm4
	pswapd %mm3, %mm0
	pfacc %mm5, %mm2
	movq 64(%eax), %mm5
	pfmul %mm1, %mm3
	movq %mm6, 40(%esp)
	movq (%ecx,%ebp), %mm6
	pfmul %mm1, %mm0
	pfmul KP866025403KP866025403, %mm4
	movq %mm2, 64(%esp)
	movq 56(%eax), %mm2
	pswapd %mm6, %mm1
	pfmul %mm5, %mm6
	pfmul %mm5, %mm1
	movq (%ecx,%edx,8), %mm5
	pfnacc %mm6, %mm3
	movq %mm4, 32(%esp)
	movq 48(%eax), %mm4
	pfacc %mm1, %mm0
	movq (%ecx,%edi), %mm1
	leal (%ebp,%edx,4), %edi
	pswapd %mm5, %mm6
	pfmul %mm2, %mm5
	leal (%edx,%edx,2), %ebp
	movq %mm3, 72(%esp)
	movq 96(%eax), %mm3
	pfmul %mm2, %mm6
	movq %mm0, 48(%esp)
	movq (%ecx,%edi), %mm0
	pswapd %mm1, %mm2
	pfmul %mm4, %mm1
	leal (%edx,%edx,8), %edi
	pfmul %mm4, %mm2
	pswapd %mm0, %mm4
	pfmul %mm3, %mm0
	pfmul %mm3, %mm4
	movq 8(%eax), %mm3
	addl $112, %eax
	pfnacc %mm0, %mm5
	movq (%ecx,%edx,2), %mm0
	pfacc %mm4, %mm6
	pswapd %mm0, %mm4
	pfmul %mm3, %mm0
	pfmul %mm3, %mm4
	movq %mm5, %mm3
	pfnacc %mm1, %mm0
	movq %mm7, %mm1
	pfacc %mm2, %mm4
	movq 72(%esp), %mm2
	pfacc %mm0, %mm5
	pfnacc %mm0, %mm3
	movq 64(%esp), %mm0
	pfadd %mm5, %mm7
	pfmul KP500000000KP500000000, %mm5
	pfmul KP866025403KP866025403, %mm3
	pfsub %mm5, %mm1
	movq %mm2, %mm5
	pfadd %mm0, %mm2
	pfmul KP500000000KP500000000, %mm0
	pfsub %mm0, %mm5
	movq %mm7, %mm0
	pfnacc %mm2, %mm7
	pfacc %mm2, %mm0
	movq %mm7, 88(%esp)
	movq %mm0, 80(%esp)
	movq 56(%esp), %mm2
	movq 40(%esp), %mm7
	movq %mm2, %mm0
	pfnacc %mm7, %mm2
	pfacc %mm7, %mm0
	movq %mm5, %mm7
	pfmul KN866025403KN866025403, %mm2
	pfsub %mm2, %mm7
	pfadd %mm2, %mm5
	movq %mm6, %mm2
	pfnacc %mm4, %mm6
	pfacc %mm4, %mm2
	movq %mm7, 112(%esp)
	movq %mm5, 96(%esp)
	movq 24(%esp), %mm4
	movq %mm1, %mm5
	pfmul KN866025403KN866025403, %mm6
	movq %mm4, %mm7
	pfadd %mm2, %mm4
	pfmul KP500000000KP500000000, %mm2
	pfsub %mm6, %mm5
	pfadd %mm6, %mm1
	movq 48(%esp), %mm6
	pfsub %mm2, %mm7
	movq %mm5, 136(%esp)
	movq %mm6, %mm2
	pfadd %mm0, %mm6
	pfmul KP500000000KP500000000, %mm0
	movq %mm7, %mm5
	pfadd %mm3, %mm7
	movq %mm1, 104(%esp)
	movq %mm4, %mm1
	pfsub %mm3, %mm5
	movq 88(%esp), %mm3
	pfnacc %mm6, %mm4
	movq %mm7, 128(%esp)
	pfacc %mm6, %mm1
	pfsub %mm0, %mm2
	movq 32(%esp), %mm0
	movq %mm3, %mm6
	pfmul KP587785252KP951056516, %mm3
	pfmul KP951056516KP587785252, %mm6
	movq %mm2, %mm7
	pfadd %mm0, %mm2
	pfsub %mm0, %mm7
	pswapd %mm4, %mm0
	pfmul KP951056516KP587785252, %mm4
	pfmul KP951056516KP587785252, %mm0
	movq %mm2, 120(%esp)
	movq %mm7, 144(%esp)
	movq 80(%esp), %mm2
	movq %mm2, %mm7
	pfacc %mm1, %mm2
	pfnacc %mm3, %mm0
	movq (%ecx), %mm3
	/* simd data load/store barrier */ 
	pfacc %mm6, %mm4
	pfnacc %mm1, %mm7
	movq %mm2, %mm1
	movq %mm3, %mm6
	pfsub 8(%esp), %mm3
	pfmul KP250000000KP250000000, %mm1
	pxor chs_lo, %mm4
	pfadd 16(%esp), %mm6
	pfmul KP559016994KP559016994, %mm7
	movq %mm3, 152(%esp)
	movq %mm6, %mm3
	pfsub %mm1, %mm6
	pfadd %mm2, %mm3
	movq %mm6, %mm1
	pfsub %mm7, %mm6
	pfadd %mm7, %mm1
	movq %mm3, (%ecx)
	movq 144(%esp), %mm3
	movq %mm6, %mm2
	pfadd %mm0, %mm6
	movq %mm1, %mm7
	pfsub %mm4, %mm1
	pfsub %mm0, %mm2
	movq %mm5, %mm0
	pfadd %mm4, %mm7
	movq 136(%esp), %mm4
	movq %mm6, (%ecx,%ebp,4)
	movq 112(%esp), %mm6
	pfnacc %mm3, %mm5
	pfacc %mm3, %mm0
	movq %mm1, (%ecx,%edi)
	movq %mm2, (%ecx,%ebp)
	movq %mm4, %mm3
	movq %mm7, (%ecx,%ebp,2)
	movq 128(%esp), %mm7
	pfnacc %mm6, %mm4
	pswapd %mm5, %mm1
	leal (%edx,%edx,4), %ebp
	pfmul KP951056516KP587785252, %mm5
	pfacc %mm6, %mm3
	movq 120(%esp), %mm6
	pfmul KP951056516KP587785252, %mm1
	leal (%edx,%ebp,2), %edi
	movq %mm4, %mm2
	pfmul KP951056516KP587785252, %mm4
	pfmul KP587785252KP951056516, %mm2
	pfacc %mm4, %mm5
	movq %mm7, %mm4
	pfacc %mm6, %mm7
	pfnacc %mm2, %mm1
	pfnacc %mm6, %mm4
	movq 104(%esp), %mm6
	pxor chs_lo, %mm5
	movq %mm1, 168(%esp)
	movq 96(%esp), %mm1
	pswapd %mm4, %mm2
	pfmul KP951056516KP587785252, %mm4
	movq %mm5, 160(%esp)
	movq %mm6, %mm5
	pfmul KP951056516KP587785252, %mm2
	pfnacc %mm1, %mm6
	pfacc %mm1, %mm5
	movq %mm6, %mm1
	pfmul KP951056516KP587785252, %mm6
	pfmul KP587785252KP951056516, %mm1
	pfacc %mm6, %mm4
	movq %mm5, %mm6
	pfacc %mm7, %mm5
	pfnacc %mm1, %mm2
	movq %mm3, %mm1
	pfnacc %mm7, %mm6
	movq 152(%esp), %mm7
	pfacc %mm0, %mm3
	pxor chs_lo, %mm4
	pfnacc %mm0, %mm1
	movq %mm2, 176(%esp)
	movq 0(%esp), %mm0
	movq %mm7, %mm2
	pfmul KP559016994KP559016994, %mm6
	movq %mm4, 184(%esp)
	pfsub %mm0, %mm7
	pfmul KP559016994KP559016994, %mm1
	pfadd %mm0, %mm2
	movq %mm7, %mm4
	pfadd %mm3, %mm7
	pfmul KP250000000KP250000000, %mm3
	movq %mm2, %mm0
	pfadd %mm5, %mm2
	pfmul KP250000000KP250000000, %mm5
	movq %mm7, (%ecx,%ebp)
	movq %mm2, (%ecx,%ebp,2)
	movq 160(%esp), %mm2
	pfsub %mm3, %mm4
	pfsub %mm5, %mm0
	movq %mm6, %mm5
	movq %mm4, %mm7
	pfadd %mm1, %mm4
	pfsubr %mm0, %mm5
	pfsub %mm1, %mm7
	movq 168(%esp), %mm1
	pfadd %mm0, %mm6
	movq 176(%esp), %mm0
	movq %mm4, %mm3
	pfsub %mm2, %mm4
	pfadd %mm2, %mm3
	movq %mm7, %mm2
	pfadd %mm1, %mm7
	pfsub %mm1, %mm2
	movq %mm5, %mm1
	pfsub %mm0, %mm5
	movq %mm3, (%ecx,%edi)
	movq 184(%esp), %mm3
	pfadd %mm0, %mm1
	movq %mm7, (%ecx,%edx,2)
	movq %mm6, %mm7
	leal (%ebp,%edx,2), %edi
	movq %mm2, (%ecx,%edx,8)
	movq %mm4, (%ecx,%edi,2)
	pfsub %mm3, %mm6
	movq %mm1, (%ecx,%edi)
	leal (%ebp,%edx,8), %edi
	pfadd %mm3, %mm7
	movq %mm5, (%ecx,%edi)
	movq %mm6, (%ecx,%edx,4)
	movq %mm7, (%ecx,%edx)
	addl %ebx, %ecx
	decl %esi
	jnz .L0
	femms 
	movl 208(%esp), %ebx
	movl 204(%esp), %esi
	movl 200(%esp), %edi
	movl 196(%esp), %ebp
	addl $212, %esp
	ret 

.section .rodata
nam:
	.string "t1k7i_15"
	.align 4
twinstr:
	.byte 4
	.byte 0
	.value 15
	.byte 3
	.byte 1
	.value 0
	.align 4
desc:
	.long 15
	.long nam
	.long twinstr
	.zero 4
	.double 92
	.double 56
	.double 0
	.double 0
	.long fftwf_kdft_ct_k7_pgenus
	.long 0
	.long 0
	.long 0

.text
	.align 4
.globl fftwf_codelet_t1k7i_15
fftwf_codelet_t1k7i_15:
	subl $12,%esp
	movl 16(%esp),%eax
	addl $-4,%esp
	pushl $desc
	pushl $t1k7i_15
	pushl %eax
	call fftwf_kdft_dit_register
	addl $16,%esp
	addl $12,%esp
	ret

