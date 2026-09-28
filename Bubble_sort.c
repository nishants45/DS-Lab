#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;

    // Traverse through all array elements
    for (i = 0; i < n - 1; i++) {

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) {

            // Swap if the element is greater than the next
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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

    printf("Original array: \n");
    printArray(arr, n);

    // Calling Bubble Sort
    bubbleSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}