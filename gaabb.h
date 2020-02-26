#pragma once
#include "t.h"

void S(pith_t, void *);
void A(pith_t, void *);

void _Ab();
void _AaA();
void _SAA();

// clang-format off
N(0,   // A -> aA / b
  _Ab,  L)N(L,
  b,    L)N(L,
  _AaA, L)N(L,
  A,    L)N(L,
  a,    A)
N(0,    // S -> AA
  _SAA, L)N(L,
  A,    L)N(L,
  A,    S)


