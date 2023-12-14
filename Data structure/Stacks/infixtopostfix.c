#include<string.h>
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

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

char* infixToPostfix(char* infix)
{
    int i, j;
    char *postfix = (char*)malloc(strlen(infix) * sizeof(char));
    char ch;

    initStack(strlen(infix));

    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (top() != '(')
            {
                postfix[j++] = pop();
            }
            pop(); 
        }
        else
        {
            
            while (!isEmpty() && precedence(top()) > precedence(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    while (!isEmpty())
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    return postfix;
}


int main()
{
    char *infix = "(a+b)*c";
    char *postfix = infixToPostfix(infix);

    printf("The postfix expression is: %s\n", postfix);

    return 0;
}