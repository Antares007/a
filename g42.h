#pragma once
#include "t.h"

void E(void *, pith_t);
void E_(void *, pith_t);
void T(void *, pith_t);
void T_(void *, pith_t);
void F(void *, pith_t);
void _Fid();
void _FlpErp();
void _T_eps();
void _T_mulFT_();
void _TFT_();
void _E_eps();
void _E_plusTE_();
void _ETE_();
/*
 */
// clang-format off
N(0,          // F -> ( E ) / id
  _Fid,       L)N(L,
  id,         L)N(L,
  _FlpErp,    L)N(L,
  rp,         L)N(L,
  E,          L)N(L,
  lp,         F)
N(0,          // T_-> * F T_ / eps
  _T_eps,     L)N(L,
  eps,        L)N(L,
  _T_mulFT_,  L)N(L,
  T_,         L)N(L,
  F,          L)N(L,
  mul,        T_)
N(0,          //T -> F T_
  _TFT_,      L)N(L,
  T_,         L)N(L,
  F,          T)
N(0,          //E_-> + T E_ / eps
  _E_eps,     L)N(L,
  eps,        L)N(L,
  _E_plusTE_, L)N(L,
  E_,         L)N(L,
  T,          L)N(L,
  plus,       E_)
N(0,          //E -> T E_
  _ETE_,      L)N(L,
  E_,         L)N(L,
  T,          E)
