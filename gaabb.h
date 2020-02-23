#pragma once
#include "n.h"

RGC(a, 'a')
RGC(b, 'b')
void S(void *, pith_t);
void A(void *, pith_t);

void _Ab();
void _AaA();
void _SAA();

// clang-format off
N(0,   // A -> aA / b
  _Ab,  L)N(L,
  b,   L)N(L,
  _AaA, L)N(L,
  A,   L)N(L,
  a,   A)
N(0,   // S -> AA
  _SAA, L)N(L,
  A,   L)N(L,
  A,   S)


