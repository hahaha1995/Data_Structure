#include <stdio.h>
#include <stdlib.h>
#define DataType int
typedef struct Node {
	DataType data;
	struct Node *next;
} ListNode, LinkList;

void initList(LinkList *head);
int isEmpty(LinkList head);
LinkList locateElem(LinkList head, DataType e);
int LocatePos(LinkList head, DataType e);
int insertList(LinkList *head, int i, DataType e);
int deleteList(LinkList *head, int i, DataType *e);
int listLength(LinkList head);
void destoryList(LinkList *head);