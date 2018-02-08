#include <stdio.h>
#include <stdlib.h>

typedef struct QueueNode node;
typedef struct QueueNode *link;

struct QueueNode
{
        int data;
        struct QueueNode *next;
};

link front = NULL;
link rear = NULL;

void display()
{
        link point;
        point = front;
        while (point != NULL)
        {
                printf("%d ", point->data);
                point = point->next;
        }
        printf("\n");
}

void addQueue(int value)
{
        link new_node;

        new_node = (link)malloc(sizeof(node));
        new_node->data = value;
        new_node->next = NULL;

        if (front == NULL)
                front = new_node;
        else
                rear->next = new_node;
        rear = new_node;
}

int delQueue()
{
        link top;
        int temp;

        if (front != NULL)
        {
                top = front;
                front = front->next;
                temp = top->data;
                free(top);
                return temp;
        }
        else
        {
                //rear = NULL;
                return -1;
        }
}

int main(int argc, char *argv[])
{
        int select, temp;

        do
        {
                printf("1.Input a data\n");
                printf("2.Output a data\n");
                printf("3.Exit\n");
                scanf("%d", &select);

                switch (select)
                {
                case 1:
                        printf("Please input a value: ");
                        scanf("%d", &temp);
                        addQueue(temp);
                        break;
                case 2:
                        if ((temp = delQueue()) == -1)
                                printf("The Queue is empty!\n");
                        else
                                printf("The out value is %d.\n", temp);
                        break;
                default:
                        break;
                }
                display();
        } while (select != 3);
        return EXIT_SUCCESS;
}