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
/* Generated on Sat Jul  5 21:43:15 EDT 2003 */

#include "codelet-dft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_twiddle_c -simd -compact -variables 4 -n 3 -name t1fv_3 -include t1f.h */

/*
 * This function contains 8 FP additions, 6 FP multiplications,
 * (or, 7 additions, 5 multiplications, 1 fused multiply/add),
 * 12 stack variables, and 6 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: t1fv_3.c,v 1.1 2005/07/26 17:37:00 glass Exp $
 * $Id: t1fv_3.c,v 1.1 2005/07/26 17:37:00 glass Exp $
 * $Id: t1fv_3.c,v 1.1 2005/07/26 17:37:00 glass Exp $
 */

#include "t1f.h"

static const R *t1fv_3(R *ri, R *ii, const R *W, stride ios, int m, int dist)
{
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     int i;
     R *x;
     x = ri;
     BEGIN_SIMD();
     for (i = m; i > 0; i = i - VL, x = x + (VL * dist), W = W + (TWVL * 4)) {
	  V T1, T3, T5, T6, T2, T4, T7, T8;
	  T1 = LD(&(x[0]), dist, &(x[0]));
	  T2 = LD(&(x[WS(ios, 1)]), dist, &(x[WS(ios, 1)]));
	  T3 = BYTWJ(&(W[0]), T2);
	  T4 = LD(&(x[WS(ios, 2)]), dist, &(x[0]));
	  T5 = BYTWJ(&(W[TWVL * 2]), T4);
	  T6 = VADD(T3, T5);
	  ST(&(x[0]), VADD(T1, T6), dist, &(x[0]));
	  T7 = VFNMS(LDK(KP500000000), T6, T1);
	  T8 = VBYI(VMUL(LDK(KP866025403), VSUB(T5, T3)));
	  ST(&(x[WS(ios, 2)]), VSUB(T7, T8), dist, &(x[0]));
	  ST(&(x[WS(ios, 1)]), VADD(T7, T8), dist, &(x[WS(ios, 1)]));
     }
     END_SIMD();
     return W;
}

static const tw_instr twinstr[] = {
     VTW(1),
     VTW(2),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 3, "t1fv_3", twinstr, {7, 5, 1, 0}, &GENUS, 0, 0, 0 };

void X(codelet_t1fv_3) (planner *p) {
     X(kdft_dit_register) (p, t1fv_3, &desc);
}
