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

/* $Id: hc2hc_dif.c,v 1.2 2006/06/14 12:26:11 glass Exp $ */

/* decimation in frequency Cooley-Tukey */
#include "rdft.h"
#include "hc2hc.h"

static void apply(const plan *ego_, R *I, R *O)
{
     const plan_hc2hc *ego = (const plan_hc2hc *) ego_;
     R *I0 = I;

     {
          plan_rdft *cld0 = (plan_rdft *) ego->cld0;
          plan_rdft *cldm = (plan_rdft *) ego->cldm;
          int i, r = ego->r, m = ego->m, vl = ego->vl;
          int is = ego->is, ivs = ego->ivs;
	  
          for (i = 0; i < vl; ++i, I += ivs) {
	       cld0->apply((plan *) cld0, I, I);
               ego->k(I + is, I + (r * m - 1) * is, ego->W, ego->ios, m, is);
	       cldm->apply((plan *) cldm, I + is*(m/2), I + is*(m/2));
	  }
     }

     /* two-dimensional r x vl sub-transform: */
     {
	  plan_rdft *cld = (plan_rdft *) ego->cld;
	  cld->apply((plan *) cld, I0, O);
     }
}

static int applicable0(const solver_hc2hc *ego, const problem *p_,
		       const planner *plnr)
{
     if (X(rdft_hc2hc_applicable)(ego, p_)) {
	  int ivs, ovs;
	  int vl;
          const hc2hc_desc *e = ego->desc;
          const problem_rdft *p = (const problem_rdft *) p_;
          iodim *d = p->sz->dims;
	  int m = d[0].n / e->radix;
	  X(tensor_tornk1)(p->vecsz, &vl, &ivs, &ovs);
          return ( 
		     (p->I == p->O || DESTROY_INPUTP(plnr))
		  && (e->genus->okp(e, p->I + d[0].is,
				    p->I + (e->radix * m - 1) * d[0].is, 
				    (int)m * d[0].is, 0, m, d[0].is))
		  && (e->genus->okp(e, p->I + ivs + d[0].is,
				    p->I + ivs + (e->radix * m - 1) * d[0].is, 
				    (int)m * d[0].is, 0, m, d[0].is))
	       );
     }
     return 0;
}

static int applicable(const solver_hc2hc *ego, const problem *p_,
		      const planner *plnr)
{
     const problem_rdft *p;

     if (!applicable0(ego, p_, plnr)) return 0;

     p = (const problem_rdft *) p_;

     /* emulate fftw2 behavior */
     if (NO_VRECURSEP(plnr) && (p->vecsz->rnk > 0)) return 0;

     if (NO_UGLYP(plnr)) {
	  if (X(ct_uglyp)(16, p->sz->dims[0].n, ego->desc->radix)) return 0;
	  if (NONTHREADED_ICKYP(plnr)) return 0; /* prefer threaded version */
     }
     return 1;
}

static void finish(plan_hc2hc *ego)
{
     const hc2hc_desc *d = ego->slv->desc;
     opcnt t;

     ego->ios = X(mkstride)(ego->r, ego->m * ego->is);

     X(ops_add)(&ego->cld0->ops, &ego->cldm->ops, &t);
     X(ops_madd)(ego->vl, &t, &ego->cld->ops, &ego->super.super.ops);
     X(ops_madd2)(ego->vl * ((ego->m - 1)/2) / d->genus->vl, &d->ops,
		  &ego->super.super.ops);
}

static plan *mkplan(const solver *ego, const problem *p, planner *plnr)
{
     static const hc2hcadt adt = {
	  sizeof(plan_hc2hc), 
	  X(rdft_mkcldrn_dif), finish, applicable, apply
     };
     return X(mkplan_rdft_hc2hc)((const solver_hc2hc *) ego, p, plnr, &adt);
}


solver *X(mksolver_rdft_hc2hc_dif)(khc2hc codelet, const hc2hc_desc *desc)
{
     static const solver_adt sadt = { mkplan };
     static const char name[] = "rdft-dif";

     return X(mksolver_rdft_hc2hc)(codelet, desc, name, &sadt);
}
