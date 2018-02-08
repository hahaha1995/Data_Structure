#include "head.h"

int insertList(SeqList *L, int i, DataType e)
{
	int j;
	
	if(i < 1 || i > L->length+1)
	{
		printf("插入位置i不合法!\n");
		return -1;
	}
	else if(L->length >= ListSize)
	{
		printf("顺序表满不能插入元素!\n");
		return 0;
	}
	else
	{
		for(j = L->length; j > i-1; --j)
		{
			L->list[j] = L->list[j-1];
		}
		L->list[i-1] = e;
		++L->length;
		return 1;
	}
}