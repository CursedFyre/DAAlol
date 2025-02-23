#include <stdio.h>
#include <stdbool.h>
void printa(int arr[], int n){
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void insort (int arr[], int n){
    int i,key,j;
    for(i=0;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1]=arr[j];
            j=j-1;
            
        }
        arr[j+1]=key;      
    }
}
 

 int main(){
    int a,b,n;
    printf("Enter array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:\n");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    insort(arr,n);
    printf("The sorted array is:\n");
    printa(arr,n);
 }