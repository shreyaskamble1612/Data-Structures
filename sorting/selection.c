#include<stdio.h>

void printarray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void selectionssort(int *A,int n){
    int indexofmin,temp;
    printf("Runnint insertion sort\n");
    for(int i=0;i<n-1;i++){
        indexofmin = i;
        for(int j=i+1;j<n;j++){
            if(A[j] < A[indexofmin]){
                indexofmin = j;
            }
        }

        temp = A[i];
        A[i]=A[indexofmin];
        A[indexofmin]=temp;
    }
}
int main()

{

    int A[] = {3,5,13,2,1,8};
    int n = 6;
    printarray(A,n);
    selectionssort(A,n);
    printarray(A,n);
return 0;
}