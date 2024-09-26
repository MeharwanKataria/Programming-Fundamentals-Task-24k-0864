#include <stdio.h>
int main() {
    int a, b;
    printf("Enter the value of A: ");
    scanf("%d", &a);
    printf("Enter the value of B: ");
    scanf("%d", &b);
    if (a > b) {
        if (a > 100) {
            printf("number1 is significantly larger\n");
        } else {
            printf("number 1 is larger\n");
        }
    } else if (a < b) {
        if (a < 0) {
            printf(" number1 is negative and smallest\n");
        } else {
            printf(" number 1 is smaller\n");
        }
    } else {
        printf("Both numbers are equal\n");
    }
    return 0;
}

