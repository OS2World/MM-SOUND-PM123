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
/* Generated on Sat Jul  5 21:40:35 EDT 2003 */

#include "codelet-dft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_notw_c -simd -compact -variables 4 -n 12 -name n2fv_12 -with-ostride 2 -include n2f.h */

/*
 * This function contains 48 FP additions, 8 FP multiplications,
 * (or, 44 additions, 4 multiplications, 4 fused multiply/add),
 * 27 stack variables, and 24 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: n2fv_12.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 * $Id: n2fv_12.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 * $Id: n2fv_12.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 */

#include "n2f.h"

static void n2fv_12(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, int v, int ivs, int ovs)
{
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     int i;
     const R *xi;
     R *xo;
     xi = ri;
     xo = ro;
     BEGIN_SIMD();
     for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs)) {
	  V T5, Ta, TJ, Ty, Tq, Tp, Tg, Tl, TI, TA, Tz, Tu;
	  {
	       V T1, T6, T4, Tw, T9, Tx;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T6 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
	       {
		    V T2, T3, T7, T8;
		    T2 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    T3 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
		    T4 = VADD(T2, T3);
		    Tw = VSUB(T3, T2);
		    T7 = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
		    T8 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    T9 = VADD(T7, T8);
		    Tx = VSUB(T8, T7);
	       }
	       T5 = VADD(T1, T4);
	       Ta = VADD(T6, T9);
	       TJ = VADD(Tw, Tx);
	       Ty = VMUL(LDK(KP866025403), VSUB(Tw, Tx));
	       Tq = VFNMS(LDK(KP500000000), T9, T6);
	       Tp = VFNMS(LDK(KP500000000), T4, T1);
	  }
	  {
	       V Tc, Th, Tf, Ts, Tk, Tt;
	       Tc = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
	       Th = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
	       {
		    V Td, Te, Ti, Tj;
		    Td = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
		    Te = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
		    Tf = VADD(Td, Te);
		    Ts = VSUB(Te, Td);
		    Ti = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    Tj = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
		    Tk = VADD(Ti, Tj);
		    Tt = VSUB(Tj, Ti);
	       }
	       Tg = VADD(Tc, Tf);
	       Tl = VADD(Th, Tk);
	       TI = VADD(Ts, Tt);
	       TA = VFNMS(LDK(KP500000000), Tk, Th);
	       Tz = VFNMS(LDK(KP500000000), Tf, Tc);
	       Tu = VMUL(LDK(KP866025403), VSUB(Ts, Tt));
	  }
	  {
	       V Tb, Tm, Tn, To;
	       Tb = VSUB(T5, Ta);
	       Tm = VBYI(VSUB(Tg, Tl));
	       ST(&(xo[18]), VSUB(Tb, Tm), ovs, &(xo[2]));
	       ST(&(xo[6]), VADD(Tb, Tm), ovs, &(xo[2]));
	       Tn = VADD(T5, Ta);
	       To = VADD(Tg, Tl);
	       ST(&(xo[12]), VSUB(Tn, To), ovs, &(xo[0]));
	       ST(&(xo[0]), VADD(Tn, To), ovs, &(xo[0]));
	  }
	  {
	       V Tv, TE, TC, TD, Tr, TB;
	       Tr = VSUB(Tp, Tq);
	       Tv = VSUB(Tr, Tu);
	       TE = VADD(Tr, Tu);
	       TB = VSUB(Tz, TA);
	       TC = VBYI(VADD(Ty, TB));
	       TD = VBYI(VSUB(Ty, TB));
	       ST(&(xo[10]), VSUB(Tv, TC), ovs, &(xo[2]));
	       ST(&(xo[22]), VSUB(TE, TD), ovs, &(xo[2]));
	       ST(&(xo[14]), VADD(TC, Tv), ovs, &(xo[2]));
	       ST(&(xo[2]), VADD(TD, TE), ovs, &(xo[2]));
	  }
	  {
	       V TK, TM, TH, TL, TF, TG;
	       TK = VBYI(VMUL(LDK(KP866025403), VSUB(TI, TJ)));
	       TM = VBYI(VMUL(LDK(KP866025403), VADD(TJ, TI)));
	       TF = VADD(Tp, Tq);
	       TG = VADD(Tz, TA);
	       TH = VSUB(TF, TG);
	       TL = VADD(TF, TG);
	       ST(&(xo[20]), VSUB(TH, TK), ovs, &(xo[0]));
	       ST(&(xo[8]), VADD(TL, TM), ovs, &(xo[0]));
	       ST(&(xo[4]), VADD(TH, TK), ovs, &(xo[0]));
	       ST(&(xo[16]), VSUB(TL, TM), ovs, &(xo[0]));
	  }
     }
     END_SIMD();
}

static const kdft_desc desc = { 12, "n2fv_12", {44, 4, 4, 0}, &GENUS, 0, 2, 0, 0 };
void X(codelet_n2fv_12) (planner *p) {
     X(kdft_register) (p, n2fv_12, &desc);
}