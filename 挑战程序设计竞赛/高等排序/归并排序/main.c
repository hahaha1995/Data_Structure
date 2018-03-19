#include <stdio.h>
#define MAX 500000
#define SENTINEL 2000000000

int cnt = 0;
int L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(int A[], int n, int left, int mid, int right);
void mergeSort(int A[], int n, int left, int right);



int main()
{
  printf("hello\n");
  freopen("data.in", "r", stdin);
  int A[MAX] = {0}, n, i;
  cnt = 0;

  //freopen("data.in", "r", stdin);
  scanf("%d", &n);
  
  for (i = 0; i < n; ++i)
    scanf("%d", &A[i]);


  mergeSort(A, n, 0, n); //归并排序

  for (i = 0; i < n; ++i)
  {
    if (i)
      printf(" ");
    printf("%d", A[i]);
  }

  printf("\n%d\n", cnt);
  return 0;
}

void merge(int A[], int n, int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;

  for (i = 0; i < n1; ++i)
    L[i] = A[left + i];

  for (i = 0; i < n2; ++i)
    R[i] = A[mid + i];

  L[n1] = R[n2] = SENTINEL;
  i = j = 0;
  for (k = left; k < right; ++k)
  {
    ++cnt;
    if (L[i] <= R[j])
      A[k] = L[i++];
    else
      A[k] = R[j++];
  }
}

void mergeSort(int A[], int n, int left, int right)
{
  if (left < right)
  {
    int mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid + 1, right);
    merge(A, n, left, mid, right);
  }
}

