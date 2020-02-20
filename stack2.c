typedef void (*a_pith_t)(void *, const char *);
void a_bark(void *a, a_pith_t o, const char *str) {
  o(a, "hello");
  o(a, "world");
  o(a, str);
}
typedef void (*b_pith_t)(void *, int);
void b_bark(void *b, b_pith_t o, int a) {
  for (int i = a; i < 42; i++)
    o(b, i);
}
#define CONCAT_IMP(a, b) a##b
#define CONCAT(a, b) CONCAT_IMP(a, b)
#define CONCAT3_IMP(a, b, c) a##b##c
#define CONCAT3(a, b, c) CONCAT3_IMP(a, b, c)
#define CONCAT6_IMP(a, b, c, d, e, f) a##b##c##d##e##f
#define CONCAT6(a, b, c, d, e, f) CONCAT6_IMP(a, b, c, d, e, f)

#define JOIN(l_bark, l_o_type, l_a_type, r_bark, r_o_type, r_a_type)           \
  JOIN_(l_bark, l_o_type, l_a_type, r_bark, r_o_type, r_a_type,                \
        CONCAT6(l_bark, _, r_bark, _b_, __LINE__, _t),                         \
        CONCAT3(l_bark, _, r_bark))
#define JOIN_(l_bark, l_o_type, l_a_type, r_bark, r_o_type, r_a_type, b_t,     \
              bark)                                                            \
  typedef struct {                                                             \
    l_a_type l;                                                                \
    r_a_type r;                                                                \
  } a_t;                                                                       \
  typedef struct {                                                             \
    void (*o)(void *, l_o_type, r_o_type);                                     \
    void *b;                                                                   \
    r_a_type a;                                                                \
    l_o_type l;                                                                \
  } b_t;                                                                       \
  static void r_pith(void *b_, r_o_type r) {                                   \
    b_t *b = b_;                                                               \
    b->o(b->b, b->l, r);                                                       \
  }                                                                            \
  static void l_pith(void *b_, l_o_type l) {                                   \
    b_t *b = b_;                                                               \
    b->l = l;                                                                  \
    r_bark(b, r_pith, b->a);                                                   \
  }                                                                            \
  void bark(void *b_, void (*o)(void *, l_o_type, r_o_type), a_t a) {          \
    b_t b = {.o = o, .b = b_, .a = a.r};                                       \
    l_bark(&b, l_pith, a.l);                                                   \
  }
JOIN(a_bark, const char *, const char *, //
     b_bark, int, int)

#include <stdio.h>
void ab_pith(void *s, const char *a, int b) { //
  printf("%p %s %d\n", s, a, b);
}
int main() { //
  a_bark_b_bark(0, ab_pith, (a_t){"!", 39});
}
