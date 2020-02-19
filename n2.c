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
#define N(b, a, n)                                                             \
  void n(pith_t o, void *s) { o(s, #n, a, b); }
#define G CONCAT(G, __LINE__ )
#define A CONCAT(A, __LINE__ )
#define T CONCAT(T, __LINE__ )
#define C CONCAT(C, __LINE__ )

N(0, noop   , G)N(G,
     id     , T)N(T,
     noop   , G)N(G,
     rparen , T)N(T,
     expr   , A)N(A,
     lparen , T)N(T,
     fact   , fact)

N(0, noop   , G)N(G,
     fact   , A)N(A,
     noop   , G)N(G,
     fact   , A)N(A,
     mul    , T)N(T,
     term   , term)

N(0, noop   , G)N(G, 
     term   , A)N(A, 
     noop   , G)N(G, 
     term   , A)N(A, 
     plus   , T)N(T,
     expr   , expr)

int main(){return 9;}
