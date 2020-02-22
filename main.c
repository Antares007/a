#include "n6.c"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef void (*bark)(void *, pith_t, void *);

inline bool contains(void **list, void *value);
inline void ident_print(int ident, const char *n);
void traverse_pith(void *b_, const char *n, void *h, void *t) {
  void **b = b_;
  int *ident = b[0];
  void **path = b[1];
  ident_print(*ident, n);
  if (n[0] == 'A') {
    b_ = (void *[]){b[0], (void *[]){h, path}};
    if (!contains(path, h))
      ((*ident)++, ((bark)h)(b_, traverse_pith, 0), (*ident)--);
  }
  if (t)
    ((bark)t)(b_, traverse_pith, 0);
}
void print(bark g) {
  int ident = 0;
  g((void *[]){&ident, (void *[]){g, 0}}, traverse_pith, 0);
}
int main() {
  print(g41_A_expr);
  return 9;
}

void ident_print(int ident, const char *n) {
  while (ident--)
    printf(". . ");
  printf("%s\n", n);
}
bool contains(void **list, void *value) {
  for (; list; list = list[1])
    if (list[0] == value)
      return true;
  return false;
}
