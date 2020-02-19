typedef void (*pith_t)(void *, const char *, void *, void *);
typedef void (*bark_t)(pith_t, void *);

void _() {}
void id() {}
void plus() {}
void mul() {}
void lparen() {}
void rparen() {}
void E(pith_t, void *);
void T(pith_t, void *);
void F(pith_t, void *);

#define CONCAT_IMP(a, b) a##b
#define CONCAT(a, b) CONCAT_IMP(a, b)
#define AUTO(n) CONCAT(n, __LINE__)
#define N AUTO(t)
#define L(t, a, name)                                                          \
  void name(pith_t o, void *s) { o(s, #a, a, t); }
// clang-format off
L(0,
    _,      N)L(N,
    id,     N)L(N,
    _,      N)L(N,
    rparen, N)L(N,
    E,      N)L(N,
    lparen, F)
L(0,
    _,      N)L(N,
    F,      N)L(N,
    _,      N)L(N,
    F,      N)L(N,
    mul,    N)L(N,
    T,      T)
L(0,
    _,      N)L(N,
    T,      N)L(N,
    _,      N)L(N,
    T,      N)L(N,
    plus,   N)L(N,
    E,      E)

