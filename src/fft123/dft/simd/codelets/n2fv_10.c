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
/* Generated on Sat Jul  5 21:40:33 EDT 2003 */

#include "codelet-dft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_notw_c -simd -compact -variables 4 -n 10 -name n2fv_10 -with-ostride 2 -include n2f.h */

/*
 * This function contains 42 FP additions, 12 FP multiplications,
 * (or, 36 additions, 6 multiplications, 6 fused multiply/add),
 * 33 stack variables, and 20 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: n2fv_10.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 * $Id: n2fv_10.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 * $Id: n2fv_10.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 */

#include "n2f.h"

static void n2fv_10(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, int v, int ivs, int ovs)
{
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     int i;
     const R *xi;
     R *xo;
     xi = ri;
     xo = ro;
     BEGIN_SIMD();
     for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs)) {
	  V Ti, Ty, Tm, Tn, Tw, Tt, Tz, TA, TB, T7, Te, Tj, Tg, Th;
	  Tg = LD(&(xi[0]), ivs, &(xi[0]));
	  Th = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	  Ti = VSUB(Tg, Th);
	  Ty = VADD(Tg, Th);
	  {
	       V T3, Tu, Td, Ts, T6, Tv, Ta, Tr;
	       {
		    V T1, T2, Tb, Tc;
		    T1 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    T2 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
		    T3 = VSUB(T1, T2);
		    Tu = VADD(T1, T2);
		    Tb = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    Tc = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    Td = VSUB(Tb, Tc);
		    Ts = VADD(Tb, Tc);
	       }
	       {
		    V T4, T5, T8, T9;
		    T4 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
		    T5 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    T6 = VSUB(T4, T5);
		    Tv = VADD(T4, T5);
		    T8 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    T9 = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
		    Ta = VSUB(T8, T9);
		    Tr = VADD(T8, T9);
	       }
	       Tm = VSUB(T3, T6);
	       Tn = VSUB(Ta, Td);
	       Tw = VSUB(Tu, Tv);
	       Tt = VSUB(Tr, Ts);
	       Tz = VADD(Tu, Tv);
	       TA = VADD(Tr, Ts);
	       TB = VADD(Tz, TA);
	       T7 = VADD(T3, T6);
	       Te = VADD(Ta, Td);
	       Tj = VADD(T7, Te);
	  }
	  ST(&(xo[10]), VADD(Ti, Tj), ovs, &(xo[2]));
	  ST(&(xo[0]), VADD(Ty, TB), ovs, &(xo[0]));
	  {
	       V To, Tq, Tl, Tp, Tf, Tk;
	       To = VBYI(VFMA(LDK(KP951056516), Tm, VMUL(LDK(KP587785252), Tn)));
	       Tq = VBYI(VFNMS(LDK(KP587785252), Tm, VMUL(LDK(KP951056516), Tn)));
	       Tf = VMUL(LDK(KP559016994), VSUB(T7, Te));
	       Tk = VFNMS(LDK(KP250000000), Tj, Ti);
	       Tl = VADD(Tf, Tk);
	       Tp = VSUB(Tk, Tf);
	       ST(&(xo[2]), VSUB(Tl, To), ovs, &(xo[2]));
	       ST(&(xo[14]), VADD(Tq, Tp), ovs, &(xo[2]));
	       ST(&(xo[18]), VADD(To, Tl), ovs, &(xo[2]));
	       ST(&(xo[6]), VSUB(Tp, Tq), ovs, &(xo[2]));
	  }
	  {
	       V Tx, TF, TE, TG, TC, TD;
	       Tx = VBYI(VFNMS(LDK(KP587785252), Tw, VMUL(LDK(KP951056516), Tt)));
	       TF = VBYI(VFMA(LDK(KP951056516), Tw, VMUL(LDK(KP587785252), Tt)));
	       TC = VFNMS(LDK(KP250000000), TB, Ty);
	       TD = VMUL(LDK(KP559016994), VSUB(Tz, TA));
	       TE = VSUB(TC, TD);
	       TG = VADD(TD, TC);
	       ST(&(xo[4]), VADD(Tx, TE), ovs, &(xo[0]));
	       ST(&(xo[12]), VSUB(TG, TF), ovs, &(xo[0]));
	       ST(&(xo[16]), VSUB(TE, Tx), ovs, &(xo[0]));
	       ST(&(xo[8]), VADD(TF, TG), ovs, &(xo[0]));
	  }
     }
     END_SIMD();
}

static const kdft_desc desc = { 10, "n2fv_10", {36, 6, 6, 0}, &GENUS, 0, 2, 0, 0 };
void X(codelet_n2fv_10) (planner *p) {
     X(kdft_register) (p, n2fv_10, &desc);
}
