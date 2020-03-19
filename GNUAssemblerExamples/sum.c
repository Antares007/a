/*
 * callsum.c
 *
 * Illustrates how to call the sum function we wrote in assembly language.
 */
#include <stdio.h>

double sum(double[], unsigned);

int main() {
  double test[] = {40.5, 26.7, 21.9, 1.5, -40.5, -23.4};
  printf("%20.7f\n", sum(test, 6));
  printf("%20.7f\n", sum(test, 2));
  printf("%20.7f\n", sum(test, 0));
  printf("%20.7f\n", sum(test, 3));
  return 0;
}
//$ clang callsum.c sum.s && ./a.out
//          26.7000000
//          67.2000000
//           0.0000000
//          89.1000000
