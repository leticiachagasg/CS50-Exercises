#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
// Define variable to store credit card number and request an input from the user

long cc;

cc = get_long("Number: ");

long n = cc;
int count = 0;

while(n != 0)
{
    n = n / 10;
    count++;
}

if ((count < 13) || (count > 16) || (count == 14) || (cc < 0))
{
    printf("INVALID\n");
}

// create an array using the credit card numbers
// count starts at 1 and arrays starts at 0, so we need to adjust it before setting the itens in the array

int full_numbers[count]; //defining array which has the same number os elements as the lenght of credit card number ( = variable "count")
int d = count - 1; //new variable to use as index for the array - the last element will always be the total lenght of array - 1 because arrays start to count at 0
int c = count; // new counter for the loop that will decrease from lenght of credit card number to zero

while(c != 0)
{
    full_numbers[d] = cc % 10;
    cc /= 10;
    d--;
    c--;
}

// print each char in array

// for (int k = 0; k <= (count - 1) ; ++k)
// {
//     printf("%i, ", full_numbers[k]);
// }


int half_numbers1[count/2]; //defining array which has half the number of elements as the lenght of credit card number ( = variable "count")
int half_numbers2even[count/2]; //defining array which has half the number of elements as the lenght of credit card number ( = variable "count")
int half_numbers2odd[count/2+1]; //defining array which has half the number of elements as the lenght of credit card number ( = variable "count")
int M = 0;
int N = 0;

if (count % 2 == 0)
{
    int d2 = count / 2 - 1; //new variable to use as index for the array - the last element will always be the total lenght of array - 1 because arrays start to count at 0
    int d3 = count - 1;

    while(d2 >= 0)
    {
        half_numbers1[d2] = full_numbers[d3-1] * 2;
            if (half_numbers1[d2] > 4)
            {
                half_numbers1[d2] = (half_numbers1[d2] / 10) + (half_numbers1[d2] % 10);
            }
        M += half_numbers1[d2];
        d2--;
        d3 = d3 - 2;
    }

    int d4 = count / 2 - 1; //new variable to use as index for the array - the last element will always be the total lenght of array - 1 because arrays start to count at 0
    int d5 = count - 1;

    while(d4 >= 0)
    {
        half_numbers2even[d4] = full_numbers[d5];
        N += half_numbers2even[d4];
        d4--;
        d5 = d5 - 2;
    }


}

else
{
    int d2 = count / 2 - 1; //new variable to use as index for the array - the last element will always be the total lenght of array - 1 because arrays start to count at 0
    int d3 = count - 1;

    while(d2 >= 0)
    {
        half_numbers1[d2] = full_numbers[d3-1] * 2;
        if (half_numbers1[d2] > 4)
            {
                half_numbers1[d2] = (half_numbers1[d2] / 10) + (half_numbers1[d2] % 10);
            }
        M += half_numbers1[d2];
        d2--;
        d3 = d3 - 2;
    }

    int d4 = count / 2; //new variable to use as index for the array - the last element will always be the total lenght of array - 1 because arrays start to count at 0
    int d5 = count - 1;


    while(d4 >= 0)
    {
        half_numbers2odd[d4] = full_numbers[d5];
        N += half_numbers2odd[d4];
        d4--;
        d5 = d5 - 2;
    }

    }

if ((M+N) % 10 != 0)
   {
    printf("INVALID\n");
    return 1;
   }


if ((count == 15 && full_numbers[0] == 3 && (full_numbers[1] == 4 || full_numbers[1] == 7)))
    {
    printf("AMEX\n");
    }
else if ((count == 13 || count == 16) && (full_numbers[0] == 4))
    {
    printf("VISA\n");
    }
else if ((count == 16) && (full_numbers[0] == 5) && (full_numbers[1] > 0 && full_numbers[1] < 5))
    {
    printf("MASTERCARD\n");
    }
else
    {
    printf("INVALID\n");
    }

}



















// test print for first array

// for (int k = 0; k <= (count / 2 - 1) ; ++k)
// {
//     printf("%i, ", half_numbers1[k]);
// }
// printf("\n%i", half_numbers1[0]);
// printf("\n");



// test print for second array - wich will be different depending on count being even or odd

// if (count % 2 == 0)
// {
//     for (int k = 0; k <= (count / 2 - 1) ; ++k)
//     {
//         printf("%i, ", half_numbers2even[k]);
//     }
//     printf("\n%i", half_numbers2even[0]);
//     printf("\n");
// }

// else
// {
//     for (int k = 0; k <= (count / 2 ) ; ++k)
//     {
//         printf("%i, ", half_numbers2odd[k]);
//     }
//     printf("\n%i", half_numbers2odd[0]);
//     printf("\n");
// }

