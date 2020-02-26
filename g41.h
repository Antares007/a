#pragma once
#include "t.h"

void _Fid();
void _FlpErp();
void _TF();
void _ET();
void _TTmulF();
void _EEplusT();
void E(pith_t, void *);
void T(pith_t, void *);
void F(pith_t, void *);
// clang-format off
N(0,        // F -> ( E ) / id
  _Fid,     L)N(L,
  id,       L)N(L,
  _FlpErp,  L)N(L,
  rp,       L)N(L,
  E,        L)N(L,
  lp,       F)
N(0,        // T -> T * F / F
  _TF,      L)N(L,
  F,        L)N(L,
  _TTmulF,  L)N(L,
  F,        L)N(L,
  mul,      L)N(L,
  T,        T)
N(0,        // E -> E + T / T
  _ET,      L)N(L,
  T,        L)N(L,
  _EEplusT, L)N(L,
  T,        L)N(L,
  plus,     L)N(L,
  E,        E)
