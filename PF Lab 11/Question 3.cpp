#include <stdio.h>

void copyFile(const char *src, const char *dest) {
    FILE *s = fopen("ABC.txt", "r");// getting from ABC.txt;
    if (s == NULL) {
        printf("Error opening source file.\n");
        return;
    }

    FILE *d = fopen(dest, "w");// transfering to Q3.txt.
    if (d == NULL) {
        printf("Error opening destination file.\n");
        fclose(s);
        return;
    }

    char c;
    while ((c = fgetc(s)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            c = c - 32;
        }
        fputc(c, d);
    }

    fclose(s);
    fclose(d);
}

int main() {
    copyFile("source.txt", "Q3.txt");
    printf("Copy data successfully with uppercase.");
    return 0;
}

