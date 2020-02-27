#pragma once
#include "t.h"

void S(pith_t, void *);
void A(pith_t, void *);
void B(pith_t, void *);
void _1();
void _2();
void _3();
void _4();

// clang-format off
N(0,    // B -> S / eps
 _4,    L)N(L,
  S,    B)
N(0,    // A -> B b / a
 _3,    L)N(L,
  a,    L)N(L,
 _2,    L)N(L,
  b,    L)N(L,
  B,    A)
N(0,    // S -> A
 _1,    L)N(L,
  A,    S)
