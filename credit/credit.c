#include <cs50.h>
#include <stdio.h>
#include <string.h>

int check_lenght(long cc_number);
int checksum(long cc_number, int lenght);
string check_cctype(long cc_number, int lenght);

int main(void)
{
// Define variable to store credit card number and request an input from the user

    long cc;

    cc = get_long("Number: ");

// check if credit card number has correct amount of digits - function check_lenght will return 0 if lenght is incorrect, or the lenght itself (therefore, true) if correct

    int lenght = check_lenght(cc);

    if (!check_lenght(cc))
    {
        printf("INVALID\n");
    }
// check if credit card number is valid using Luhn's Algorithm - checksum will return false (0) if not valid, and true (1) if valid
    else if (!checksum(cc, lenght))
    {
        printf("INVALID\n");
    }
// check if credit card number is visa, mastercard or amex
    else
    {
        printf("%s\n", check_cctype(cc, lenght));
    }
}





// abstraction of functions used

int check_lenght(long cc_number)
{
    int lenght = 0;

    while (cc_number != 0)
    {
        cc_number /= 10;
        lenght++;
    }

    if ((lenght < 13) || (lenght > 16) || (lenght == 14))
    {
        return 0;
    }
    else
    {
        return lenght;
    }
}





int checksum(long cc_number, int lenght)
{

// declare new array where each item will be a digit of the credit card number
    int full_ccnumber[lenght];

// c = counter for the loop which matches number of elements in the array, i = index for the array (which matches total elements minus 1 because first element is index 0)
// while loop might read better but usability is more restricted and you need to declare variables outside of loop

    for (int c = lenght, i = lenght - 1; c != 0; c--, i--)
    {
        full_ccnumber[i] = cc_number % 10;
        cc_number /= 10;
    }

// declare variables to store sum of the digits of each half of arrays
    int sum_1 = 0;
    int sum_2 = 0;

// array 1 is going to have the same number of itens regardless if lenght is odd or even

    int half_1[(lenght / 2)];

    for (int c = lenght, i = (lenght / 2 - 1); i >= 0; c -= 2, i--)
    {
        half_1[i] = full_ccnumber[(c - 2)] * 2;
        if (half_1[i] > 4)
        {
            half_1[i] = (half_1[i] / 10) + (half_1[i] % 10);
        }
        sum_1 += half_1[i];
    }

// array 2 is going to have different number of itens depending on if lenght is odd or even

    if (lenght % 2 == 0)
    {
        int half_2[(lenght / 2)];

        for (int c = lenght, i = (lenght / 2 - 1); i >= 0; c -= 2, i--)
        {
            half_2[i] = full_ccnumber[(c - 1)];
            sum_2 += half_2[i];
        }
    }
    else
    {
        int half_2[(lenght / 2 + 1)];

        for (int c = lenght, i = (lenght / 2); i >= 0; c -= 2, i--)
        {
            half_2[i] = full_ccnumber[(c - 1)];
            sum_2 += half_2[i];
        }
    }

// if the last digit of the luhn number is 0, return true (1), else return false (0)
    int total_sum = sum_1 + sum_2;

    if (total_sum % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}







string check_cctype(long cc_number, int lenght)
{
    int full_ccnumber[lenght]; // setting int cc_number into an array to be able to iterate over items and get first and second itens for comparison

    for (int c = lenght, i = lenght - 1; c != 0; c--, i--)
    {
        full_ccnumber[i] = cc_number % 10;
        cc_number /= 10;
    }

    string cctype;

    if (lenght == 15 && full_ccnumber[0] == 3 && (full_ccnumber[1] == 4 || full_ccnumber[1] == 7))
    {
        cctype = "AMEX";
    }
    else if (lenght == 16 && full_ccnumber[0] == 5 && full_ccnumber[1] > 0 & full_ccnumber[1] < 6)
    {
        cctype = "MASTERCARD";
    }
    else if ((lenght == 13 || lenght == 16) && full_ccnumber[0] == 4)
    {
        cctype = "VISA";
    }
    else
    {
        cctype = "INVALID";
    }
    return cctype;
}
