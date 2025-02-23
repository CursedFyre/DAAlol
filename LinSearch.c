#include <stdio.h>
#include <stdlib.h>

void ls(int arr[], int n, int x);

//linear search
void ls(int arr[], int n, int x) {
    for(int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found in the array\n");
}

int main() {
    int n, x;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to be searched: ");
    scanf("%d", &x);
    ls(arr, n, x);
    return 0;
}