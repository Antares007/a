#pragma once
typedef void (*pith_t)(void *, const char *, void *, void *);

#define NN_(a, b) a##b
#define NN(a, b) NN_(a, b)
#define N(t, a, n)                                                             \
  void n(pith_t o, void *bs) { o(bs, #a, a, t); }
#define L NN(n, __LINE__)
#define RGB(name) void name(int *o, const char *b)
#define RGC(name, c)                                                           \
  RGB(name) { *o = *b == c ? 1 : -1; }
