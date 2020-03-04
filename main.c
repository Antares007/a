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

typedef enum { skip = -1, first = 0, follow = 1 } states;
typedef struct {
  void (*o)(void *, ...);
  const char *in;
  void **path;
  void **tail;
  states state;
} config_t;

void print_config(const config_t *c) {
  c->o("%d\t%.7s\t", c->state, c->in);
  void **list = c->path;
  c->o("path[");
  for (; list; list = list[1]) {
    ((variable_t)(*list))(print_pith, c->o);
    if (list[1])
      c->o(", ");
  };
  c->o("]");
  list = c->tail;
  c->o("tail[");
  for (; list; list = list[1]) {
    ((variable_t)(*list))(print_pith, c->o);
    if (list[1])
      c->o(", ");
  };
  c->o("]");
}
void a_pith(void *b, const char *n, void *h_, void *t_) { //
  config_t *c = b;
  variable_t t = (variable_t)t_;
  c->o("%s\t", n);
  print_config(c);
  c->o("\n");
  if (c->state == skip) {
    if ('_' != *n) {
      t(a_pith, c);
    } else if (t) {
      c->state = first;
      t(a_pith, c);
    } else if (c->tail) {
      c->tail = c->tail[1];
      ((variable_t)c->tail[0])(a_pith, c);
    } else {
      c->o("error: cant skip\n");
    }
  } else if ('a' <= *n && *n <= 'z') {
    terminal_t h = h_;
    int len = 9;
    h(&len, c->in);
    if (len > -1) {
      c->state = follow;
      c->in = c->in + len;
      t(a_pith, c);
    } else if (c->state == first) {
      c->state = skip;
      t(a_pith, (c));
    } else {
      c->o("error aa\n");
    }
  } else if ('A' <= *n && *n <= 'Z') {
    variable_t h = h_;
    c->state = first;
    c->path = (void *[]){h, c->path};
    c->tail = (void *[]){t, c->tail};
    h(a_pith, (c));
  } else if ('_' == *n) {
    if (c->tail) {
      variable_t g = c->tail[0];
      c->tail = c->tail[1];
      g(a_pith, c);
    } else {
      c->o(*c->in == 0 ? "accept\n" : "bccept\n");
    }
  } else {
    c->o("error\n");
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
  v(a_pith, &(config_t){.o=(void*)printf, .state=first, .in = text, .path = (void*[]){v, 0}, .tail = 0});
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
