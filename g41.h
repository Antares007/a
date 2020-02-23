#pragma once
#include "n.h"
// clang-format off
RGB(id) {
  int i = 0;
  while ('a' <= b[i] && b[i] <= 'z')
    i++;
  *o = i > 0 ? i : -1;
}
RGC(plus, '+')
RGC(mul, '*')
RGC(lp, '(')
RGC(rp, ')')
void _(){};
void E(void *, pith_t);
void T(void *, pith_t);
void F(void *, pith_t);

N(0,    // F -> ( E ) / id
  _,    L)N(L,
  id,   L)N(L,
  _,    L)N(L,
  rp,   L)N(L,
  E,    L)N(L,
  lp,   F)
N(0,    // T -> T * F / F
  _,    L)N(L,
  F,    L)N(L,
  _,    L)N(L,
  F,    L)N(L,
  mul,  L)N(L,
  T,    T)
N(0,    // E -> E + T / T
  _,    L)N(L,
  T,    L)N(L,
  _,    L)N(L,
  T,    L)N(L,
  plus, L)N(L,
  E,    E)
