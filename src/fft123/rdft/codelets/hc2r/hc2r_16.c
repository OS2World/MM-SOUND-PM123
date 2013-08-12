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
/* Generated on Sat Jul  5 22:11:13 EDT 2003 */

#include "codelet_rdft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_hc2r -compact -variables 4 -sign 1 -n 16 -name hc2r_16 -include hc2r.h */

/*
 * This function contains 58 FP additions, 18 FP multiplications,
 * (or, 54 additions, 14 multiplications, 4 fused multiply/add),
 * 31 stack variables, and 32 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: hc2r_16.c,v 1.2 2006/06/14 11:55:17 glass Exp $
 * $Id: hc2r_16.c,v 1.2 2006/06/14 11:55:17 glass Exp $
 * $Id: hc2r_16.c,v 1.2 2006/06/14 11:55:17 glass Exp $
 */

#include "hc2r.h"

static void hc2r_16(const R *ri, const R *ii, R *O, stride ris, stride iis, stride os, int v, int ivs, int ovs)
{
     DK(KP1_847759065, +1.847759065022573512256366378793576573644833252);
     DK(KP765366864, +0.765366864730179543456919968060797733522689125);
     DK(KP1_414213562, +1.414213562373095048801688724209698078569671875);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     int i;
     for (i = v; i > 0; i = i - 1, ri = ri + ivs, ii = ii + ivs, O = O + ovs) {
	  E T9, TS, Tl, TG, T6, TR, Ti, TD, Td, Tq, Tg, Tt, Tn, Tu, TV;
	  E TU, TN, TK;
	  {
	       E T7, T8, TE, Tj, Tk, TF;
	       T7 = ri[WS(ris, 2)];
	       T8 = ri[WS(ris, 6)];
	       TE = T7 - T8;
	       Tj = ii[WS(iis, 2)];
	       Tk = ii[WS(iis, 6)];
	       TF = Tj + Tk;
	       T9 = KP2_000000000 * (T7 + T8);
	       TS = KP1_414213562 * (TE + TF);
	       Tl = KP2_000000000 * (Tj - Tk);
	       TG = KP1_414213562 * (TE - TF);
	  }
	  {
	       E T5, TC, T3, TA;
	       {
		    E T4, TB, T1, T2;
		    T4 = ri[WS(ris, 4)];
		    T5 = KP2_000000000 * T4;
		    TB = ii[WS(iis, 4)];
		    TC = KP2_000000000 * TB;
		    T1 = ri[0];
		    T2 = ri[WS(ris, 8)];
		    T3 = T1 + T2;
		    TA = T1 - T2;
	       }
	       T6 = T3 + T5;
	       TR = TA + TC;
	       Ti = T3 - T5;
	       TD = TA - TC;
	  }
	  {
	       E TI, TM, TL, TJ;
	       {
		    E Tb, Tc, To, Tp;
		    Tb = ri[WS(ris, 1)];
		    Tc = ri[WS(ris, 7)];
		    Td = Tb + Tc;
		    TI = Tb - Tc;
		    To = ii[WS(iis, 1)];
		    Tp = ii[WS(iis, 7)];
		    Tq = To - Tp;
		    TM = To + Tp;
	       }
	       {
		    E Te, Tf, Tr, Ts;
		    Te = ri[WS(ris, 5)];
		    Tf = ri[WS(ris, 3)];
		    Tg = Te + Tf;
		    TL = Te - Tf;
		    Tr = ii[WS(iis, 5)];
		    Ts = ii[WS(iis, 3)];
		    Tt = Tr - Ts;
		    TJ = Tr + Ts;
	       }
	       Tn = Td - Tg;
	       Tu = Tq - Tt;
	       TV = TM - TL;
	       TU = TI + TJ;
	       TN = TL + TM;
	       TK = TI - TJ;
	  }
	  {
	       E Ta, Th, TT, TW;
	       Ta = T6 + T9;
	       Th = KP2_000000000 * (Td + Tg);
	       O[WS(os, 8)] = Ta - Th;
	       O[0] = Ta + Th;
	       TT = TR - TS;
	       TW = FNMS(KP1_847759065, TV, KP765366864 * TU);
	       O[WS(os, 11)] = TT - TW;
	       O[WS(os, 3)] = TT + TW;
	  }
	  {
	       E TX, TY, Tm, Tv;
	       TX = TR + TS;
	       TY = FMA(KP1_847759065, TU, KP765366864 * TV);
	       O[WS(os, 7)] = TX - TY;
	       O[WS(os, 15)] = TX + TY;
	       Tm = Ti - Tl;
	       Tv = KP1_414213562 * (Tn - Tu);
	       O[WS(os, 10)] = Tm - Tv;
	       O[WS(os, 2)] = Tm + Tv;
	  }
	  {
	       E Tw, Tx, TH, TO;
	       Tw = Ti + Tl;
	       Tx = KP1_414213562 * (Tn + Tu);
	       O[WS(os, 6)] = Tw - Tx;
	       O[WS(os, 14)] = Tw + Tx;
	       TH = TD + TG;
	       TO = FNMS(KP765366864, TN, KP1_847759065 * TK);
	       O[WS(os, 9)] = TH - TO;
	       O[WS(os, 1)] = TH + TO;
	  }
	  {
	       E TP, TQ, Ty, Tz;
	       TP = TD - TG;
	       TQ = FMA(KP765366864, TK, KP1_847759065 * TN);
	       O[WS(os, 5)] = TP - TQ;
	       O[WS(os, 13)] = TP + TQ;
	       Ty = T6 - T9;
	       Tz = KP2_000000000 * (Tt + Tq);
	       O[WS(os, 4)] = Ty - Tz;
	       O[WS(os, 12)] = Ty + Tz;
	  }
     }
}

static const khc2r_desc desc = { 16, "hc2r_16", {54, 14, 4, 0}, &GENUS, 0, 0, 0, 0, 0 };

void X(codelet_hc2r_16) (planner *p) {
     X(khc2r_register) (p, hc2r_16, &desc);
}
