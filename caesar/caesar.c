#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int only_digits(string s);
int rotate(char c, int key);

int main(int argc, string argv[])
{

// making sure the command line only works with program name + 1 argument

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// using a function to check if the argument has only digits/numbers

    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

//convert the key from string to interger

    int key = atoi(argv[1]);

// get text to be encrypted through rotate function

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    int lenght_text = strlen(plaintext);

// iterate through each characther from user input to encrypt it using the rotate function and print the return of that function

    for (int i = 0; i < lenght_text; i++)
    {
        printf("%c", rotate(plaintext[i], key));
    }
    printf("\n");

}






int rotate(char c, int key)
{

// check if the character if alphabetical - if so, check wheather is upper/not upper (=lower) and apply formula

    if (isalpha(c))
    {
        if (isupper(c))
        {
            char new_c = ((c - 65 + key) % 26) + 65;
            return new_c;
        }

        else
        {
            char new_c = ((c - 97 + key) % 26) + 97;
            return new_c;;
        }
    }

// if the characther is not alphabetical (like spaces, numbers or symbols - return the characther itself without changes

    else
    {
        return c;
    }
}

int only_digits(string s)
{
// iterate through each caracther on the argument to make sure it's all digits - if any character is NOT, print usage message

    for (int i = 0; i < strlen(s); i++)
        if (!isdigit(s[i]))
        {
            printf("Usage: ./caesar key\n");
            return 0;
        }
    return 1;
}
