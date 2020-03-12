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

void n14(pith_t, void *);
void n15(pith_t, void *);
void n16(pith_t, void *);
void n17(pith_t, void *);
void A(pith_t, void *);
void n20(pith_t, void *);
void n21(pith_t, void *);
void n22(pith_t, void *);
void n23(pith_t, void *);
void S(pith_t, void *);
void _1() {}
void _2() {}
void _3() {}
void _4() {}

void n14(pith_t o, void *bs) { o(bs, "_4", _4, 0); }
void n15(pith_t o, void *bs) { o(bs, "c", c, n14); }
void n16(pith_t o, void *bs) { o(bs, "_3", _3, n15); }
void n17(pith_t o, void *bs) { o(bs, "b", b, n16); }
void A(pith_t o, void *bs) { o(bs, "S", S, n17); }

void n20(pith_t o, void *bs) { o(bs, "_2", _2, 0); }
void n21(pith_t o, void *bs) { o(bs, "d", d, n20); }
void n22(pith_t o, void *bs) { o(bs, "_1", _1, n21); }
void n23(pith_t o, void *bs) { o(bs, "a", a, n22); }
void S(pith_t o, void *bs) { o(bs, "A", A, n23); }
