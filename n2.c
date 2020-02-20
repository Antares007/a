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
/* clang-format off */
#define CONCAT_IMP(a,b) a##b
#define CONCAT(a,b) CONCAT_IMP(a,b)
#define CCP(n) #n
#define N_(n, t, a, b)                                                             \
  void n(pith_t o, void *s) { o(s, CCP(t), a, b); }
#define N(b, a, n) N_(n, CONCAT(n, a), a, b)
#define C(b, a) N_(a, C, a, b)
#define G CONCAT(G, __LINE__ )
#define A CONCAT(A, __LINE__ )
#define T CONCAT(T, __LINE__ )

N(0, noop   , G)N(G,
     id     , T)N(T,
     noop   , G)N(G,
     rparen , T)N(T,
     expr   , A)N(A,
     lparen , T)C(T, fact)
N(0, noop   , G)N(G,
     fact   , A)N(A,
     noop   , G)N(G,
     fact   , A)N(A,
     mul    , T)C(T, term)
N(0, noop   , G)N(G, 
     term   , A)N(A, 
     noop   , G)N(G, 
     term   , A)N(A, 
     plus   , T)C(T, expr)

int main(){return 9;}
