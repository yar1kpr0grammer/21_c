#include "utils.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encodeChar(char c, char *hex_output) {
  sprintf(hex_output, "%02X", (unsigned char)c);
}

int decodeHex(char *hex, char *output) {
  // Проверка, что строка состоит ровно из двух шестнадцатеричных символов
  if (strlen(hex) != 2) {
    return 0;
  }

  for (int i = 0; i < 2; i++) {
    if (!isxdigit(hex[i])) {
      return 0;
    }
  }

  // Преобразование шестнадцатеричной строки в число
  char *endptr;
  long value = strtol(hex, &endptr, 16);

  if (*endptr != '\0' || value < 0 || value > 255) {
    return 0;
  }

  *output = (char)value;
  return 1;
}

// Функция для чтения и разбиения строки на токены
// Возвращает массив токенов или NULL в случае ошибки
char **readAndSplit(int *token_count) {
  string line;

  input(&line);

  // Подсчитываем количество токенов
  *token_count = 0;
  string temp;
  strcpy(temp, line);

  char *token = strtok(temp, " ");
  while (token != NULL) {
    (*token_count)++;
    token = strtok(NULL, " ");
  }

  if (*token_count == 0) {
    return NULL;
  }

  // Выделяем память для массива токенов
  char **tokens = malloc(*token_count * sizeof(char *));
  if (tokens == NULL) {
    return NULL;
  }

  // Копируем токены
  token = strtok(line, " ");
  for (int i = 0; i < *token_count && token != NULL; i++) {
    tokens[i] = malloc((strlen(token) + 1) * sizeof(char));
    if (tokens[i] == NULL) {
      // Освобождаем уже выделенную память
      for (int j = 0; j < i; j++) {
        free(tokens[j]);
      }
      free(tokens);
      return NULL;
    }
    strcpy(tokens[i], token);
    token = strtok(NULL, " ");
  }

  return tokens;
}

// Функция для освобождения памяти токенов
void freeTokens(char **tokens, int token_count) {
  for (int i = 0; i < token_count; i++) {
    free(tokens[i]);
  }
  free(tokens);
}

// Функция кодирования: читает символы из stdin, выводит шестнадцатеричные коды
void encodeMode() {
  int token_count;
  char **tokens = readAndSplit(&token_count);

  if (tokens == NULL) {
    printf("n/a\n");
    return;
  }

  // Проверяем, что все токены - это один символ
  for (int i = 0; i < token_count; i++) {
    if (strlen(tokens[i]) != 1) {
      printf("n/a\n");
      freeTokens(tokens, token_count);
      return;
    }
  }

  // Кодируем и выводим результат
  string result = "";
  for (int i = 0; i < token_count; i++) {
    char hex[3];
    encodeChar(tokens[i][0], hex);

    if (i > 0) {
      strcat(result, " ");
    }
    strcat(result, hex);
  }

  printf("%s\n", result);
  freeTokens(tokens, token_count);
}

// Функция декодирования: читает шестнадцатеричные коды из stdin, выводит
// символы
void decodeMode() {
  int tokenCount;
  char **tokens = readAndSplit(&tokenCount);

  if (tokens == NULL) {
    printf("n/a\n");
    return;
  }

  // Декодируем и выводим результат
  string result = "";
  for (int i = 0; i < tokenCount; i++) {
    char decodedChar;

    if (!decodeHex(tokens[i], &decodedChar)) {
      printf("n/a\n");
      freeTokens(tokens, tokenCount);
      return;
    }

    if (i > 0) {
      strcat(result, " ");
    }

    char charStr[2] = {decodedChar, '\0'};
    strcat(result, charStr);
  }

  printf("%s\n", result);
  freeTokens(tokens, tokenCount);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("n/a\n");
    return 0;
  }

  int mode;
  if (!sscanf(argv[1], "%d", &mode)) {
    puts("n/a");
  }

  // Выбор режима
  if (mode == 0) {
    encodeMode();
  } else if (mode == 1) {
    decodeMode();
  } else {
    printf("n/a\n");
  }

  return 0;
}
