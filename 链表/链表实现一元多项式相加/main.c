#include <stdio.h>
#include <stdlib.h>

typedef struct List *Link;
typedef struct List Lnode;

struct List {
	int coef;
	int expn;
	struct List *next;
};

Link create();
Link add(Link pa, Link pb);
void display(Link Head);

int main(int argc, char *argv[]) {
	Link Link1, Link2, Link3;

	printf("\n建立第一个一元多项式（以0，0标志结束）：\n");
	printf("要求：1.按幂从大到小次序输入各结点。\n");
	printf("	 2.没有两个结点具有相同的幂。\n");
	Link1 = create();
	printf("第一个一元多项式为：");
	display(Link1);

	printf("\n建立第一个二元多项式（以0，0标志结束）：\n");
	printf("要求：1.按幂从大到小次序输入各结点。\n");
	printf("	 2.没有两个结点具有相同的幂。\n");
	Link2 = create();
	printf("第二个一元多项式为：");
	display(Link2);

	Link3 = add(Link1, Link2);
	
	printf("\n相加后的一元多项式为：");
	display(Link3);

	return EXIT_SUCCESS;
}

Link create() {
	Link Head, s, p;
	int i = 1, n, a;

	Head = (Link)malloc(sizeof(Lnode));
	Head->next = NULL;
	p = Head;

	do {
		printf("\n第%d次->系数，幂：", i++);
		scanf("%d %d", &a, &n);

		if (a != 0 || n != 0) {
			s = (Link)malloc(sizeof(Lnode));
			s->coef = a;
			s->expn = n;
			s->next = NULL;
			p->next = s;
			p = s;
		}
	} while (a != 0 || n != 0);

	printf("\n");
	return Head->next;
}

Link add(Link pa, Link pb) {
	Link pc, s, p;
	int n;

	pc = (Link)malloc(sizeof(Lnode));
	pc->next = NULL;
	p = pc;
	while (pa != NULL && pb != NULL) {
		if (pa->expn > pb->expn) {
			s = (Link)malloc(sizeof(Lnode));
			s->coef = pa->coef;
			s->expn = pa->expn;
			s->next = NULL;
			p->next = s;
			p = s;
			pa = pa->next;
		}
		else if (pa->expn < pb->expn) {
			s = (Link)malloc(sizeof(Lnode));
			s->coef = pb->coef;
			s->expn = pb->expn;
			s->next = NULL;
			p->next = s;
			p = s;
			pb = pb->next;
		}
		else {
			n = pa->coef + pb->coef;
			if (n != 0) {
				s = (Link)malloc(sizeof(Lnode));
				s->coef = n;
				s->expn = pa->expn;
				s->next = NULL;
				p->next = s;
				p = s;
			}
			pa = pa->next;
			pb = pb->next;
		}
	}

	while (pa != NULL) {
		s = (Link)malloc(sizeof(Lnode));
		s->coef = pa->coef;
		s->expn = pa->expn;
		s->next = NULL;
		p->next = s;
		p = s;
		pa = pa->next;
	}

	while (pb != NULL) {
		s = (Link)malloc(sizeof(Lnode));
		s->coef = pb->coef;
		s->expn = pb->expn;
		s->next = NULL;
		p->next = s;
		p = s;
		pb = pb->next;
	}
	return (pc->next);
}

void display(Link Head) {
	Link p = Head;
	int first = 1;
	while (p != NULL) {
		if (first == 1) {
			if (p->expn == 1)
				printf("%dx", p->coef);
			else if (p->expn == 0)
				printf("%d", p->coef);
			else
				printf("%dx^%d", p->coef, p->expn);
		}
		else {
			if (p->expn == 1)
				printf("+%dx", p->coef);
			else if (p->expn == 0)
				printf("+%d", p->coef);
			else
				printf("+%dx^%d", p->coef, p->expn);
		}
		++first;
		p = p->next;
	}
	printf("\n");
}