#include <stdio.h>
#include <cs50.h>
#include <math.h>

int isValid(long int ccNumber);

int main(void)
{
  // ask for the credit card number
  long int ccNumber = get_long("Number: ");
  //check if is valid
  if (isValid(ccNumber))
  {
    // get the card provider number, 1-amex, 2mastercard, 3 visa
    int cardProvN = isValid(ccNumber);
    if (cardProvN == 1)
    {
      printf("AMEX\n");
    }
    else if (cardProvN == 2)
    {
      printf("MASTERCARD\n");
    }
    else
    {
      printf("VISA\n");
    }
  }
  else
  {
    printf("INVALID\n");
  }
}

bool isEven(int digit)
{
  if (digit % 2 == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int cardProvider(long int oriCCNumber, int cardLength)
{
  int firstCCNumber = oriCCNumber / pow(10, cardLength - 1);

  if (cardLength == 15)
  {
    return 1;
  }
  else if (cardLength == 13)
  {
    return 3;
  }
  else if (cardLength == 16 && firstCCNumber == 4)
  {
    return 3;
  }
  else
  {
    return 2;
  }
}

bool checkLast2Numbers(int last2N)
{
  int firstN = last2N / 10;
  if (firstN == 4 || last2N == 37 || last2N == 34 || (last2N >= 51 && last2N <= 55))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int isValid(long int oriCCNumber)
{
  long int ccNumber = oriCCNumber;
  int totalEven = 0;
  int totalSecondToLast = 0;
  int fixedI;
  // get every other digit starting at second-to-last digit in the totalSecondToLast
  for (int i = 0; ccNumber > 0; i++)
  {
    //get the last digit
    int lastDigit = ccNumber % 10;
    if (isEven(i))
    {
      totalEven += lastDigit;
    }
    else
    {
      if (lastDigit >= 5)
      {
        int multiResult = lastDigit * 2;
        int lastMultiDigit = multiResult % 10;
        int firstMultiDigit = multiResult / 10;
        totalSecondToLast += lastMultiDigit + firstMultiDigit;
      }
      else
      {
        totalSecondToLast += lastDigit * 2;
      }
    }
    // remove the last digit
    ccNumber = ccNumber / 10;
    fixedI = i;
  }

  int totalSum = totalEven + totalSecondToLast;
  int last2Numbers = oriCCNumber / pow(10, fixedI - 1);

  if (totalSum % 10 == 0 && fixedI + 1 >= 13 && fixedI + 1 <= 16 && checkLast2Numbers(last2Numbers))
  {
    int cardProvNumber = cardProvider(oriCCNumber, fixedI + 1);
    return cardProvNumber;
  }
  else
  {
    return 0;
  }
}
