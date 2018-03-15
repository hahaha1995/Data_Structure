#include <stdio.h>
#define ElementType int

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(ElementType A[], int N)
{
    int i, j;
    for(j = N-1; j > 0; --j)
        for(i = 0; i < j; ++i)
            if(A[i] > A[i+1]) swap(&A[i], &A[i+1]);
}

int main()
{
    int N, i;
    int A[10];
    scanf("%d", &N);

    for (i = 0; i < N; ++i)
        scanf("%d", &A[i]);

    bubbleSort(A, N);

    for (i = 0; i < N; ++i)
        printf("%d ", A[i]);
}