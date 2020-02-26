#pragma once
#include "t.h"

void S(pith_t, void *);
void A(pith_t, void *);
void B(pith_t, void *);
void _SA();
void _ABb();
void _Aa();
void _BS();

// clang-format off
N(0,    // B -> S / eps
  _BS,  L)N(L,
  S,    B)
N(0,    // A -> B b / a
  _Aa,  L)N(L,
  a,    L)N(L,
  _ABb, L)N(L,
  b,    L)N(L,
  B,    A)
N(0,    // S -> A
  _SA,  L)N(L,
  A,    S)
