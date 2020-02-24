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

RGB(theend) { *o = -*b; }
void _theend() { printf("the end\n"); }
N(0, _theend, End);
N(End, theend, TheEnd);

// b :: [void*, pith_t]
void skip_pith(void *b_, const char *n, void *h, void *t) { //
  if (is_reducer(n)) {
    if (t) {
      void **b = b_;
      ((variable_t)t)(b[0], (pith_t)b[1]);
    } else
      printf("error: cant skip\n");
  } else
    ((variable_t)t)(b_, skip_pith);
}
void lolr_pith(void *b_, const char *n, void *h, void *t) {
  void **b = b_;
  const char *in = b[0];
  void **tail = b[1];
  void **lpath = b[2];
  // printf("%s %s\n", n, in);
  if (is_terminal(n)) {
    int len = 9;
    ((terminal_t)h)(&len, in);
    if (len < 0) {
      ((variable_t)t)((void *[]){b_, lolr_pith}, skip_pith);
    } else {
      ((variable_t)t)((const void *[]){in + len, tail, 0}, lolr_pith);
    }
  } else if (is_var(n)) {
    if (contains(lpath, h)) {
      ((variable_t)t)((void *[]){(const void *[]){in, tail, 0}, lolr_pith},
                      skip_pith);
    } else {
      ((variable_t)h)(
          (const void *[]){in, (void *[]){t, tail}, (void *[]){h, lpath}},
          lolr_pith);
    }
  } else {
    ((reducer_t)h)();
    if (tail)
      ((variable_t)tail[0])(
          (const void *[]){in, tail[1], (void *[]){tail[0], 0}}, lolr_pith);
    else if (*in == '\0')
      printf("accept!\n");
    else
      printf("error!\n");
  }
}
void lolr(variable_t g, const char *in) { //
  g((const void *[]){in, 0, 0}, lolr_pith);
}
#include "g42.h"
int main() {
  print(E);
  const char *text = "a+b*b";
  printf("\n\nparse:\n");
  lolr(E, text);
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
