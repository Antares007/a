#include "m.h"

RG(lparen, RSymbol('('))
RG(rparen, RSymbol(')'))
RG(plus, RSymbol('+'))
RG(mul, RSymbol('*'))
RG(dollar, RSymbol('\0'))
RG(id, {
  int i = 0;
  while ('a' <= b[i] && b[i] <= 'z')
    ++i;
  *o = i ? i : -1;
})

void E(pith, void *);
void T(pith, void *);
void F(pith, void *);

L3(E0, E, plus, T)
L1(E1, T)
L2(E, E0, E1)

L3(T0, T, mul, F)
L1(T1, F)
L2(T, T0, T1)

L3(F0, lparen, E, rparen)
L1(F1, id)
L2(F, F0, F1)

#include "avl.h"
#include <stdarg.h>
#include <stdio.h>

#include <string.h>
void noop(void *k) {}
void noop2(void *k, void *d) {}

void p_pith(void *s, const char *n, ...) {
  va_list args;
  va_start(args, n);
  bark h = va_arg(args, bark);
  bark t = va_arg(args, bark);
  printf("%s %d %d\n", n, (int)h, (int)t);
}

void v_pith(void *s, const char *n, ...) {
  va_list args;
  va_start(args, n);
  bark h = va_arg(args, bark);
  bark t = va_arg(args, bark);
  printf("%s %d %d\n", n, (int)h, (int)t);
  h(p_pith, s);
}

void avl(void (*o)(avl_tree_t *), avl_comparator_t cmp,
         avl_key_destructor_t dkey);

void avl_ring(avl_tree_t *tree) { E(v_pith, tree); }

int main(void) { avl(avl_ring, (avl_comparator_t)strcmp, noop); }

void avl(void (*o)(avl_tree_t *), avl_comparator_t cmp,
         avl_key_destructor_t dkey) {
  avl_tree_t tree;
  avl_initialize(&tree, cmp, dkey);
  o(&tree);
  avl_destroy(&tree, noop2);
}
