#include "n6.c"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef void (*bark)(void *, pith_t, void *);

void print_pith(void *b_, const char *n, void *h, void *t) { //
  int *i = (int *)b_;
  printf("%d(%s) ", *i, n);
  ((int *)b_)[0]++;
  if (n[0] == 'G') {
    printf("\n");
    *i = 0;
  }
  if (t)
    ((bark)t)(b_, print_pith, 0);
}
void ag_pith(void *b_, const char *n, void *h, void *t) { //
  void **b = b_;
  pith_t p = b[0];
  bark g = b[1];
  g(b[2], p, 0);
}
void ag(void *b, pith_t o, void *g) {
  ((bark)g)((void *[]){o, g, b}, ag_pith, 0);
}
void print(bark g) { //
  int i = 0;
  ag(&i, print_pith, g);
}
int main() {
  print(g41_A_expr);
  return 9;
}
