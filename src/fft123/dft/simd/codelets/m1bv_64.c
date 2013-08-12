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
/* Generated on Sat Jul  5 21:41:06 EDT 2003 */

#include "codelet-dft.h"

/* Generated by: /homee/stevenj/cvs/fftw3.0.1/genfft/gen_notw_noinline_c -simd -compact -variables 4 -sign 1 -n 64 -name m1bv_64 -include n1b.h */

/*
 * This function contains 456 FP additions, 124 FP multiplications,
 * (or, 404 additions, 72 multiplications, 52 fused multiply/add),
 * 105 stack variables, and 128 memory accesses
 */
/*
 * Generator Id's : 
 * $Id: m1bv_64.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 * $Id: m1bv_64.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 * $Id: m1bv_64.c,v 1.1 2005/07/26 17:36:59 glass Exp $
 */

#include "n1b.h"

static void m1bv_64_0(const R *xi, R *xo, stride is, stride os, int ivs, int ovs)
{
     DVK(KP634393284, +0.634393284163645498215171613225493370675687095);
     DVK(KP773010453, +0.773010453362736960810906609758469800971041293);
     DVK(KP290284677, +0.290284677254462367636192375817395274691476278);
     DVK(KP956940335, +0.956940335732208864935797886980269969482849206);
     DVK(KP098017140, +0.098017140329560601994195563888641845861136673);
     DVK(KP995184726, +0.995184726672196886244836953109479921575474869);
     DVK(KP471396736, +0.471396736825997648556387625905254377657460319);
     DVK(KP881921264, +0.881921264348355029712756863660388349508442621);
     DVK(KP195090322, +0.195090322016128267848284868477022240927691618);
     DVK(KP980785280, +0.980785280403230449126182236134239036973933731);
     DVK(KP555570233, +0.555570233019602224742830813948532874374937191);
     DVK(KP831469612, +0.831469612302545237078788377617905756738560812);
     DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
     DVK(KP382683432, +0.382683432365089771728459984030398866761344562);
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     {
	  V T4p, T5u, Tb, T3A, T2q, T3v, T6G, T78, Tq, T3w, T6B, T79, T2l, T3B, T4w;
	  V T5r, TI, T2g, T6u, T74, T3q, T3D, T4E, T5o, TZ, T2h, T6x, T75, T3t, T3E;
	  V T4L, T5p, T23, T2N, T6m, T70, T6p, T71, T2c, T2O, T3i, T3Y, T5f, T5R, T5k;
	  V T5S, T3l, T3Z, T1s, T2K, T6f, T6X, T6i, T6Y, T1B, T2L, T3b, T3V, T4Y, T5O;
	  V T53, T5P, T3e, T3W;
	  {
	       V T3, T4n, T2p, T4o, T6, T5s, T9, T5t;
	       {
		    V T1, T2, T2n, T2o;
		    T1 = LD(&(xi[0]), ivs, &(xi[0]));
		    T2 = LD(&(xi[WS(is, 32)]), ivs, &(xi[0]));
		    T3 = VSUB(T1, T2);
		    T4n = VADD(T1, T2);
		    T2n = LD(&(xi[WS(is, 16)]), ivs, &(xi[0]));
		    T2o = LD(&(xi[WS(is, 48)]), ivs, &(xi[0]));
		    T2p = VSUB(T2n, T2o);
		    T4o = VADD(T2n, T2o);
	       }
	       {
		    V T4, T5, T7, T8;
		    T4 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
		    T5 = LD(&(xi[WS(is, 40)]), ivs, &(xi[0]));
		    T6 = VSUB(T4, T5);
		    T5s = VADD(T4, T5);
		    T7 = LD(&(xi[WS(is, 56)]), ivs, &(xi[0]));
		    T8 = LD(&(xi[WS(is, 24)]), ivs, &(xi[0]));
		    T9 = VSUB(T7, T8);
		    T5t = VADD(T7, T8);
	       }
	       T4p = VSUB(T4n, T4o);
	       T5u = VSUB(T5s, T5t);
	       {
		    V Ta, T2m, T6E, T6F;
		    Ta = VMUL(LDK(KP707106781), VADD(T6, T9));
		    Tb = VSUB(T3, Ta);
		    T3A = VADD(T3, Ta);
		    T2m = VMUL(LDK(KP707106781), VSUB(T6, T9));
		    T2q = VSUB(T2m, T2p);
		    T3v = VADD(T2p, T2m);
		    T6E = VADD(T4n, T4o);
		    T6F = VADD(T5s, T5t);
		    T6G = VSUB(T6E, T6F);
		    T78 = VADD(T6E, T6F);
	       }
	  }
	  {
	       V Te, T4q, To, T4t, Th, T4r, Tl, T4u;
	       {
		    V Tc, Td, Tm, Tn;
		    Tc = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    Td = LD(&(xi[WS(is, 36)]), ivs, &(xi[0]));
		    Te = VSUB(Tc, Td);
		    T4q = VADD(Tc, Td);
		    Tm = LD(&(xi[WS(is, 60)]), ivs, &(xi[0]));
		    Tn = LD(&(xi[WS(is, 28)]), ivs, &(xi[0]));
		    To = VSUB(Tm, Tn);
		    T4t = VADD(Tm, Tn);
	       }
	       {
		    V Tf, Tg, Tj, Tk;
		    Tf = LD(&(xi[WS(is, 20)]), ivs, &(xi[0]));
		    Tg = LD(&(xi[WS(is, 52)]), ivs, &(xi[0]));
		    Th = VSUB(Tf, Tg);
		    T4r = VADD(Tf, Tg);
		    Tj = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
		    Tk = LD(&(xi[WS(is, 44)]), ivs, &(xi[0]));
		    Tl = VSUB(Tj, Tk);
		    T4u = VADD(Tj, Tk);
	       }
	       {
		    V Ti, Tp, T6z, T6A;
		    Ti = VFMA(LDK(KP382683432), Te, VMUL(LDK(KP923879532), Th));
		    Tp = VFNMS(LDK(KP382683432), To, VMUL(LDK(KP923879532), Tl));
		    Tq = VSUB(Ti, Tp);
		    T3w = VADD(Ti, Tp);
		    T6z = VADD(T4q, T4r);
		    T6A = VADD(T4t, T4u);
		    T6B = VSUB(T6z, T6A);
		    T79 = VADD(T6z, T6A);
	       }
	       {
		    V T2j, T2k, T4s, T4v;
		    T2j = VFNMS(LDK(KP382683432), Th, VMUL(LDK(KP923879532), Te));
		    T2k = VFMA(LDK(KP923879532), To, VMUL(LDK(KP382683432), Tl));
		    T2l = VSUB(T2j, T2k);
		    T3B = VADD(T2j, T2k);
		    T4s = VSUB(T4q, T4r);
		    T4v = VSUB(T4t, T4u);
		    T4w = VMUL(LDK(KP707106781), VADD(T4s, T4v));
		    T5r = VMUL(LDK(KP707106781), VSUB(T4s, T4v));
	       }
	  }
	  {
	       V TB, T4z, TF, T4y, Ty, T4C, TG, T4B;
	       {
		    V Tz, TA, TD, TE;
		    Tz = LD(&(xi[WS(is, 18)]), ivs, &(xi[0]));
		    TA = LD(&(xi[WS(is, 50)]), ivs, &(xi[0]));
		    TB = VSUB(Tz, TA);
		    T4z = VADD(Tz, TA);
		    TD = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    TE = LD(&(xi[WS(is, 34)]), ivs, &(xi[0]));
		    TF = VSUB(TD, TE);
		    T4y = VADD(TD, TE);
		    {
			 V Ts, Tt, Tu, Tv, Tw, Tx;
			 Ts = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
			 Tt = LD(&(xi[WS(is, 42)]), ivs, &(xi[0]));
			 Tu = VSUB(Ts, Tt);
			 Tv = LD(&(xi[WS(is, 58)]), ivs, &(xi[0]));
			 Tw = LD(&(xi[WS(is, 26)]), ivs, &(xi[0]));
			 Tx = VSUB(Tv, Tw);
			 Ty = VMUL(LDK(KP707106781), VSUB(Tu, Tx));
			 T4C = VADD(Tv, Tw);
			 TG = VMUL(LDK(KP707106781), VADD(Tu, Tx));
			 T4B = VADD(Ts, Tt);
		    }
	       }
	       {
		    V TC, TH, T6s, T6t;
		    TC = VSUB(Ty, TB);
		    TH = VSUB(TF, TG);
		    TI = VFMA(LDK(KP831469612), TC, VMUL(LDK(KP555570233), TH));
		    T2g = VFNMS(LDK(KP555570233), TC, VMUL(LDK(KP831469612), TH));
		    T6s = VADD(T4y, T4z);
		    T6t = VADD(T4B, T4C);
		    T6u = VSUB(T6s, T6t);
		    T74 = VADD(T6s, T6t);
	       }
	       {
		    V T3o, T3p, T4A, T4D;
		    T3o = VADD(TB, Ty);
		    T3p = VADD(TF, TG);
		    T3q = VFMA(LDK(KP980785280), T3o, VMUL(LDK(KP195090322), T3p));
		    T3D = VFNMS(LDK(KP195090322), T3o, VMUL(LDK(KP980785280), T3p));
		    T4A = VSUB(T4y, T4z);
		    T4D = VSUB(T4B, T4C);
		    T4E = VFMA(LDK(KP382683432), T4A, VMUL(LDK(KP923879532), T4D));
		    T5o = VFNMS(LDK(KP382683432), T4D, VMUL(LDK(KP923879532), T4A));
	       }
	  }
	  {
	       V TS, T4J, TW, T4I, TP, T4G, TX, T4F;
	       {
		    V TQ, TR, TU, TV;
		    TQ = LD(&(xi[WS(is, 14)]), ivs, &(xi[0]));
		    TR = LD(&(xi[WS(is, 46)]), ivs, &(xi[0]));
		    TS = VSUB(TQ, TR);
		    T4J = VADD(TQ, TR);
		    TU = LD(&(xi[WS(is, 62)]), ivs, &(xi[0]));
		    TV = LD(&(xi[WS(is, 30)]), ivs, &(xi[0]));
		    TW = VSUB(TU, TV);
		    T4I = VADD(TU, TV);
		    {
			 V TJ, TK, TL, TM, TN, TO;
			 TJ = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
			 TK = LD(&(xi[WS(is, 38)]), ivs, &(xi[0]));
			 TL = VSUB(TJ, TK);
			 TM = LD(&(xi[WS(is, 54)]), ivs, &(xi[0]));
			 TN = LD(&(xi[WS(is, 22)]), ivs, &(xi[0]));
			 TO = VSUB(TM, TN);
			 TP = VMUL(LDK(KP707106781), VSUB(TL, TO));
			 T4G = VADD(TM, TN);
			 TX = VMUL(LDK(KP707106781), VADD(TL, TO));
			 T4F = VADD(TJ, TK);
		    }
	       }
	       {
		    V TT, TY, T6v, T6w;
		    TT = VSUB(TP, TS);
		    TY = VSUB(TW, TX);
		    TZ = VFNMS(LDK(KP555570233), TY, VMUL(LDK(KP831469612), TT));
		    T2h = VFMA(LDK(KP555570233), TT, VMUL(LDK(KP831469612), TY));
		    T6v = VADD(T4I, T4J);
		    T6w = VADD(T4F, T4G);
		    T6x = VSUB(T6v, T6w);
		    T75 = VADD(T6v, T6w);
	       }
	       {
		    V T3r, T3s, T4H, T4K;
		    T3r = VADD(TS, TP);
		    T3s = VADD(TW, TX);
		    T3t = VFNMS(LDK(KP195090322), T3s, VMUL(LDK(KP980785280), T3r));
		    T3E = VFMA(LDK(KP195090322), T3r, VMUL(LDK(KP980785280), T3s));
		    T4H = VSUB(T4F, T4G);
		    T4K = VSUB(T4I, T4J);
		    T4L = VFNMS(LDK(KP382683432), T4K, VMUL(LDK(KP923879532), T4H));
		    T5p = VFMA(LDK(KP923879532), T4K, VMUL(LDK(KP382683432), T4H));
	       }
	  }
	  {
	       V T21, T5h, T26, T5g, T1Y, T5d, T27, T5c, T55, T56, T1J, T57, T29, T58, T59;
	       V T1Q, T5a, T2a;
	       {
		    V T1Z, T20, T24, T25;
		    T1Z = LD(&(xi[WS(is, 15)]), ivs, &(xi[WS(is, 1)]));
		    T20 = LD(&(xi[WS(is, 47)]), ivs, &(xi[WS(is, 1)]));
		    T21 = VSUB(T1Z, T20);
		    T5h = VADD(T1Z, T20);
		    T24 = LD(&(xi[WS(is, 63)]), ivs, &(xi[WS(is, 1)]));
		    T25 = LD(&(xi[WS(is, 31)]), ivs, &(xi[WS(is, 1)]));
		    T26 = VSUB(T24, T25);
		    T5g = VADD(T24, T25);
	       }
	       {
		    V T1S, T1T, T1U, T1V, T1W, T1X;
		    T1S = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
		    T1T = LD(&(xi[WS(is, 39)]), ivs, &(xi[WS(is, 1)]));
		    T1U = VSUB(T1S, T1T);
		    T1V = LD(&(xi[WS(is, 55)]), ivs, &(xi[WS(is, 1)]));
		    T1W = LD(&(xi[WS(is, 23)]), ivs, &(xi[WS(is, 1)]));
		    T1X = VSUB(T1V, T1W);
		    T1Y = VMUL(LDK(KP707106781), VSUB(T1U, T1X));
		    T5d = VADD(T1V, T1W);
		    T27 = VMUL(LDK(KP707106781), VADD(T1U, T1X));
		    T5c = VADD(T1S, T1T);
	       }
	       {
		    V T1F, T1I, T1M, T1P;
		    {
			 V T1D, T1E, T1G, T1H;
			 T1D = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
			 T1E = LD(&(xi[WS(is, 35)]), ivs, &(xi[WS(is, 1)]));
			 T1F = VSUB(T1D, T1E);
			 T55 = VADD(T1D, T1E);
			 T1G = LD(&(xi[WS(is, 19)]), ivs, &(xi[WS(is, 1)]));
			 T1H = LD(&(xi[WS(is, 51)]), ivs, &(xi[WS(is, 1)]));
			 T1I = VSUB(T1G, T1H);
			 T56 = VADD(T1G, T1H);
		    }
		    T1J = VFNMS(LDK(KP382683432), T1I, VMUL(LDK(KP923879532), T1F));
		    T57 = VSUB(T55, T56);
		    T29 = VFMA(LDK(KP382683432), T1F, VMUL(LDK(KP923879532), T1I));
		    {
			 V T1K, T1L, T1N, T1O;
			 T1K = LD(&(xi[WS(is, 59)]), ivs, &(xi[WS(is, 1)]));
			 T1L = LD(&(xi[WS(is, 27)]), ivs, &(xi[WS(is, 1)]));
			 T1M = VSUB(T1K, T1L);
			 T58 = VADD(T1K, T1L);
			 T1N = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
			 T1O = LD(&(xi[WS(is, 43)]), ivs, &(xi[WS(is, 1)]));
			 T1P = VSUB(T1N, T1O);
			 T59 = VADD(T1N, T1O);
		    }
		    T1Q = VFMA(LDK(KP923879532), T1M, VMUL(LDK(KP382683432), T1P));
		    T5a = VSUB(T58, T59);
		    T2a = VFNMS(LDK(KP382683432), T1M, VMUL(LDK(KP923879532), T1P));
	       }
	       {
		    V T1R, T22, T6k, T6l;
		    T1R = VSUB(T1J, T1Q);
		    T22 = VSUB(T1Y, T21);
		    T23 = VSUB(T1R, T22);
		    T2N = VADD(T22, T1R);
		    T6k = VADD(T5g, T5h);
		    T6l = VADD(T5c, T5d);
		    T6m = VSUB(T6k, T6l);
		    T70 = VADD(T6k, T6l);
	       }
	       {
		    V T6n, T6o, T28, T2b;
		    T6n = VADD(T55, T56);
		    T6o = VADD(T58, T59);
		    T6p = VSUB(T6n, T6o);
		    T71 = VADD(T6n, T6o);
		    T28 = VSUB(T26, T27);
		    T2b = VSUB(T29, T2a);
		    T2c = VSUB(T28, T2b);
		    T2O = VADD(T28, T2b);
	       }
	       {
		    V T3g, T3h, T5b, T5e;
		    T3g = VADD(T26, T27);
		    T3h = VADD(T1J, T1Q);
		    T3i = VADD(T3g, T3h);
		    T3Y = VSUB(T3g, T3h);
		    T5b = VMUL(LDK(KP707106781), VSUB(T57, T5a));
		    T5e = VSUB(T5c, T5d);
		    T5f = VSUB(T5b, T5e);
		    T5R = VADD(T5e, T5b);
	       }
	       {
		    V T5i, T5j, T3j, T3k;
		    T5i = VSUB(T5g, T5h);
		    T5j = VMUL(LDK(KP707106781), VADD(T57, T5a));
		    T5k = VSUB(T5i, T5j);
		    T5S = VADD(T5i, T5j);
		    T3j = VADD(T21, T1Y);
		    T3k = VADD(T29, T2a);
		    T3l = VADD(T3j, T3k);
		    T3Z = VSUB(T3k, T3j);
	       }
	  }
	  {
	       V T1q, T50, T1v, T4Z, T1n, T4W, T1w, T4V, T4O, T4P, T18, T4Q, T1y, T4R, T4S;
	       V T1f, T4T, T1z;
	       {
		    V T1o, T1p, T1t, T1u;
		    T1o = LD(&(xi[WS(is, 17)]), ivs, &(xi[WS(is, 1)]));
		    T1p = LD(&(xi[WS(is, 49)]), ivs, &(xi[WS(is, 1)]));
		    T1q = VSUB(T1o, T1p);
		    T50 = VADD(T1o, T1p);
		    T1t = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    T1u = LD(&(xi[WS(is, 33)]), ivs, &(xi[WS(is, 1)]));
		    T1v = VSUB(T1t, T1u);
		    T4Z = VADD(T1t, T1u);
	       }
	       {
		    V T1h, T1i, T1j, T1k, T1l, T1m;
		    T1h = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
		    T1i = LD(&(xi[WS(is, 41)]), ivs, &(xi[WS(is, 1)]));
		    T1j = VSUB(T1h, T1i);
		    T1k = LD(&(xi[WS(is, 57)]), ivs, &(xi[WS(is, 1)]));
		    T1l = LD(&(xi[WS(is, 25)]), ivs, &(xi[WS(is, 1)]));
		    T1m = VSUB(T1k, T1l);
		    T1n = VMUL(LDK(KP707106781), VSUB(T1j, T1m));
		    T4W = VADD(T1k, T1l);
		    T1w = VMUL(LDK(KP707106781), VADD(T1j, T1m));
		    T4V = VADD(T1h, T1i);
	       }
	       {
		    V T14, T17, T1b, T1e;
		    {
			 V T12, T13, T15, T16;
			 T12 = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
			 T13 = LD(&(xi[WS(is, 37)]), ivs, &(xi[WS(is, 1)]));
			 T14 = VSUB(T12, T13);
			 T4O = VADD(T12, T13);
			 T15 = LD(&(xi[WS(is, 21)]), ivs, &(xi[WS(is, 1)]));
			 T16 = LD(&(xi[WS(is, 53)]), ivs, &(xi[WS(is, 1)]));
			 T17 = VSUB(T15, T16);
			 T4P = VADD(T15, T16);
		    }
		    T18 = VFNMS(LDK(KP382683432), T17, VMUL(LDK(KP923879532), T14));
		    T4Q = VSUB(T4O, T4P);
		    T1y = VFMA(LDK(KP382683432), T14, VMUL(LDK(KP923879532), T17));
		    {
			 V T19, T1a, T1c, T1d;
			 T19 = LD(&(xi[WS(is, 61)]), ivs, &(xi[WS(is, 1)]));
			 T1a = LD(&(xi[WS(is, 29)]), ivs, &(xi[WS(is, 1)]));
			 T1b = VSUB(T19, T1a);
			 T4R = VADD(T19, T1a);
			 T1c = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
			 T1d = LD(&(xi[WS(is, 45)]), ivs, &(xi[WS(is, 1)]));
			 T1e = VSUB(T1c, T1d);
			 T4S = VADD(T1c, T1d);
		    }
		    T1f = VFMA(LDK(KP923879532), T1b, VMUL(LDK(KP382683432), T1e));
		    T4T = VSUB(T4R, T4S);
		    T1z = VFNMS(LDK(KP382683432), T1b, VMUL(LDK(KP923879532), T1e));
	       }
	       {
		    V T1g, T1r, T6d, T6e;
		    T1g = VSUB(T18, T1f);
		    T1r = VSUB(T1n, T1q);
		    T1s = VSUB(T1g, T1r);
		    T2K = VADD(T1r, T1g);
		    T6d = VADD(T4Z, T50);
		    T6e = VADD(T4V, T4W);
		    T6f = VSUB(T6d, T6e);
		    T6X = VADD(T6d, T6e);
	       }
	       {
		    V T6g, T6h, T1x, T1A;
		    T6g = VADD(T4O, T4P);
		    T6h = VADD(T4R, T4S);
		    T6i = VSUB(T6g, T6h);
		    T6Y = VADD(T6g, T6h);
		    T1x = VSUB(T1v, T1w);
		    T1A = VSUB(T1y, T1z);
		    T1B = VSUB(T1x, T1A);
		    T2L = VADD(T1x, T1A);
	       }
	       {
		    V T39, T3a, T4U, T4X;
		    T39 = VADD(T1v, T1w);
		    T3a = VADD(T18, T1f);
		    T3b = VADD(T39, T3a);
		    T3V = VSUB(T39, T3a);
		    T4U = VMUL(LDK(KP707106781), VSUB(T4Q, T4T));
		    T4X = VSUB(T4V, T4W);
		    T4Y = VSUB(T4U, T4X);
		    T5O = VADD(T4X, T4U);
	       }
	       {
		    V T51, T52, T3c, T3d;
		    T51 = VSUB(T4Z, T50);
		    T52 = VMUL(LDK(KP707106781), VADD(T4Q, T4T));
		    T53 = VSUB(T51, T52);
		    T5P = VADD(T51, T52);
		    T3c = VADD(T1q, T1n);
		    T3d = VADD(T1y, T1z);
		    T3e = VADD(T3c, T3d);
		    T3W = VSUB(T3d, T3c);
	       }
	  }
	  {
	       V T7h, T7l, T7k, T7m;
	       {
		    V T7f, T7g, T7i, T7j;
		    T7f = VADD(T78, T79);
		    T7g = VADD(T74, T75);
		    T7h = VSUB(T7f, T7g);
		    T7l = VADD(T7f, T7g);
		    T7i = VADD(T6X, T6Y);
		    T7j = VADD(T70, T71);
		    T7k = VBYI(VSUB(T7i, T7j));
		    T7m = VADD(T7i, T7j);
	       }
	       ST(&(xo[WS(os, 48)]), VSUB(T7h, T7k), ovs, &(xo[0]));
	       ST(&(xo[0]), VADD(T7l, T7m), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 16)]), VADD(T7h, T7k), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 32)]), VSUB(T7l, T7m), ovs, &(xo[0]));
	  }
	  {
	       V T76, T7a, T73, T7b, T6Z, T72;
	       T76 = VSUB(T74, T75);
	       T7a = VSUB(T78, T79);
	       T6Z = VSUB(T6X, T6Y);
	       T72 = VSUB(T70, T71);
	       T73 = VMUL(LDK(KP707106781), VSUB(T6Z, T72));
	       T7b = VMUL(LDK(KP707106781), VADD(T6Z, T72));
	       {
		    V T77, T7c, T7d, T7e;
		    T77 = VBYI(VSUB(T73, T76));
		    T7c = VSUB(T7a, T7b);
		    ST(&(xo[WS(os, 24)]), VADD(T77, T7c), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 40)]), VSUB(T7c, T77), ovs, &(xo[0]));
		    T7d = VBYI(VADD(T76, T73));
		    T7e = VADD(T7a, T7b);
		    ST(&(xo[WS(os, 8)]), VADD(T7d, T7e), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 56)]), VSUB(T7e, T7d), ovs, &(xo[0]));
	       }
	  }
	  {
	       V T6C, T6S, T6I, T6P, T6r, T6Q, T6L, T6T, T6y, T6H;
	       T6y = VMUL(LDK(KP707106781), VSUB(T6u, T6x));
	       T6C = VSUB(T6y, T6B);
	       T6S = VADD(T6B, T6y);
	       T6H = VMUL(LDK(KP707106781), VADD(T6u, T6x));
	       T6I = VSUB(T6G, T6H);
	       T6P = VADD(T6G, T6H);
	       {
		    V T6j, T6q, T6J, T6K;
		    T6j = VFNMS(LDK(KP382683432), T6i, VMUL(LDK(KP923879532), T6f));
		    T6q = VFMA(LDK(KP923879532), T6m, VMUL(LDK(KP382683432), T6p));
		    T6r = VSUB(T6j, T6q);
		    T6Q = VADD(T6j, T6q);
		    T6J = VFMA(LDK(KP382683432), T6f, VMUL(LDK(KP923879532), T6i));
		    T6K = VFNMS(LDK(KP382683432), T6m, VMUL(LDK(KP923879532), T6p));
		    T6L = VSUB(T6J, T6K);
		    T6T = VADD(T6J, T6K);
	       }
	       {
		    V T6D, T6M, T6V, T6W;
		    T6D = VBYI(VSUB(T6r, T6C));
		    T6M = VSUB(T6I, T6L);
		    ST(&(xo[WS(os, 20)]), VADD(T6D, T6M), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 44)]), VSUB(T6M, T6D), ovs, &(xo[0]));
		    T6V = VSUB(T6P, T6Q);
		    T6W = VBYI(VSUB(T6T, T6S));
		    ST(&(xo[WS(os, 36)]), VSUB(T6V, T6W), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 28)]), VADD(T6V, T6W), ovs, &(xo[0]));
	       }
	       {
		    V T6N, T6O, T6R, T6U;
		    T6N = VBYI(VADD(T6C, T6r));
		    T6O = VADD(T6I, T6L);
		    ST(&(xo[WS(os, 12)]), VADD(T6N, T6O), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 52)]), VSUB(T6O, T6N), ovs, &(xo[0]));
		    T6R = VADD(T6P, T6Q);
		    T6U = VBYI(VADD(T6S, T6T));
		    ST(&(xo[WS(os, 60)]), VSUB(T6R, T6U), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 4)]), VADD(T6R, T6U), ovs, &(xo[0]));
	       }
	  }
	  {
	       V T5N, T68, T61, T69, T5U, T65, T5Y, T66;
	       {
		    V T5L, T5M, T5Z, T60;
		    T5L = VADD(T4p, T4w);
		    T5M = VADD(T5o, T5p);
		    T5N = VSUB(T5L, T5M);
		    T68 = VADD(T5L, T5M);
		    T5Z = VFNMS(LDK(KP195090322), T5O, VMUL(LDK(KP980785280), T5P));
		    T60 = VFMA(LDK(KP195090322), T5R, VMUL(LDK(KP980785280), T5S));
		    T61 = VSUB(T5Z, T60);
		    T69 = VADD(T5Z, T60);
	       }
	       {
		    V T5Q, T5T, T5W, T5X;
		    T5Q = VFMA(LDK(KP980785280), T5O, VMUL(LDK(KP195090322), T5P));
		    T5T = VFNMS(LDK(KP195090322), T5S, VMUL(LDK(KP980785280), T5R));
		    T5U = VSUB(T5Q, T5T);
		    T65 = VADD(T5Q, T5T);
		    T5W = VADD(T4E, T4L);
		    T5X = VADD(T5u, T5r);
		    T5Y = VSUB(T5W, T5X);
		    T66 = VADD(T5X, T5W);
	       }
	       {
		    V T5V, T62, T6b, T6c;
		    T5V = VADD(T5N, T5U);
		    T62 = VBYI(VADD(T5Y, T61));
		    ST(&(xo[WS(os, 50)]), VSUB(T5V, T62), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 14)]), VADD(T5V, T62), ovs, &(xo[0]));
		    T6b = VBYI(VADD(T66, T65));
		    T6c = VADD(T68, T69);
		    ST(&(xo[WS(os, 2)]), VADD(T6b, T6c), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 62)]), VSUB(T6c, T6b), ovs, &(xo[0]));
	       }
	       {
		    V T63, T64, T67, T6a;
		    T63 = VSUB(T5N, T5U);
		    T64 = VBYI(VSUB(T61, T5Y));
		    ST(&(xo[WS(os, 46)]), VSUB(T63, T64), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 18)]), VADD(T63, T64), ovs, &(xo[0]));
		    T67 = VBYI(VSUB(T65, T66));
		    T6a = VSUB(T68, T69);
		    ST(&(xo[WS(os, 30)]), VADD(T67, T6a), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 34)]), VSUB(T6a, T67), ovs, &(xo[0]));
	       }
	  }
	  {
	       V T11, T2C, T2v, T2D, T2e, T2z, T2s, T2A;
	       {
		    V Tr, T10, T2t, T2u;
		    Tr = VSUB(Tb, Tq);
		    T10 = VSUB(TI, TZ);
		    T11 = VSUB(Tr, T10);
		    T2C = VADD(Tr, T10);
		    T2t = VFNMS(LDK(KP471396736), T1s, VMUL(LDK(KP881921264), T1B));
		    T2u = VFMA(LDK(KP471396736), T23, VMUL(LDK(KP881921264), T2c));
		    T2v = VSUB(T2t, T2u);
		    T2D = VADD(T2t, T2u);
	       }
	       {
		    V T1C, T2d, T2i, T2r;
		    T1C = VFMA(LDK(KP881921264), T1s, VMUL(LDK(KP471396736), T1B));
		    T2d = VFNMS(LDK(KP471396736), T2c, VMUL(LDK(KP881921264), T23));
		    T2e = VSUB(T1C, T2d);
		    T2z = VADD(T1C, T2d);
		    T2i = VSUB(T2g, T2h);
		    T2r = VSUB(T2l, T2q);
		    T2s = VSUB(T2i, T2r);
		    T2A = VADD(T2r, T2i);
	       }
	       {
		    V T2f, T2w, T2F, T2G;
		    T2f = VADD(T11, T2e);
		    T2w = VBYI(VADD(T2s, T2v));
		    ST(&(xo[WS(os, 53)]), VSUB(T2f, T2w), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 11)]), VADD(T2f, T2w), ovs, &(xo[WS(os, 1)]));
		    T2F = VBYI(VADD(T2A, T2z));
		    T2G = VADD(T2C, T2D);
		    ST(&(xo[WS(os, 5)]), VADD(T2F, T2G), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 59)]), VSUB(T2G, T2F), ovs, &(xo[WS(os, 1)]));
	       }
	       {
		    V T2x, T2y, T2B, T2E;
		    T2x = VSUB(T11, T2e);
		    T2y = VBYI(VSUB(T2v, T2s));
		    ST(&(xo[WS(os, 43)]), VSUB(T2x, T2y), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 21)]), VADD(T2x, T2y), ovs, &(xo[WS(os, 1)]));
		    T2B = VBYI(VSUB(T2z, T2A));
		    T2E = VSUB(T2C, T2D);
		    ST(&(xo[WS(os, 27)]), VADD(T2B, T2E), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 37)]), VSUB(T2E, T2B), ovs, &(xo[WS(os, 1)]));
	       }
	  }
	  {
	       V T3n, T3O, T3J, T3R, T3y, T3Q, T3G, T3N;
	       {
		    V T3f, T3m, T3H, T3I;
		    T3f = VFNMS(LDK(KP098017140), T3e, VMUL(LDK(KP995184726), T3b));
		    T3m = VFMA(LDK(KP995184726), T3i, VMUL(LDK(KP098017140), T3l));
		    T3n = VSUB(T3f, T3m);
		    T3O = VADD(T3f, T3m);
		    T3H = VFMA(LDK(KP098017140), T3b, VMUL(LDK(KP995184726), T3e));
		    T3I = VFNMS(LDK(KP098017140), T3i, VMUL(LDK(KP995184726), T3l));
		    T3J = VSUB(T3H, T3I);
		    T3R = VADD(T3H, T3I);
	       }
	       {
		    V T3u, T3x, T3C, T3F;
		    T3u = VADD(T3q, T3t);
		    T3x = VADD(T3v, T3w);
		    T3y = VSUB(T3u, T3x);
		    T3Q = VADD(T3x, T3u);
		    T3C = VADD(T3A, T3B);
		    T3F = VADD(T3D, T3E);
		    T3G = VSUB(T3C, T3F);
		    T3N = VADD(T3C, T3F);
	       }
	       {
		    V T3z, T3K, T3T, T3U;
		    T3z = VBYI(VSUB(T3n, T3y));
		    T3K = VSUB(T3G, T3J);
		    ST(&(xo[WS(os, 17)]), VADD(T3z, T3K), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 47)]), VSUB(T3K, T3z), ovs, &(xo[WS(os, 1)]));
		    T3T = VSUB(T3N, T3O);
		    T3U = VBYI(VSUB(T3R, T3Q));
		    ST(&(xo[WS(os, 33)]), VSUB(T3T, T3U), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 31)]), VADD(T3T, T3U), ovs, &(xo[WS(os, 1)]));
	       }
	       {
		    V T3L, T3M, T3P, T3S;
		    T3L = VBYI(VADD(T3y, T3n));
		    T3M = VADD(T3G, T3J);
		    ST(&(xo[WS(os, 15)]), VADD(T3L, T3M), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 49)]), VSUB(T3M, T3L), ovs, &(xo[WS(os, 1)]));
		    T3P = VADD(T3N, T3O);
		    T3S = VBYI(VADD(T3Q, T3R));
		    ST(&(xo[WS(os, 63)]), VSUB(T3P, T3S), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 1)]), VADD(T3P, T3S), ovs, &(xo[WS(os, 1)]));
	       }
	  }
	  {
	       V T4N, T5G, T5z, T5H, T5m, T5D, T5w, T5E;
	       {
		    V T4x, T4M, T5x, T5y;
		    T4x = VSUB(T4p, T4w);
		    T4M = VSUB(T4E, T4L);
		    T4N = VSUB(T4x, T4M);
		    T5G = VADD(T4x, T4M);
		    T5x = VFNMS(LDK(KP555570233), T4Y, VMUL(LDK(KP831469612), T53));
		    T5y = VFMA(LDK(KP555570233), T5f, VMUL(LDK(KP831469612), T5k));
		    T5z = VSUB(T5x, T5y);
		    T5H = VADD(T5x, T5y);
	       }
	       {
		    V T54, T5l, T5q, T5v;
		    T54 = VFMA(LDK(KP831469612), T4Y, VMUL(LDK(KP555570233), T53));
		    T5l = VFNMS(LDK(KP555570233), T5k, VMUL(LDK(KP831469612), T5f));
		    T5m = VSUB(T54, T5l);
		    T5D = VADD(T54, T5l);
		    T5q = VSUB(T5o, T5p);
		    T5v = VSUB(T5r, T5u);
		    T5w = VSUB(T5q, T5v);
		    T5E = VADD(T5v, T5q);
	       }
	       {
		    V T5n, T5A, T5J, T5K;
		    T5n = VADD(T4N, T5m);
		    T5A = VBYI(VADD(T5w, T5z));
		    ST(&(xo[WS(os, 54)]), VSUB(T5n, T5A), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 10)]), VADD(T5n, T5A), ovs, &(xo[0]));
		    T5J = VBYI(VADD(T5E, T5D));
		    T5K = VADD(T5G, T5H);
		    ST(&(xo[WS(os, 6)]), VADD(T5J, T5K), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 58)]), VSUB(T5K, T5J), ovs, &(xo[0]));
	       }
	       {
		    V T5B, T5C, T5F, T5I;
		    T5B = VSUB(T4N, T5m);
		    T5C = VBYI(VSUB(T5z, T5w));
		    ST(&(xo[WS(os, 42)]), VSUB(T5B, T5C), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 22)]), VADD(T5B, T5C), ovs, &(xo[0]));
		    T5F = VBYI(VSUB(T5D, T5E));
		    T5I = VSUB(T5G, T5H);
		    ST(&(xo[WS(os, 26)]), VADD(T5F, T5I), ovs, &(xo[0]));
		    ST(&(xo[WS(os, 38)]), VSUB(T5I, T5F), ovs, &(xo[0]));
	       }
	  }
	  {
	       V T2J, T34, T2X, T35, T2Q, T31, T2U, T32;
	       {
		    V T2H, T2I, T2V, T2W;
		    T2H = VADD(Tb, Tq);
		    T2I = VADD(T2g, T2h);
		    T2J = VSUB(T2H, T2I);
		    T34 = VADD(T2H, T2I);
		    T2V = VFNMS(LDK(KP290284677), T2K, VMUL(LDK(KP956940335), T2L));
		    T2W = VFMA(LDK(KP290284677), T2N, VMUL(LDK(KP956940335), T2O));
		    T2X = VSUB(T2V, T2W);
		    T35 = VADD(T2V, T2W);
	       }
	       {
		    V T2M, T2P, T2S, T2T;
		    T2M = VFMA(LDK(KP956940335), T2K, VMUL(LDK(KP290284677), T2L));
		    T2P = VFNMS(LDK(KP290284677), T2O, VMUL(LDK(KP956940335), T2N));
		    T2Q = VSUB(T2M, T2P);
		    T31 = VADD(T2M, T2P);
		    T2S = VADD(TI, TZ);
		    T2T = VADD(T2q, T2l);
		    T2U = VSUB(T2S, T2T);
		    T32 = VADD(T2T, T2S);
	       }
	       {
		    V T2R, T2Y, T37, T38;
		    T2R = VADD(T2J, T2Q);
		    T2Y = VBYI(VADD(T2U, T2X));
		    ST(&(xo[WS(os, 51)]), VSUB(T2R, T2Y), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 13)]), VADD(T2R, T2Y), ovs, &(xo[WS(os, 1)]));
		    T37 = VBYI(VADD(T32, T31));
		    T38 = VADD(T34, T35);
		    ST(&(xo[WS(os, 3)]), VADD(T37, T38), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 61)]), VSUB(T38, T37), ovs, &(xo[WS(os, 1)]));
	       }
	       {
		    V T2Z, T30, T33, T36;
		    T2Z = VSUB(T2J, T2Q);
		    T30 = VBYI(VSUB(T2X, T2U));
		    ST(&(xo[WS(os, 45)]), VSUB(T2Z, T30), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 19)]), VADD(T2Z, T30), ovs, &(xo[WS(os, 1)]));
		    T33 = VBYI(VSUB(T31, T32));
		    T36 = VSUB(T34, T35);
		    ST(&(xo[WS(os, 29)]), VADD(T33, T36), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 35)]), VSUB(T36, T33), ovs, &(xo[WS(os, 1)]));
	       }
	  }
	  {
	       V T41, T4g, T4b, T4j, T44, T4i, T48, T4f;
	       {
		    V T3X, T40, T49, T4a;
		    T3X = VFNMS(LDK(KP634393284), T3W, VMUL(LDK(KP773010453), T3V));
		    T40 = VFMA(LDK(KP773010453), T3Y, VMUL(LDK(KP634393284), T3Z));
		    T41 = VSUB(T3X, T40);
		    T4g = VADD(T3X, T40);
		    T49 = VFMA(LDK(KP634393284), T3V, VMUL(LDK(KP773010453), T3W));
		    T4a = VFNMS(LDK(KP634393284), T3Y, VMUL(LDK(KP773010453), T3Z));
		    T4b = VSUB(T49, T4a);
		    T4j = VADD(T49, T4a);
	       }
	       {
		    V T42, T43, T46, T47;
		    T42 = VSUB(T3D, T3E);
		    T43 = VSUB(T3w, T3v);
		    T44 = VSUB(T42, T43);
		    T4i = VADD(T43, T42);
		    T46 = VSUB(T3A, T3B);
		    T47 = VSUB(T3q, T3t);
		    T48 = VSUB(T46, T47);
		    T4f = VADD(T46, T47);
	       }
	       {
		    V T45, T4c, T4l, T4m;
		    T45 = VBYI(VSUB(T41, T44));
		    T4c = VSUB(T48, T4b);
		    ST(&(xo[WS(os, 23)]), VADD(T45, T4c), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 41)]), VSUB(T4c, T45), ovs, &(xo[WS(os, 1)]));
		    T4l = VSUB(T4f, T4g);
		    T4m = VBYI(VSUB(T4j, T4i));
		    ST(&(xo[WS(os, 39)]), VSUB(T4l, T4m), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 25)]), VADD(T4l, T4m), ovs, &(xo[WS(os, 1)]));
	       }
	       {
		    V T4d, T4e, T4h, T4k;
		    T4d = VBYI(VADD(T44, T41));
		    T4e = VADD(T48, T4b);
		    ST(&(xo[WS(os, 9)]), VADD(T4d, T4e), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 55)]), VSUB(T4e, T4d), ovs, &(xo[WS(os, 1)]));
		    T4h = VADD(T4f, T4g);
		    T4k = VBYI(VADD(T4i, T4j));
		    ST(&(xo[WS(os, 57)]), VSUB(T4h, T4k), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 7)]), VADD(T4h, T4k), ovs, &(xo[WS(os, 1)]));
	       }
	  }
     }
}

static void m1bv_64(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, int v, int ivs, int ovs)
{
     int i;
     BEGIN_SIMD();
     for (i = 0; i < v; i += VL) {
	  m1bv_64_0(ii, io, is, os, ivs, ovs);
	  ii += VL * ivs;
	  io += VL * ovs;
     }
     END_SIMD();
}

static const kdft_desc desc = { 64, "m1bv_64", {404, 72, 52, 0}, &GENUS, 0, 0, 0, 0 };
void X(codelet_m1bv_64) (planner *p) {
     X(kdft_register) (p, m1bv_64, &desc);
}
