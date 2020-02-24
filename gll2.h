#pragma once
#include "t.h"

void S(void *, pith_t);
void A(void *, pith_t);
void B(void *, pith_t);
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
