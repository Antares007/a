typedef void (*pith_t)(void *, const char *, void *, void *);
typedef void (*bark_t)(pith_t, void *);

void noop() {}
void id() {}
void plus() {}
void mul() {}
void lparen() {}
void rparen() {}
void expr(pith_t, void *);
void term(pith_t, void *);
void fact(pith_t, void *);

#define CONCAT_IMP(a, b) a##b
#define CONCAT(a, b) CONCAT_IMP(a, b)

#define CCP(n) #n
#define L __LINE__
#define N(n, t, a, b)                                                          \
  void n(pith_t o, void *s) { o(s, CCP(t), a, b); }

#define G(a, l) N(CONCAT(G, l), G, a, 0)
#define GA(t, a, l) N(CONCAT(A, l), A, a, CONCAT(G, t))
#define GT(t, a, l) N(CONCAT(T, l), T, a, CONCAT(G, t))
#define AT(t, a, l) N(CONCAT(T, l), T, a, CONCAT(A, t))
#define AG(t, a, l) N(CONCAT(G, l), G, a, CONCAT(A, t))
#define TA(t, a, l) N(CONCAT(A, l), A, a, CONCAT(T, t))
#define TG(t, a, l) N(CONCAT(G, l), G, a, CONCAT(T, t))
#define AC(t, a) N(a, C, a, CONCAT(A, t))
#define TC(t, a) N(a, C, a, CONCAT(T, t))

// clang-format off
G(      noop, 
L)GT(L, id,
L)TG(L, noop,
L)GT(L, rparen,
L)TA(L, expr, 
L)AT(L, lparen, 
L)TC(L, fact)

G(      noop, 
L)GA(L, fact, 
L)AG(L, noop, 
L)GA(L, fact, 
L)AT(L, mul, 
L)TC(L, term)

G(      noop, 
L)GA(L, term,
L)AG(L, noop,
L)GA(L, term,
L)AT(L, plus,
L)TC(L, expr)

int main() { //
  return 9;
}
