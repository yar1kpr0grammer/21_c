#include <math.h>
#include <stdio.h>

int main() {
  double x, result;

  if (scanf("%lf", &x) != 1) {
    printf("n/a\n");
    return 0;
  }

  // Проверка на деление на ноль (x^2 / 2 != 0)
  if (x == 0) {
    puts("n/a");
    return 0;
  }

  // Проверка области определения:
  // 1) x^(1/3) - кубический корень определен для всех x
  // 2) (10 + x)^(2/x) требует x != 0 и 10 + x > 0
  if (x == 0 || (10 + x) <= 0) {
    puts("n/a");
    return 0;
  }

  // Вычисление функции
  double term1 = 7e-3 * pow(x, 4);
  double term2 = (22.8 * cbrt(x) - 1e3) * x + 3;
  double term3 = pow(x, 2) / 2;
  double term4 = x * pow(10 + x, 2 / x);

  result = term1 + (term2 / term3) - term4 - 1.01;

  // Вывод результата с одной цифрой после запятой
  printf("%.1lf\n", result);

  return 0;
}
