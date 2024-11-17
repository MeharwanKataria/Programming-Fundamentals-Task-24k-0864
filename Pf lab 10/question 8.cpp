#include <stdio.h>

void printArrayRecursive(int arr[], int size, int index) {
    if (index == size) {
        return;
    }
    printf("%d ", arr[index]);
    printArrayRecursive(arr, size, index + 1);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array elements are:\n");
    printArrayRecursive(arr, n, 0);

    return 0;
}

