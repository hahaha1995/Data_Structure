#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Stack *link;
typedef struct Stack Snode;

struct Stack
{
	ElemType data;
	struct Stack *next;
};

link init()
{
	link p;

	p = NULL;
	return p;
}

link push(link Head, ElemType x)
{
	link p;

	p = (link)malloc(sizeof(Snode));
	if (p == NULL)
	{
		printf("\nMemory Error\n");
		return Head;
	}
	p->data = x;
	p->next = Head;
	return p;
}

link pop(link Head)
{
	link p;

	p = Head;
	if (p == NULL)
		printf("\nStack is empty!\n");
	else
	{
		p = p->next;
		free(Head);
	}
	return p;
}

ElemType getTop(link Head)
{
	if (Head == NULL)
	{
		printf("\nStack is empty!\n");
		return -1;
	}
	else
		return Head->data;
}

int isEmpty(link Head)
{
	if (Head == NULL)
		return 1;
	else
		return 0;
}

void display(link Head)
{
	link p;
	p = Head;

	if (p == NULL)
		printf("\nStack is empty\n");
	else
		do
		{
			printf("%d ", p->data);
			p = p->next;
		} while (p != NULL);
}

link setNull(link Head)
{
	link p;
	p = Head;
	while (p != NULL)
	{
		p = p->next;
		free(Head);
		Head = p;
	}
	return Head;
}

int getLength(link head)
{
	int len = 0;
	link p;

	p = head;

	while (p != NULL)
	{
		++len;
		p = p->next;
	}

	return len;
}

int main(int argc, char *argv[])
{
	int i, x;
	link head;
	do
	{
		printf("\n 1.Input a stack data");
		printf("\n 2.Output a stack data");
		printf("\n 3.Empty or Not");
		printf("\n 4.Display a top of stack");
		printf("\n 5.Display the length of stack");
		printf("\n 6.Exit and Free Stack\n");
		printf("\n Stack is: ");
		display(head);
		printf("\n");

		scanf("%d", &i);
		switch (i)
		{
		case 1:
			printf("\nInput a number: ");
			scanf("%d", &x);
			head = push(head, x);
			break;
		case 2:
			head = pop(head);
			break;
		case 3:
			if (isEmpty(head))
				printf("\nStack is empty\n");
			else
				printf("\nStack is not empty\n");
			;
			break;
		case 4:
			printf("\nThe top is %d.\n", getTop(head));
			break;
		case 5:
			printf("\nTher length of stack is %d.", getLength(head));
			break;
		default:
			break;
		}
	} while (i != 6);
	head = setNull(head);
	display(head);
	return EXIT_SUCCESS;
}
