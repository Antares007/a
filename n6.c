#include "mb.h"

#define N g41_

RGB(id) {
  int i = 0;
  while ('a' <= b[i] && b[i] <= 'z')
    i++;
  *o = i > 0 ? i : -1;
}
RGC(plus, '+')
RGC(mul, '*')
RGC(lparen, '(')
RGC(rparen, ')')

static void A(expr)(void *, pith_t, void *);
static void A(term)(void *, pith_t, void *);
static void A(fact)(void *, pith_t, void *);

static void G(noop)() {}
// clang-format off
S(0,  noop,   G,  P)S(P,   //
      id,     T,  P)S(P,   //
      noop,   G,  P)S(P,   //[fact,[term,[expr,0]]]
      rparen, T,  P)S(P,   //[fact,[term,[expr,0]]]
      expr,   A,  P)S(P,   //[fact,[term,[expr,0]]]
      lparen, T,  A(fact)) //[fact,[term,[expr,0]]]
S(0,  noop,   G,  P)S(P,   //
      fact,   A,  P)S(P,   //[term,[expr,0]]
      noop,   G,  P)S(P,   //[term,[expr,0]]
      fact,   A,  P)S(P,   //[term,[expr,0]]
      mul,    T,  P)S(P,   //[term,[expr,0]]
      term,   A,  A(term)) //[term,[expr,0]]
S(0,  noop,   G,  P)S(P,   //
      term,   A,  P)S(P,   //[expr,0]
      noop,   G,  P)S(P,   //[expr,0]
      term,   A,  P)S(P,   //[expr,0]
      plus,   T,  P)S(P,   //[expr,0]
      expr,   A,  A(expr)) //[expr,0]
// start
