#include <stdbool.h>
#include <stdio.h>

#define STRING_LENTH 128
typedef char string[STRING_LENTH];

void input(string str) { fgets(str, STRING_LENTH, stdin); }

#define DEFINE_INPUT_FUNC(fname, format, type1, type2)                         \
  bool fname(type1 *a, type2 *b) {                                             \
    string str;                                                                \
    input(str);                                                                \
    int parced = sscanf(str, format, a, b);                                    \
    return parced == 2;                                                        \
  }

DEFINE_INPUT_FUNC(input2doubles, "%lf %lf", double, double);
DEFINE_INPUT_FUNC(input2ints, "%d %d", int, int);
