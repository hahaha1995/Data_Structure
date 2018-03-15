#include <stdio.h>
#define ElementType int

void shellSort(ElementType A[], int N)
{
    int i, j, Increment;
    ElementType Tmp;

    for(Increment = N / 2; Increment > 0; Increment /= 2)//增量为N/2,缩小增量方法为1/2
        for(i = Increment; i < N; ++i)
        {
            Tmp = A[i];
            for(j = i; j >= Increment; j -= Increment)
            {
                if(Tmp < A[j - Increment])
                    A[j] = A[j - Increment];
                else
                    break;
            }
            A[j] = Tmp;
        }
}

int main()
{
    int N, i;
    int A[10];
    scanf("%d", &N);

    for(i = 0; i < N; ++i)
        scanf("%d", &A[i]);

    shellSort(A, N);

    for(i = 0; i < N; ++i)
        printf("%d ", A[i]);

}