#include <stdio.h>

int linearSearch(int *A, int n, int key)
{
    int i = 0;

    A[n] = key; //线性搜索标记
    while (A[i] != key)
        ++i;

    return i != n;
}

int main()
{
    freopen("data.in", "r", stdin);
    int n, A[10000 + 1], i, q, key, sum = 0;

    scanf("%d", &n);

    for (i = 0; i < n; ++i)
        scanf("%d", &A[i]);

    scanf("%d", &q);

    for (i = 0; i < q; ++i)
    {
        scanf("%d", &key);
        if (linearSearch(A, n, key))
            ++sum;
    }
    printf("%d\n", sum);
    return 0;
}