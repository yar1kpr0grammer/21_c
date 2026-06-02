#include "utils.h"
#include <stdio.h>

int main() {
  int number1;
  int number2;

  if (!input2ints(&number1, &number2)) {
    puts("n/a");
  }

  int sum = number1 + number2;
  int dif = number1 - number2;
  int mult = number1 * number2;
  if (number2 != 0) {
    int quo = number1 / number2;
    printf("%d %d %d %d\n", sum, dif, mult, quo);
  } else {
    printf("%d %d %d n/a\n", sum, dif, mult);
  }

  return 0;
}
