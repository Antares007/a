#pragma once
#include "t.h"

void S(pith_t, void *);
void A(pith_t, void *);

void _3(){};
void _2(){};
void _1(){};

// clang-format off
N(0,    // A -> aA / b
  _3,   L)N(L,
  b,    L)N(L,
  _2,   L)N(L,
  A,    L)N(L,
  a,    A)
N(0,    // S -> AA
  _1,   L)N(L,
  A,    L)N(L,
  A,    S)


