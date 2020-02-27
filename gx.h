#pragma once
#include "t.h"
// S -> A
// S -> b
// A -> a
void _1() {}
void _2() {}
void _3() {}
// clang-format off
N(0,
  _3,  L)N(L,
  b,  A)
N(0,
  _2,  L)N(L,
  a,  L)N(L,
  _1,  L)N(L,
  A,  S)
