#include <stdio.h>
#include <stdlib.h>

int queue[5] = {0};
int front = -1;
int rear = -1;

void addqueue(int value)
{
  if (rear >= 5)
    printf("The queue is full!\n");
  else
  {
    ++rear;
    queue[rear] = value;
  }
}

int delqueue()
{
  int temp;
  if (front == rear)
    return -1;
  else
  {
    temp = queue[++front];
    queue[front] = 0;
    return temp;
  }
}

void display()
{
  int i;
  for (i = 0; i < 5; ++i)
    if (queue[i] != 0)
      printf("%d ", queue[i]);
  printf("\n");
}

int main(int argc, char *argv[])
{
  int select, temp;
  while (1)
  {
    printf("\n 1.Input a data\n");
    printf("\n 2.Output a data\n");
    printf("\n 3.Exit\n");
    scanf("%d", &select);

    switch (select)
    {
    case 1:
      printf("Please input a value: ");
      scanf("%d", &temp);
      addqueue(temp);
      break;
    case 2:
      if ((temp = delqueue()) == -1)
        printf("The queue is empty.!\n");
      else
        printf("The out value is %d\n", temp);
      break;
    case 3:
      return EXIT_SUCCESS;
    }
    display();
  }
}
