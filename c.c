typedef void (*pith)(void *, const char *, ...);
typedef void (*bark)(pith, void *);

void lparen_r(int *o, const char *b) { *o = b[0] == '(' ? 1 : -1; }
void lparen(pith o, void *s) {
  const char *n = "R"
                  "lparen";
  o(s, n, lparen_r);
}
void rparen_r(int *o, const char *b) { *o = b[0] == ')' ? 1 : -1; }
void rparen(pith o, void *s) {
  const char *n = "R"
                  "rparen";
  o(s, n, rparen_r);
}
void plus_r(int *o, const char *b) { *o = b[0] == '+' ? 1 : -1; }
void plus(pith o, void *s) {
  const char *n = "R"
                  "plus";
  o(s, n, plus_r);
}
void mul_r(int *o, const char *b) { *o = b[0] == '*' ? 1 : -1; }
void mul(pith o, void *s) {
  const char *n = "R"
                  "mul";
  o(s, n, mul_r);
}
void dollar_r(int *o, const char *b) { *o = b[0] == '\0' ? 1 : -1; }
void dollar(pith o, void *s) {
  const char *n = "R"
                  "dollar";
  o(s, n, dollar_r);
}
void id_r(int *o, const char *b) {
  int i = 0;
  while ('a' <= b[i] && b[i] <= 'z')
    ++i;
  *o = i ? i : -1;
}
void id(pith o, void *s) {
  const char *n = "R"
                  "id";
  o(s, n, id_r);
}

void E(pith, void *);
void T(pith, void *);
void F(pith, void *);

void E0_l22(pith o, void *s) {
  const char *n = "L"
                  "E0"
                  "_l22";
  o(s, n, T, 0);
}
void E0_l12(pith o, void *s) {
  const char *n = "L"
                  "E0"
                  "_l12";
  o(s, n, plus, E0_l22);
}
void E0(pith o, void *s) {
  const char *n = "L"
                  "E0"
                  "_l02";
  o(s, n, E, E0_l12);
}
void E1(pith o, void *s) {
  const char *n = "L"
                  "E1"
                  "_l00";
  o(s, n, T, 0);
}
void E_l11(pith o, void *s) {
  const char *n = "L"
                  "E"
                  "_l11";
  o(s, n, E1, 0);
}
void E(pith o, void *s) {
  const char *n = "L"
                  "E"
                  "_l01";
  o(s, n, E0, E_l11);
}

void T0_l22(pith o, void *s) {
  const char *n = "L"
                  "T0"
                  "_l22";
  o(s, n, F, 0);
}
void T0_l12(pith o, void *s) {
  const char *n = "L"
                  "T0"
                  "_l12";
  o(s, n, mul, T0_l22);
}
void T0(pith o, void *s) {
  const char *n = "L"
                  "T0"
                  "_l02";
  o(s, n, T, T0_l12);
}
void T1(pith o, void *s) {
  const char *n = "L"
                  "T1"
                  "_l00";
  o(s, n, F, 0);
}
void T_l11(pith o, void *s) {
  const char *n = "L"
                  "T"
                  "_l11";
  o(s, n, T1, 0);
}
void T(pith o, void *s) {
  const char *n = "L"
                  "T"
                  "_l01";
  o(s, n, T0, T_l11);
}

void F0_l22(pith o, void *s) {
  const char *n = "L"
                  "F0"
                  "_l22";
  o(s, n, rparen, 0);
}
void F0_l12(pith o, void *s) {
  const char *n = "L"
                  "F0"
                  "_l12";
  o(s, n, E, F0_l22);
}
void F0(pith o, void *s) {
  const char *n = "L"
                  "F0"
                  "_l02";
  o(s, n, lparen, F0_l12);
}
void F1(pith o, void *s) {
  const char *n = "L"
                  "F1"
                  "_l00";
  o(s, n, id, 0);
}
void F_l11(pith o, void *s) {
  const char *n = "L"
                  "F"
                  "_l11";
  o(s, n, F1, 0);
}
void F(pith o, void *s) {
  const char *n = "L"
                  "F"
                  "_l01";
  o(s, n, F0, F_l11);
}
