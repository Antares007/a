#pragma once
typedef void (*pith_t)(void *, const char *, void *, void *);

#define CONCAT_IMP(a, b) a##b
#define CONCAT(a, b) CONCAT_IMP(a, b)
#define CONCAT3_IMP(a, b, c) a##b##c
#define CONCAT3(a, b, c) CONCAT3_IMP(a, b, c)

#define CCP(n) #n
#define P CONCAT(N, __LINE__)
#define S__(b, a, t, n)                                                        \
  static void n(pith_t o, void *s) { o(s, #t, a, b); }
#define S_(b, a, t, n) S__(b, a, t, n)
#define S(b, a, t, n) S_(b, t(a), CONCAT3(t, _, a), n)

#define RGB(name) void T(name)(int *o, const char *b)
#define RGC(name, c)                                                           \
  RGB(name) { *o = *b == c ? 1 : -1; }

#define G(n) CONCAT3(N, G_, n)
#define T(n) CONCAT3(N, T_, n)
#define A(n) CONCAT3(N, A_, n)
