#include "utils.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isint(double num) {
  double int_part;

  if (modf(num, &int_part) == 0.0) {
    return true;
  } else {
    return false;
  }
}

double bigger(double a, double b) {
  if (a < b) {
    return b;
  }
  return a;
}

int main() {
  double number1;
  double number2;

  if (!input2doubles(&number1, &number2)) {
    puts("n/a");
    return 0;
  }

  if (!isint(number1) || !isint(number2)) {
    puts("n/a");
    return 0;
  }

  double big = bigger(number1, number2);
  printf("%.0f\n", big);

  return 0;
}
