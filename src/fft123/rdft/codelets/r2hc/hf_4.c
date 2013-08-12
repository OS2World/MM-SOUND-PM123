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
/* Generated on Sat Jul  5 21:56:51 EDT 2003 */

#include "codelet_rdft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_hc2hc -compact -variables 4 -n 4 -dit -name hf_4 -include hf.h */

/*
 * This function contains 22 FP additions, 12 FP multiplications,
 * (or, 16 additions, 6 multiplications, 6 fused multiply/add),
 * 13 stack variables, and 16 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: hf_4.c,v 1.2 2006/06/14 11:56:49 glass Exp $
 * $Id: hf_4.c,v 1.2 2006/06/14 11:56:49 glass Exp $
 * $Id: hf_4.c,v 1.2 2006/06/14 11:56:49 glass Exp $
 */

#include "hf.h"

static const R *hf_4(R *rio, R *iio, const R *W, stride ios, int m, int dist)
{
     int i;
     for (i = m - 2; i > 0; i = i - 2, rio = rio + dist, iio = iio - dist, W = W + 6) {
	  E T1, Th, Tl, Tp, T6, To, Tc, Tk;
	  T1 = rio[0];
	  {
	       E Te, Tg, Td, Tf;
	       Te = rio[WS(ios, 3)];
	       Tg = iio[0];
	       Td = W[4];
	       Tf = W[5];
	       Th = FMA(Td, Te, Tf * Tg);
	       Tl = FNMS(Tf, Te, Td * Tg);
	  }
	  Tp = iio[-WS(ios, 3)];
	  {
	       E T3, T5, T2, T4;
	       T3 = rio[WS(ios, 2)];
	       T5 = iio[-WS(ios, 1)];
	       T2 = W[2];
	       T4 = W[3];
	       T6 = FMA(T2, T3, T4 * T5);
	       To = FNMS(T4, T3, T2 * T5);
	  }
	  {
	       E T9, Tb, T8, Ta;
	       T9 = rio[WS(ios, 1)];
	       Tb = iio[-WS(ios, 2)];
	       T8 = W[0];
	       Ta = W[1];
	       Tc = FMA(T8, T9, Ta * Tb);
	       Tk = FNMS(Ta, T9, T8 * Tb);
	  }
	  {
	       E T7, Ti, Tn, Tq;
	       T7 = T1 + T6;
	       Ti = Tc + Th;
	       iio[-WS(ios, 2)] = T7 - Ti;
	       rio[0] = T7 + Ti;
	       Tn = Tk + Tl;
	       Tq = To + Tp;
	       rio[WS(ios, 2)] = Tn - Tq;
	       iio[0] = Tn + Tq;
	  }
	  {
	       E Tj, Tm, Tr, Ts;
	       Tj = T1 - T6;
	       Tm = Tk - Tl;
	       iio[-WS(ios, 3)] = Tj - Tm;
	       rio[WS(ios, 1)] = Tj + Tm;
	       Tr = Th - Tc;
	       Ts = Tp - To;
	       rio[WS(ios, 3)] = Tr - Ts;
	       iio[-WS(ios, 1)] = Tr + Ts;
	  }
     }
     return W;
}

static const tw_instr twinstr[] = {
     {TW_FULL, 0, 4},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 4, "hf_4", twinstr, {16, 6, 6, 0}, &GENUS, 0, 0, 0 };

void X(codelet_hf_4) (planner *p) {
     X(khc2hc_dit_register) (p, hf_4, &desc);
}
