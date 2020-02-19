typedef void (*pith_t)(void *, const char *, void *, void *);
typedef void (*bark_t)(pith_t, void *);
#define CONCAT_IMP(a, b) a##b
#define CONCAT(a, b) CONCAT_IMP(a, b)
#define A(n) CONCAT(n, __LINE__)
void plus() {}
void mul() {}
void lparen() {}
void rparen() {}
void id() {}
void E(pith_t, void *);
void T(pith_t, void *);
void F(pith_t, void *);
#define N_(n) #n
#define N(n, a, b)                                                             \
  void n(pith_t o, void *s) { o(s, N_(a), a, b); }
#define N3(n, na, nb, nc)                                                      \
  N(A(c), nc, 0)                                                               \
  N(A(b), nb, A(c))                                                            \
  N(n, na, A(b))
#define N2(n, na, nb)                                                          \
  N(A(b), nb, 0)                                                               \
  N(n, na, A(b))
#define N1(n, a) N(n, a, 0)

N3(E0, E, plus, T)
N1(E1, T)
N2(E, E0, E1)

N3(T0, T, mul, F)
N1(T1, F)
N2(T, T0, T1)

N3(F0, lparen, E, rparen)
N1(F1, id)
N2(F, F0, F1)

int main() {
  //
  return 9;
}
