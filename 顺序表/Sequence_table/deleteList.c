#include "head.h"

int deleteList(SeqList *L, int i, DataType *e)
{
	int j;
	
	if(L->length <= 0)
	{
		printf("顺序表为空，不能删除！\n");
		return 0;
	}
	else if(i < 1 || i > L->length)
	{
		printf("删除位置不合法!\n");
		return -1;
	}
	else
	{
		*e = L->list[i-1];
		for(j = i-1; j < L->length-1; ++j)
			L->list[j] = L->list[j+1];
		--L->length;
		return 1;
	}
}