#pragma once
#include "t.h"

void S(pith_t, void *);
void G(pith_t, void *);
void _3() {}
void _2() {}
void _1() {}

// clang-format off
//
  N(0,  _3,  
L)N(L,  b,
L)N(L,  _2,
L)N(L,  a,
L)N(L,  S,
        S)
  N(0,  _1,
L)N(L,  S,
        G)
