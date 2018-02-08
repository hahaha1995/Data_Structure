#include <stdio.h>
#include <stdlib.h>
#define MAXN 5

int queue[MAXN];
int front = 0;
int rear = 0;

void display()
{
    int i;
    for (i = 0; i < MAXN; ++i)
        printf("%d ", queue[i]);
    printf("\n");
}

void init()
{
    int i;
    for (i = 0; i < MAXN; ++i)
        queue[i] = -1;
}

void addQueue(int value)
{
    if ((rear + 1) % MAXN == front) //队满
        printf("Queue is full!\n");
    else
    {
        rear = (rear + 1) % MAXN;
        queue[rear] = value;
    }
}

void delQueue()
{
    if (front == rear)
        printf("Queue is empty！\n");
    else
    {
        front = (front + 1) % MAXN;
        queue[front] = -1;
    }
}

int main(int argc, char *argv[])
{
    int select, temp;
    init();

    do
    {
        printf("1.Input a data\n");
        printf("2.Output a data\n");
        printf("3.Display the queue\n");
        printf("4.Exit\n");
        scanf("%d", &select);
        switch (select)
        {
        case 1:
            printf("Please input a value");
            scanf("%d", &temp);
            addQueue(temp);
            break;
        case 2:
            delQueue();
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    } while (select != 4);
    return EXIT_SUCCESS;
}