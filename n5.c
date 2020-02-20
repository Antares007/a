#define CONCAT_IMP(a, b) a##b
#define CONCAT(a, b) CONCAT_IMP(a, b)
#define AUTO(n) CONCAT(n, __LINE__)
#define RG(name, c)                                                            \
  void name(int *o, const char *b) { *o = *b == c ? 1 : -1; }

typedef void (*pith_t)(void *, const char *, void *, void *);
typedef void (*bark_t)(pith_t, void *);

void _() {}
void E(pith_t, void *);
void T(pith_t, void *);
void F(pith_t, void *);

void id(int *o, const char *b) {
  int i = 0;
  while ('a' <= b[i] && b[i] <= 'z')
    i++;
  *o = i > 0 ? i : -1;
}
RG(plus, '+')
RG(mult, '*')
RG(rpar, ')')
RG(lpar, '(')

#define N AUTO(t)
#define L(t, a, name)                                                          \
  void name(pith_t o, void *s) { o(s, #a, a, t); }

// clang-format off
L(0, _,    N)L(N,
     id,   N)L(N,
     _,    N)L(N,
     rpar, N)L(N,
     E,    N)L(N,
     lpar, F)
L(0, _,    N)L(N,
     F,    N)L(N,
     _,    N)L(N,
     F,    N)L(N,
     mult, N)L(N,
     T,    T)
L(0, _,    N)L(N,
     T,    N)L(N,
     _,    N)L(N,
     T,    N)L(N,
     plus, N)L(N,
     E,    E)
