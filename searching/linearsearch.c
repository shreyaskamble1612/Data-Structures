#include<stdio.h>

int linearsearch(int arr[],int size,int element){
    for(int i=0;i<size;i++){
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}
int main()
{
int arr[] = {12,4,4,698,651,8,5,9,6,5,9,9,6,5,89,52,6,9,21,9,2,69,6};
int size = sizeof(arr)/sizeof(arr[0]);
int searched = linearsearch(arr,size,651);
printf("%d",searched);
return 0;
}