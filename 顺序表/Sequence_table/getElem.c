#include "head.h"

int getElem(SeqList L, int i, DataType *e)
{
	if(i < 1 || i > L.length)
		return -1;
	
	*e = L.list[i-1];
	return 1;
}