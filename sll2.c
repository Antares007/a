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

void n14(void *bs, pith_t o) {
  o(bs, "_BS", _BS, 0);
  // 8) "_b" [n23]
  // reduce
}
void B(void *bs, pith_t o) {
  o(bs, "S", S, n14);
  // 2) "ab" [n20,n23]
  // goin
}

void n17(void *bs, pith_t o) {
  o(bs, "_Aa", _Aa, 0);
  // 7) "_b" [n14,n23]
  // reduce
}
void n18(void *bs, pith_t o) {
  o(bs, "a", a, n17);
  // 6) "ab" [n14,n23]
  // eat
}
void n19(void *bs, pith_t o) { o(bs, "_ABb", _ABb, n18); }
void n20(void *bs, pith_t o) {
  o(bs, "b", b, n19);
  // 5) "ab" [n14,n23]
  // skip
}
void A(void *bs, pith_t o) {
  o(bs, "B", B, n20);
  // 1) "ab" [n23]
  // goin
}

void n23(void *bs, pith_t o) {
  o(bs, "_SA", _SA, 0);
  // 4) "ab" [n20,n14,n23]
  // reduce
}
void S(void *bs, pith_t o) {
  o(bs, "A", A, n23);
  // 0) "ab" []
  // goin
  // 3) "ab" [n14,n20,n23]
  // lr n23,
  // 9) "_b" []
}
// A       ab      - goin
// B       ab      - goin
// S       ab      - goin
// A       ab      - skip lr
// error: cant skip
// S -> A
// A -> Bb
// A -> a
// B -> S
// S
// A
// Bb
// Sb
// Ab
// ab
