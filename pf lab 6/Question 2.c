#include <stdio.h>
int main() {
    int x, y = 1;
    printf("Enter the number: ");
    scanf("%d", &x);
    if (x >= 1) {
        
        while (y <= x) {
            if (y % 2 == 0) {
                printf("%d ", y);  
            }
            y++; 
        }
    } else {
        printf("Please enter a number greater than or equal to 1.\n");
    }
    return 0;
}
