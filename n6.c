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
S(0,  noop,   G,  P)S(P,
      id,     T,  P)S(P,
      noop,   G,  P)S(P,
      rparen, T,  P)S(P,
      expr,   A,  P)S(P,
      lparen, T,  A(fact))
S(0,  noop,   G,  P)S(P,
      fact,   A,  P)S(P,
      noop,   G,  P)S(P,
      fact,   A,  P)S(P,
      mul,    T,  P)S(P,
      term,   A,  A(term))
S(0,  noop,   G,  P)S(P,
      term,   A,  P)S(P,
      noop,   G,  P)S(P,
      term,   A,  P)S(P,
      plus,   T,  P)S(P,
      expr,   A,  A(expr))
// start
