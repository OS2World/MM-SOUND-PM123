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
/* Generated on Sat Jul  5 21:57:30 EDT 2003 */

#include "codelet_rdft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_hc2hc -compact -variables 4 -twiddle-log3 -n 16 -dit -name hf2_16 -include hf.h */

/*
 * This function contains 196 FP additions, 108 FP multiplications,
 * (or, 156 additions, 68 multiplications, 40 fused multiply/add),
 * 104 stack variables, and 64 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: hf2_16.c,v 1.2 2006/06/14 11:56:49 glass Exp $
 * $Id: hf2_16.c,v 1.2 2006/06/14 11:56:49 glass Exp $
 * $Id: hf2_16.c,v 1.2 2006/06/14 11:56:49 glass Exp $
 */

#include "hf.h"

static const R *hf2_16(R *rio, R *iio, const R *W, stride ios, int m, int dist)
{
     DK(KP382683432, +0.382683432365089771728459984030398866761344562);
     DK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     int i;
     for (i = m - 2; i > 0; i = i - 2, rio = rio + dist, iio = iio - dist, W = W + 8) {
	  E T1, T3d, T18, T26, T29, T2R, Tq, T1r, T1E, T2k, T2g, T1O, Te, T3c, Tz;
	  E T1P, T1S, T1T, T1U, TG, TL, T1V, T1Y, T1Z, T20, TT, TY, T1X, T1A, T2l;
	  E T1J, T2h, T1h, T2b, T1m, T2a;
	  T1 = rio[0];
	  T3d = iio[-WS(ios, 15)];
	  {
	       E T9, T1z, Td, T1v, T1I, Tl, Tp, T1G, Tu, T1D, TD, Ty, T1C, T1l, TX;
	       E TK, T1g, TI, T1j, TF, T1c, TQ, TS, T1p, T1q, TV, T2, T5, Ti, Tg;
	       E T4, Tw, Ts, Ta, Tv, T7, Tb, Tr, Tk, TW, TJ, TC, TU, To, TE;
	       E TH, T14, T24, T17, T25, TN, TO, TP, TR;
	       T9 = rio[WS(ios, 8)];
	       T1z = iio[-WS(ios, 8)];
	       Td = iio[-WS(ios, 7)];
	       T1v = rio[WS(ios, 7)];
	       T1I = iio[-WS(ios, 4)];
	       Tl = rio[WS(ios, 4)];
	       Tp = iio[-WS(ios, 11)];
	       T1G = rio[WS(ios, 11)];
	       Tu = rio[WS(ios, 12)];
	       T1D = iio[-WS(ios, 12)];
	       TD = rio[WS(ios, 2)];
	       Ty = iio[-WS(ios, 3)];
	       T1C = rio[WS(ios, 3)];
	       T1l = iio[-WS(ios, 2)];
	       TX = iio[-WS(ios, 9)];
	       TK = iio[-WS(ios, 5)];
	       T1g = iio[-WS(ios, 10)];
	       TI = rio[WS(ios, 10)];
	       T1j = rio[WS(ios, 13)];
	       TF = iio[-WS(ios, 13)];
	       T1c = rio[WS(ios, 5)];
	       TQ = rio[WS(ios, 14)];
	       TS = iio[-WS(ios, 1)];
	       T1p = rio[WS(ios, 15)];
	       T1q = iio[0];
	       TV = rio[WS(ios, 6)];
	       {
		    E T12, T16, T13, T15, T3, T6, Tm, Tj, Tn, Th;
		    T12 = rio[WS(ios, 1)];
		    T16 = iio[-WS(ios, 6)];
		    T13 = iio[-WS(ios, 14)];
		    T15 = rio[WS(ios, 9)];
		    T2 = W[4];
		    T5 = W[5];
		    T3 = W[0];
		    T6 = W[1];
		    Ti = W[3];
		    Tg = W[2];
		    T4 = T2 * T3;
		    Tw = T5 * Tg;
		    Ts = T5 * Ti;
		    Ta = T2 * T6;
		    Tv = T2 * Ti;
		    T7 = T5 * T6;
		    Tb = T5 * T3;
		    Tr = T2 * Tg;
		    Tm = Tg * T6;
		    Tj = Ti * T6;
		    Tn = Ti * T3;
		    Th = Tg * T3;
		    Tk = Th - Tj;
		    TW = Tv - Tw;
		    TJ = Ta + Tb;
		    TC = Th + Tj;
		    TU = Tr + Ts;
		    To = Tm + Tn;
		    TE = Tm - Tn;
		    TH = T4 - T7;
		    T14 = FMA(T3, T12, T6 * T13);
		    T24 = FNMS(T6, T12, T3 * T13);
		    T17 = FMA(T2, T15, T5 * T16);
		    T25 = FNMS(T5, T15, T2 * T16);
		    TN = W[6];
		    TO = W[7];
		    TP = FMA(TN, T3, TO * T6);
		    TR = FNMS(TO, T3, TN * T6);
	       }
	       T18 = T14 + T17;
	       T26 = T24 - T25;
	       T29 = T14 - T17;
	       T2R = T24 + T25;
	       Tq = FMA(Tk, Tl, To * Tp);
	       T1r = FMA(TN, T1p, TO * T1q);
	       T1E = FMA(Tg, T1C, Ti * T1D);
	       T2k = FNMS(TO, T1p, TN * T1q);
	       T2g = FNMS(Ti, T1C, Tg * T1D);
	       {
		    E T8, Tc, Tt, Tx;
		    T1O = FNMS(To, Tl, Tk * Tp);
		    T8 = T4 + T7;
		    Tc = Ta - Tb;
		    Te = FNMS(Tc, Td, T8 * T9);
		    T3c = FMA(Tc, T9, T8 * Td);
		    Tt = Tr - Ts;
		    Tx = Tv + Tw;
		    Tz = FMA(Tt, Tu, Tx * Ty);
		    T1P = FNMS(Tx, Tu, Tt * Ty);
		    T1S = FMA(TE, TD, TC * TF);
		    T1T = FNMS(TJ, TI, TH * TK);
		    T1U = T1S - T1T;
	       }
	       TG = FNMS(TE, TF, TC * TD);
	       TL = FMA(TH, TI, TJ * TK);
	       T1V = TG - TL;
	       T1Y = FMA(TR, TQ, TP * TS);
	       T1Z = FMA(TW, TV, TU * TX);
	       T20 = T1Y - T1Z;
	       TT = FNMS(TR, TS, TP * TQ);
	       TY = FNMS(TW, TX, TU * TV);
	       T1X = TT - TY;
	       {
		    E T1u, T1F, T1y, T1H;
		    {
			 E T1s, T1t, T1w, T1x;
			 T1s = T2 * TC;
			 T1t = T5 * TE;
			 T1u = T1s - T1t;
			 T1F = T1s + T1t;
			 T1w = T2 * TE;
			 T1x = T5 * TC;
			 T1y = T1w + T1x;
			 T1H = T1w - T1x;
		    }
		    T1A = FMA(T1u, T1v, T1y * T1z);
		    T2l = FNMS(T1y, T1v, T1u * T1z);
		    T1J = FNMS(T1H, T1I, T1F * T1G);
		    T2h = FMA(T1H, T1G, T1F * T1I);
	       }
	       {
		    E T1b, T1i, T1f, T1k;
		    {
			 E T19, T1a, T1d, T1e;
			 T19 = T2 * Tk;
			 T1a = T5 * To;
			 T1b = T19 + T1a;
			 T1i = T19 - T1a;
			 T1d = T2 * To;
			 T1e = T5 * Tk;
			 T1f = T1d - T1e;
			 T1k = T1d + T1e;
		    }
		    T1h = FNMS(T1f, T1g, T1b * T1c);
		    T2b = FNMS(T1k, T1j, T1i * T1l);
		    T1m = FMA(T1i, T1j, T1k * T1l);
		    T2a = FMA(T1f, T1c, T1b * T1g);
	       }
	  }
	  {
	       E TB, T2L, T10, T3k, T3f, T3l, T2O, T3a, T1o, T36, T2U, T32, T1L, T37, T2Z;
	       E T33;
	       {
		    E Tf, TA, T2M, T2N;
		    Tf = T1 + Te;
		    TA = Tq + Tz;
		    TB = Tf + TA;
		    T2L = Tf - TA;
		    {
			 E TM, TZ, T3b, T3e;
			 TM = TG + TL;
			 TZ = TT + TY;
			 T10 = TM + TZ;
			 T3k = TZ - TM;
			 T3b = T1O + T1P;
			 T3e = T3c + T3d;
			 T3f = T3b + T3e;
			 T3l = T3e - T3b;
		    }
		    T2M = T1S + T1T;
		    T2N = T1Y + T1Z;
		    T2O = T2M - T2N;
		    T3a = T2M + T2N;
		    {
			 E T1n, T2Q, T2S, T2T;
			 T1n = T1h + T1m;
			 T2Q = T18 - T1n;
			 T2S = T2a + T2b;
			 T2T = T2R - T2S;
			 T1o = T18 + T1n;
			 T36 = T2R + T2S;
			 T2U = T2Q + T2T;
			 T32 = T2T - T2Q;
		    }
		    {
			 E T1B, T1K, T2V, T2W, T2X, T2Y;
			 T1B = T1r + T1A;
			 T1K = T1E + T1J;
			 T2V = T1B - T1K;
			 T2W = T2k + T2l;
			 T2X = T2g + T2h;
			 T2Y = T2W - T2X;
			 T1L = T1B + T1K;
			 T37 = T2W + T2X;
			 T2Z = T2V - T2Y;
			 T33 = T2V + T2Y;
		    }
	       }
	       {
		    E T11, T1M, T39, T3g;
		    T11 = TB + T10;
		    T1M = T1o + T1L;
		    iio[-WS(ios, 8)] = T11 - T1M;
		    rio[0] = T11 + T1M;
		    T39 = T36 + T37;
		    T3g = T3a + T3f;
		    rio[WS(ios, 8)] = T39 - T3g;
		    iio[0] = T39 + T3g;
	       }
	       {
		    E T2P, T30, T3j, T3m;
		    T2P = T2L + T2O;
		    T30 = KP707106781 * (T2U + T2Z);
		    iio[-WS(ios, 10)] = T2P - T30;
		    rio[WS(ios, 2)] = T2P + T30;
		    T3j = KP707106781 * (T32 + T33);
		    T3m = T3k + T3l;
		    rio[WS(ios, 10)] = T3j - T3m;
		    iio[-WS(ios, 2)] = T3j + T3m;
	       }
	       {
		    E T31, T34, T3n, T3o;
		    T31 = T2L - T2O;
		    T34 = KP707106781 * (T32 - T33);
		    iio[-WS(ios, 14)] = T31 - T34;
		    rio[WS(ios, 6)] = T31 + T34;
		    T3n = KP707106781 * (T2Z - T2U);
		    T3o = T3l - T3k;
		    rio[WS(ios, 14)] = T3n - T3o;
		    iio[-WS(ios, 6)] = T3n + T3o;
	       }
	       {
		    E T35, T38, T3h, T3i;
		    T35 = TB - T10;
		    T38 = T36 - T37;
		    iio[-WS(ios, 12)] = T35 - T38;
		    rio[WS(ios, 4)] = T35 + T38;
		    T3h = T1L - T1o;
		    T3i = T3f - T3a;
		    rio[WS(ios, 12)] = T3h - T3i;
		    iio[-WS(ios, 4)] = T3h + T3i;
	       }
	  }
	  {
	       E T1R, T2v, T22, T3q, T3t, T3z, T2y, T3y, T2e, T2I, T2s, T2C, T2p, T2J, T2t;
	       E T2F;
	       {
		    E T1N, T1Q, T2w, T2x;
		    T1N = T1 - Te;
		    T1Q = T1O - T1P;
		    T1R = T1N - T1Q;
		    T2v = T1N + T1Q;
		    {
			 E T1W, T21, T3r, T3s;
			 T1W = T1U - T1V;
			 T21 = T1X + T20;
			 T22 = KP707106781 * (T1W - T21);
			 T3q = KP707106781 * (T1W + T21);
			 T3r = T3d - T3c;
			 T3s = Tq - Tz;
			 T3t = T3r - T3s;
			 T3z = T3s + T3r;
		    }
		    T2w = T1V + T1U;
		    T2x = T1X - T20;
		    T2y = KP707106781 * (T2w + T2x);
		    T3y = KP707106781 * (T2x - T2w);
		    {
			 E T28, T2A, T2d, T2B, T27, T2c;
			 T27 = T1h - T1m;
			 T28 = T26 + T27;
			 T2A = T26 - T27;
			 T2c = T2a - T2b;
			 T2d = T29 - T2c;
			 T2B = T29 + T2c;
			 T2e = FMA(KP923879532, T28, KP382683432 * T2d);
			 T2I = FNMS(KP382683432, T2B, KP923879532 * T2A);
			 T2s = FNMS(KP923879532, T2d, KP382683432 * T28);
			 T2C = FMA(KP382683432, T2A, KP923879532 * T2B);
		    }
		    {
			 E T2j, T2D, T2o, T2E;
			 {
			      E T2f, T2i, T2m, T2n;
			      T2f = T1r - T1A;
			      T2i = T2g - T2h;
			      T2j = T2f - T2i;
			      T2D = T2f + T2i;
			      T2m = T2k - T2l;
			      T2n = T1E - T1J;
			      T2o = T2m + T2n;
			      T2E = T2m - T2n;
			 }
			 T2p = FNMS(KP923879532, T2o, KP382683432 * T2j);
			 T2J = FMA(KP923879532, T2E, KP382683432 * T2D);
			 T2t = FMA(KP382683432, T2o, KP923879532 * T2j);
			 T2F = FNMS(KP382683432, T2E, KP923879532 * T2D);
		    }
	       }
	       {
		    E T23, T2q, T3x, T3A;
		    T23 = T1R + T22;
		    T2q = T2e + T2p;
		    iio[-WS(ios, 11)] = T23 - T2q;
		    rio[WS(ios, 3)] = T23 + T2q;
		    T3x = T2s + T2t;
		    T3A = T3y + T3z;
		    rio[WS(ios, 11)] = T3x - T3A;
		    iio[-WS(ios, 3)] = T3x + T3A;
	       }
	       {
		    E T2r, T2u, T3B, T3C;
		    T2r = T1R - T22;
		    T2u = T2s - T2t;
		    iio[-WS(ios, 15)] = T2r - T2u;
		    rio[WS(ios, 7)] = T2r + T2u;
		    T3B = T2p - T2e;
		    T3C = T3z - T3y;
		    rio[WS(ios, 15)] = T3B - T3C;
		    iio[-WS(ios, 7)] = T3B + T3C;
	       }
	       {
		    E T2z, T2G, T3p, T3u;
		    T2z = T2v + T2y;
		    T2G = T2C + T2F;
		    iio[-WS(ios, 9)] = T2z - T2G;
		    rio[WS(ios, 1)] = T2z + T2G;
		    T3p = T2I + T2J;
		    T3u = T3q + T3t;
		    rio[WS(ios, 9)] = T3p - T3u;
		    iio[-WS(ios, 1)] = T3p + T3u;
	       }
	       {
		    E T2H, T2K, T3v, T3w;
		    T2H = T2v - T2y;
		    T2K = T2I - T2J;
		    iio[-WS(ios, 13)] = T2H - T2K;
		    rio[WS(ios, 5)] = T2H + T2K;
		    T3v = T2F - T2C;
		    T3w = T3t - T3q;
		    rio[WS(ios, 13)] = T3v - T3w;
		    iio[-WS(ios, 5)] = T3v + T3w;
	       }
	  }
     }
     return W;
}

static const tw_instr twinstr[] = {
     {TW_COS, 0, 1},
     {TW_SIN, 0, 1},
     {TW_COS, 0, 3},
     {TW_SIN, 0, 3},
     {TW_COS, 0, 9},
     {TW_SIN, 0, 9},
     {TW_COS, 0, 15},
     {TW_SIN, 0, 15},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 16, "hf2_16", twinstr, {156, 68, 40, 0}, &GENUS, 0, 0, 0 };

void X(codelet_hf2_16) (planner *p) {
     X(khc2hc_dit_register) (p, hf2_16, &desc);
}
