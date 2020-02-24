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

void n15(void *bs, pith_t o) { o(bs, "_Fid", _Fid, 0); }
void n16(void *bs, pith_t o) { o(bs, "id", id, n15); }
void n17(void *bs, pith_t o) { o(bs, "_FlpErp", _FlpErp, n16); }
void n18(void *bs, pith_t o) { o(bs, "rp", rp, n17); }
void n19(void *bs, pith_t o) { o(bs, "E", E, n18); }
void F(void *bs, pith_t o) { o(bs, "lp", lp, n19); }

void n22(void *bs, pith_t o) { o(bs, "_TF", _TF, 0); }
void n23(void *bs, pith_t o) { o(bs, "F", F, n22); }
void n24(void *bs, pith_t o) { o(bs, "_TTmulF", _TTmulF, n23); }
void n25(void *bs, pith_t o) { o(bs, "F", F, n24); }
void n26(void *bs, pith_t o) { o(bs, "mul", mul, n25); }
void T(void *bs, pith_t o) { o(bs, "T", T, n26); }

void n29(void *bs, pith_t o) { o(bs, "_ET", _ET, 0); }
void n30(void *bs, pith_t o) { o(bs, "T", T, n29); }
void n31(void *bs, pith_t o) { o(bs, "_EEplusT", _EEplusT, n30); }
void n32(void *bs, pith_t o) { o(bs, "T", T, n31); }
void n33(void *bs, pith_t o) { o(bs, "plus", plus, n32); }
void E(void *bs, pith_t o) {
  o(bs, "E", E, n33);
  // in="a*b+o" lpath=0 tail=0
}
// E       a*b+b   - goin
// E       a*b+b   - skip lr
// T       a*b+b   - goin
// T       a*b+b   - skip lr
// F       a*b+b   - goin
// lp      a*b+b   - skip t
// id      a*b+b   - eat
//_Fid    *b+b    - F->id
// goin tail
//_TF     *b+b    - T->F
// goin tail
//_ET     *b+b    - E->T
// goin tail
// plus    *b+b    - skip t
// T       *b+b    - goin
// T       *b+b    - skip lr
// F       *b+b    - goin
// lp      *b+b    - skip t
// id      *b+b    - skip t
