#include "t.h"
#undef N
#define N(t, m, a, n)                                                             \
  void n(pith_t o, void *bs) { o(bs, m, a, t); }
#define TATGTGC(a1, a2, a3, a4, a5, a6, n)                                     \
  void n(pith_t, void *);                                                      \
  N(n, "GC", a6, NN(_, n))                                                     \
  N(NN(_, n), "TGC", a5, NN(a5, NN(_, n)))                                     \
  N(NN(a5, NN(_, n)), "GTGC", a4, NN(_, NN(a5, NN(_, n))))                     \
  N(NN(_, NN(a5, NN(_, n))), "TGTGC", a3, NN(a3, NN(_, NN(a5, NN(_, n)))))     \
  N(NN(a3, NN(_, NN(a5, NN(_, n)))), "ATGTGC", a2,                             \
    NN(a2, NN(a3, NN(_, NN(a5, NN(_, n))))))                                   \
  N(NN(a2, NN(a3, NN(_, NN(a5, NN(_, n))))), "TATGTGC", a1, n)
#define ATAGAGC(a1, a2, a3, a4, a5, a6, n)                                     \
  void n(pith_t, void *);                                                      \
  N(n, "GC", a6, NN(_, n))                                                     \
  N(NN(_, n), "AGC", a5, NN(a5, NN(_, n)))                                     \
  N(NN(a5, NN(_, n)), "GAGC", a4, NN(_, NN(a5, NN(_, n))))                     \
  N(NN(_, NN(a5, NN(_, n))), "AGAGC", a3, NN(a3, NN(_, NN(a5, NN(_, n)))))     \
  N(NN(a3, NN(_, NN(a5, NN(_, n)))), "TAGAGC", a2,                             \
    NN(a2, NN(a3, NN(_, NN(a5, NN(_, n))))))                                   \
  N(NN(a2, NN(a3, NN(_, NN(a5, NN(_, n))))), "ATAGAGC", a1, n)
#define TGC(t1, g2, n)                                                         \
  void n(pith_t, void *);                                                      \
  N(n, "GC", g2, NN(_, n))                                                     \
  N(NN(_, n), "TGC", t1, n)
#define AGGC(a1, g2, g3, n)                                                    \
  void n(pith_t, void *);                                                      \
  N(n, "GC", g3, NN(_, n))                                                     \
  N(NN(_, n), "GGC", g2, NN(_, NN(_, n)))                                      \
  N(NN(_, NN(_, n)), "AGGC", a1, n)
#define AAGC(a1, a2, g3, n)                                                    \
  void n(pith_t, void *);                                                      \
  N(n, "GC", g3, NN(_, n))                                                     \
  N(NN(_, n), "AGC", a2, NN(a2, NN(_, n)))                                     \
  N(NN(a2, NN(_, n)), "AAGC", a1, n)
#define AGAGC(a1, g2, a3, g4, n)
void _2() {}
void _1() {}
void E(pith_t, void *);
void F(pith_t, void *);
void T(pith_t, void *);

TGC(a, _1, A)
AGGC(A, _1, _2, B)

ATAGAGC(E, p, E, _1, T, _2, E)
ATAGAGC(T, m, F, _1, F, _2, T)
TATGTGC(l, E, r, _1, i, _2, F)
#define C(...)                                                                 \
  (const void *[]) { a, b }
const void *keywords[] = C(C("a", 0), 0);
/*
multiplicative-expression:
      cast-expression
      multiplicative-expression * cast-expression
      multiplicative-expression / cast-expression
      multiplicative-expression % cast-expression

    AG(L, cast-expression, _1,
L)ATAG(L, multiplicative-expression, *, cast-expression, _1,
L)ATAG(L, multiplicative-expression, /, cast-expression, _1,
L)ATAG(L, multiplicative-expression, %, cast-expression, _1,
          multiplicative-expression)
A.1.2 Keywords
(6.4.1) keyword: one of
*/
#define _(c, body)                                                             \
  if (*b == c) {                                                               \
    b++;                                                                       \
    body                                                                       \
  }
#define R(x) return (void)(*o = x);
// clang-format off
void keyword(int *o, const char *b) {
       _('a', _('u', _('t', _('o', R(4)))))
  else _('b', _('r', _('e', _('a', _('k', R(5))))))
  else _('c', _('a', _('s', _('e', R(4))))
         else _('h', _('a', _('r', R(4))))
         else _('o', _('n', _('s', _('t', R(5)))
                       else _('t', _('i', _('n', _('u', _('e', R(8)))))))))
  else _('d', _('e', _('f', _('a', _('u', _('l', _('t', R(7)))))))
         else _('o', _('u', _('b', _('l', _('e', R(6)))))
                else R(2)))
  else _('e', _('l', _('s', _('e', R(4))))
         else _('n', _('u', _('m', R(4))))
         else _('x', _('t', _('e', _('r', _('n', R(6)))))))
  else _('f', _('l', _('o', _('a', _('t', R(5)))))
         else _('o', _('r', R(3))))
  else _('g', _('o', _('t', _('o', R(4)))))
  else _('*', R(1))
  else _('i', _('f', R(2))
         else _('n', _('l', _('i', _('n', _('e', R(6)))))
                else _('t', R(3))))
  else _('l', _('o', _('n', _('g', R(4)))))
  else _('r', _('e', _('g', _('i', _('s', _('t', _('e', _('r', R(8)))))))
                else _('s', _('t', _('r', _('i', _('c', _('t', R(8)))))))
                else _('t', _('u', _('r', _('n', R(6)))))))
  else _('s', _('h', _('o', _('r', _('t', R(5)))))
         else _('i', _('g', _('n', _('e', _('d', R(6)))))
                else _('z', _('e', _('o', _('f', R(6))))))
         else _('t', _('a', _('t', _('i', _('c', R(6)))))
                else _('r', _('u', _('c', _('t', R(6))))))
         else _('w', _('i', _('t', _('c', _('h', R(6)))))))
  else _('t', _('y', _('p', _('e', _('d', _('e', _('f', R(7))))))))
  else _('u', _('n', _('i', _('o', _('n', R(5))))
                else _('s', _('i', _('g', _('n', _('e', _('d', R(8)))))))))
  else _('v', _('o', _('i', _('d', R(4)))
                else _('l', _('a', _('t', _('i', _('l', _('e', R(8)))))))))
  else _('w', _('h', _('i', _('l', _('e', R(5))))))
  else _('_', _('A', _('l', _('i', _('g', _('n', _('a', _('s', R(8)))
                                            else _('o', _('f', R(8)))))))
                else _('t', _('o', _('m', _('i', _('c', R(7)))))))
         else _('B', _('o', _('o', _('l', R(5)))))
         else _('C', _('o', _('m', _('p', _('l', _('e', _('x', R(8))))))))
         else _('G', _('e', _('n', _('e', _('r', _('i', _('c', R(8))))))))
         else _('I', _('m', _('a', _('g', _('i', _('n', _('a', _('r', _('y', R(10))))))))))
         else _('N', _('o', _('r', _('e', _('t', _('u', _('r', _('n', R(9)))))))))
         else _('S', _('t', _('a', _('t', _('i', _('c', _('_', _('a', _('s', _('s', _('e', _('r', _('t', R(14))))))))))))))
         else _('T', _('h', _('r', _('e', _('a', _('d', _('_', _('l', _('o', _('c', _('a', _('l', R(13))))))))))))))
  R(-1);
}
#undef _
#undef R
/*
A.2 Phrase structure grammar
A.2.1 Expressions

(6.5.1)
primary-expression:
  identifier
  constant
  string-literal
  ( expression )
  generic-selection

    AG(0,  identifier, _2,
L)  AG(L,  constant, _2,
L)  AG(L,  string-literal, _2
L)TATG(L,  (, expression, ), _2,
L)
  generic-selection
primary-expression:
*/
void identifier(pith_t,void*);
void constant(pith_t,void*);
void string_literal(pith_t,void*);
void expression(pith_t,void*);
void generic_association(pith_t,void*);
void assignment_expression(pith_t,void*);

  N(0, "G", _1,
L)N(L, "A", generic_association,
L)N(L, "G", _1,
L)N(L, "A", generic_association,
L)N(L, "C", ",",
L)N(L, "A", generic_assoc_list,
            generic_assoc_list)
//generic-assoc-list , generic-association
//generic-assoc-list:

//_Generic ( assignment-expression , generic-assoc-list )
//generic_selection:
  N(0, "G", _1,
L)N(L, "C", ")",
L)N(L, "A", generic_assoc_list,
L)N(L, "C", ",",
L)N(L, "A", assignment_expression,
L)N(L, "C", "(",
L)N(L, "C", "_Generic",
            generic_selection)

  N(0, "G", _1, 
L)N(L, "A", identifier, 
L)N(L, "G", _1, 
L)N(L, "A", constant, 
L)N(L, "G", _1, 
L)N(L, "A", string_literal, 
L)N(L, "G", _1, 
L)N(L, "C", ")", 
L)N(L, "A", expression, 
L)N(L, "C", "(", 
L)N(L, "G", _1, 
L)N(L, "A", generic_selection, 
            primary_expression)







// clang-format on
const char* keys[] = {
    "auto",
    "break",
    "case", "char", "const", "continue",
    "default", "do", "double",
    "else", "enum", "extern", "float",
    "for",
    "goto",
    "*",
    "if", "inline", "int",
    "long",
    "register", "restrict", "return",
    "short", "signed", "sizeof", "static", "struct", "switch",
    "typedef",
    "union", "unsigned",
    "void", "volatile",
    "while",
    "_Alignas", "_Alignof", "_Atomic",
    "_Bool",
    "_Complex",
    "_Generic",
    "_Imaginary",
    "_Noreturn",
    "_Static_assert",
    "_Thread_local"};
#include <stdio.h>
int main()
{
  for(int i=0;i<sizeof(keys) / sizeof(const char*);i++){
    int o;
    keyword(&o, keys[i]);
  printf("%2d %2d %s\n", i, o, keys[i]);
  }
}
/*  

*/
