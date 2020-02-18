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
NA(term, (void *)0, (void *)0)

NT(plus)
NG(noop)
NC(term, Gnoop)
NC(Tplus, CtermGnoop)
NC(expr, CTplusCtermGnoop)
NA(expr, CexprCTplusCtermGnoop, CtermGnoop)

/* clang-format off */
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
#include <stdio.h>
void g(void *s, n_t *n, void *h, void *t) {
  printf("%s ", n->n);
  if (t)
    ((bark)t)(g, s);
}
void p(void *s, n_t *n, void *h, void *t) {
  printf("%s\n", n->n);
  if(h){
  ((bark)h)(p, s);
  printf("\n");
  }
  if (t)
    ((bark)t)(p, s);
}


int main() {
  expr(p, 0);
  return 9;
}
