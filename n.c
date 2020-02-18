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
void factor(pith, void *);

NT(plus)
NT(mul)
NT(lparen)
NT(rparen)
NT(id)

NG(noop)

NC(term, Gnoop)
NC(Tplus, CtermGnoop)
NC(expr, CTplusCtermGnoop)
NA(expr, CexprCTplusCtermGnoop, CtermGnoop)

NC(factor, Gnoop)
NC(Tmul, CfactorGnoop)
NC(term, CTmulCfactorGnoop)
NA(term, CtermCTmulCfactorGnoop, CfactorGnoop)

NC(Trparen, Gnoop)
NC(expr, CTrparenGnoop)
NC(Tlparen, CexprCTrparenGnoop)
NC(Tid, Gnoop)
NA(factor, CTlparenCexprCTrparenGnoop, CTidGnoop)

#include "avl.h"
#include <stdio.h>
#include <string.h>

static int ident = 0;
void print(const char *s) {
  int i = ident;
  while (i--)
    printf(". . ");
  printf("%s\n", s);
}

void p(void *s, n_t *n, void *h, void *t) {
  avl_tree_t *tree = (avl_tree_t *)s;
  avl_insert(tree, n->p, n->p);
  const char type = n->n[0];
  print(n->n);
  if (type != 'G' && type != 'T' && !avl_search(tree, h)) {
    ident++;
    ((bark)h)(p, s);
    ident--;
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
