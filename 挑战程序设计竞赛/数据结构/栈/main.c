#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ElemType int

ElemType S[1000];
int top;

void push(ElemType x)
{
    S[++top] = x;
}

int pop(void)
{
    --top;
    return S[top + 1];
}

int main()
{
    freopen("data.in", "r", stdin);
    int a, b;
    char s[100];
    top = 0;

    while (scanf("%s", s) != EOF)
    {
        if (s[0] == '+')
        {
            a = pop();
            b = pop();
            push(a + b);
        }
        else if (s[0] == '-')
        {
            b = pop();
            a = pop();
            push(a - b);
        }
        else if (s[0] == '*')
        {
            a = pop();
            b = pop();
            push(a * b);
        }
        else
            push(atoi(s));
    }

    printf("%d\n", pop());
    return 0;
}