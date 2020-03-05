#include <stdio.h>
#include <cs50.h>

int main(void)
{
  // ask for the credit card number
  int ccNumber = get_long("Number: ");
  //check if is valid
  // get every other digit starting at second-to-last digit
  // do while ccNumber isnt 0, USA SOMA PRA IR SOMANDO OS NUMEROS E PEGAR O RESULTADO
  int lastDigit = ccNumber % 10;
  //remove the last number
  ccNumber = ccNumber / 10;
  // get last digit
  lastDigit = ccNumber % 10;
  printf("cc number: %i\n", ccNumber / 100);
  // check if american express, mastercard or visa or INVALID
  //print the card flag
}
