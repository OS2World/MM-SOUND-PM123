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
/* Generated on Sat Jul  5 22:12:13 EDT 2003 */

#include "codelet_rdft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_hc2r -compact -variables 4 -sign 1 -n 16 -name hc2rIII_16 -dft-III -include hc2rIII.h */

/*
 * This function contains 66 FP additions, 32 FP multiplications,
 * (or, 54 additions, 20 multiplications, 12 fused multiply/add),
 * 40 stack variables, and 32 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: hc2rIII_16.c,v 1.2 2006/06/14 11:55:17 glass Exp $
 * $Id: hc2rIII_16.c,v 1.2 2006/06/14 11:55:17 glass Exp $
 * $Id: hc2rIII_16.c,v 1.2 2006/06/14 11:55:17 glass Exp $
 */

#include "hc2rIII.h"

static void hc2rIII_16(const R *ri, const R *ii, R *O, stride ris, stride iis, stride os, int v, int ivs, int ovs)
{
     DK(KP1_961570560, +1.961570560806460898252364472268478073947867462);
     DK(KP390180644, +0.390180644032256535696569736954044481855383236);
     DK(KP1_111140466, +1.111140466039204449485661627897065748749874382);
     DK(KP1_662939224, +1.662939224605090474157576755235811513477121624);
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     DK(KP1_414213562, +1.414213562373095048801688724209698078569671875);
     DK(KP765366864, +0.765366864730179543456919968060797733522689125);
     DK(KP1_847759065, +1.847759065022573512256366378793576573644833252);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     int i;
     for (i = v; i > 0; i = i - 1, ri = ri + ivs, ii = ii + ivs, O = O + ovs) {
	  E T7, TW, T13, Tj, TD, TK, TP, TH, Te, TX, T12, To, Tt, Tx, TS;
	  E Tw, TT, TY;
	  {
	       E T3, Tf, TC, TV, T6, Tz, Ti, TU;
	       {
		    E T1, T2, TA, TB;
		    T1 = ri[0];
		    T2 = ri[WS(ris, 7)];
		    T3 = T1 + T2;
		    Tf = T1 - T2;
		    TA = ii[0];
		    TB = ii[WS(iis, 7)];
		    TC = TA + TB;
		    TV = TB - TA;
	       }
	       {
		    E T4, T5, Tg, Th;
		    T4 = ri[WS(ris, 4)];
		    T5 = ri[WS(ris, 3)];
		    T6 = T4 + T5;
		    Tz = T4 - T5;
		    Tg = ii[WS(iis, 4)];
		    Th = ii[WS(iis, 3)];
		    Ti = Tg + Th;
		    TU = Tg - Th;
	       }
	       T7 = T3 + T6;
	       TW = TU + TV;
	       T13 = TV - TU;
	       Tj = Tf - Ti;
	       TD = Tz + TC;
	       TK = Tz - TC;
	       TP = T3 - T6;
	       TH = Tf + Ti;
	  }
	  {
	       E Ta, Tk, Tn, TR, Td, Tp, Ts, TQ;
	       {
		    E T8, T9, Tl, Tm;
		    T8 = ri[WS(ris, 2)];
		    T9 = ri[WS(ris, 5)];
		    Ta = T8 + T9;
		    Tk = T8 - T9;
		    Tl = ii[WS(iis, 2)];
		    Tm = ii[WS(iis, 5)];
		    Tn = Tl + Tm;
		    TR = Tl - Tm;
	       }
	       {
		    E Tb, Tc, Tq, Tr;
		    Tb = ri[WS(ris, 1)];
		    Tc = ri[WS(ris, 6)];
		    Td = Tb + Tc;
		    Tp = Tb - Tc;
		    Tq = ii[WS(iis, 1)];
		    Tr = ii[WS(iis, 6)];
		    Ts = Tq + Tr;
		    TQ = Tr - Tq;
	       }
	       Te = Ta + Td;
	       TX = Ta - Td;
	       T12 = TR + TQ;
	       To = Tk - Tn;
	       Tt = Tp - Ts;
	       Tx = Tp + Ts;
	       TS = TQ - TR;
	       Tw = Tk + Tn;
	  }
	  O[0] = KP2_000000000 * (T7 + Te);
	  O[WS(os, 8)] = KP2_000000000 * (T13 - T12);
	  TT = TP + TS;
	  TY = TW - TX;
	  O[WS(os, 2)] = FMA(KP1_847759065, TT, KP765366864 * TY);
	  O[WS(os, 10)] = FNMS(KP765366864, TT, KP1_847759065 * TY);
	  {
	       E T11, T14, TZ, T10;
	       T11 = T7 - Te;
	       T14 = T12 + T13;
	       O[WS(os, 4)] = KP1_414213562 * (T11 + T14);
	       O[WS(os, 12)] = KP1_414213562 * (T14 - T11);
	       TZ = TP - TS;
	       T10 = TX + TW;
	       O[WS(os, 6)] = FMA(KP765366864, TZ, KP1_847759065 * T10);
	       O[WS(os, 14)] = FNMS(KP1_847759065, TZ, KP765366864 * T10);
	  }
	  {
	       E TJ, TN, TM, TO, TI, TL;
	       TI = KP707106781 * (Tw + Tx);
	       TJ = TH - TI;
	       TN = TH + TI;
	       TL = KP707106781 * (To - Tt);
	       TM = TK - TL;
	       TO = TL + TK;
	       O[WS(os, 3)] = FMA(KP1_662939224, TJ, KP1_111140466 * TM);
	       O[WS(os, 15)] = FNMS(KP1_961570560, TN, KP390180644 * TO);
	       O[WS(os, 11)] = FNMS(KP1_111140466, TJ, KP1_662939224 * TM);
	       O[WS(os, 7)] = FMA(KP390180644, TN, KP1_961570560 * TO);
	  }
	  {
	       E Tv, TF, TE, TG, Tu, Ty;
	       Tu = KP707106781 * (To + Tt);
	       Tv = Tj + Tu;
	       TF = Tj - Tu;
	       Ty = KP707106781 * (Tw - Tx);
	       TE = Ty + TD;
	       TG = Ty - TD;
	       O[WS(os, 1)] = FNMS(KP390180644, TE, KP1_961570560 * Tv);
	       O[WS(os, 13)] = FNMS(KP1_662939224, TF, KP1_111140466 * TG);
	       O[WS(os, 9)] = -(FMA(KP390180644, Tv, KP1_961570560 * TE));
	       O[WS(os, 5)] = FMA(KP1_111140466, TF, KP1_662939224 * TG);
	  }
     }
}

static const khc2r_desc desc = { 16, "hc2rIII_16", {54, 20, 12, 0}, &GENUS, 0, 0, 0, 0, 0 };

void X(codelet_hc2rIII_16) (planner *p) {
     X(khc2rIII_register) (p, hc2rIII_16, &desc);
}
