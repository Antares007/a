typedef void (*pith_t)(void *, const char *, void *, void *);

void id(int *o, const char *b) {
  int i = 0;
  while ('a' <= b[i] && b[i] <= 'z')
    i++;
  *o = i > 0 ? i : -1;
}
void plus(int *o, const char *b) { *o = *b == '+' ? 1 : -1; }
void mul(int *o, const char *b) { *o = *b == '*' ? 1 : -1; }
void lp(int *o, const char *b) { *o = *b == '(' ? 1 : -1; }
void rp(int *o, const char *b) { *o = *b == ')' ? 1 : -1; }

void a(int *o, const char *b) { *o = *b == 'a' ? 1 : -1; }
void b(int *o, const char *b) { *o = *b == 'b' ? 1 : -1; }
void eps(int *o, const char *b) { *o = 0; }

void S(void *, pith_t);
void A(void *, pith_t);
void B(void *, pith_t);
void _SA();
void _ABb();
void _Aa();
void _BS();

void n14(void *bs, pith_t o) { o(bs, "_BS", _BS, 0); }
void B(void *bs, pith_t o) {
  o(bs, "S", S, n14);
  // 2) "ab" tail[n20,n23] lpath[B,A]
  // goin
}

void n17(void *bs, pith_t o) { o(bs, "_Aa", _Aa, 0); }
void n18(void *bs, pith_t o) { o(bs, "a", a, n17); }
void n19(void *bs, pith_t o) { o(bs, "_ABb", _ABb, n18); }
void n20(void *bs, pith_t o) { o(bs, "b", b, n19); }
void A(void *bs, pith_t o) {
  o(bs, "B", B, n20);
  // 1) "ab" tail[n23] lpath[A]
  // goin
}

void n23(void *bs, pith_t o) { o(bs, "_SA", _SA, 0); }
void S(void *bs, pith_t o) {
  o(bs, "A", A, n23);
  // 0) "ab" tail[] lpath[]
  // goin
  // 3) "ab" tail[n14,n20,n23] lpath[S,B,A]
}
// A       ab      - goin
// B       ab      - goin
// S       ab      - goin
// A       ab      - skip lr
// error: cant skip
// S -> Ab
// S -> a
// S
// Sb
// ab
