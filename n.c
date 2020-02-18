typedef struct n_t {
  const char *n;
  void *p;
} n_t;
typedef void (*pith)(void *, n_t *, void *, void *);
typedef void (*bark)(pith, void *);

#define NA(name, a, b)                                                         \
  void name(pith o, void *s) {                                                 \
    n_t n = {#name, name};                                                     \
    o(s, &n, a, b);                                                            \
  }
#define NT(a) NA(T##a, a, (void *)0)
#define NG(a) NA(G##a, a, (void *)0)
#define NC(a, b) NA(C##a##b, a, b)
void noop() {}
void id() {}
void plus() {}
void mul() {}
void lparen() {}
void rparen() {}

void expr(pith, void *);
void term(pith, void *);
NA(term, term, (void *)0)

NT(plus)
NG(noop)
NC(term, Gnoop)
NC(Tplus, CtermGnoop)
NC(expr, CTplusCtermGnoop)
NA(expr, CexprCTplusCtermGnoop, CtermGnoop)

/*
N(T_, T);
NN(plus, T_)
NN(E, plusT_)
N(E_, T_)
NN(EplusT_, E_)

N(TF, F);
NN(mulF, _mul, TF)
NN(TmulF, T, mulF)
NN(T, TmulF, TF)

N(rparen, _rparen);
NN(Erparen, E, rparen)
NN(lparenErparen, _lparen, Erparen)
N(id, _id)
N(F1, id)
NN(F, lparenErparen, F1)
*/
#include "avl.h"
#include <stdio.h>
#include <string.h>

void p(void *s, n_t *n, void *h, void *t) {
  avl_tree_t *tree = (avl_tree_t *)s;
  const char type = n->n[0];
  printf("%s\n", n->n);
  if (type != 'G' && type != 'T' && !avl_search(tree, h)) {
    avl_insert(tree, h, h);
    ((bark)h)(p, s);
  }
  if (t)
    ((bark)t)(p, s);
}

void avl_ring(avl_tree_t *tree) { expr(p, tree); }
int main() {
  avl_bark(avl_ring, avl_ptrcmp, avl_void_key_destructor,
           avl_void_value_destructor);
  return 9;
}
