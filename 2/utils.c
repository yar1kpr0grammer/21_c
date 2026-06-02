
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define STRING_LENTH 128
typedef char string[STRING_LENTH];

void input(string str) {
  fgets(str, STRING_LENTH, stdin);
  str[strcspn(str, "\n")] = '\0';
}

bool inputInt(int *outp) {
  string str;
  input(str);

  int i;
  int parsed = sscanf(str, "%d", &i);
  if (parsed == 1) {
    *outp = i;
    return true;
  }
  return false;
}
