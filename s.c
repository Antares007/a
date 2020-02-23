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
void _(){};
void E(void *, pith_t);
void T(void *, pith_t);
void F(void *, pith_t);
void n27(void *b, pith_t o) { o(b, "_", _, 0); }
void n28(void *b, pith_t o) { o(b, "id", id, n27); }
void n29(void *b, pith_t o) { o(b, "_", _, n28); }
void n30(void *b, pith_t o) { o(b, "rp", rp, n29); }
void n31(void *b, pith_t o) { o(b, "E", E, n30); }
void F(void *b, pith_t o) { o(b, "lp", lp, n31); }

void n34(void *b, pith_t o) { o(b, "_", _, 0); }
void n35(void *b, pith_t o) { o(b, "F", F, n34); }
void n36(void *b, pith_t o) { o(b, "_", _, n35); }
void n37(void *b, pith_t o) { o(b, "F", F, n36); }
void n38(void *b, pith_t o) { o(b, "mul", mul, n37); }
void T(void *b, pith_t o) { o(b, "T", T, n38); }

void n41(void *b, pith_t o) { o(b, "_", _, 0); }
void n42(void *b, pith_t o) { o(b, "T", T, n41); }
void n43(void *b, pith_t o) { o(b, "_", _, n42); }
void n44(void *b, pith_t o) { o(b, "T", T, n43); }
void n45(void *b, pith_t o) { o(b, "plus", plus, n44); }
void E(void *b, pith_t o) { o(b, "E", E, n45); }

void S(void *, pith_t);
void A(void *, pith_t);
void a(int *o, const char *b) { *o = *b == 'a' ? 1 : -1; }
void b(int *o, const char *b) { *o = *b == 'b' ? 1 : -1; }
void n53(void *b, pith_t o) {
  o(b, "_", _, 0);
  // 6. "__b" [n55, n60, $, 0]
  // reduce, goin tail
  // 11. "___" [n59, $, 0]
  // reduce, goin tail
}
void n54(void *b, pith_t o) {
  o(b, "b", b, n53);
  // 5. "_bb" [n55, n60, $, 0]
  // eat 'b', continue
  // 10. "__b" [n59, $, 0]
  // eat 'b', continue
}
void n55(void *b, pith_t o) {
  o(b, "_", _, n54);
  // 7. "__b" [n60, $, 0]
  // reduce, goin tial
}
void n56(void *b, pith_t o) {
  o(b, "A", A, n55);
  // 3. "_bb" [n60, $, 0]
  // add tail, goin A
}
void A(void *b, pith_t o) {
  o(b, "a", a, n56);
  // 2. "abb" [n60, $, 0]
  // eat 'a', continue
  // 4. "_bb" [n55, n60, $, 0]
  // skip to next production
  // 9. "__b" [n59, $, 0]
  // skip to next production
}

void n59(void *b, pith_t o) {
  o(b, "_", _, 0);
  // 12. "___" [$, 0]
  // reduce go intal
  // 13. "___" [$, 0]
}
void n60(void *b, pith_t o) {
  o(b, "A", A, n59);
  // 8. "__b" [$, 0]
  // add tail, goin A
}
void S(void *b, pith_t o) {
  o(b, "A", A, n60);
  // 1. "abb" [$, 0]
  // add tail, goin A
}
