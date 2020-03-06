#include <stdio.h>
#include <cs50.h>

int main(void)
{
  // get_int, string etc are from the cs50 library
  int age = get_int('Whats your age? \n');
  int days = age * 365;
  printf("You have %i days in earth.\n", days);
}