#include "n.h"

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
#define P(...)
#define C(a, b)                                                                \
  (void *[]) { a, b }

void n13(pith_t o, void *bs);
void n14(pith_t o, void *bs);
void n15(pith_t o, void *bs);
void n16(pith_t o, void *bs);
void S(pith_t, void *);

void n19(pith_t o, void *bs);
void G(pith_t, void *);

void _3() {}
void _2() {}
void _1() {}

void EpT_T_E(pith_t o, void *bs);

void _F(pith_t o, void *bs) { o(bs, "_3", _3, 0); }
void i_F(pith_t o, void *bs) { o(bs, "i", i, _F); }
void _i_F(pith_t o, void *bs) { o(bs, "_2", _2, i_F); }
void r_i_F(pith_t o, void *bs) { o(bs, "r", r, _i_F); }
void Er_i_F(pith_t o, void *bs) { o(bs, "m", EpT_T_E, r_i_F); }
void lEr_i_F(pith_t o, void *bs) { o(bs, "p", l, Er_i_F); }

void _T(pith_t o, void *bs) { o(bs, "_3", _3, 0); }
void F_T(pith_t o, void *bs) { o(bs, "T", lEr_i_F, _T); }
void _F_T(pith_t o, void *bs) { o(bs, "_2", _2, F_T); }
void F_F_T(pith_t o, void *bs) { o(bs, "F", lEr_i_F, _F_T); }
void mF_F_T(pith_t o, void *bs) { o(bs, "m", m, F_F_T); }
void TmF_F_T(pith_t o, void *bs) { o(bs, "p", TmF_F_T, mF_F_T); }

void _E(pith_t o, void *bs) { o(bs, "_3", _3, 0); }
void T_E(pith_t o, void *bs) { o(bs, "T", TmF_F_T, _E); }
void _T_E(pith_t o, void *bs) { o(bs, "_2", _2, T_E); }
void T_T_E(pith_t o, void *bs) { o(bs, "_2", TmF_F_T, T_E); }
void pT_T_E(pith_t o, void *bs) { o(bs, "p", p, T_T_E); }
void EpT_T_E(pith_t o, void *bs) { o(bs, "p", EpT_T_E, pT_T_E); }

void _S(pith_t o, void *bs) { o(bs, "_3", _3, 0); }
void b_S(pith_t o, void *bs) { o(bs, "b", b, _S); }
void _b_S(pith_t o, void *bs) { o(bs, "_2", _2, b_S); }
void a_b_S(pith_t o, void *bs) { o(bs, "a", a, _b_S); }
void Sa_b_S(pith_t o, void *bs) { o(bs, "S", Sa_b_S, a_b_S); }

void n13(pith_t o, void *bs) {
  P("_aa", C(0, C(0, C(0, 0))), C(S, 0), C(n16, ...));
  o(bs, "_3", _3, 0);
}
void n14(pith_t o, void *bs) {
  P("baa", C(0, C(0, 0)), C(S, 0), C(n16, ...));
  o(bs, "b", b, n13);
}
void n15(pith_t o, void *bs) { o(bs, "_2", _2, n14); }
void n16(pith_t o, void *bs) { o(bs, "a", a, n15); }
void S(pith_t o, void *bs) {
  P("baa", C(0, 0), C(S, 0), C(n19, C($, 0)));
  void **rec = C(n16, 0);
  rec[1] = rec;
  o(bs, "S", S, n16);
}

void n19(pith_t o, void *bs) { o(bs, "_1", _1, 0); }
void G(pith_t o, void *bs) {
  P("baa", 0, C(G, 0), C($, 0));
  o(bs, "S", S, n19);
}
