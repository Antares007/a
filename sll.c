typedef void (*pith_t)(void *, const char *, void *, void *);

void i(int *o, const char *b) {
  int i = 0;
  while ('a' <= b[i] && b[i] <= 'z')
    i++;
  *o = i > 0 ? i : -1;
}
void p(int *o, const char *b) { *o = *b == '+' ? 1 : -1; }
void m(int *o, const char *b) { *o = *b == '*' ? 1 : -1; }
void l(int *o, const char *b) { *o = *b == '(' ? 1 : -1; }
void r(int *o, const char *b) { *o = *b == ')' ? 1 : -1; }

void a(int *o, const char *b) { *o = *b == 'a' ? 1 : -1; }
void b(int *o, const char *b) { *o = *b == 'b' ? 1 : -1; }
void c(int *o, const char *b) { *o = *b == 'c' ? 1 : -1; }
void d(int *o, const char *b) { *o = *b == 'd' ? 1 : -1; }
void eps(int *o, const char *b) { *o = 0; }

void n12(pith_t o, void *bs);
void n13(pith_t o, void *bs);
void n14(pith_t o, void *bs);
void n15(pith_t o, void *bs);

void S(pith_t, void *);
void _3() {}
void _2() {}
void _1() {}

void P(int, ...);
typedef struct {
  const char *input;
  void **parsed;
  void **first_path;
  void **tail;
} configuration;
#define C(a, b)                                                                \
  (void *[]) { a, b }
void v_pith(void *a, const char *in, void *h, void *t){};
void print(configuration *c);

void n12(pith_t o, void *bs) { //
  o(bs, "_2", _2, 0);
}

void n13(pith_t o, void *bs) { //
  o(bs, "a", a, n13);
}

void n14(pith_t o, void *bs) { //
  o(bs, "S", S, n13);
}

void n15(pith_t o, void *bs) {
  configuration *c = bs;
  print(c);
  //// P(1, "_aa", C(a, 0), C(n15, 0), 0);
  void *h, *t;
  o(bs, "_1", h = _1, t = n14);
  S(v_pith, c);

  // int cant_reduce = *c->input != '\0' && !c->tail;
  // int x = cant_reduce && t;

  //// P(2, "_aa", C(a, 0), C(n15, 0), 0);
}

void S(pith_t o, void *bs) {
  static int i = 0;
  if (i++ == 1)
    return print(bs);
  configuration *c = bs;
  print(c);
  o(bs, "a", a, n15);
  c->input++;
  c->parsed = C(a, c->parsed);
  n15(v_pith, c);
}
void ppith(void *vb, const char *n, void *h, void *t) {
  void **b = vb;
  //
}
typedef void (*var_t)(pith_t, void *);
void ring(pith_t o, void *vb) {
  void **b = vb;
  var_t v = b[0];
  v(ppith, C(o, C(v, b[1])));
}

int main() {
  configuration config = {.input = "aaa", .first_path = C(S, 0)};
  S(v_pith, &config);
}
extern int printf(const char *restrict __format, ...);
#define printname(p)                                                           \
  printf(p == _1                                                               \
             ? "_1"                                                            \
             : p == _2                                                         \
                   ? "_2"                                                      \
                   : p == n12                                                  \
                         ? "n12"                                               \
                         : p == n13                                            \
                               ? "n13"                                         \
                               : p == n14                                      \
                                     ? "n14"                                   \
                                     : p == n15                                \
                                           ? "n15"                             \
                                           : p == S ? "S"                      \
                                                    : p == a ? "a" : "error!")
void printlist(void **list) { //
  printf("[");
  for (; list; list = list[1]) {
    printname(*list);
    if (list[1])
      printf(", ");
  }
  printf("]");
}
void print(configuration *c) {
  printf("%s\t", c->input);
  printlist(c->parsed);
  printf("\t");
  printlist(c->first_path);
  printf("\t");
  printlist(c->tail);
  printf("\n");
}

// S: a
//  | Sa
//
//   S
//  Sa
// Saa
// aaa
