#include <stdio.h>

// Function to find the minimum and maximum elements in an array
void max_min(int arr[], int l, int r, int *min, int *max) {
    // If there are 1 or 2 elements in the subarray, compare and find min and max
    if (r - l + 1 <= 2) {
        if (arr[l] <= arr[r]) {
            *min = arr[l];
            *max = arr[r];
        } else {
            *min = arr[r];
            *max = arr[l];
        }
        return;
    }

    // If there are more than 2 elements, divide the array into two halves
    int mid = (l + r) / 2;
    int left_min, left_max, right_min, right_max;

    // Recursively find the minimum and maximum elements in the left and right halves
    max_min(arr, l, mid, &left_min, &left_max);
    max_min(arr, mid + 1, r, &right_min, &right_max);

    // Compare the minimum and maximum elements of the left and right halves
    // Update the overall minimum and maximum accordingly
    *min = (left_min < right_min) ? left_min : right_min;
    *max = (left_max > right_max) ? left_max : right_max;
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    int min, max;

    // Find the minimum and maximum elements in the array
    max_min(arr, 0, size - 1, &min, &max);

    // Print the minimum and maximum elements
    printf("Minimum element: %d\n", min);
    printf("Maximum element: %d\n", max);

    return 0;
}