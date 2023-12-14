#include <stdio.h>

void shellSort(int arr[], int n){
    for(int gap=n/2;gap>0;gap/=2){
        for(int i=gap;i<n;i++){
            int j,temp;
            temp = arr[i];

            for(j=i;j>=gap&& arr[j-gap]>temp;j-=gap){
                arr[j] = arr[j-gap];
            }

            arr[j] = temp;
        }
    }
}

int main() {
    int n;


    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    shellSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
