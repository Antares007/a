#pragma once
#include "t.h"

void S(pith_t, void *);
void A(pith_t, void *);
void B(pith_t, void *);
void _1(){}
void _2(){}
void _3(){}
void _4(){}

// clang-format off
N(0,    // A -> Sb/c
 _4,    L)N(L,
  c,    L)N(L,
 _3,    L)N(L,
  b,    L)N(L,
  S,    A)
N(0,    // S -> Aa/d
 _2,    L)N(L,
  d,    L)N(L,
 _1,    L)N(L,
  a,    L)N(L,
  A,    S)
