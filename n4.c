// clang-format off
typedef void (*pith_t)(void *, const char *, void *, void *);
typedef void (*bark_t)(pith_t, void *);

#define CONCAT_IMP(a, b) a##b
#define CONCAT(a, b) CONCAT_IMP(a, b)

#define CCP(n) #n
#define N(b, a, n)                                                             \
  void n(pith_t o, void *s) { o(s, CCP(n), a, b); }

#define L __LINE__

void noop() {}
void id() {}
void plus() {}
void mul() {}
void lparen() {}
void rparen() {}
void expr(pith_t, void *);
void term(pith_t, void *);
void fact(pith_t, void *);

#define G(a, l)     N(0,            a, CONCAT(G, l))
#define GA(t, a, l) N(CONCAT(G, t), a, CONCAT(A, l))
#define GT(t, a, l) N(CONCAT(G, t), a, CONCAT(T, l))

#define AT(t, a, l) N(CONCAT(A, t), a, CONCAT(T, l))
#define AG(t, a, l) N(CONCAT(A, t), a, CONCAT(G, l))

#define TA(t, a, l) N(CONCAT(T, t), a, CONCAT(A, l))
#define TG(t, a, l) N(CONCAT(T, t), a, CONCAT(G, l))

#define AC(t, a)    N(CONCAT(A, t), a, a)
#define TC(t, a)    N(CONCAT(T, t), a, a)
#define CG(t, a, l) N(t,            a, CONCAT(G, l))

G(noop   ,L)GT(L,
  id     ,L)TG(L,
  noop   ,L)GT(L, 
  rparen ,L)TA(L,
  expr   ,L)AT(L,
  lparen ,L)TC(L, fact)
G(noop   ,L)GA(L,
  fact   ,L)AG(L,
  noop   ,L)GA(L, 
  fact   ,L)AT(L,
  mul    ,L)TA(L,
  term   ,L)AC(L, term)
G(noop   ,L)GA(L,
  term   ,L)AG(L,
  noop   ,L)GA(L, 
  term   ,L)AT(L,
  plus   ,L)TA(L,
  expr   ,L)AC(L, expr)  
  
//
int main() { //
  return 9;
}




