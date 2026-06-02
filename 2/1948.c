#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool myDiv(int a, int b, int output[2]) {
  output[0] = 0;
  output[1] = a;

  if (a < b) {
    return false;
  }

  while (a >= b) {
    a -= b;
    output[0] += 1;
    output[1] -= b;
  }

  return true;
}

bool isSimple(int a) {
  int divRes[2] = {0, 0};

  for (int i = 2; i < a; i++) {

    if (!myDiv(a, i, divRes)) {
      return false;
    }

    if (divRes[1] == 0) {
      return false;
    }
  }
  return true;
}

int findBiggestSimpleDivinder(int limit) {
  int res = -1;
  int divRes[2] = {0, 0};

  for (int i = 2; i < limit; i++) {
    myDiv(limit, i, divRes);
    if (isSimple(i) && divRes[1] == 0) {
      res = i;
    }
  }
  return res;
}

int main() {
  int a;
  if (!inputInt(&a)) {
    puts("n/a");
    return 0;
  }
  a = abs(a);

  int biggestSimpleDiv = findBiggestSimpleDivinder(a);
  printf("%d\n", biggestSimpleDiv);

  return 0;
}
