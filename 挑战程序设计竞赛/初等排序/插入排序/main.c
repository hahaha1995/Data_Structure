#include <stdio.h>
#define ElemType int

void intersectionSort(ElemType A[], int N)
{
    int j, i, v;

    for (i = 1; i < N; ++i)
    {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;
    }
}

int main()
{
    int N, i;
    ElemType A[10];
    scanf("%d", &N);

    for (i = 0; i < N; ++i)
        scanf("%d", &A[i]);

    intersectionSort(A, N);

    for (i = 0; i < N; ++i)
        printf("%d ", A[i]);
    printf("\n");
}