typedef void (*pith_t)(void *, const char *, void *, void *);

void a(int *o, const char *b) { *o = *b == 'a' ? 1 : -1; }
void b(int *o, const char *b) { *o = *b == 'b' ? 1 : -1; }
void eps(int *o, const char *b) { *o = 0; }
void S(void *, pith_t);
void A(void *, pith_t);
void _3();
void _2();
void _1();

void n14(void *bs, pith_t o) {
  o(bs, "_3", _3, 0);
  //
}
void A(void *bs, pith_t o) {
  o(bs, "a", a, n14);
  //
}

void n17(void *bs, pith_t o) {
  o(bs, "_2", _2, 0);
  //
}
void n18(void *bs, pith_t o) {
  o(bs, "eps", eps, n17);
  //
}
void n19(void *bs, pith_t o) {
  o(bs, "_1", _1, n18);
  //
}
void n20(void *bs, pith_t o) {
  o(bs, "A", A, n19);
  //
}
void S(void *bs, pith_t o) {
  o(bs, "S", S, n20);
  //
}
