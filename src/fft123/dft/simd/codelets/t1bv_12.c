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
/* Generated on Sat Jul  5 21:43:52 EDT 2003 */

#include "codelet-dft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_twiddle_c -simd -compact -variables 4 -n 12 -name t1bv_12 -include t1b.h -sign 1 */

/*
 * This function contains 59 FP additions, 30 FP multiplications,
 * (or, 55 additions, 26 multiplications, 4 fused multiply/add),
 * 28 stack variables, and 24 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: t1bv_12.c,v 1.1 2005/07/26 17:37:00 glass Exp $
 * $Id: t1bv_12.c,v 1.1 2005/07/26 17:37:00 glass Exp $
 * $Id: t1bv_12.c,v 1.1 2005/07/26 17:37:00 glass Exp $
 */

#include "t1b.h"

static const R *t1bv_12(R *ri, R *ii, const R *W, stride ios, int m, int dist)
{
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     int i;
     R *x;
     x = ii;
     BEGIN_SIMD();
     for (i = m; i > 0; i = i - VL, x = x + (VL * dist), W = W + (TWVL * 22)) {
	  V T1, Tt, T6, T7, TB, Tq, TC, TD, T9, Tu, Te, Tf, Tx, Tl, Ty;
	  V Tz;
	  {
	       V T5, T3, T4, T2;
	       T1 = LD(&(x[0]), dist, &(x[0]));
	       T4 = LD(&(x[WS(ios, 8)]), dist, &(x[0]));
	       T5 = BYTW(&(W[TWVL * 14]), T4);
	       T2 = LD(&(x[WS(ios, 4)]), dist, &(x[0]));
	       T3 = BYTW(&(W[TWVL * 6]), T2);
	       Tt = VSUB(T3, T5);
	       T6 = VADD(T3, T5);
	       T7 = VFNMS(LDK(KP500000000), T6, T1);
	  }
	  {
	       V Tn, Tp, Tm, TA, To;
	       Tm = LD(&(x[WS(ios, 1)]), dist, &(x[WS(ios, 1)]));
	       Tn = BYTW(&(W[0]), Tm);
	       TA = LD(&(x[WS(ios, 9)]), dist, &(x[WS(ios, 1)]));
	       TB = BYTW(&(W[TWVL * 16]), TA);
	       To = LD(&(x[WS(ios, 5)]), dist, &(x[WS(ios, 1)]));
	       Tp = BYTW(&(W[TWVL * 8]), To);
	       Tq = VSUB(Tn, Tp);
	       TC = VADD(Tn, Tp);
	       TD = VFNMS(LDK(KP500000000), TC, TB);
	  }
	  {
	       V Td, Tb, T8, Tc, Ta;
	       T8 = LD(&(x[WS(ios, 6)]), dist, &(x[0]));
	       T9 = BYTW(&(W[TWVL * 10]), T8);
	       Tc = LD(&(x[WS(ios, 2)]), dist, &(x[0]));
	       Td = BYTW(&(W[TWVL * 2]), Tc);
	       Ta = LD(&(x[WS(ios, 10)]), dist, &(x[0]));
	       Tb = BYTW(&(W[TWVL * 18]), Ta);
	       Tu = VSUB(Tb, Td);
	       Te = VADD(Tb, Td);
	       Tf = VFNMS(LDK(KP500000000), Te, T9);
	  }
	  {
	       V Ti, Tk, Th, Tw, Tj;
	       Th = LD(&(x[WS(ios, 7)]), dist, &(x[WS(ios, 1)]));
	       Ti = BYTW(&(W[TWVL * 12]), Th);
	       Tw = LD(&(x[WS(ios, 3)]), dist, &(x[WS(ios, 1)]));
	       Tx = BYTW(&(W[TWVL * 4]), Tw);
	       Tj = LD(&(x[WS(ios, 11)]), dist, &(x[WS(ios, 1)]));
	       Tk = BYTW(&(W[TWVL * 20]), Tj);
	       Tl = VSUB(Ti, Tk);
	       Ty = VADD(Ti, Tk);
	       Tz = VFNMS(LDK(KP500000000), Ty, Tx);
	  }
	  {
	       V Ts, TG, TF, TH;
	       {
		    V Tg, Tr, Tv, TE;
		    Tg = VSUB(T7, Tf);
		    Tr = VMUL(LDK(KP866025403), VSUB(Tl, Tq));
		    Ts = VSUB(Tg, Tr);
		    TG = VADD(Tg, Tr);
		    Tv = VMUL(LDK(KP866025403), VSUB(Tt, Tu));
		    TE = VSUB(Tz, TD);
		    TF = VBYI(VADD(Tv, TE));
		    TH = VBYI(VSUB(TE, Tv));
	       }
	       ST(&(x[WS(ios, 11)]), VSUB(Ts, TF), dist, &(x[WS(ios, 1)]));
	       ST(&(x[WS(ios, 5)]), VADD(TG, TH), dist, &(x[WS(ios, 1)]));
	       ST(&(x[WS(ios, 1)]), VADD(Ts, TF), dist, &(x[WS(ios, 1)]));
	       ST(&(x[WS(ios, 7)]), VSUB(TG, TH), dist, &(x[WS(ios, 1)]));
	  }
	  {
	       V TS, TW, TV, TX;
	       {
		    V TQ, TR, TT, TU;
		    TQ = VADD(T1, T6);
		    TR = VADD(T9, Te);
		    TS = VSUB(TQ, TR);
		    TW = VADD(TQ, TR);
		    TT = VADD(Tx, Ty);
		    TU = VADD(TB, TC);
		    TV = VBYI(VSUB(TT, TU));
		    TX = VADD(TT, TU);
	       }
	       ST(&(x[WS(ios, 3)]), VSUB(TS, TV), dist, &(x[WS(ios, 1)]));
	       ST(&(x[0]), VADD(TW, TX), dist, &(x[0]));
	       ST(&(x[WS(ios, 9)]), VADD(TS, TV), dist, &(x[WS(ios, 1)]));
	       ST(&(x[WS(ios, 6)]), VSUB(TW, TX), dist, &(x[0]));
	  }
	  {
	       V TK, TO, TN, TP;
	       {
		    V TI, TJ, TL, TM;
		    TI = VADD(Tl, Tq);
		    TJ = VADD(Tt, Tu);
		    TK = VBYI(VMUL(LDK(KP866025403), VSUB(TI, TJ)));
		    TO = VBYI(VMUL(LDK(KP866025403), VADD(TJ, TI)));
		    TL = VADD(T7, Tf);
		    TM = VADD(Tz, TD);
		    TN = VSUB(TL, TM);
		    TP = VADD(TL, TM);
	       }
	       ST(&(x[WS(ios, 2)]), VADD(TK, TN), dist, &(x[0]));
	       ST(&(x[WS(ios, 8)]), VSUB(TP, TO), dist, &(x[0]));
	       ST(&(x[WS(ios, 10)]), VSUB(TN, TK), dist, &(x[0]));
	       ST(&(x[WS(ios, 4)]), VADD(TO, TP), dist, &(x[0]));
	  }
     }
     END_SIMD();
     return W;
}

static const tw_instr twinstr[] = {
     VTW(1),
     VTW(2),
     VTW(3),
     VTW(4),
     VTW(5),
     VTW(6),
     VTW(7),
     VTW(8),
     VTW(9),
     VTW(10),
     VTW(11),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 12, "t1bv_12", twinstr, {55, 26, 4, 0}, &GENUS, 0, 0, 0 };

void X(codelet_t1bv_12) (planner *p) {
     X(kdft_dit_register) (p, t1bv_12, &desc);
}