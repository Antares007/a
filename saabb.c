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
void A(pith_t, void *);
void n19(pith_t o, void *bs);
void n20(pith_t o, void *bs);
void S(pith_t, void *);

void _3(){};
void _2(){};
void _1(){};

void P(int, ...);
#define C(a, b)                                                                \
  (void *[]) { a, b }

void n13(pith_t o, void *bs) {
  P(5, "__b", C(A, C(A, C(S, 0))), C(n15, C(n20, 0)));
  P(10, "___", C(A, C(S, 0)), C(n19, 0));
  o(bs, "_3", _3, 0);
}
void n14(pith_t o, void *bs) {
  P(4, "_bb", C(A, C(A, C(S, 0))), C(n15, C(n20, 0)));
  P(9, "__b", C(A, C(S, 0)), C(n19, 0));
  o(bs, "b", b, n13);
}
void n15(pith_t o, void *bs) {
  P(6, "__b", C(A, C(S, 0)), C(n20, 0));
  o(bs, "_2", _2, n14);
}
void n16(pith_t o, void *bs) {
  P(2, "_bb", C(A, C(S, 0)), C(n20, 0));
  o(bs, "A", A, n15);
}
void A(pith_t o, void *bs) {
  P(1, "abb", C(A, C(S, 0)), C(n20, 0));
  P(3, "_bb", C(A, C(A, C(S, 0))), C(n15, C(n20, 0)));
  P(8, "__b", C(A, C(S, 0)), C(n19, 0));
  o(bs, "a", a, n16);
}

void n19(pith_t o, void *bs) {
  P(11, "___", C(S, 0), 0);
  o(bs, "_1", _1, 0);
}
void n20(pith_t o, void *bs) {
  P(7, "__b", C(A, C(S, 0)), 0);
  o(bs, "A", A, n19);
}
void S(pith_t o, void *bs) {
  P(0, "abb", C(S, 0), 0);
  o(bs, "A", A, n20);
}
// S: AA
// A: aA/b
// S
// AA
// aAA
// abb
