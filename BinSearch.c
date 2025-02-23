#include <stdio.h>
#include <stdlib.h>

int bs(int arr[], int x, int s, int e);

//binary search
int bs(int arr[], int x, int s, int e) {
    if (e >= s) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return bs(arr, x, s, mid - 1);
        //only present in later part
        return bs(arr, x, mid + 1, e);
    }
    return -1;
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
    
    int result = bs(arr, x, 0, n - 1);
    if(result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result);
    return 0;
}