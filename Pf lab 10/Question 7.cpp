#include <stdio.h>

void bubble_pass(int arr[], int n, int i) {
    if (i == n - 1) 
        return;

    if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
   
    bubble_pass(arr, n, i + 1);
}

void bubble_sort(int arr[], int n) {
    if (n == 1) 
        return;

    bubble_pass(arr, n, 0);

    bubble_sort(arr, n - 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    printf("Original array: ");
    printArray(A, n);

    bubble_sort(A, n);

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}

