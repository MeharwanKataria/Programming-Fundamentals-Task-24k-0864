#include <stdio.h>

void drawShape(int size) {
    int totalLines = 2 * size + 1;
    for (int line = 0; line < totalLines; line++) {
        for (int pos = 0; pos < totalLines; pos++) {
            if (line <= size) { // Upper half including middle row
                if (pos >= size - line && pos <= size + line) {
                    printf("o");
                } else {
                    if (pos > size)
                        printf(" ");
                    else
                        printf(" * ");
                }
            } else { // Lower half
                if (pos >= size - (totalLines - 1 - line) && pos <= size + (totalLines - 1 - line)) {
                    printf("o");
                } else {
                    if (pos > size)
                        printf("    ");
                    else
                        printf(" * ");
                }
            }
        }
        printf("\n");
    }
}

void palindrometriangle(int N) {
	int i,j;
    for (i = 1; i <= N; i++) {
        for (j=1;j<=i; j++) {
            printf("%d", j);
        }
        for (j =i-1; j>= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
}


int main() {
    int n;
    printf("Enter the Number of Rows: ");
    scanf("%d", &n);
    printf("Part A\n\n");
    drawShape(n);
    printf("\n");
    printf("Part B\n\n");
    palindrometriangle(n);

    return 0;
}

