# 1 "gll.h"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 341 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "gll.h" 2

# 1 "./t.h" 1

# 1 "./n.h" 1

typedef void (*pith_t)(void *, const char *, void *, void *);
# 3 "./t.h" 2

void i(int *o, const char *b) {
  int i = 0;
  while ('a' <= b[i] && b[i] <= 'z')
    i++;
  *o = i > 0 ? i : -1;
}
void p(int *o, const char *b) { *o = *b == '+' ? 1 : -1; }
void m(int *o, const char *b) { *o = *b == '*' ? 1 : -1; }
void l(int *o, const char *b) { *o = *b == '(' ? 1 : -1; }
void r(int *o, const char *b) { *o = *b == ')' ? 1 : -1; }

void a(int *o, const char *b) { *o = *b == 'a' ? 1 : -1; }
void b(int *o, const char *b) { *o = *b == 'b' ? 1 : -1; }
void c(int *o, const char *b) { *o = *b == 'c' ? 1 : -1; }
void d(int *o, const char *b) { *o = *b == 'd' ? 1 : -1; }
void eps(int *o, const char *b) { *o = 0; }
# 3 "gll.h" 2

void S(pith_t, void *);
void _3() {}
void _2() {}
void _1() {}



  void n12(pith_t o, void *bs) { o(bs, "_2", _2, 0); }void n13(pith_t o, void *bs) { o(bs, "a", a, n12); }void n14(pith_t o, void *bs) { o(bs, "S", S, n13); }void n15(pith_t o, void *bs) { o(bs, "_1", _1, n14); }void S(pith_t o, void *bs) { o(bs, "a", a, n15); }
