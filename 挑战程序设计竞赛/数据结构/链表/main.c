#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int key;
    struct node *prev, *next;
} Node;

Node *head;

Node *listSearch(int key)
{
    Node *cur = head->next;
    while (cur != NULL && cur->key != key)
        cur = cur->next;
    return cur;
}

void init()
{
    head = (Node *)malloc(sizeof(Node));
    //head = NULL;
    head->next = NULL;
    head->prev = NULL;
}

void printList()
{
    Node *cur;
    if (head->next != NULL)
        cur = head->next;
    else
    {
        printf("链表为空！");
        exit(-1);
    }

    int isf = 0;
    while (1)
    {
        if (cur == NULL || cur == head)
            break;
        if (isf++ > 0)
            printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
    }
    printf("\n");
}

void deleteNode(Node *t)
{
    if (t == NULL)
        exit(-1);

    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void deleteFirst()
{
    deleteNode(head->next);
}

void deleteLast()
{
    deleteNode(head->prev);
}

void deleteKey(int key)
{
    deleteNode(listSearch(key));
}

void insert(int key) //头插法
{
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    if (head->next != NULL)
    {
        x->next = head->next;
        head->next->prev = x;
    }
    else
        x->next = head;
    head->next = x;
    x->prev = head;
}

int main()
{
    freopen("command.in", "r", stdin);
    int key, n, i;
    int size = 0;
    char com[20];
    int np = 0, nd = 0;
    init();

    scanf("%d", &n);
    init();
    for (i = 0; i < n; ++i)
    {
        scanf("%s%d", com, &key);
        if (com[0] == 'i')
        {
            insert(key);
            np++;
            size++;
        }
        else if (com[0] == 'd')
        {
            if (strlen(com) > 6)
            {
                if (com[6] == 'F')
                    deleteFirst();
                else if(com[6] == 'L')
                    deleteLast();
            }
            else
            {
                deleteKey(key);
                nd++;
            }
            --size;
        }
    }
    printList();
    return 0;
}