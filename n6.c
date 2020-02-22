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
void A(expr)(void *, pith_t, void *);
void A(term)(void *, pith_t, void *);
void A(fact)(void *, pith_t, void *);
void G(noop)() {}
// clang-format off
S(0,  G,  noop,   P)S(P,   //
      T,  id,     P)S(P,   //
      G,  noop,   P)S(P,   //[fact,[term,[expr,0]]]
      T,  rparen, P)S(P,   //[fact,[term,[expr,0]]]
      A,  expr,   P)S(P,   //[fact,[term,[expr,0]]]
      T,  lparen, A(fact)) //[fact,[term,[expr,0]]]
S(0,  G,  noop,   P)S(P,   //
      A,  fact,   P)S(P,   //[term,[expr,0]]
      G,  noop,   P)S(P,   //[term,[expr,0]]
      A,  fact,   P)S(P,   //[term,[expr,0]]
      T,  mul,    P)S(P,   //[term,[expr,0]]
      A,  term,   A(term)) //[term,[expr,0]]
S(0,  G,  noop,   P)S(P,   //
      A,  term,   P)S(P,   //[expr,0]
      G,  noop,   P)S(P,   //[expr,0]
      A,  term,   P)S(P,   //[expr,0]
      T,  plus,   P)S(P,   //[expr,0]
      A,  expr,   A(expr)) //[expr,0]
// start


#undef N
#define N gaabb
void G(n1)(){}
void G(n2)(){}
void G(n3)(){}
void A(E)(void*,pith_t,void*);
void A(B)(void*,pith_t,void*);
RGC(a, 'a')
RGC(b, 'b')
// B -> aB / b
S(0,  G,  n3, P)S(P,
      T,  b,  P)S(P,
      G,  n2, P)S(P,
      A,  B,  P)S(P,
      T,  a,  A(B)) // [AA, AE, T0]
// E -> BB
S(0,  G,  n1, P)S(P,
      A,  B,  P)S(P,
      A,  B,  A(E)) // [AE, T0]
/*
AB
. . Ta
. . AB
. . Gn2
. . Tb
. . Gn3
AB
Gn1
*/


#undef N
#define N ll
RGC(_a,'a')
RGB(_eps){ *o=0; }
void A(_S)(void*,pith_t,void*);
void A(_A)(void*,pith_t,void*);
void G(_n1)(){}
void G(_n2)(){}
void G(_n3)(){}
S(0,  G,  _n3,  P)S(P,
      T,  _a,   A(_A)) 
// A -> a
S(0,  G,  _n2,  P)S(P,
      T,  _eps, P)S(P, 
// S -> eps
      G,  _n1,  P)S(P,
      A,  _A,   P)S(P,
      A,  _S,   A(_S))
// S -> S A

