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

void _Fid();
void _FlpErp();
void _TF();
void _ET();
void _TTmulF();
void _EEplusT();
void E(void *, pith_t);
void T(void *, pith_t);
void F(void *, pith_t);

void n15(void *bs, pith_t o) {
  o(bs, "_Fid", _Fid, 0);
  // 10) F "_*b+o" [n22, T, n29, E]
  // reduce goin n22
}
void n16(void *bs, pith_t o) {
  o(bs, "id", id, n15);
  // 9) F "a*b+o" [n22, T, n29, E]
  // eat
}
void n17(void *bs, pith_t o) { o(bs, "_FlpErp", _FlpErp, n16); }
void n18(void *bs, pith_t o) { o(bs, "rp", rp, n17); }
void n19(void *bs, pith_t o) { o(bs, "E", E, n18); }
void F(void *bs, pith_t o) {
  o(bs, "lp", lp, n19);
  // 8) F "a*b+o" [n22, T, n29, E]
  // skip
}

void n22(void *bs, pith_t o) {
  o(bs, "_TF", _TF, 0);
  // 11) n22 "_*b+o" [T, n29, E]
  // reduce, goin T
}
void n23(void *bs, pith_t o) {
  o(bs, "F", F, n22);
  // 7) n26 "a*b+o" [T, n29, E]
  // goin F
}
void n24(void *bs, pith_t o) { o(bs, "_TTmulF", _TTmulF, n23); }
void n25(void *bs, pith_t o) {
  o(bs, "F", F, n24);
  // 15) n26 "__b+o" [T, n29, E]
}
void n26(void *bs, pith_t o) {
  o(bs, "mul", mul, n25);
  // 6) n26 "a*b+o" [T, n29, E]
  // skip
  // 14) n26 "_*b+o" [T, n29, E]
  // eat
}
void T(void *bs, pith_t o) {
  o(bs, "T", T, n26);
  // 4) T "a*b+o" [n29, E]
  // goin T
  // 5) T "a*b+o" [n26, n29, E]
  // lr goin n26
  // 12) T "_*b+o" [n29, E]
  // goin T
  // 13) T "_*b+o" [n26, n29, E]
  // lr goin n26
}

void n29(void *bs, pith_t o) { o(bs, "_ET", _ET, 0); }
void n30(void *bs, pith_t o) {
  o(bs, "T", T, n29);
  // 3) n33 "a*b+o" [E]
  // goin T
}
void n31(void *bs, pith_t o) { o(bs, "_EEplusT", _EEplusT, n30); }
void n32(void *bs, pith_t o) { o(bs, "T", T, n31); }
void n33(void *bs, pith_t o) {
  o(bs, "plus", plus, n32);
  // 2) n33 "a*b+o" [E]
  // skip
}
void E(void *bs, pith_t o) {
  o(bs, "E", E, n33);
  // 0) 0 "a*b+o" []
  // goin E
  // 1) E "a*b+o" [n33]
  // lr, goin n33
}
