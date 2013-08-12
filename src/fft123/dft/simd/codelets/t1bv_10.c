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
/* Generated on Sat Jul  5 21:43:51 EDT 2003 */

#include "codelet-dft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_twiddle_c -simd -compact -variables 4 -n 10 -name t1bv_10 -include t1b.h -sign 1 */

/*
 * This function contains 51 FP additions, 30 FP multiplications,
 * (or, 45 additions, 24 multiplications, 6 fused multiply/add),
 * 32 stack variables, and 20 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: t1bv_10.c,v 1.1 2005/07/26 17:37:00 glass Exp $
 * $Id: t1bv_10.c,v 1.1 2005/07/26 17:37:00 glass Exp $
 * $Id: t1bv_10.c,v 1.1 2005/07/26 17:37:00 glass Exp $
 */

#include "t1b.h"

static const R *t1bv_10(R *ri, R *ii, const R *W, stride ios, int m, int dist)
{
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     int i;
     R *x;
     x = ii;
     BEGIN_SIMD();
     for (i = m; i > 0; i = i - VL, x = x + (VL * dist), W = W + (TWVL * 18)) {
	  V Tu, TH, Tg, Tl, Tp, TD, TE, TJ, T5, Ta, To, TA, TB, TI, Tr;
	  V Tt, Ts;
	  Tr = LD(&(x[0]), dist, &(x[0]));
	  Ts = LD(&(x[WS(ios, 5)]), dist, &(x[WS(ios, 1)]));
	  Tt = BYTW(&(W[TWVL * 8]), Ts);
	  Tu = VSUB(Tr, Tt);
	  TH = VADD(Tr, Tt);
	  {
	       V Td, Tk, Tf, Ti;
	       {
		    V Tc, Tj, Te, Th;
		    Tc = LD(&(x[WS(ios, 4)]), dist, &(x[0]));
		    Td = BYTW(&(W[TWVL * 6]), Tc);
		    Tj = LD(&(x[WS(ios, 1)]), dist, &(x[WS(ios, 1)]));
		    Tk = BYTW(&(W[0]), Tj);
		    Te = LD(&(x[WS(ios, 9)]), dist, &(x[WS(ios, 1)]));
		    Tf = BYTW(&(W[TWVL * 16]), Te);
		    Th = LD(&(x[WS(ios, 6)]), dist, &(x[0]));
		    Ti = BYTW(&(W[TWVL * 10]), Th);
	       }
	       Tg = VSUB(Td, Tf);
	       Tl = VSUB(Ti, Tk);
	       Tp = VADD(Tg, Tl);
	       TD = VADD(Td, Tf);
	       TE = VADD(Ti, Tk);
	       TJ = VADD(TD, TE);
	  }
	  {
	       V T2, T9, T4, T7;
	       {
		    V T1, T8, T3, T6;
		    T1 = LD(&(x[WS(ios, 2)]), dist, &(x[0]));
		    T2 = BYTW(&(W[TWVL * 2]), T1);
		    T8 = LD(&(x[WS(ios, 3)]), dist, &(x[WS(ios, 1)]));
		    T9 = BYTW(&(W[TWVL * 4]), T8);
		    T3 = LD(&(x[WS(ios, 7)]), dist, &(x[WS(ios, 1)]));
		    T4 = BYTW(&(W[TWVL * 12]), T3);
		    T6 = LD(&(x[WS(ios, 8)]), dist, &(x[0]));
		    T7 = BYTW(&(W[TWVL * 14]), T6);
	       }
	       T5 = VSUB(T2, T4);
	       Ta = VSUB(T7, T9);
	       To = VADD(T5, Ta);
	       TA = VADD(T2, T4);
	       TB = VADD(T7, T9);
	       TI = VADD(TA, TB);
	  }
	  {
	       V Tq, Tv, Tw, Tn, Tz, Tb, Tm, Ty, Tx;
	       Tq = VMUL(LDK(KP559016994), VSUB(To, Tp));
	       Tv = VADD(To, Tp);
	       Tw = VFNMS(LDK(KP250000000), Tv, Tu);
	       Tb = VSUB(T5, Ta);
	       Tm = VSUB(Tg, Tl);
	       Tn = VBYI(VFMA(LDK(KP951056516), Tb, VMUL(LDK(KP587785252), Tm)));
	       Tz = VBYI(VFNMS(LDK(KP951056516), Tm, VMUL(LDK(KP587785252), Tb)));
	       ST(&(x[WS(ios, 5)]), VADD(Tu, Tv), dist, &(x[WS(ios, 1)]));
	       Ty = VSUB(Tw, Tq);
	       ST(&(x[WS(ios, 3)]), VSUB(Ty, Tz), dist, &(x[WS(ios, 1)]));
	       ST(&(x[WS(ios, 7)]), VADD(Tz, Ty), dist, &(x[WS(ios, 1)]));
	       Tx = VADD(Tq, Tw);
	       ST(&(x[WS(ios, 1)]), VADD(Tn, Tx), dist, &(x[WS(ios, 1)]));
	       ST(&(x[WS(ios, 9)]), VSUB(Tx, Tn), dist, &(x[WS(ios, 1)]));
	  }
	  {
	       V TM, TK, TL, TG, TP, TC, TF, TO, TN;
	       TM = VMUL(LDK(KP559016994), VSUB(TI, TJ));
	       TK = VADD(TI, TJ);
	       TL = VFNMS(LDK(KP250000000), TK, TH);
	       TC = VSUB(TA, TB);
	       TF = VSUB(TD, TE);
	       TG = VBYI(VFNMS(LDK(KP951056516), TF, VMUL(LDK(KP587785252), TC)));
	       TP = VBYI(VFMA(LDK(KP951056516), TC, VMUL(LDK(KP587785252), TF)));
	       ST(&(x[0]), VADD(TH, TK), dist, &(x[0]));
	       TO = VADD(TM, TL);
	       ST(&(x[WS(ios, 4)]), VSUB(TO, TP), dist, &(x[0]));
	       ST(&(x[WS(ios, 6)]), VADD(TP, TO), dist, &(x[0]));
	       TN = VSUB(TL, TM);
	       ST(&(x[WS(ios, 2)]), VADD(TG, TN), dist, &(x[0]));
	       ST(&(x[WS(ios, 8)]), VSUB(TN, TG), dist, &(x[0]));
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
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 10, "t1bv_10", twinstr, {45, 24, 6, 0}, &GENUS, 0, 0, 0 };

void X(codelet_t1bv_10) (planner *p) {
     X(kdft_dit_register) (p, t1bv_10, &desc);
}
