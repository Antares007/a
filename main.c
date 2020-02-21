#include "n6.c"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef void (*bark)(void *, pith_t, void *);

bool contains(void **list, void *value) {
  for (; list; list = list[1])
    if (list[0] == value)
      return true;
  return false;
}
void traverse_pith(void *b_, const char *n, void *h, void *t) {
  void **b = b_;
  int *ident = b[0];
  void **path = b[1];
  for (int i = *ident; i > 0; i--)
    printf(". . ");
  printf("%s\n", n);
  if (n[0] == 'A') {
    b_ = (void *[]){b[0], (void *[]){h, path}};
    (*ident)++;
    if (!contains(path, h))
      ((bark)h)(b_, traverse_pith, 0);
    (*ident)--;
  }
  if (t)
    ((bark)t)(b_, traverse_pith, 0);
}
void print(bark g) {
  int ident = 0;
  g((void *[]){&ident, (void *[]){g, 0}}, traverse_pith, 0);
}
int main() {
  print(g41_32);
  return 9;
}
