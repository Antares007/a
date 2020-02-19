typedef void (*pith_t)(void *, const char *, void *, void *, void *);
typedef void (*bark_t)(pith_t, void *);

#define NA(n, a, b)                                                            \
  void n(pith_t o, void *s) { o(s, #n, n, a, b); }
#define NT(a) NA(T##a, a, (void *)0)
#define NG(a) NA(G##a, a, (void *)0)
#define NC(a, b) NA(C##a##b, a, b)

void noop() {}
void id() {}
void plus() {}
void mul() {}
void lparen() {}
void rparen() {}

void expr(pith_t, void *);
void term(pith_t, void *);
void factor(pith_t, void *);

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

void print(int ident, const char *s) {
  while (ident--)
    printf(". . ");
  printf("%s\n", s);
}

typedef struct state_t {
  int ident;
  avl_tree_t *tree;
} state_t;

void print_pith(void *vs, const char *n, void *pid, void *h, void *t) {
  state_t *s = (state_t *)vs;
  avl_insert(s->tree, pid, pid);
  const char type = n[0];
  print(s->ident, n);
  if (type != 'G' && type != 'T' && !avl_search(s->tree, h)) {
    s->ident++;
    ((bark_t)h)(print_pith, vs);
    s->ident--;
  }
  if (t)
    ((bark_t)t)(print_pith, vs);
}

void avl_ring(avl_tree_t *tree) {
  state_t state = {0, tree};
  expr(print_pith, &state);
}

int main() {
  int a[10] = {1, 2, 3, 4};
  printf("%d", a[4]);
  avl_bark(avl_ring, avl_ptrcmp, avl_void_key_destructor,
           avl_void_value_destructor);
  return 9;
}
