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
#define JOIN(name, l_bark, l_o_type, l_a_type, r_bark, r_o_type, r_a_type)     \
  JOIN_(l_bark, l_o_type, l_a_type, r_bark, r_o_type, r_a_type,                \
        CONCAT(name, _a_t), name, CONCAT(name, _o_t), CONCAT(name, _l_pith),   \
        CONCAT(name, _r_pith))
#define JOIN_(l_bark, l_o_type, l_a_type, r_bark, r_o_type, r_a_type, a_t,     \
              bark, o_t, l_pith, r_pith)                                       \
  typedef struct {                                                             \
    l_a_type l;                                                                \
    r_a_type r;                                                                \
  } a_t;                                                                       \
  typedef struct {                                                             \
    l_o_type l;                                                                \
    r_o_type r;                                                                \
  } o_t;                                                                       \
  static void r_pith(void *ba, r_o_type r) {                                   \
    void **b = ba;                                                             \
    void (*o)(void *, o_t) = b[0];                                             \
    o(b[1], (o_t){.l = *((l_o_type *)b[2]), .r = r});                          \
  }                                                                            \
  static void l_pith(void *ba, l_o_type l) {                                   \
    void **b = ba;                                                             \
    r_bark((void *[]){b[0], b[1], &l}, r_pith, *(r_a_type *)b[2]);             \
  }                                                                            \
  void bark(void *b, void (*o)(void *, o_t), a_t a) {                          \
    l_bark((void *[]){o, b, &a.r}, l_pith, a.l);                               \
  }
JOIN(a_bark_b_bark,                      //
     a_bark, const char *, const char *, //
     b_bark, int, int)                   //

#include <stdio.h>
static void ab_pith(void *s, a_bark_b_bark_o_t v) { //
  printf("%p %s %d\n", s, v.l, v.r);
}
int main() { //
  a_bark_b_bark(0, ab_pith, (a_bark_b_bark_a_t){"!", 39});
}
