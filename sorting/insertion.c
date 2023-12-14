#include<stdio.h>
#include<stdlib.h>

void printarray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void insertionsort(int *A,int n){
    for(int i = 1;i<n;i++){
        int key = A[i];
        int j = i-1;

        while(j>=0 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;

    }
}

int main()

{


int A[]= {12,54,65,7,23,9};
int n = 6;
printarray(A,n);
insertionsort(A,n);
printarray(A,n);

return 0;
}