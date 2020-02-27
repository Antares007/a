#pragma once
#include "t.h"

void E(pith_t, void *);
void E_(pith_t, void *);
void T(pith_t, void *);
void T_(pith_t, void *);
void F(pith_t, void *);
void _1() {}
void _2() {}
void _3() {}
void _4() {}
void _5() {}
void _6() {}
void _7() {}
void _8() {}
// clang-format off
N(0,          // F -> ( E ) / id
 _8,          L)N(L,
  i,         L)N(L,
 _7,          L)N(L,
  r,         L)N(L,
  E,          L)N(L,
  l,         F)
N(0,          // T_-> * F T_ / eps
 _6,          L)N(L,
  eps,        L)N(L,
 _5,          L)N(L,
  T_,         L)N(L,
  F,          L)N(L,
  m,        T_)
N(0,          //T -> F T_
 _4,          L)N(L,
  T_,         L)N(L,
  F,          T)
N(0,          //E_-> + T E_ / eps
 _3,          L)N(L,
  eps,        L)N(L,
 _2,          L)N(L,
  E_,         L)N(L,
  T,          L)N(L,
  p,       E_)
N(0,          //E -> T E_
 _1,          L)N(L,
  E_,         L)N(L,
  T,          E)
