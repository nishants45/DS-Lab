#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    int i;

    for (i = 0; i < n; i++)
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

    // Calling Insertion Sort
    insertionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
