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
/* Generated on Sat Jul  5 21:51:39 EDT 2003 */

#include "config.h"



/* cheap-mode: VECTGRADE_FULL succeeded. (958 steps) */
/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft-k7/gen_notw -no-randomized-cse -n 32 -sign 1 -name n1k7i_32 */

/*
 * Generator Id's : 
 * $Id: n1k7i_32.S,v 1.1 2005/07/26 17:36:58 glass Exp $
 * $Id: n1k7i_32.S,v 1.1 2005/07/26 17:36:58 glass Exp $
 * $Id: n1k7i_32.S,v 1.1 2005/07/26 17:36:58 glass Exp $
 */

/* The following asm code is Copyright (c) 2000-2001 Stefan Kral */
.section .rodata
	.balign 64
chs_lo: .long 0x80000000, 0x00000000
KP707106781KP707106781: .float +0.707106781186547524400844362104849039284835938, +0.707106781186547524400844362104849039284835938
KP923879532KP382683432: .float +0.923879532511286756128183189396788286822416626, +0.382683432365089771728459984030398866761344562
KP382683432KP923879532: .float +0.382683432365089771728459984030398866761344562, +0.923879532511286756128183189396788286822416626
chs_hi: .long 0x00000000, 0x80000000
KP195090322KP980785280: .float +0.195090322016128267848284868477022240927691618, +0.980785280403230449126182236134239036973933731
KP555570233KP831469612: .float +0.555570233019602224742830813948532874374937191, +0.831469612302545237078788377617905756738560812
KP831469612KP555570233: .float +0.831469612302545237078788377617905756738560812, +0.555570233019602224742830813948532874374937191
KP980785280KP195090322: .float +0.980785280403230449126182236134239036973933731, +0.195090322016128267848284868477022240927691618
.text
.text
	.balign 64
n1k7i_32:
	subl $340, %esp
	femms 
	movl 360(%esp), %ecx
	movl %esi, 332(%esp)
	movl 364(%esp), %esi
	movl 348(%esp), %eax
	movl %ebx, 336(%esp)
	movl 356(%esp), %ebx
	movl %edi, 328(%esp)
	leal (,%ecx,4), %ecx
	movl %ebp, 324(%esp)
	leal (,%esi,4), %esi
	movl %ecx, %edx
	movl %esi, %edi
	sall $4, %edx
	addl %eax, %edx
	sall $4, %edi
	addl %ebx, %edi
	sall $2, 372(%esp)
	sall $2, 376(%esp)
	.p2align 4,,7
.L0:
	/* promise simd cell size = 8 */ 
	movq (%eax), %mm1
	movq (%edx), %mm0
	movq (%eax,%ecx,4), %mm7
	movq (%eax,%ecx,8), %mm4
	leal (%ecx,%ecx,2), %ebp
	movq (%edx,%ecx,4), %mm6
	movq (%edx,%ecx,8), %mm3
	movq %mm1, %mm2
	pfsub %mm0, %mm1
	movq %mm4, %mm5
	pfadd %mm0, %mm2
	movq %mm7, %mm0
	pfsub %mm6, %mm7
	pfadd %mm6, %mm0
	movq (%edx,%ebp,4), %mm6
	pfadd %mm3, %mm4
	pfsub %mm3, %mm5
	movq (%eax,%ebp,4), %mm3
	leal (%ecx,%ecx,4), %ebp
	movq %mm7, 0(%esp)
	movq %mm6, %mm7
	pfadd %mm3, %mm7
	pswapd %mm5, %mm5
	pfsub %mm3, %mm6
	movq %mm0, %mm3
	pxor chs_lo, %mm5
	pfsubr %mm7, %mm3
	pfadd %mm7, %mm0
	movq %mm2, %mm7
	pfsub %mm4, %mm2
	pfadd %mm4, %mm7
	movq %mm1, %mm4
	pfsub %mm5, %mm1
	movq %mm3, 48(%esp)
	pfadd %mm5, %mm4
	movq %mm2, 40(%esp)
	movq 0(%esp), %mm5
	pswapd %mm6, %mm2
	movq %mm7, %mm3
	pfsub %mm0, %mm7
	movq %mm1, 32(%esp)
	movq (%edx,%ecx,2), %mm1
	pfpnacc %mm5, %mm2
	movq %mm4, 8(%esp)
	pfpnacc %mm6, %mm5
	movq (%edx,%ebp,2), %mm6
	pfadd %mm0, %mm3
	movq %mm7, 56(%esp)
	movq (%eax,%ecx,2), %mm0
	movq %mm2, %mm7
	pfnacc %mm5, %mm2
	pfacc %mm7, %mm5
	movq %mm3, 64(%esp)
	movq (%eax,%ebp,2), %mm3
	movq %mm0, %mm4
	leal (%ecx,%ecx,2), %ebp
	pfsub %mm1, %mm0
	pfmul KP707106781KP707106781, %mm2
	pfadd %mm1, %mm4
	leal (%ecx,%ebp,2), %ebp
	pfmul KP707106781KP707106781, %mm5
	movq %mm3, %mm1
	pfadd %mm6, %mm3
	movq %mm0, 72(%esp)
	movq (%eax,%ebp,2), %mm0
	pfsub %mm6, %mm1
	movq (%edx,%ebp,2), %mm6
	leal (%ecx,%ecx,2), %ebp
	movq %mm4, %mm7
	pfsub %mm3, %mm4
	movq %mm2, 24(%esp)
	movq (%edx,%ebp,2), %mm2
	pfadd %mm3, %mm7
	movq %mm5, 16(%esp)
	movq (%eax,%ebp,2), %mm5
	movq %mm6, %mm3
	pfsub %mm0, %mm6
	pswapd %mm1, %mm1
	leal (%ecx,%ecx,8), %ebp
	pfadd %mm0, %mm3
	pxor chs_lo, %mm1
	movq %mm5, %mm0
	pfadd %mm2, %mm5
	pswapd %mm6, %mm6
	pfsub %mm2, %mm0
	movq %mm3, %mm2
	pfadd %mm5, %mm3
	pfsub %mm5, %mm2
	movq %mm7, %mm5
	pxor chs_lo, %mm0
	pfadd %mm3, %mm7
	pfsubr %mm3, %mm5
	movq %mm6, %mm3
	pfsub %mm0, %mm6
	pfadd %mm0, %mm3
	pswapd %mm2, %mm0
	movq %mm7, 88(%esp)
	pfpnacc %mm4, %mm0
	movq %mm5, 80(%esp)
	pfpnacc %mm2, %mm4
	movq 72(%esp), %mm2
	movq %mm6, %mm7
	movq %mm3, %mm5
	pfmul KP923879532KP382683432, %mm6
	pfmul KP382683432KP923879532, %mm7
	movq %mm0, 96(%esp)
	pfmul KP382683432KP923879532, %mm3
	movq %mm2, %mm0
	pfsub %mm1, %mm2
	movq %mm4, 136(%esp)
	pfmul KP923879532KP382683432, %mm5
	pfadd %mm1, %mm0
	movq %mm2, %mm1
	pfmul KP923879532KP382683432, %mm2
	movq %mm0, %mm4
	pfmul KP923879532KP382683432, %mm0
	pfmul KP382683432KP923879532, %mm1
	pfmul KP382683432KP923879532, %mm4
	pfpnacc %mm2, %mm3
	movq (%edx,%ecx), %mm2
	pfpnacc %mm7, %mm0
	movq (%edx,%ebp), %mm7
	pfpnacc %mm5, %mm1
	pfpnacc %mm4, %mm6
	movq (%eax,%ebp), %mm4
	leal (%ecx,%ecx,2), %ebp
	movq %mm3, 128(%esp)
	movq %mm0, 104(%esp)
	movq %mm1, 120(%esp)
	movq %mm6, 112(%esp)
	movq (%eax,%ecx), %mm0
	movq (%eax,%ebp), %mm3
	movq (%edx,%ebp), %mm1
	leal (%ecx,%ecx,2), %ebp
	movq %mm4, %mm5
	pfadd %mm7, %mm4
	movq %mm0, %mm6
	pfsub %mm2, %mm0
	leal (%ebp,%ecx,8), %ebp
	pfsub %mm7, %mm5
	movq %mm3, %mm7
	pfadd %mm2, %mm6
	movq (%eax,%ebp), %mm2
	pfsub %mm1, %mm3
	movq %mm0, 144(%esp)
	movq (%edx,%ebp), %mm0
	pfadd %mm1, %mm7
	movq %mm5, 152(%esp)
	leal (%ecx,%ecx,4), %ebp
	movq %mm6, %mm5
	pfsub %mm4, %mm6
	movq %mm0, %mm1
	pfadd %mm4, %mm5
	movq %mm3, %mm4
	pfsub %mm2, %mm0
	pfadd %mm2, %mm1
	movq %mm7, %mm2
	movq %mm6, 176(%esp)
	movq %mm5, 168(%esp)
	movq (%edx,%ebp), %mm6
	movq (%eax,%ebp), %mm5
	leal (%ecx,%ecx,2), %ebp
	pfpnacc %mm0, %mm4
	pswapd %mm0, %mm0
	pfadd %mm1, %mm2
	leal (%ecx,%ebp,4), %ebp
	pfsub %mm1, %mm7
	pfpnacc %mm3, %mm0
	movq (%eax,%ebp), %mm3
	movq %mm5, %mm1
	pfsub %mm6, %mm5
	movq %mm2, 160(%esp)
	movq (%edx,%ebp), %mm2
	pfadd %mm6, %mm1
	pxor chs_hi, %mm7
	leal (%ecx,%ecx,2), %ebp
	leal (%ebp,%ebp,4), %ebp
	movq %mm2, %mm6
	pfsub %mm3, %mm2
	movq %mm7, 200(%esp)
	movq %mm5, %mm7
	pfadd %mm3, %mm6
	movq %mm1, %mm3
	pfpnacc %mm2, %mm7
	pswapd %mm2, %mm2
	pfadd %mm6, %mm1
	pfsubr %mm6, %mm3
	movq (%eax,%ebp), %mm6
	pfpnacc %mm5, %mm2
	movq (%edx,%ebp), %mm5
	leal (%ecx,%ecx,2), %ebp
	leal (%ecx,%ebp,2), %ebp
	movq %mm1, 184(%esp)
	movq %mm3, 192(%esp)
	movq %mm2, 208(%esp)
	movq (%edx,%ebp), %mm3
	movq %mm5, %mm1
	movq (%eax,%ebp), %mm2
	pfsub %mm6, %mm5
	/* simd data load/store barrier */ 
	pfadd %mm6, %mm1
	leal (%esi,%esi,2), %ebp
	addl 372(%esp), %eax
	addl 372(%esp), %edx
	movq %mm2, %mm6
	pfsub %mm3, %mm2
	pswapd %mm5, %mm5
	pfadd %mm3, %mm6
	movq %mm1, %mm3
	pxor chs_lo, %mm2
	pfsub %mm6, %mm3
	pfadd %mm6, %mm1
	movq %mm5, %mm6
	pfsub %mm2, %mm5
	pfadd %mm2, %mm6
	movq %mm0, %mm2
	pfacc %mm4, %mm0
	pswapd %mm3, %mm3
	pfnacc %mm2, %mm4
	movq %mm5, %mm2
	movq %mm6, 248(%esp)
	movq 208(%esp), %mm6
	pfmul KP707106781KP707106781, %mm0
	pfmul KP707106781KP707106781, %mm4
	pfsub %mm0, %mm2
	pfadd %mm0, %mm5
	movq %mm4, 240(%esp)
	movq %mm7, %mm0
	movq 200(%esp), %mm4
	pfacc %mm6, %mm7
	pfnacc %mm0, %mm6
	movq %mm3, %mm0
	movq %mm2, 232(%esp)
	movq %mm5, 216(%esp)
	movq 192(%esp), %mm2
	movq 176(%esp), %mm5
	pfsub %mm4, %mm0
	pfmul KP707106781KP707106781, %mm7
	pfadd %mm4, %mm3
	pfmul KP707106781KP707106781, %mm6
	pswapd %mm2, %mm2
	movq %mm5, %mm4
	movq %mm0, 256(%esp)
	pxor chs_hi, %mm2
	movq %mm3, 272(%esp)
	movq %mm7, 224(%esp)
	movq 168(%esp), %mm0
	movq 184(%esp), %mm3
	pfsub %mm2, %mm4
	pfadd %mm2, %mm5
	movq %mm0, %mm7
	movq 160(%esp), %mm2
	pfsub %mm3, %mm0
	pfadd %mm3, %mm7
	movq %mm1, %mm3
	movq %mm4, 264(%esp)
	pfadd %mm2, %mm1
	movq %mm5, 280(%esp)
	pfsub %mm2, %mm3
	movq 152(%esp), %mm2
	movq %mm0, %mm5
	movq %mm7, %mm4
	pfsubr %mm1, %mm4
	pfadd %mm1, %mm7
	pswapd %mm2, %mm2
	movq 144(%esp), %mm1
	pfpnacc %mm3, %mm5
	pswapd %mm3, %mm3
	pxor chs_lo, %mm2
	pfpnacc %mm0, %mm3
	pswapd %mm4, %mm4
	movq %mm1, %mm0
	pxor chs_hi, %mm4
	pfsub %mm2, %mm0
	pfadd %mm2, %mm1
	movq %mm0, %mm2
	pfsub %mm6, %mm0
	movq %mm1, 288(%esp)
	movq 64(%esp), %mm1
	pfadd %mm6, %mm2
	movq %mm2, 296(%esp)
	movq 88(%esp), %mm6
	movq %mm1, %mm2
	pfadd %mm6, %mm1
	pfsub %mm6, %mm2
	movq %mm1, %mm6
	pfsub %mm7, %mm1
	pfadd %mm7, %mm6
	movq %mm2, %mm7
	pfsub %mm4, %mm2
	movq %mm1, (%edi)
	movq 80(%esp), %mm1
	pfadd %mm4, %mm7
	movq %mm3, %mm4
	pfnacc %mm5, %mm3
	movq %mm6, (%ebx)
	movq 56(%esp), %mm6
	pfacc %mm4, %mm5
	movq %mm2, (%edi,%esi,8)
	pswapd %mm1, %mm1
	pfmul KP707106781KP707106781, %mm3
	pxor chs_hi, %mm1
	movq %mm7, (%ebx,%esi,8)
	movq %mm6, %mm2
	pfmul KP707106781KP707106781, %mm5
	pfsub %mm1, %mm6
	pfadd %mm1, %mm2
	movq 280(%esp), %mm1
	movq %mm6, %mm4
	pfadd %mm3, %mm6
	movq %mm2, %mm7
	pfsub %mm5, %mm2
	pfsub %mm3, %mm4
	pswapd %mm1, %mm3
	pfadd %mm5, %mm7
	movq 272(%esp), %mm5
	pfmul KP923879532KP382683432, %mm1
	pfmul KP923879532KP382683432, %mm3
	movq %mm6, (%ebx,%ebp,4)
	movq %mm2, (%edi,%esi,4)
	movq 48(%esp), %mm2
	movq 40(%esp), %mm6
	movq %mm4, (%edi,%ebp,4)
	leal (%esi,%esi,4), %ebp
	movq %mm5, %mm4
	pfmul KP923879532KP382683432, %mm5
	pfmul KP382683432KP923879532, %mm4
	movq %mm7, (%ebx,%esi,4)
	pswapd %mm2, %mm2
	movq %mm6, %mm7
	pxor chs_hi, %mm2
	pfpnacc %mm3, %mm5
	movq 136(%esp), %mm3
	pfpnacc %mm4, %mm1
	movq 96(%esp), %mm4
	pfadd %mm2, %mm7
	pfsub %mm2, %mm6
	movq %mm3, %mm2
	pfacc %mm4, %mm3
	pfnacc %mm2, %mm4
	movq %mm7, %mm2
	pfmul KP707106781KP707106781, %mm3
	pfmul KP707106781KP707106781, %mm4
	pfsub %mm3, %mm7
	pfadd %mm3, %mm2
	movq %mm5, %mm3
	pfnacc %mm1, %mm5
	pfacc %mm3, %mm1
	movq %mm7, %mm3
	pfsub %mm5, %mm3
	pfadd %mm5, %mm7
	movq %mm2, %mm5
	pfadd %mm1, %mm2
	pfsub %mm1, %mm5
	movq %mm6, %mm1
	movq %mm3, (%edi,%ebp,2)
	movq 256(%esp), %mm3
	pfsub %mm4, %mm6
	pfadd %mm4, %mm1
	movq 264(%esp), %mm4
	movq %mm7, (%ebx,%ebp,2)
	movq %mm2, (%ebx,%esi,2)
	leal (%esi,%esi,2), %ebp
	movq %mm5, (%edi,%esi,2)
	pswapd %mm0, %mm5
	pfmul KP195090322KP980785280, %mm0
	movq %mm3, %mm7
	pfmul KP382683432KP923879532, %mm3
	leal (%esi,%ebp,2), %ebp
	pswapd %mm4, %mm2
	pfmul KP382683432KP923879532, %mm4
	pfmul KP923879532KP382683432, %mm7
	pfmul KP382683432KP923879532, %mm2
	pfmul KP195090322KP980785280, %mm5
	pfpnacc %mm7, %mm4
	pfpnacc %mm2, %mm3
	movq %mm1, %mm2
	movq %mm4, %mm7
	pfacc %mm3, %mm4
	pfnacc %mm7, %mm3
	movq %mm6, %mm7
	pfsub %mm4, %mm2
	pfsub %mm3, %mm7
	pfadd %mm3, %mm6
	movq 248(%esp), %mm3
	pfadd %mm4, %mm1
	movq 240(%esp), %mm4
	movq %mm7, (%edi,%ebp,2)
	movq %mm6, (%ebx,%ebp,2)
	movq %mm3, %mm7
	leal (%esi,%esi,2), %ebp
	pfadd %mm4, %mm3
	pfsub %mm4, %mm7
	movq %mm2, (%edi,%ebp,2)
	movq 296(%esp), %mm2
	movq %mm1, (%ebx,%ebp,2)
	leal (%esi,%esi,2), %ebp
	movq %mm3, %mm6
	pfmul KP555570233KP831469612, %mm3
	leal (%ebp,%ebp,4), %ebp
	movq %mm7, %mm4
	pswapd %mm2, %mm1
	pfmul KP195090322KP980785280, %mm7
	pfmul KP831469612KP555570233, %mm2
	pfmul KP831469612KP555570233, %mm6
	pfmul KP980785280KP195090322, %mm4
	pfmul KP831469612KP555570233, %mm1
	pfpnacc %mm5, %mm7
	movq 32(%esp), %mm5
	pfpnacc %mm3, %mm2
	movq 24(%esp), %mm3
	pfpnacc %mm4, %mm0
	pfpnacc %mm1, %mm6
	movq %mm5, %mm4
	movq %mm2, 304(%esp)
	movq 128(%esp), %mm1
	movq 120(%esp), %mm2
	pfadd %mm3, %mm5
	pfsub %mm3, %mm4
	movq %mm1, %mm3
	pfnacc %mm2, %mm1
	pfacc %mm3, %mm2
	movq %mm4, %mm3
	pfadd %mm1, %mm3
	pfsub %mm1, %mm4
	movq %mm5, %mm1
	pfsub %mm2, %mm5
	pfadd %mm2, %mm1
	movq %mm7, %mm2
	pfnacc %mm0, %mm7
	pfacc %mm2, %mm0
	movq %mm4, %mm2
	pfsub %mm7, %mm2
	pfadd %mm7, %mm4
	movq %mm3, %mm7
	pfadd %mm0, %mm3
	pfsub %mm0, %mm7
	movq 304(%esp), %mm0
	movq %mm2, (%edi,%ebp)
	movq %mm6, %mm2
	movq %mm4, (%ebx,%ebp)
	leal (%esi,%esi,2), %ebp
	movq %mm5, %mm4
	pfnacc %mm0, %mm6
	leal (%esi,%ebp,2), %ebp
	pfacc %mm2, %mm0
	movq %mm1, %mm2
	movq %mm7, (%edi,%ebp)
	movq 232(%esp), %mm7
	movq %mm3, (%ebx,%ebp)
	leal (%esi,%esi,2), %ebp
	pfsub %mm6, %mm4
	pfadd %mm6, %mm5
	leal (%ebp,%esi,8), %ebp
	movq 288(%esp), %mm6
	pfsub %mm0, %mm2
	pswapd %mm7, %mm3
	pfadd %mm0, %mm1
	movq 224(%esp), %mm0
	pfmul KP555570233KP831469612, %mm7
	pfmul KP555570233KP831469612, %mm3
	movq %mm4, (%edi,%ebp)
	movq %mm5, (%ebx,%ebp)
	leal (%esi,%esi,2), %ebp
	movq %mm6, %mm4
	movq %mm2, (%edi,%ebp)
	movq 216(%esp), %mm2
	pfadd %mm0, %mm6
	pfsub %mm0, %mm4
	movq %mm1, (%ebx,%ebp)
	leal (%esi,%esi,2), %ebp
	leal (%esi,%ebp,4), %ebp
	pswapd %mm2, %mm0
	movq %mm6, %mm5
	pfmul KP980785280KP195090322, %mm6
	movq %mm4, %mm1
	pfmul KP980785280KP195090322, %mm2
	pfmul KP980785280KP195090322, %mm0
	pfmul KP831469612KP555570233, %mm1
	pfmul KP555570233KP831469612, %mm4
	pfmul KP195090322KP980785280, %mm5
	pfpnacc %mm0, %mm6
	movq 8(%esp), %mm0
	pfpnacc %mm1, %mm7
	movq 16(%esp), %mm1
	pfpnacc %mm3, %mm4
	pfpnacc %mm5, %mm2
	movq %mm6, 312(%esp)
	movq 112(%esp), %mm5
	movq %mm0, %mm3
	movq 104(%esp), %mm6
	pfadd %mm1, %mm0
	pfsub %mm1, %mm3
	movq %mm5, %mm1
	pfnacc %mm6, %mm5
	pfacc %mm1, %mm6
	movq %mm3, %mm1
	pfsub %mm5, %mm1
	pfadd %mm5, %mm3
	movq %mm0, %mm5
	pfadd %mm6, %mm0
	pfsub %mm6, %mm5
	movq %mm7, %mm6
	pfnacc %mm4, %mm7
	pfacc %mm6, %mm4
	movq %mm1, %mm6
	pfsub %mm7, %mm6
	pfadd %mm7, %mm1
	movq %mm3, %mm7
	pfsub %mm4, %mm3
	pfadd %mm4, %mm7
	movq 312(%esp), %mm4
	movq %mm6, (%edi,%ebp)
	movq %mm2, %mm6
	movq %mm1, (%ebx,%ebp)
	leal (%esi,%esi,4), %ebp
	movq %mm5, %mm1
	pfnacc %mm4, %mm2
	movq %mm3, (%edi,%ebp)
	movq %mm0, %mm3
	pfacc %mm6, %mm4
	movq %mm7, (%ebx,%ebp)
	leal (%esi,%esi,8), %ebp
	pfsub %mm2, %mm1
	pfadd %mm2, %mm5
	pfsub %mm4, %mm3
	pfadd %mm4, %mm0
	movq %mm1, (%edi,%ebp)
	movq %mm5, (%ebx,%ebp)
	movq %mm3, (%edi,%esi)
	movq %mm0, (%ebx,%esi)
	addl 376(%esp), %ebx
	addl 376(%esp), %edi
	decl 368(%esp)
	jnz .L0
	femms 
	movl 336(%esp), %ebx
	movl 332(%esp), %esi
	movl 328(%esp), %edi
	movl 324(%esp), %ebp
	addl $340, %esp
	ret 

.section .rodata
nam:
	.string "n1k7i_32"
	.align 4
desc:
	.long 32
	.long nam
	.double 186
	.double 42
	.double 0
	.double 0
	.long fftwf_kdft_k7_pgenus
	.long 0
	.long 0
	.long 0
	.long 0

.text
	.align 4
.globl fftwf_codelet_n1k7i_32
fftwf_codelet_n1k7i_32:
	subl $12,%esp
	addl $-4,%esp
	pushl $desc
	pushl $n1k7i_32
	pushl 28(%esp)
	call fftwf_kdft_register
	addl $16,%esp
	addl $12,%esp
	ret

