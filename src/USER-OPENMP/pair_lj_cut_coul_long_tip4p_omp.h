/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef PAIR_CLASS

PairStyle(lj/cut/coul/long/tip4p/omp,PairLJCutCoulLongTIP4POMP)

#else

#ifndef LMP_PAIR_LJ_CUT_COUL_LONG_TIP4P_OMP_H
#define LMP_PAIR_LJ_CUT_COUL_LONG_TIP4P_OMP_H

#include "pair_lj_cut_coul_long_omp.h"

namespace LAMMPS_NS {

class PairLJCutCoulLongTIP4POMP : public PairLJCutCoulLongOMP {
 public:
  PairLJCutCoulLongTIP4POMP(class LAMMPS *);
  void compute(int, int);
  void settings(int, char **);
  void init_style();
  void write_restart_settings(FILE *fp);
  void read_restart_settings(FILE *fp);
  void *extract(char *);

 protected:
  template <int EVFLAG, int EFLAG, int VFLAG> void eval_tip4p();

 private:
  int typeH,typeO;             // atom types of TIP4P water H and O atoms
  int typeA,typeB;             // angle and bond types of TIP4P water
  double qdist;                // distance from O site to negative charge
  double alpha;                // geometric constraint parameter for TIP4P

  void find_M(int, int &, int &, double *);
};

}

#endif
#endif
