#include <stdio.h>
#include <stdlib.h>
#define MAXN 100
typedef int DataType;

int stack[MAXN];
int top = -1;

void push(int value)
{
    if(top>=MAXN)
        printf("\nThe stack is full!\n");
    else
        stack[++top] = value;
}

void display()
{
    int tmp;
    for(tmp = top; tmp > -1; --tmp)
        printf("%d ", stack[tmp]);
    printf("\n");
}

int pop()
{
    int tmp;
    if(top < 0)
    {
        printf("\nThe stack is emtpy\n");
        return -1;
    }
    tmp = stack[top--];
    return tmp;
}

int main(int argc, char *argv[])
{
    int ins;

    while(1)
    {
        printf("\nPlease input a value,(0=value, -1=pop)\n");
        scanf("%d", &ins);
        if(ins == 0)
            exit(0);
        else if(ins!=-1)
            push(ins);
        else if(ins==-1)
            pop();
        display();
    }
    return EXIT_SUCCESS;
}