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
/* Generated on Sat Jul  5 21:43:19 EDT 2003 */

#include "codelet-dft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_twiddle_c -simd -compact -variables 4 -n 9 -name t1fv_9 -include t1f.h */

/*
 * This function contains 54 FP additions, 42 FP multiplications,
 * (or, 38 additions, 26 multiplications, 16 fused multiply/add),
 * 38 stack variables, and 18 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: t1fv_9.c,v 1.1 2005/07/26 17:37:00 glass Exp $
 * $Id: t1fv_9.c,v 1.1 2005/07/26 17:37:00 glass Exp $
 * $Id: t1fv_9.c,v 1.1 2005/07/26 17:37:00 glass Exp $
 */

#include "t1f.h"

static const R *t1fv_9(R *ri, R *ii, const R *W, stride ios, int m, int dist)
{
     DVK(KP939692620, +0.939692620785908384054109277324731469936208134);
     DVK(KP296198132, +0.296198132726023843175338011893050938967728390);
     DVK(KP852868531, +0.852868531952443209628250963940074071936020296);
     DVK(KP173648177, +0.173648177666930348851716626769314796000375677);
     DVK(KP556670399, +0.556670399226419366452912952047023132968291906);
     DVK(KP766044443, +0.766044443118978035202392650555416673935832457);
     DVK(KP642787609, +0.642787609686539326322643409907263432907559884);
     DVK(KP663413948, +0.663413948168938396205421319635891297216863310);
     DVK(KP984807753, +0.984807753012208059366743024589523013670643252);
     DVK(KP150383733, +0.150383733180435296639271897612501926072238258);
     DVK(KP342020143, +0.342020143325668733044099614682259580763083368);
     DVK(KP813797681, +0.813797681349373692844693217248393223289101568);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     int i;
     R *x;
     x = ri;
     BEGIN_SIMD();
     for (i = m; i > 0; i = i - VL, x = x + (VL * dist), W = W + (TWVL * 16)) {
	  V T1, T6, TA, Tt, Tf, Ts, Tw, Tn, Tv;
	  T1 = LD(&(x[0]), dist, &(x[0]));
	  {
	       V T3, T5, T2, T4;
	       T2 = LD(&(x[WS(ios, 3)]), dist, &(x[WS(ios, 1)]));
	       T3 = BYTWJ(&(W[TWVL * 4]), T2);
	       T4 = LD(&(x[WS(ios, 6)]), dist, &(x[0]));
	       T5 = BYTWJ(&(W[TWVL * 10]), T4);
	       T6 = VADD(T3, T5);
	       TA = VMUL(LDK(KP866025403), VSUB(T5, T3));
	  }
	  {
	       V T9, Td, Tb, T8, Tc, Ta, Te;
	       T8 = LD(&(x[WS(ios, 1)]), dist, &(x[WS(ios, 1)]));
	       T9 = BYTWJ(&(W[0]), T8);
	       Tc = LD(&(x[WS(ios, 7)]), dist, &(x[WS(ios, 1)]));
	       Td = BYTWJ(&(W[TWVL * 12]), Tc);
	       Ta = LD(&(x[WS(ios, 4)]), dist, &(x[0]));
	       Tb = BYTWJ(&(W[TWVL * 6]), Ta);
	       Tt = VSUB(Td, Tb);
	       Te = VADD(Tb, Td);
	       Tf = VADD(T9, Te);
	       Ts = VFNMS(LDK(KP500000000), Te, T9);
	  }
	  {
	       V Th, Tl, Tj, Tg, Tk, Ti, Tm;
	       Tg = LD(&(x[WS(ios, 2)]), dist, &(x[0]));
	       Th = BYTWJ(&(W[TWVL * 2]), Tg);
	       Tk = LD(&(x[WS(ios, 8)]), dist, &(x[0]));
	       Tl = BYTWJ(&(W[TWVL * 14]), Tk);
	       Ti = LD(&(x[WS(ios, 5)]), dist, &(x[WS(ios, 1)]));
	       Tj = BYTWJ(&(W[TWVL * 8]), Ti);
	       Tw = VSUB(Tl, Tj);
	       Tm = VADD(Tj, Tl);
	       Tn = VADD(Th, Tm);
	       Tv = VFNMS(LDK(KP500000000), Tm, Th);
	  }
	  {
	       V Tq, T7, To, Tp;
	       Tq = VBYI(VMUL(LDK(KP866025403), VSUB(Tn, Tf)));
	       T7 = VADD(T1, T6);
	       To = VADD(Tf, Tn);
	       Tp = VFNMS(LDK(KP500000000), To, T7);
	       ST(&(x[0]), VADD(T7, To), dist, &(x[0]));
	       ST(&(x[WS(ios, 3)]), VADD(Tp, Tq), dist, &(x[WS(ios, 1)]));
	       ST(&(x[WS(ios, 6)]), VSUB(Tp, Tq), dist, &(x[0]));
	  }
	  {
	       V TI, TB, TC, TD, Tu, Tx, Ty, Tr, TH;
	       TI = VBYI(VSUB(VFNMS(LDK(KP342020143), Tv, VFNMS(LDK(KP150383733), Tt, VFNMS(LDK(KP984807753), Ts, VMUL(LDK(KP813797681), Tw)))), TA));
	       TB = VFNMS(LDK(KP642787609), Ts, VMUL(LDK(KP663413948), Tt));
	       TC = VFNMS(LDK(KP984807753), Tv, VMUL(LDK(KP150383733), Tw));
	       TD = VADD(TB, TC);
	       Tu = VFMA(LDK(KP766044443), Ts, VMUL(LDK(KP556670399), Tt));
	       Tx = VFMA(LDK(KP173648177), Tv, VMUL(LDK(KP852868531), Tw));
	       Ty = VADD(Tu, Tx);
	       Tr = VFNMS(LDK(KP500000000), T6, T1);
	       TH = VFMA(LDK(KP173648177), Ts, VFNMS(LDK(KP296198132), Tw, VFNMS(LDK(KP939692620), Tv, VFNMS(LDK(KP852868531), Tt, Tr))));
	       ST(&(x[WS(ios, 7)]), VSUB(TH, TI), dist, &(x[WS(ios, 1)]));
	       ST(&(x[WS(ios, 2)]), VADD(TH, TI), dist, &(x[0]));
	       {
		    V Tz, TE, TF, TG;
		    Tz = VADD(Tr, Ty);
		    TE = VBYI(VADD(TA, TD));
		    ST(&(x[WS(ios, 8)]), VSUB(Tz, TE), dist, &(x[0]));
		    ST(&(x[WS(ios, 1)]), VADD(TE, Tz), dist, &(x[WS(ios, 1)]));
		    TF = VFMA(LDK(KP866025403), VSUB(TB, TC), VFNMS(LDK(KP500000000), Ty, Tr));
		    TG = VBYI(VADD(TA, VFNMS(LDK(KP500000000), TD, VMUL(LDK(KP866025403), VSUB(Tx, Tu)))));
		    ST(&(x[WS(ios, 5)]), VSUB(TF, TG), dist, &(x[WS(ios, 1)]));
		    ST(&(x[WS(ios, 4)]), VADD(TF, TG), dist, &(x[0]));
	       }
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
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 9, "t1fv_9", twinstr, {38, 26, 16, 0}, &GENUS, 0, 0, 0 };

void X(codelet_t1fv_9) (planner *p) {
     X(kdft_dit_register) (p, t1fv_9, &desc);
}