from cs50 import get_float

while True:
    owedCashF = get_float("Change owed: ")
    if owedCashF > 0:
        break

owedCash = owedCashF * 100
quarters = 25;
dimes = 10;
nickels = 5;
pennies = 1;
totalCoins = 0;

while True:
    if owedCash <= 0:
        break
    if owedCash >= quarters:
        owedCash -= quarters
        totalCoins += 1
    elif owedCash >= dimes:
        owedCash -= dimes
        totalCoins += 1
    elif owedCash >= nickels:
        owedCash -= nickels
        totalCoins += 1
    else:
        owedCash -= pennies
        totalCoins += 1

print(f"{totalCoins}")