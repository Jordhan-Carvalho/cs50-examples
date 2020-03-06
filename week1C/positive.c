#include <stdio.h>
#include <cs50.h>
int get_positive_int(void);

int main(void)
{
  int number = get_positive_int();
  printf("O numero foi: %i \n", number);
}

int get_positive_int(void)
{
  int n;
  do
  {
    n = get_int("Positive integer: ");
  } while (n < 1);
  return n;
}
