#include "head.h"

int main(int argc, char *argv[]) { 
	DataType a[] = {12,16,21,33,35,87,102};
	DataType b[] = {3,5,21,23,35,99,123};
	LinkList A,B,C;
	ListNode *p;
	int i;

	//initial
	initList(&A);
	initList(&B);

	//insert
	for(i=1;i<=sizeof(a)/sizeof(a[0]);++i)
		if(insertList(A,i,a[i-1])==0)
			return EXIT_FAILURE;
	for(i=1;i<=sizeof(b)/sizeof(b[0]);++i)
		if(insertList(B,i,b[i-1])==0)
			return EXIT_FAILURE;

	//display
	printf("单链表A中的元素有%d个：\n");
	for(i=1;i<=listLength(A);++i){
		p = get(A,i);
		if(p)
			printf("%4d", p->data);
	}
	printf("\n");
	printf("单链表B中的元素有%d个：\n");
	for(i=1;i<=listLength(B);++i){
		p = get(B,i);
		if(p)
			printf("%4d", p->data);
	}
	printf("\n");

	//merge
	mergeList(A,B,&C);
	printf("合并后的递减有序链表C包含%d个元素：\n", listLength(C))
	for(i=1;i<=listLength(C);++i){
		p = get(C,i);
		if(p)
			printf("%4d", p->data);
	}
	printf("\n");
	return EXIT_SUCCESS; 
}

void initList(LinkList *head) {
	if ((*head = (LinkList)malloc(sizeof(LinkList))) == NULL)
		exit - 1;
	(*head)->next = NULL;
}

int isEmpty(LinkList head) {
	if (head->next == NULL)
		return 1;
	else
		return 0;
}

LinkList get(LinkList head, int i) {
	LinkList p;
	int j;
	if (isEmpty(head))
		return NULL;
	j = 0;
	p = head;
	while (p->next != NULL && j < i) {
		p = p->next;
		++j;
	}
	if (j == i)
		return p;
	else
		return NULL;
}

LinkList locateElem(LinkList head, DataType e) {
	LinkList p;

	if (isEmpty(head))
		return NULL;

	p = head->next;

	while (p) {
		if (p->data == e)
			break;
		p = p->next;
	}
	return p;
}

int LocatePos(LinkList head, DataType e) {
	LinkList p;
	int i;
	if (isEmpty(head))
		return 0;

	p = head->next;
	i = 1;
	while (p) {
		if (p->data == e)
			return i;
		p = p->next;
		++i;
	}
	if (!p)
		return 0;
}

int insertList(LinkList *head, int i, DataType e) {
	LinkList pre, p;
	int j;

	pre = head;
	j = 0;
	while (pre->next != NULL && j < i - 1) {
		pre = pre->next;
		++j;
	}

	if (j != i - 1) {
		printf("插入位置错误！\n");
		return EXIT_FAILURE;
	}

	if ((p = (LinkList)malloc(sizeof(LinkList))) == NULL)
		exit(-1);
	p->data = e;
	p->next = pre->next;
	pre->next = p;
	return 1;
}

int deleteList(LinkList *head, int i, DataType *e) {
	LinkList pre, p;

	pre = head;
	j = 0;
	while (pre->next != NULL && pre->next->next != NULL && j < i - 1) {
		pre = pre->next;
		++j;
	}
	if (j != i - 1) {
		printf("删除位置错误！\n");
		return 0;
	}
	p = pre->next;
	*e = pre->data;
	pre->next = p->next;
	free(p);
	return 1;
}

int listLength(LinkList head) {
	LinkList p;
	int count = 0;
	p = head;

	while (p->next != NULL) {
		p = p->next;
		++count;
	}
	return count;
}

void destoryList(LinkList *head) {
	LinkList q, p;
	p = head;
	while (p != NULL) {
		p = p->next;
		q = p;
		free(q);
	}
}

void mergeList(LinkList A, LinkList B, LinkList *C){
	ListNode *pa, *pb;

	pa = A->next;
	pb = B->next;
	free(B);
	*C = A;
	(*C)->next = NULL;

	while(pa&&pb){
		
	}
}