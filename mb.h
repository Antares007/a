#pragma once
typedef void (*pith_t)(void *, const char *, void *, void *);

#define CONCAT_IMP(a, b) a##b
#define CONCAT(a, b) CONCAT_IMP(a, b)
#define CONCAT3_IMP(a, b, c) a##b##c
#define CONCAT3(a, b, c) CONCAT3_IMP(a, b, c)

#define CCP(n) #n
#define P CONCAT(N, __LINE__)
#define S__(tail, head, type, name)                                            \
  static void name(void *b, pith_t o, void *a) { o(b, #type, head, tail); }
#define S_(tail, head, type, name) S__(tail, head, type, name)
#define S(tail, head, type, name)                                              \
  S_(tail, type(head), CONCAT3(type, _, head), name)

#define RGB(name) void T(name)(int *o, const char *b)
#define RGC(name, c)                                                           \
  RGB(name) { *o = *b == c ? 1 : -1; }

#define G(n) CONCAT3(N, G_, n)
#define T(n) CONCAT3(N, T_, n)
#define A(n) CONCAT3(N, A_, n)
