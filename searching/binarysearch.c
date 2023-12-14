#include <stdio.h>

int binarysearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    mid = (low + high) / 2;
    while (low <= high)
    {
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {12, 4, 4, 698, 651, 8, 5, 9, 6, 5, 9, 9, 6, 5, 89, 52, 6, 9, 21, 9, 2, 69, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int searched = binarysearch(arr, size, 651);
    printf("%d", searched);
    return 0;
}