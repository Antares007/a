#pragma once

#ifndef STYPE
#define STYPE void
#endif

typedef void (*pith)(STYPE *, const char *, ...);
typedef void (*bark)(pith, STYPE *);

#define RG(name, body)                                                         \
  void name##_r(int *o, const char *b) body void name(pith o, STYPE *s) {      \
    const char *n = "R" #name;                                                 \
    o(s, n, name##_r);                                                         \
  }
#define RSymbol(s)                                                             \
  { *o = b[0] == s ? 1 : -1; }

#define L1(name, a)                                                            \
  void name(pith o, STYPE *s) {                                                \
    const char *n = "L" #name "_l00";                                          \
    o(s, n, a, 0);                                                             \
  }
#define L2(name, a, b)                                                         \
  void name##_l11(pith o, STYPE *s) {                                          \
    const char *n = "L" #name "_l11";                                          \
    o(s, n, b, 0);                                                             \
  }                                                                            \
  void name(pith o, STYPE *s) {                                                \
    const char *n = "L" #name "_l01";                                          \
    o(s, n, a, name##_l11);                                                    \
  }

#define L3(name, a, b, c)                                                      \
  void name##_l22(pith o, STYPE *s) {                                          \
    const char *n = "L" #name "_l22";                                          \
    o(s, n, c, 0);                                                             \
  }                                                                            \
  void name##_l12(pith o, STYPE *s) {                                          \
    const char *n = "L" #name "_l12";                                          \
    o(s, n, b, name##_l22);                                                    \
  }                                                                            \
  void name(pith o, STYPE *s) {                                                \
    const char *n = "L" #name "_l02";                                          \
    o(s, n, a, name##_l12);                                                    \
  }
