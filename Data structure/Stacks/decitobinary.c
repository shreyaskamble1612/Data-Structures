

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

void decimalToBinary(int n)
{
    initStack(100);
    int remainder;

    while (n != 0)
    {
        remainder = n % 2;
        push(remainder);
        n = n / 2;
    }
    while (!isEmpty())
    {
        printf("%d", pop());
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    decimalToBinary(n);

    return 0;
}