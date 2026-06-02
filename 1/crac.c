#include "utils.h"
#include <math.h>
#include <stdio.h>

int main() {
  double x;
  double y;

  if (!input2doubles(&x, &y)) {
    puts("n/a");
  }

  if (pow(x, 2) + pow(y, 2) <= 25) {
    puts("GOTCHA");
  } else {
    puts("MISS");
  }

  return 0;
}
