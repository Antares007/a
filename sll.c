typedef void (*pith_t)(void *, const char *, void *, void *);

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

void n13(pith_t o, void *bs);
void n14(pith_t o, void *bs);
void n15(pith_t o, void *bs);
void n16(pith_t o, void *bs);
void S(pith_t o, void *bs);

void n19(pith_t o, void *bs);
void G(pith_t o, void *bs);
void _3() {}
void _2() {}
void _1() {}
#define P(...)
#define C(a, b)                                                                \
  (void *[]) { a, b }

void n13(pith_t o, void *bs) { o(bs, "_3", _3, 0); }
void n14(pith_t o, void *bs) { o(bs, "b", b, n13); }
void n15(pith_t o, void *bs) { o(bs, "_2", _2, n14); }
void n16(pith_t o, void *bs) { o(bs, "a", a, n15); }
void S(pith_t o, void *bs) {
  P(1, "baa", C(S, 0), C(n19, 0));
  o(bs, "S", S, n16);
  P(2, "baa", C(S, 0), C(n19, 0));
}

void n19(pith_t o, void *bs) { o(bs, "_1", _1, 0); }
void G(pith_t o, void *bs) {
  P(0, "baa", 0, 0);
  o(bs, "S", S, n19);
}
// G: S
// S: Sa/b
//
// G
// S
// Sa
// Saa
// baa
