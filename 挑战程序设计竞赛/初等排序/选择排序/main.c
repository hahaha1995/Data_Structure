#include <stdio.h>

int selectionSort(int A[], int N) {
  int i, j, t, sw = 0, minj;
  for (i = 0; i < N - 1; ++i) {
    minj = i;
    for (j = i; j < N; ++j) {
      if (A[j] < A[minj])
        minj = j;
    }

    t = A[minj];
    A[minj] = A[i];
    A[i] = t;
    
    if (i != minj) {
      ++sw;
    }
  }
  return sw; //返回交换次数
}

int main() {
  int A[100], N, i, sw;

  scanf("%d", &N);
  for (i = 0; i < N; ++i)
    scanf("%d", &A[i]);

  sw = selectionSort(A, N);

  printf("\n");
  for (i = 0; i < N; ++i) {
    if (i > 0)
      printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", sw);
  return 0;
}
