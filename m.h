#pragma once
// clang-format off

typedef void (*pith_t)(void *, const char *, void *, void *);

#define NN_(a, b) a##b
#define NN(a, b) NN_(a, b)
#define N(tail, type, head, name)           \
  void name(pith_t o, void *vs) { o(vs, type, head, tail); }
#define L NN(n, __LINE__)
#define TG(tail, t1, g, n)                  \
  N(tail, "G", g, NN(g_, n))N(NN(g_, n),    \
          "T", t1, n)
#define AG(tail, a1, g, n)                  \
  N(tail, "G", g, NN(g_, n))N(NN(g_, n),    \
          "A", a1, n)
#define AAAAG(tail, a1, a2, a3, a4, g, n)   \
  N(tail, "G", g,  NN(g_,  n))N(NN(g_,  n), \
          "A", a4, NN(a4_, n))N(NN(a4_, n), \
          "A", a3, NN(a3_, n))N(NN(a3_, n), \
          "A", a2, NN(a2_, n))N(NN(a2_, n), \
          "A", a1, n)
#define TAAG(tail, t1, a2, a3, g, n)        \
  N(tail, "G", g,  NN(g_,  n))N(NN(g_,  n), \
          "A", a3, NN(a3_, n))N(NN(a3_, n), \
          "A", a2, NN(a2_, n))N(NN(a2_, n), \
          "T", t1, n)
#define TAG(tail, t1, a2, g, n)             \
  N(tail, "G", g,  NN(g_,  n))N(NN(g_,  n), \
          "A", a2, NN(a2_, n))N(NN(a2_, n), \
          "T", t1, n)
#define AAG(tail, a1, a2, g, n) \
  N(tail, "G", g,  NN(g_,  n))N(NN(g_,  n), \
          "A", a2, NN(a2_, n))N(NN(a2_, n), \
          "A", a1, n)
