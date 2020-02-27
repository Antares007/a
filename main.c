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
typedef struct {

} state_t;
void a_pith(void *s_, const char *n, void *h_, void *t_) { //
  void **s = s_;
  void (*o)(void *, ...) = *s++;
  const char *mode = *s++;
  const char *in = *s++;
  void **ltail = *s++;
  void **tail = *s++;
  variable_t t = (variable_t)t_;
  if (1) {
    o("%s\t%.7s\t%s\t", mode, n, in);
    if (t)
      t(print_pith, o);
    void **list = tail;
    o(" [");
    for (; list; list = list[1]) {
      ((variable_t)(*list))(print_pith, o);
      if (list[1])
        o(", ");
    };
    o("]");
    list = ltail;
    o(" [");
    for (; list; list = list[1]) {
      ((variable_t)(*list))(print_pith, o);
      if (list[1])
        o(", ");
    };
    o("]\n");
  } else
    o("\n");
  if (mode == skip) {
    if ('_' != *n)
      t(a_pith, s_);
    else if (t)
      t(a_pith, (const void *[]){o, first, in, ltail, tail});
    else if (tail)
      ((variable_t)tail[0])(a_pith,
                            (const void *[]){o, mode, in, ltail, tail[1]});
    else
      o("error: cant skip\n");
  } else if ('a' <= *n && *n <= 'z') {
    terminal_t h = h_;
    int len = 9;
    h(&len, in);
    if (len > -1)
      t(a_pith, (const void *[]){o, follow, in + len, ltail, tail});
    else if (mode == first)
      t(a_pith, (const void *[]){o, skip, in, ltail, tail});
    // else if (ltail)
    //  o("hmm");
    else
      o("error aa\n");
  } else if ('A' <= *n && *n <= 'Z') {
    variable_t h = h_;
    void **nltail = ltail;
    void **ntail = tail;
    int is_lrhead = 0;
    if (mode == first)
      while (ntail) {
        nltail = (void *[]){ntail[0], nltail};
        is_lrhead = ntail[0] == t;
        ntail = ntail[1];
        if (is_lrhead)
          break;
      }
    if (is_lrhead) {
      o("!!");
      t(a_pith, (const void *[]){o, skip, in, nltail, ntail});
    } else
      h(a_pith, (const void *[]){o, first, in, ltail, (void *[]){t, tail}});
  } else if ('_' == *n) {
    if (tail)
      ((variable_t)tail[0])(a_pith,
                            (const void *[]){o, follow, in, ltail, tail[1]});
    else if (ltail && mode == follow) {
      o("??");
      ((variable_t)ltail[0])(a_pith,
                             (const void *[]){o, first, in, ltail, ltail[1]});
    } else
      o(*in == 0 ? "accept\n" : "bccept\n");
  } else {
    o("error\n");
  };
}

// clang-format off
#include "t.h"
void _2(){}
void _1(){}
// S -> Sa/b
//N(0,
// _2,        L)N(L,
//  b,        L)N(L,
// _1,        L)N(L,
//  a,        L)N(L,
//  S,        S)
//void S_(pith_t, void *);
//void _3(){}
//void _2(){}
//void _1(){}
// S -> bS'
// S' -> aS' / a
//N(0,
// _3,        L)N(L,
//  eps,      L)N(L,
// _2,        L)N(L,
//  S_,       L)N(L,
//  a,        S_)
//N(0,
// _1,        L)N(L,
//  S_,       L)N(L,
//  b,        S)
//N(0,
// _2,        L)N(L,
//  b,        L)N(L,
// _1,        L)N(L,
//  a,        L)N(L,
//  S,        S)
void SS(pith_t o,void*);
N(0,
 _2,        L)N(L,
  b,        L)N(L,
 _1,        L)N(L,
  a,        L)N(L,
  SS,       L)N(L,
  a,        SS)
#include "g43.h"
#include <stdio.h>
int main() {
  variable_t v = SS;
  const char *text = "aabaa";
  print(v);
  printf("Parse: %s\n_______________\n", text);
  v(a_pith, (const void *[]){printf, first, text, 0, 0});
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
