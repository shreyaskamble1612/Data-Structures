#include<stdio.h>

void printarray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
int partition(int A[],int low,int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;

    do{
        while(A[i] <= pivot){
            i++;
        }
        while(A[j] > pivot){
            j--;
        }
        if(i<j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i<j);
//swap a[low] and a[j];
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void quicksort(int A[],int low,int high){
    int partitionindex;

    if(low<high){
        partitionindex = partition(A,low,high);
        quicksort(A ,low, partitionindex-1);
        quicksort(A ,partitionindex+1,high);        
    }

}

int main()

{
int A[]={23,5,23,6,7,5};
int n=6;
printarray(A,n);
quicksort(A,0,n-1);
printarray(A,n);

return 0;
}
