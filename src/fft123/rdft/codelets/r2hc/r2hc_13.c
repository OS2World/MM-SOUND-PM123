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
/* Generated on Sat Jul  5 21:56:41 EDT 2003 */

#include "codelet_rdft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_r2hc -compact -variables 4 -n 13 -name r2hc_13 -include r2hc.h */

/*
 * This function contains 76 FP additions, 34 FP multiplications,
 * (or, 57 additions, 15 multiplications, 19 fused multiply/add),
 * 55 stack variables, and 26 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: r2hc_13.c,v 1.2 2006/06/14 11:56:49 glass Exp $
 * $Id: r2hc_13.c,v 1.2 2006/06/14 11:56:49 glass Exp $
 * $Id: r2hc_13.c,v 1.2 2006/06/14 11:56:49 glass Exp $
 */

#include "r2hc.h"

static void r2hc_13(const R *I, R *ro, R *io, stride is, stride ros, stride ios, int v, int ivs, int ovs)
{
     DK(KP083333333, +0.083333333333333333333333333333333333333333333);
     DK(KP075902986, +0.075902986037193865983102897245103540356428373);
     DK(KP251768516, +0.251768516431883313623436926934233488546674281);
     DK(KP503537032, +0.503537032863766627246873853868466977093348562);
     DK(KP113854479, +0.113854479055790798974654345867655310534642560);
     DK(KP265966249, +0.265966249214837287587521063842185948798330267);
     DK(KP387390585, +0.387390585467617292130675966426762851778775217);
     DK(KP300462606, +0.300462606288665774426601772289207995520941381);
     DK(KP132983124, +0.132983124607418643793760531921092974399165133);
     DK(KP258260390, +0.258260390311744861420450644284508567852516811);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     DK(KP1_732050807, +1.732050807568877293527446341505872366942805254);
     DK(KP300238635, +0.300238635966332641462884626667381504676006424);
     DK(KP011599105, +0.011599105605768290721655456654083252189827041);
     DK(KP156891391, +0.156891391051584611046832726756003269660212636);
     DK(KP256247671, +0.256247671582936600958684654061725059144125175);
     DK(KP174138601, +0.174138601152135905005660794929264742616964676);
     DK(KP575140729, +0.575140729474003121368385547455453388461001608);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     int i;
     for (i = v; i > 0; i = i - 1, I = I + ivs, ro = ro + ovs, io = io + ovs) {
	  E T13, Tb, Tm, TW, TX, T14, TU, T10, Tz, TB, Tu, TC, TR, T11;
	  T13 = I[0];
	  {
	       E Te, TO, Ta, Tv, To, T5, Tw, Tp, Th, Tr, Tk, Ts, Tl, TP, Tc;
	       E Td;
	       Tc = I[WS(is, 8)];
	       Td = I[WS(is, 5)];
	       Te = Tc - Td;
	       TO = Tc + Td;
	       {
		    E T6, T7, T8, T9;
		    T6 = I[WS(is, 1)];
		    T7 = I[WS(is, 3)];
		    T8 = I[WS(is, 9)];
		    T9 = T7 + T8;
		    Ta = T6 + T9;
		    Tv = T7 - T8;
		    To = FNMS(KP500000000, T9, T6);
	       }
	       {
		    E T1, T2, T3, T4;
		    T1 = I[WS(is, 12)];
		    T2 = I[WS(is, 10)];
		    T3 = I[WS(is, 4)];
		    T4 = T2 + T3;
		    T5 = T1 + T4;
		    Tw = T2 - T3;
		    Tp = FNMS(KP500000000, T4, T1);
	       }
	       {
		    E Tf, Tg, Ti, Tj;
		    Tf = I[WS(is, 11)];
		    Tg = I[WS(is, 6)];
		    Th = Tf - Tg;
		    Tr = Tf + Tg;
		    Ti = I[WS(is, 7)];
		    Tj = I[WS(is, 2)];
		    Tk = Ti - Tj;
		    Ts = Ti + Tj;
	       }
	       Tl = Th + Tk;
	       TP = Tr + Ts;
	       Tb = T5 - Ta;
	       Tm = Te + Tl;
	       TW = Ta + T5;
	       TX = TO + TP;
	       T14 = TW + TX;
	       {
		    E TS, TT, Tx, Ty;
		    TS = Tv + Tw;
		    TT = Th - Tk;
		    TU = TS - TT;
		    T10 = TS + TT;
		    Tx = KP866025403 * (Tv - Tw);
		    Ty = FNMS(KP500000000, Tl, Te);
		    Tz = Tx + Ty;
		    TB = Ty - Tx;
	       }
	       {
		    E Tq, Tt, TN, TQ;
		    Tq = To - Tp;
		    Tt = KP866025403 * (Tr - Ts);
		    Tu = Tq - Tt;
		    TC = Tq + Tt;
		    TN = To + Tp;
		    TQ = FNMS(KP500000000, TP, TO);
		    TR = TN - TQ;
		    T11 = TN + TQ;
	       }
	  }
	  ro[0] = T13 + T14;
	  {
	       E Tn, TG, TE, TF, TJ, TM, TK, TL;
	       Tn = FNMS(KP174138601, Tm, KP575140729 * Tb);
	       TG = FMA(KP174138601, Tb, KP575140729 * Tm);
	       {
		    E TA, TD, TH, TI;
		    TA = FNMS(KP156891391, Tz, KP256247671 * Tu);
		    TD = FNMS(KP300238635, TC, KP011599105 * TB);
		    TE = TA + TD;
		    TF = KP1_732050807 * (TD - TA);
		    TH = FMA(KP300238635, TB, KP011599105 * TC);
		    TI = FMA(KP256247671, Tz, KP156891391 * Tu);
		    TJ = TH - TI;
		    TM = KP1_732050807 * (TI + TH);
	       }
	       io[WS(ios, 5)] = FMA(KP2_000000000, TE, Tn);
	       io[WS(ios, 1)] = FMA(KP2_000000000, TJ, TG);
	       TK = TG - TJ;
	       io[WS(ios, 4)] = TF - TK;
	       io[WS(ios, 3)] = TF + TK;
	       TL = Tn - TE;
	       io[WS(ios, 2)] = TL - TM;
	       io[WS(ios, 6)] = TL + TM;
	  }
	  {
	       E TZ, T1b, T19, T1e, T16, T1a, TV, TY, T1c, T1d;
	       TV = FNMS(KP132983124, TU, KP258260390 * TR);
	       TY = KP300462606 * (TW - TX);
	       TZ = FMA(KP2_000000000, TV, TY);
	       T1b = TY - TV;
	       {
		    E T17, T18, T12, T15;
		    T17 = FMA(KP387390585, TU, KP265966249 * TR);
		    T18 = FNMS(KP503537032, T11, KP113854479 * T10);
		    T19 = T17 - T18;
		    T1e = T17 + T18;
		    T12 = FMA(KP251768516, T10, KP075902986 * T11);
		    T15 = FNMS(KP083333333, T14, T13);
		    T16 = FMA(KP2_000000000, T12, T15);
		    T1a = T15 - T12;
	       }
	       ro[WS(ros, 1)] = TZ + T16;
	       ro[WS(ros, 5)] = T16 - TZ;
	       T1c = T1a - T1b;
	       ro[WS(ros, 2)] = T19 + T1c;
	       ro[WS(ros, 6)] = T1c - T19;
	       T1d = T1b + T1a;
	       ro[WS(ros, 3)] = T1d - T1e;
	       ro[WS(ros, 4)] = T1e + T1d;
	  }
     }
}

static const kr2hc_desc desc = { 13, "r2hc_13", {57, 15, 19, 0}, &GENUS, 0, 0, 0, 0, 0 };

void X(codelet_r2hc_13) (planner *p) {
     X(kr2hc_register) (p, r2hc_13, &desc);
}
