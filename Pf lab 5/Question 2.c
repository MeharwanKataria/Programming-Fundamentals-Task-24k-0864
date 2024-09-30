#include <stdio.h>
int main() {
    float A1, A2, A3;
    printf("Enter sides of three angles\n");
    printf("Angle 1:\n");
    scanf("%f", &A1); 
    printf("Angle 2:\n");
    scanf("%f", &A2); 
    printf("Angle 3:\n");
    scanf("%f", &A3);

    float sum = A1 + A2 + A3; 
    printf("Sum of three angles: %.2f\n", sum); 
    if (sum == 180.0) {
        printf("The given triangle is valid\n");
    } else {
        printf("The given triangle is not valid\n");
    }

    return 0;
}

