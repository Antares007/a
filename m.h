#pragma once
// clang-format off

typedef struct this {
  void (*o)(struct this*, const char *, void *, void *);
} pith_t;

#define NN_(a, b) a##b
#define NN(a, b) NN_(a, b)
#define N(tail, type, head, name)           \
  void name(pith_t *o) { o->o(o, type #head, head, tail); }
#define L NN(n, __LINE__)
#define TG(tail, t1, g2, n)                  \
  N(tail,                                    \
  "G", g2, NN(n, _g2))N(NN(n, _g2),          \
  "T", t1, n)
#define AG(tail, a1, g2, n)                  \
  N(tail,                                    \
  "G", g2, NN(n, _g2))N(NN(n, _g2),          \
  "A", a1, n)
#define AAAAG(tail, a1, a2, a3, a4, g5, n)   \
  N(tail,                                    \
  "G", g5, NN(n, _g5))N(NN(n, _g5),          \
  "A", a4, NN(n, _a4))N(NN(n, _a4),          \
  "A", a3, NN(n, _a3))N(NN(n, _a3),          \
  "A", a2, NN(n, _a2))N(NN(n, _a2),          \
  "A", a1, n)
#define TAAG(tail, t1, a2, a3, g4, n)        \
  N(tail,                                    \
  "G", g4, NN(n, _g4))N(NN(n, _g4),          \
  "A", a3, NN(n, _a3))N(NN(n, _a3),          \
  "A", a2, NN(n, _a2))N(NN(n, _a2),          \
  "T", t1, n)
#define TAG(tail, t1, a2, g3, n)             \
  N(tail,                                    \
  "G", g3, NN(n, _g3))N(NN(n, _g3),          \
  "A", a2, NN(n, _a2))N(NN(n, _a2),          \
  "T", t1, n)
#define AAG(tail, a1, a2, g3, n) \
  N(tail,                                    \
  "G", g3, NN(n, _g3))N(NN(n, _g3),          \
  "A", a2, NN(n, _a2))N(NN(n, _a2),          \
  "A", a1, n)
