#include "n.h"

typedef void (*variable_t)(pith_t, void *);
typedef void (*terminal_t)(int *, const char *);
typedef void (*reducer_t)();

inline int contains(void **list, void *value);
inline void ident_print(int ident, const char *n);

void traverse_pith(void *b_, const char *n, void *h, void *t) {
  void **b = b_;
  int *ident = b[0];
  void **path = b[1];
  ident_print(*ident, n);
  if ('A' <= *n && *n <= 'Z') {
    b_ = (void *[]){b[0], (void *[]){h, path}};
    if (!contains(path, h))
      ((*ident)++, ((variable_t)h)(traverse_pith, b_), (*ident)--);
  }
  if (t)
    ((variable_t)t)(traverse_pith, b_);
}
void print(variable_t g) {
  int ident = 0;
  g(traverse_pith, (void *[]){&ident, (void *[]){g, 0}});
}

void print_pith(void *b, const char *n, void *h, void *t) {
  void (*o)(void *, ...) = b;
  if (t) {
    o("%s.", n);
    ((variable_t)t)(print_pith, b);
  } else
    o("%s", n);
}
static const char *first = "first";
static const char *follow = "follow";
static const char *skip = "skip";
void a_pith(void *s_, const char *n, void *h_, void *t_) { //
  void **s = s_;
  void (*o)(void *, ...) = *s++;
  const char *mode = *s++;
  const char *in = *s++;
  variable_t *tail = *s++;
  variable_t t = (variable_t)t_;

  o("%.7s\t%s\t", n, in);
  if (t)
    t(print_pith, o);
  void **list = (void *)tail;
  o(" [");
  for (; list; list = list[1]) {
    ((variable_t)(*list))(print_pith, o);
    if (list[1])
      o(", ");
  };
  o("]\n");

  if (mode == skip) {
    if ('_' != *n)
      t(a_pith, s_);
    else if (t)
      t(a_pith, (const void *[]){o, first, in, tail});
    else if (tail)
      tail[0](a_pith, (const void *[]){o, mode, in, tail[1]});
    else
      o("error: cant skip\n");
  } else if ('a' <= *n && *n <= 'z') {
    terminal_t h = h_;
    int len = 9;
    h(&len, in);
    if (len > -1)
      t(a_pith, (const void *[]){o, follow, in + len, tail});
    else if (mode == first)
      t(a_pith, (const void *[]){o, skip, in, tail});
    else
      o("error\n");
  } else if ('A' <= *n && *n <= 'Z') {
    variable_t h = h_;
    if (contains((void **)tail, t)) {
      t(a_pith, (const void *[]){o, skip, in, tail});
    } else {
      h(a_pith, (const void *[]){o, first, in, (void *[]){t, tail}});
    }
  } else if ('_' == *n) {
    if (tail)
      tail[0](a_pith, (const void *[]){o, follow, in, tail[1]});
    else
      o(*in == 0 ? "accept\n" : "bccept\n");
  } else {
    o("error\n");
  };
}

// clang-format off
#include "g42.h"
void _1() {}
void _2() {}
N(0,
 _2,        L)N(L,
  b,        L)N(L,
 _1,        L)N(L,
  a,        L)N(L,
  S,        S)
#include <stdio.h>
int main() {
  print(S);
  const char *text = "baaaa";
  printf("Parse: %s\n_______________\n", text);
  S(a_pith, (const void *[]){printf, first, text, 0});
  return 9;
}

void ident_print(int ident, const char *n) {
  while (ident--)
    printf(". . ");
  printf("%s\n", n);
}

int contains(void **list, void *value) {
  for (; list; list = list[1])
    if (list[0] == value)
      return 1;
  return 0;
}
void _Eid() { printf("E -> id\n"); }
void _EEplusE() { printf("E -> E plus E\n"); }

void _EEplusT() { printf("E->EplusT\n"); }
void _ET() { printf("E->T\n"); }
void _TTmulF() { printf("T->TmulF\n"); }
void _TF() { printf("T->F\n"); }
void _FlpErp() { printf("F->lpErp\n"); }
void _Fid() { printf("F->id\n"); }
void _T_eps() { printf("T_->eps\n"); }
void _T_mulFT_() { printf("T_->mulFT_\n"); }
void _TFT_() { printf("T->FT_\n"); }
void _E_eps() { printf("E_->eps\n"); }
void _E_plusTE_() { printf("E_->plusTE_\n"); }
void _ETE_() { printf("E->TE_\n"); }

void _SAA() { printf("S->AA\n"); }
void _AaA() { printf("A->aA\n"); }

void _Ab() { printf("A->b\n"); }
void _BS() { printf("B->S"); }
void _Aa() { printf("A->a"); }
void _ABb() { printf("A->Bb"); }
void _SA() { printf("S->A"); }
