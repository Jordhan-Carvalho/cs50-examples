#include <stdio.h>

void cought(int n);

int main(void)
{
  cought(10);
}

void cought(int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("cough\n");
  }
}