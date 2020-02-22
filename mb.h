#pragma once
typedef void (*pith_t)(void *, const char *, void *, void *);

#define CONCAT_IMP(a, b) a##b
#define CONCAT(a, b) CONCAT_IMP(a, b)
#define CCP(n) #n

#define S__(tail, head, type, name)                                            \
  void name(void *b, pith_t o, void *a) { o(b, #type, head, tail); }
#define S_(tail, head, type, name) S__(tail, head, type, name)
#define S(tail, type, head, name) S_(tail, type(head), CONCAT(type, head), name)
#define P CONCAT(N, __LINE__)

#define G(n) CONCAT(N, CONCAT(G, n))
#define T(n) CONCAT(N, CONCAT(T, n))
#define A(n) CONCAT(N, CONCAT(A, n))

#define RGB(name) void T(name)(int *o, const char *b)
#define RGC(name, c)                                                           \
  RGB(name) { *o = *b == c ? 1 : -1; }
