#pragma once
#include "n.h"

RGC(a, 'a')
RGC(b, 'b')
RGB(eps) { *o = 0; }
void S(void *, pith_t);
void A(void *, pith_t);
void _3();
void _2();
void _1();
// clang-format off
N(0,    // A -> a
  _3,   L)N(L,
  a,    A)
N(0,    //S -> SA/Eps
  _2,   L)N(L,
  eps,  L)N(L,
  _1,   L)N(L,
  A,    L)N(L,
  S,    S)
