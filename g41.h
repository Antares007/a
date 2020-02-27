#pragma once
#include "t.h"

void _1() {}
void _2() {}
void _3() {}
void _4() {}
void _5() {}
void _6() {}
void E(pith_t, void *);
void T(pith_t, void *);
void F(pith_t, void *);
// clang-format off
N(0,    // F -> ( E ) / id
 _6,    L)N(L,
  i,    L)N(L,
 _5,    L)N(L,
  r,    L)N(L,
  E,    L)N(L,
  l,    F)
N(0,    // T -> T * F / F
 _4,    L)N(L,
  F,    L)N(L,
 _3,    L)N(L,
  F,    L)N(L,
  m,    L)N(L,
  T,    T)
N(0,    // E -> E + T / T
 _2,    L)N(L,
  T,    L)N(L,
 _1,    L)N(L,
  T,    L)N(L,
  p,    L)N(L,
  E,    E)
