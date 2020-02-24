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

void E(void *, pith_t);

void _Eid();
void _EEplusE();

void n9(void *bs, pith_t o) { //
  o(bs, "_Eid", _Eid, 0);
}
void n10(void *bs, pith_t o) { //
  o(bs, "id", id, n9);
}
void n11(void *bs, pith_t o) { //
  o(bs, "_EEplusE", _EEplusE, n10);
}
void n12(void *bs, pith_t o) { //
  o(bs, "E", E, n11);
}
void n13(void *bs, pith_t o) { //
  o(bs, "plus", plus, n12);
}
void E(void *bs, pith_t o) { //
  o(bs, "E", E, n13);
}
