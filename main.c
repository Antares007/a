#include "n.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

typedef void (*variable_t)(void *, pith_t);
typedef void (*terminal_t)(int *, const char *);
typedef void (*reducer_t)();

inline bool contains(void **list, void *value);
inline void ident_print(int ident, const char *n);

inline bool is_var(const char *n);
inline bool is_terminal(const char *n);
inline bool is_reducer(const char *n);

void traverse_pith(void *b_, const char *n, void *h, void *t) {
  void **b = b_;
  int *ident = b[0];
  void **path = b[1];
  ident_print(*ident, n);
  if (is_var(n)) {
    b_ = (void *[]){b[0], (void *[]){h, path}};
    if (!contains(path, h))
      ((*ident)++, ((variable_t)h)(b_, traverse_pith), (*ident)--);
  }
  if (t)
    ((variable_t)t)(b_, traverse_pith);
}
void print(variable_t g) {
  int ident = 0;
  g((void *[]){&ident, (void *[]){g, 0}}, traverse_pith);
}

#define CV(v) ((variable_t)v)
#define CT(v) ((terminal_t)v)
#define CR(v) ((reducer_t)v)
#define Nil 0
#define Cons(head, tail)                                                       \
  (void *[]) { head, tail }
#define Blolr(in, tail)                                                        \
  (const void *[]) { in, tail }
#define Bskip(b, pith)                                                         \
  (void *[]) { b, pith }
#define LOG(...) printf(__VA_ARGS__)
#define VSA(...)                                                               \
  (void *[]) { __VA_ARGS__ }
#define CVSA(...)                                                              \
  (const void *[]) { __VA_ARGS__ }

// b :: [void*, pith_t]
// clang-format off
void first_pith(void *b_, const char *n, void *h, void *t);
void skip_pith(void *sb_, const char *n, void *h, void *t) { //
  LOG("spith %s\n", n);
  if (is_reducer(n)) {
    void **sb = sb_;
    if (t) {
      CV(t)(sb[0], (pith_t)sb[1]);
    } else {
      void **fb = sb[0];
      const char *in = fb[0];
      void **tail = fb[1];
      if (tail)
        CV(tail[0])(VSA(CVSA(in, tail[1]), (pith_t)sb[1]), skip_pith);
      else
        printf("error: cant skip\n");
    }
  } else
    CV(t)(sb_, skip_pith);
}
void follow_pith(void *b_, const char *n, void *h, void *t) {
  void **b = b_;
  const char *in = b[0];
  void **tail = b[1];                                 LOG("follow\t%.7s\t%s\t", n, in);
  if (is_terminal(n)) {                               LOG("T\t");
    int len = 9;
    CT(h)(&len, in);
    if (len < 0) {                                    LOG("error\n");
    } else {                                          LOG("eat&follw\n");
      CV(t)(CVSA(in + len, tail), follow_pith);
    }
  } else if (is_var(n)) {                             LOG("V\tdelegate to first_pith\n");
    first_pith(b_, n, h, t);
  } else {                                            LOG("R\t");
    if(tail) {                                        LOG("reduce\n");
      CV(tail[0])(CVSA(in, tail[1]), follow_pith);
    } else if (*in == 0){                             LOG("accept\n");
    } else {                                          LOG("bccept\n");
    }
  }
}
void first_pith(void *b_, const char *n, void *h, void *t) { //
  void **b = b_;
  const char *in = b[0];
  void **tail = b[1];                                 LOG("first\t%.7s\t%s\t", n, in);
  if (is_terminal(n)) {                               LOG("T\t");
    int len = 9;
    CT(h)(&len, in);
    if (len < 0) {                                    LOG("skip\n");
      CV(t)(VSA(b_, first_pith), skip_pith);
    } else {                                          LOG("eat&follw\n");
      CV(t)(CVSA(in + len, tail), follow_pith);
    }
  } else if (is_var(n)) {                             LOG("V\t");
    if (contains(tail, t)) {                          LOG("Left recursion not implemented yet!\n");
      CV(t)(VSA(CVSA(in,  VSA(t, VSA(t, tail))), first_pith), skip_pith);
      //CV(t)(CVSA(in, VSA(t, tail)), first_pith);
    } else {                                          LOG("goin\n");
      CV(h)(CVSA(in, VSA(t, tail)), first_pith);
    }
  } else {                                            LOG("R\t");
                                                      LOG("error: first cant be reducer\n");
  }
}
void lolr(variable_t g, const char *in) { g(Blolr(in, Nil), first_pith); }
#include "gll.h"
int main() {
  print(S);
  const char *text = "aaa";
  printf("Parse: %s\n_______________\n", text);
  lolr(S, text);
  return 9;
}

bool is_var(const char *n) { return 'A' <= *n && *n <= 'Z'; }
bool is_reducer(const char *n) { return '_' == *n; }
bool is_terminal(const char *n) { return !is_var(n) && !is_reducer(n); }

void ident_print(int ident, const char *n) {
  while (ident--)
    printf(". . ");
  printf("%s\n", n);
}

bool contains(void **list, void *value) {
  for (; list; list = list[1])
    if (list[0] == value)
      return true;
  return false;
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
