#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdio.h>

typedef char string[128];

void input(string *str);

bool input2doubles(double *a, double *b);
bool input2ints(int *a, int *b);

#endif
