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

void S(pith_t, void *);
void A(pith_t, void *);
void n13(pith_t o, void *bs);
void n14(pith_t o, void *bs);
void n15(pith_t o, void *bs);
void n16(pith_t o, void *bs);
void n19(pith_t o, void *bs);
void n20(pith_t o, void *bs);
void n21(pith_t o, void *bs);
void n22(pith_t o, void *bs);
void _1() {}
void _2() {}
void _3() {}
void _4() {}
void P(int, ...);
#define C(a, b)                                                                \
  (void *[]) { a, b }
void n13(pith_t o, void *bs) { o(bs, "_4", _4, 0); }
void n14(pith_t o, void *bs) { o(bs, "c", c, n13); }
void n15(pith_t o, void *bs) { o(bs, "_3", _3, n14); }
void n16(pith_t o, void *bs) { o(bs, "b", b, n15); }
void A(pith_t o, void *bs) {
  P(1, "caba", C(A, 0), C(n22, 0));
  o(bs, "S", S, n16);
}

void n19(pith_t o, void *bs) { o(bs, "_2", _2, 0); }
void n20(pith_t o, void *bs) { o(bs, "d", d, n19); }
void n21(pith_t o, void *bs) { o(bs, "_1", _1, n20); }
void n22(pith_t o, void *bs) { o(bs, "a", a, n21); }
void S(pith_t o, void *bs) {
  P(0, "caba", 0, 0);
  P(2, "caba", C(S, C(A, 0)), C(n16, C(n22, 0)));
  o(bs, "A", A, n22);

  P(3, "caba", C(S, C(A, 0)), C(n16, C(n22, 0)));
}
// S: Aa/d
// A: Sb/c
// S': S'ba/ca/d
//
//      S     S'
//     Aa     S'ba
//    Sba     caba
//   Aaba
//   caba
