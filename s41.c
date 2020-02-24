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
void _id();
void _lpErp();
void _F();
void _TmulF();
void _EplusT();
void E(void *, pith_t);
void T(void *, pith_t);
void F(void *, pith_t);

void n24(void *bs, pith_t o) { o(bs, "_id", _id, 0); }
void n25(void *bs, pith_t o) { o(bs, "id", id, n24); }
void n26(void *bs, pith_t o) { o(bs, "_lpErp", _lpErp, n25); }
void n27(void *bs, pith_t o) { o(bs, "rp", rp, n26); }
void n28(void *bs, pith_t o) { o(bs, "E", E, n27); }
void F(void *bs, pith_t o) { o(bs, "lp", lp, n28); }

void n31(void *bs, pith_t o) { o(bs, "_F", _F, 0); }
void n32(void *bs, pith_t o) { o(bs, "F", F, n31); }
void n33(void *bs, pith_t o) { o(bs, "_TmulF", _TmulF, n32); }
void n34(void *bs, pith_t o) { o(bs, "F", F, n33); }
void n35(void *bs, pith_t o) { o(bs, "mul", mul, n34); }
void T(void *bs, pith_t o) { o(bs, "T", T, n35); }

void n38(void *bs, pith_t o) { o(bs, "_F", _F, 0); }
void n39(void *bs, pith_t o) { o(bs, "T", T, n38); }
void n40(void *bs, pith_t o) { o(bs, "_EplusT", _EplusT, n39); }
void n41(void *bs, pith_t o) { o(bs, "T", T, n40); }
void n42(void *bs, pith_t o) { o(bs, "plus", plus, n41); }
void E(void *bs, pith_t o) {
  o(bs, "E", E, n42);
  // 0) in=a*b+o tail=0 lpath=0
  // add t to tail, add h to lpath, goin h
  // 1) in=a*b+o tail=[n42,0] lpath=[E,0]
  // lr!
  // 2) in=a*b+o tail=[n42,0] lpath=[E,0]
}
