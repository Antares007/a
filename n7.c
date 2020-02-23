typedef void (*pith_t)(void *, const char *, void *, void *);

#define NN_(a, b) a##b
#define NN(a, b) NN_(a, b)
#define N(t, a, n)                                                             \
  void n(void *bs, pith_t o) { o(bs, #a, a, t); }
#define L NN(n, __LINE__)
#define RGB(name) void name(int *o, const char *b)
#define RGC(name, c)                                                           \
  RGB(name) { *o = *b == c ? 1 : -1; }
// clang-format off
RGB(id) {
  int i = 0;
  while ('a' <= b[i] && b[i] <= 'z')
    i++;
  *o = i > 0 ? i : -1;
}
RGC(plus, '+')
RGC(mul, '*')
RGC(lp, '(')
RGC(rp, ')')
void _(){};
void E(void *, pith_t);
void T(void *, pith_t);
void F(void *, pith_t);
N(0,    // F -> ( E ) / id
  _,    L)N(L,
  id,   L)N(L,
  _,    L)N(L,
  rp,   L)N(L,
  E,    L)N(L,
  lp,   F)
N(0,    // T -> T * F / F
  _,    L)N(L,
  F,    L)N(L,
  _,    L)N(L,
  F,    L)N(L,
  mul,  L)N(L,
  T,    T)
N(0,    // E -> E + T / T
  _,    L)N(L,
  T,    L)N(L,
  _,    L)N(L,
  T,    L)N(L,
  plus, L)N(L,
  E,    E)

RGC(a, 'a')
RGC(b, 'b')
void S(void*, pith_t);
void A(void*, pith_t);
#include<stdio.h>
void _3(){ printf("b\n"); }
void _2(){ printf("aA\n"); }
void _1(){ printf("AA\n"); }
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
