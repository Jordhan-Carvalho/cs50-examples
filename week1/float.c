#include <stdio.h>
#include <cs50.h>

int main(void)
{
  float price = get_float("What's the price? \n");
  // .2f, shows only 2 digits after decimal point
  printf("Your total is %.2f \n", price * 1.0625);
}