#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_valid_float(void);
int calculateCoins(int owedCashCoins);

int main(void)
{
  // ask user the change (float)
  float owedCash = get_valid_float();
  // convert dollars to cents float to int
  int owedCashCoins = round(owedCash * 100);
  // Do the math Loop reducing the coins from the owed value
  int coins = calculateCoins(owedCashCoins);
  // return the number of coins to return
  printf("%i\n", coins);
}

int calculateCoins(int owedCashCoins)
{
  // declare the coins
  int quarters = 25;
  int dimes = 10;
  int nickels = 5;
  int pennies = 1;
  int totalCoins = 0;
  do
  {
    if (owedCashCoins >= quarters)
    {
      owedCashCoins -= quarters;
      totalCoins++;
    }
    else if (owedCashCoins >= dimes)
    {
      owedCashCoins -= dimes;
      totalCoins++;
    }
    else if (owedCashCoins >= nickels)
    {
      owedCashCoins -= nickels;
      totalCoins++;
    }
    else if (owedCashCoins >= pennies)
    {
      owedCashCoins -= pennies;
      totalCoins++;
    }
  } while (owedCashCoins > 0);
  return totalCoins;
}

float get_valid_float(void)
{
  float n;
  do
  {
    n = get_float("Change owed: ");
  } while (n < 0);
  return n;
}