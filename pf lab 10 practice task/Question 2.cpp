#include <stdio.h>

void calc(int len, int f1, int f2, int f3) {
    if (len >= 3) {
        calc(len - 3, f1, f2, f3 + 1);
    } else if (len == 2) {
        calc(len - 2, f1, f2 + 1, f3);
    } else if (len == 1) {
        calc(len - 1, f1 + 1, f2, f3);
    } else if (len == 0) {
        printf("1-unit pieces: %d\n", f1);
        printf("2-unit pieces: %d\n", f2);
        printf("3-unit pieces: %d\n", f3);
    }
}

int main() {
    int len;
    printf("Enter the length of the rope: ");
    scanf("%d", &len);

    int f1 = 0, f2 = 0, f3 = 0;
    calc(len, f1, f2, f3);

    return 0;
}

