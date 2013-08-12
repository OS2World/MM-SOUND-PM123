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
/* Generated on Sat Jul  5 21:40:21 EDT 2003 */

#include "codelet-dft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_notw_c -simd -compact -variables 4 -sign 1 -n 13 -name n1bv_13 -include n1b.h */

/*
 * This function contains 88 FP additions, 34 FP multiplications,
 * (or, 69 additions, 15 multiplications, 19 fused multiply/add),
 * 60 stack variables, and 26 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: n1bv_13.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 * $Id: n1bv_13.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 * $Id: n1bv_13.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 */

#include "n1b.h"

static void n1bv_13(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, int v, int ivs, int ovs)
{
     DVK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DVK(KP083333333, +0.083333333333333333333333333333333333333333333);
     DVK(KP075902986, +0.075902986037193865983102897245103540356428373);
     DVK(KP251768516, +0.251768516431883313623436926934233488546674281);
     DVK(KP132983124, +0.132983124607418643793760531921092974399165133);
     DVK(KP258260390, +0.258260390311744861420450644284508567852516811);
     DVK(KP1_732050807, +1.732050807568877293527446341505872366942805254);
     DVK(KP300238635, +0.300238635966332641462884626667381504676006424);
     DVK(KP011599105, +0.011599105605768290721655456654083252189827041);
     DVK(KP256247671, +0.256247671582936600958684654061725059144125175);
     DVK(KP156891391, +0.156891391051584611046832726756003269660212636);
     DVK(KP174138601, +0.174138601152135905005660794929264742616964676);
     DVK(KP575140729, +0.575140729474003121368385547455453388461001608);
     DVK(KP503537032, +0.503537032863766627246873853868466977093348562);
     DVK(KP113854479, +0.113854479055790798974654345867655310534642560);
     DVK(KP265966249, +0.265966249214837287587521063842185948798330267);
     DVK(KP387390585, +0.387390585467617292130675966426762851778775217);
     DVK(KP300462606, +0.300462606288665774426601772289207995520941381);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     int i;
     const R *xi;
     R *xo;
     xi = ii;
     xo = io;
     BEGIN_SIMD();
     for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs)) {
	  V TW, Tb, Tm, Ts, TB, TR, TX, TK, TU, Tz, TC, TN, TT;
	  TW = LD(&(xi[0]), ivs, &(xi[0]));
	  {
	       V Te, TH, Ta, Tu, Tp, T5, Tt, To, Th, Tw, Tk, Tx, Tl, TI, Tc;
	       V Td, Tq, Tr;
	       Tc = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
	       Td = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       Te = VSUB(Tc, Td);
	       TH = VADD(Tc, Td);
	       {
		    V T6, T7, T8, T9;
		    T6 = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
		    T7 = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
		    T8 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    T9 = VADD(T7, T8);
		    Ta = VADD(T6, T9);
		    Tu = VFNMS(LDK(KP500000000), T9, T6);
		    Tp = VSUB(T7, T8);
	       }
	       {
		    V T1, T2, T3, T4;
		    T1 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    T2 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    T3 = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
		    T4 = VADD(T2, T3);
		    T5 = VADD(T1, T4);
		    Tt = VFNMS(LDK(KP500000000), T4, T1);
		    To = VSUB(T2, T3);
	       }
	       {
		    V Tf, Tg, Ti, Tj;
		    Tf = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
		    Tg = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    Th = VSUB(Tf, Tg);
		    Tw = VADD(Tf, Tg);
		    Ti = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
		    Tj = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    Tk = VSUB(Ti, Tj);
		    Tx = VADD(Ti, Tj);
	       }
	       Tl = VADD(Th, Tk);
	       TI = VADD(Tw, Tx);
	       Tb = VSUB(T5, Ta);
	       Tm = VADD(Te, Tl);
	       Tq = VMUL(LDK(KP866025403), VSUB(To, Tp));
	       Tr = VFNMS(LDK(KP500000000), Tl, Te);
	       Ts = VADD(Tq, Tr);
	       TB = VSUB(Tq, Tr);
	       {
		    V TP, TQ, TG, TJ;
		    TP = VADD(T5, Ta);
		    TQ = VADD(TH, TI);
		    TR = VMUL(LDK(KP300462606), VSUB(TP, TQ));
		    TX = VADD(TP, TQ);
		    TG = VADD(Tt, Tu);
		    TJ = VFNMS(LDK(KP500000000), TI, TH);
		    TK = VSUB(TG, TJ);
		    TU = VADD(TG, TJ);
	       }
	       {
		    V Tv, Ty, TL, TM;
		    Tv = VSUB(Tt, Tu);
		    Ty = VMUL(LDK(KP866025403), VSUB(Tw, Tx));
		    Tz = VSUB(Tv, Ty);
		    TC = VADD(Tv, Ty);
		    TL = VADD(To, Tp);
		    TM = VSUB(Th, Tk);
		    TN = VSUB(TL, TM);
		    TT = VADD(TL, TM);
	       }
	  }
	  ST(&(xo[0]), VADD(TW, TX), ovs, &(xo[0]));
	  {
	       V T1c, T1n, T11, T14, T17, T1k, Tn, TE, T18, T1j, TS, T1m, TZ, T1f, TA;
	       V TD;
	       {
		    V T1a, T1b, T12, T13;
		    T1a = VFMA(LDK(KP387390585), TN, VMUL(LDK(KP265966249), TK));
		    T1b = VFNMS(LDK(KP503537032), TU, VMUL(LDK(KP113854479), TT));
		    T1c = VSUB(T1a, T1b);
		    T1n = VADD(T1a, T1b);
		    T11 = VFMA(LDK(KP575140729), Tb, VMUL(LDK(KP174138601), Tm));
		    T12 = VFNMS(LDK(KP256247671), Tz, VMUL(LDK(KP156891391), Ts));
		    T13 = VFMA(LDK(KP011599105), TB, VMUL(LDK(KP300238635), TC));
		    T14 = VADD(T12, T13);
		    T17 = VSUB(T11, T14);
		    T1k = VMUL(LDK(KP1_732050807), VSUB(T12, T13));
	       }
	       Tn = VFNMS(LDK(KP575140729), Tm, VMUL(LDK(KP174138601), Tb));
	       TA = VFMA(LDK(KP256247671), Ts, VMUL(LDK(KP156891391), Tz));
	       TD = VFNMS(LDK(KP011599105), TC, VMUL(LDK(KP300238635), TB));
	       TE = VADD(TA, TD);
	       T18 = VMUL(LDK(KP1_732050807), VSUB(TD, TA));
	       T1j = VSUB(Tn, TE);
	       {
		    V TO, T1e, TV, TY, T1d;
		    TO = VFNMS(LDK(KP132983124), TN, VMUL(LDK(KP258260390), TK));
		    T1e = VSUB(TR, TO);
		    TV = VFMA(LDK(KP251768516), TT, VMUL(LDK(KP075902986), TU));
		    TY = VFNMS(LDK(KP083333333), TX, TW);
		    T1d = VSUB(TY, TV);
		    TS = VFMA(LDK(KP2_000000000), TO, TR);
		    T1m = VADD(T1e, T1d);
		    TZ = VFMA(LDK(KP2_000000000), TV, TY);
		    T1f = VSUB(T1d, T1e);
	       }
	       {
		    V TF, T10, T1l, T1o;
		    TF = VBYI(VFMA(LDK(KP2_000000000), TE, Tn));
		    T10 = VADD(TS, TZ);
		    ST(&(xo[WS(os, 1)]), VADD(TF, T10), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 12)]), VSUB(T10, TF), ovs, &(xo[0]));
		    {
			 V T15, T16, T1p, T1q;
			 T15 = VBYI(VFMA(LDK(KP2_000000000), T14, T11));
			 T16 = VSUB(TZ, TS);
			 ST(&(xo[WS(os, 5)]), VADD(T15, T16), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 8)]), VSUB(T16, T15), ovs, &(xo[0]));
			 T1p = VADD(T1n, T1m);
			 T1q = VBYI(VADD(T1j, T1k));
			 ST(&(xo[WS(os, 4)]), VSUB(T1p, T1q), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 9)]), VADD(T1q, T1p), ovs, &(xo[WS(os, 1)]));
		    }
		    T1l = VBYI(VSUB(T1j, T1k));
		    T1o = VSUB(T1m, T1n);
		    ST(&(xo[WS(os, 3)]), VADD(T1l, T1o), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 10)]), VSUB(T1o, T1l), ovs, &(xo[0]));
		    {
			 V T1h, T1i, T19, T1g;
			 T1h = VBYI(VADD(T18, T17));
			 T1i = VSUB(T1f, T1c);
			 ST(&(xo[WS(os, 6)]), VADD(T1h, T1i), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 7)]), VSUB(T1i, T1h), ovs, &(xo[WS(os, 1)]));
			 T19 = VBYI(VSUB(T17, T18));
			 T1g = VADD(T1c, T1f);
			 ST(&(xo[WS(os, 2)]), VADD(T19, T1g), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 11)]), VSUB(T1g, T19), ovs, &(xo[WS(os, 1)]));
		    }
	       }
	  }
     }
     END_SIMD();
}

static const kdft_desc desc = { 13, "n1bv_13", {69, 15, 19, 0}, &GENUS, 0, 0, 0, 0 };
void X(codelet_n1bv_13) (planner *p) {
     X(kdft_register) (p, n1bv_13, &desc);
}
