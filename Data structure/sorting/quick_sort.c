#include <stdio.h>


int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low - 1; 

    for (int j = low; j < high; j++) {
       
        if (arr[j] <= pivot) {
            i++;
     
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}


void quickSort(int arr[], int low, int high) {
    if (low < high) {
  
        int pivotIndex = partition(arr,low, high);
    
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;


    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform quick sort
    quickSort(arr, 0, n - 1);

    // Output the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
