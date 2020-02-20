#include "n6.c"
#include <stddef.h>
#include <stdint.h>

typedef void (*bark)(pith_t, void *);

void print_pith(void *s_, const char *n, void *h, void *t) { //
  // if(contains(s,h))
}

void print(bark b) { //
  b(print_pith, 0);
}
int main() {
  print(g41_A_expr);

  return 9;
}
