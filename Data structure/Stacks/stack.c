#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int topi = -1;
int *arr;
int max;

void initStack(int mx)
{
    max = mx;
    arr = (int *)malloc(max * sizeof(int));

    // arr = (int *)malloc(max * sizeof(int));
}

void push()
{
    if (topi == max-1)
    {
        printf("\nStack overflow\n");
    }
    else
    {
        int ele;
        printf("Enter element to push : ");
        scanf("%d", &ele);
        topi = topi + 1;
        arr[topi] = ele;
    }
}

int pop()
{
    if (topi == -1)
    {
        printf("\nStack underflow \n");
    }
    else
    {
        topi = topi - 1;
        printf("\nStack is popped \n");
        return arr[topi+1];
    }
}

int top()
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

int takeChoice()
{
    int c;
    printf("\n-> 1 For pushing to stack\n");
    printf("-> 2 For popping stack\n");
    printf("-> 3 For getting top of stack\n");
    printf("-> 4 For checking is empty\n");
    printf("-> 5 For quitting\n");
    printf("-> Type : ");
    scanf("%d", &c);
    return c;
}


void main()
{
    int size;
    printf("Enter size of stack : ");
    scanf("%d", &size);
    initStack(size);
    int choice = takeChoice();
    while (choice != 5)
    {
        switch (choice)
        {
        case 1:
            push();
            choice = takeChoice();
            break;
        case 2:
            pop();
            choice = takeChoice();
            break;
        case 3:
            int tpe = top();
            if (tpe == -1)
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Element at top is %d \n", tpe);
            }
            choice = takeChoice();
            break;
        case 4:
            if (isEmpty())
            {
                printf("Stack is empty\n");
            }
            else
            {
                printf("Stack is not empty\n");
            }
            choice = takeChoice();
            break;

        default:
            printf("\nMake right choice !! \n");
            break;
        }
    }
}