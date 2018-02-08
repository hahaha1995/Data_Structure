#include "head.h"

int locateElem(SeqList L, DataType e)
{
	int i;
	
	for(i = 0; i < L.length; ++i)
	{
		if(L.list[i] == e)
			return i+1;
	}
	return 0;
}