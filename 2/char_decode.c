#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void encode(void);
void decode(void);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        puts("n/a");
        return 0;
    }

    char *endptr;
    long mode = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || (mode != 0 && mode != 1)) {
        puts("n/a\n");
        return 0;
    }

    if (mode == 0) {
        encode();
    } else {
        decode();
    }

    return 0;
}

void encode(void) {
    char c, sep;
    bool has_data = false;

    while (scanf("%c%c", &c, &sep) == 2) {
        if (has_data) {
            printf(" ");
        }
        printf("%02X", (unsigned char)c);
        has_data = true;

        if (sep == '\n') {
            printf("\n");
            return;
        }
        if (sep != ' ') {
            puts("n/a");
            return;
        }
    }
    puts("n/a");
}

void decode(void) {
    unsigned int code;
    char sep;
    bool has_data = false;

    // Читаем строго до 2-х hex-символов и сразу за ними разделитель
    while (scanf("%2X%c", &code, &sep) == 2) {
        if (has_data) {
            printf(" ");
        }
        printf("%c", (char)code);
        has_data = true;

        if (sep == '\n') {
            printf("\n");
            return;
        }
        if (sep != ' ') {
            puts("n/a");
            return;
        }
    }
    puts("n/a");
}
