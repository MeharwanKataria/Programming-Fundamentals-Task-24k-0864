#include <stdio.h>
#include <string.h>

int main() {
    int i;
    char A[5][50] = {"Mehrwan", "Yash", "Ali", "Dan", "Harsh"};
    char input[50];
    
    printf("Enter the name to search: ");
    gets(input);
    
    int found = 0;
    for (i = 0; i < 5; i++) {
        if (strcmp(input, A[i]) == 0) 
            found = 1;
            break;
        }
    if (found) 
        printf("Found\n");
    else 
        printf("Not found\n");

    return 0;
}

