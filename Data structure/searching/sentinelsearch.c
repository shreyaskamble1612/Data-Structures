#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i <n; i++) {
        if (arr[i] == key) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int n, key;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[5];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < 4; i++) { 
        scanf("%d", &arr[i]);
    }



    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    arr[4] = key;

    
    int result = linearSearch(arr, 5, key);

    if (result == 4) {
        printf("Key %d not found in the array.\n", key);
    } else {
        printf("Key %d found at index %d.\n", key, result);
    }

    return 0;
}
