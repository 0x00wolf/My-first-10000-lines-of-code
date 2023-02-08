#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change due (1 to 200 cents): ");
        if (cents <= 200 && cents >= 1)
        {
            return cents;
        }
        else
        {
            cents = 0;
            printf("I am a happy robot, are you a happy cat?!\n");
        }
    }
    while (cents == 0);
    return cents;
}
//quotient = dividend / divisor
int calculate_quarters(int cents)
{
    int remainder = cents % 25;
    int numquarters = (cents - remainder) / 25;
    return numquarters;
}

int calculate_dimes(int cents)
{
    int remainder = cents % 10;
    int numdimes = (cents - remainder) / 10;
    return numdimes;
}

int calculate_nickels(int cents)
{
    int remainder = cents % 5;
    int numnickels = (cents - remainder) / 5;
    return numnickels;
}

int calculate_pennies(int cents)
{
    int remainder = cents % 1;
    int numpennies = cents - remainder;
    return numpennies;
}
