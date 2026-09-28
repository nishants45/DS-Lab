#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    // Move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        min_idx = i;

        // Find the minimum element in unsorted array
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap the found minimum with the first element
        if (min_idx != i) {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

// Main function
int main() {
    int arr[100];
    int n, i;

    // Taking number of elements from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Taking array elements from user
    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    printArray(arr, n);

    // Calling Selection Sort
    selectionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}