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
/* Generated on Sat Jul  5 21:40:12 EDT 2003 */

#include "codelet-dft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_notw_c -simd -compact -variables 4 -sign 1 -n 6 -name n1bv_6 -include n1b.h */

/*
 * This function contains 18 FP additions, 4 FP multiplications,
 * (or, 16 additions, 2 multiplications, 2 fused multiply/add),
 * 19 stack variables, and 12 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: n1bv_6.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 * $Id: n1bv_6.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 * $Id: n1bv_6.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 */

#include "n1b.h"

static void n1bv_6(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, int v, int ivs, int ovs)
{
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     int i;
     const R *xi;
     R *xo;
     xi = ii;
     xo = io;
     BEGIN_SIMD();
     for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs)) {
	  V Ta, Td, T3, Te, T6, Tf, Tb, Tg, T8, T9;
	  T8 = LD(&(xi[0]), ivs, &(xi[0]));
	  T9 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
	  Ta = VSUB(T8, T9);
	  Td = VADD(T8, T9);
	  {
	       V T1, T2, T4, T5;
	       T1 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       T3 = VSUB(T1, T2);
	       Te = VADD(T1, T2);
	       T4 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
	       T5 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
	       T6 = VSUB(T4, T5);
	       Tf = VADD(T4, T5);
	  }
	  Tb = VADD(T3, T6);
	  Tg = VADD(Te, Tf);
	  ST(&(xo[WS(os, 3)]), VADD(Ta, Tb), ovs, &(xo[WS(os, 1)]));
	  ST(&(xo[0]), VADD(Td, Tg), ovs, &(xo[0]));
	  {
	       V T7, Tc, Th, Ti;
	       T7 = VBYI(VMUL(LDK(KP866025403), VSUB(T3, T6)));
	       Tc = VFNMS(LDK(KP500000000), Tb, Ta);
	       ST(&(xo[WS(os, 1)]), VADD(T7, Tc), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 5)]), VSUB(Tc, T7), ovs, &(xo[WS(os, 1)]));
	       Th = VFNMS(LDK(KP500000000), Tg, Td);
	       Ti = VBYI(VMUL(LDK(KP866025403), VSUB(Te, Tf)));
	       ST(&(xo[WS(os, 2)]), VSUB(Th, Ti), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 4)]), VADD(Ti, Th), ovs, &(xo[0]));
	  }
     }
     END_SIMD();
}

static const kdft_desc desc = { 6, "n1bv_6", {16, 2, 2, 0}, &GENUS, 0, 0, 0, 0 };
void X(codelet_n1bv_6) (planner *p) {
     X(kdft_register) (p, n1bv_6, &desc);
}
