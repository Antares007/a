#pragma once
#include "n.h"

RGC(a, 'a')
RGC(b, 'b')
void S(void *, pith_t);
void A(void *, pith_t);

#include <stdio.h>
void _3() { printf("b\n"); }
void _2() { printf("aA\n"); }
void _1() { printf("AA\n"); }

// clang-format off
N(0,  // A -> aA / b
  _3, L)N(L,
  b,  L)N(L,
  _2, L)N(L,
  A,  L)N(L,
  a,  A)
N(0,  // S -> AA
  _1, L)N(L,
  A,  L)N(L,
  A,  S)


