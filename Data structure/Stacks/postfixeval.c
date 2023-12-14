#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<string.h>

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
int evaluatePostfix(char* postfix)
{
    int i, operand1, operand2, result;

    initStack(strlen(postfix));

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i] - '0');
        }
        else
        {
            operand2 = pop();
            operand1 = pop();

            switch (postfix[i])
            {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            push(result);
        }
    }

    return pop();
}

int main()
{
    char *postfix = "234+*5-";

    int result = evaluatePostfix(postfix);

    printf("The result of the expression is: %d\n", result);

    return 0;
}