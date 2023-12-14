#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int topi = -1;
char *arr;
int max;

void initStack(int mx)
{
    max = mx;
    arr =(char*)malloc(max * sizeof(char));
}

void push(char ch)
{
    if (topi == max-1)
    {
        printf("\nStack overflow\n");
    }
    else
    {
        topi = topi + 1;
        arr[topi] = ch;
    }
}

char pop()
{
    if (topi == -1)
    {
        printf("\nStack underflow \n");
    }
    else
    {
        topi = topi - 1;
        return arr[topi+1];
    }
}

char top()
{
    if (topi == -1)
    {
        printf("\nStack is empty\n");
        return -1;
    }
    else
    {
        return arr[topi];
    }
}

bool isEmpty()
{
    return topi == -1;
}

void revString(char* str){
    for(int i=0;str[i]!='\0';i++){
        push(str[i]);
    }

    for(int i=0;!isEmpty();i++){
        str[i] = pop();
    }
    
    printf("\nReversed string : %s\n",str);
}
void main(){
    initStack(100);
    char str[100];
    printf("Enter a string : ");
    scanf("%s",str);
    revString(str);
}