typedef int (*push_t)(void *);
typedef int (*pop_t)(void *);
typedef void *(*peek_t)();
typedef void (*pith_t)(void *, push_t, pop_t, peek_t);

void stack_bark(pith_t o, void *s) {
  // void *arr[100];
  // void *b = arr;
  // void *e = &arr[100];
  // void *p = b;
  //
}
void pith(void *s, push_t push, pop_t pop, peek_t peek) {
  //
}

typedef void (*a_pith_t)(void *, const char *);
void a_bark(void *a, a_pith_t o, void *b) {
  o(a, "hello");
  o(a, "world");
}
typedef void (*b_pith_t)(void *, int);
void b_bark(void *a, b_pith_t o, void *b) {
  for (int i = 39; i < 42; i++)
    o(a, i);
}

typedef void (*ab_pith_t)(void *, const char *, int);
typedef struct {
  ab_pith_t abo;
  void *ab_s;
  const char *a_v;
} abs_t;
void b_pith(void *s, int b_v) { //
  abs_t *abs = s;
  abs->abo(abs->ab_s, abs->a_v, b_v);
}
void a_pith(void *s, const char *a_v) { //
  abs_t *abs = s;
  abs->a_v = a_v;
  b_bark(abs, b_pith, 0);
}
void ab_bark(void *ab_s, ab_pith_t abo, void *b) { //
  abs_t abs = {.abo = abo, .ab_s = ab_s};
  a_bark(&abs, a_pith, b);
}

#include <stdio.h>
void ab_pith(void *s, const char *a, int b) { printf("%p %s %d\n", s, a, b); }
int main() { ab_bark(ab_pith, ab_pith, 0); }
