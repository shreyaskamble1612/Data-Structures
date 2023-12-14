#include <stdio.h>

void printarray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void mergesort(int *A,  int mid, int low,int high)
{


}
int main()
{
    int A[] = {3, 5, 13, 2, 1, 8};
    int n = 6;
    printarray(A, n);
    mergesort(A,n);
    printarray(A,n);
    return 0;
}