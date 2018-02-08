#include <stdio.h>
#include <stdlib.h>

#define ListSize 100

typedef int DataType;
typedef struct 
{
	DataType list[ListSize];
	int length;
}SeqList;

void initList  (SeqList *L);
int  listEmpty (SeqList L);
int  getElem   (SeqList L, int i, DataType *e);
int  locateElem(SeqList L, DataType e);
int  insertList(SeqList *L, int i, DataType e);
int  deleteList(SeqList *L, int i, DataType *e);
int  listLength(SeqList L);
void clearList (SeqList *L);