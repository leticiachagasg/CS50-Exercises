#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int only_letters(string s);
int total_digits(string s);
int is_repeated(string s);
char rotate(char c, string key);

int main(int argc, string argv[])
{

//check if parameter has single argument

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

//  check if the key has 26 digits total

    else if (total_digits(argv[1]) != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }

// check if the key has only letters in it

    else if (!only_letters(argv[1]))
    {
        printf("Key must contain only letters\n");
        return 1;
    }

// check if any of the letters is repeated

    else if (is_repeated(argv[1]))
    {
        printf("Letters must not be repeated\n");
        return 1;
    }

// if all criteria is met, prompt user for plaintext and cipher it

    else
    {
        string plaintext = get_string("plaintext: ");

        printf("ciphertext: ");

        int lenght_text = strlen(plaintext);

// iterate through each characther from user input to encrypt it using the rotate function and print the return value of that function

        for (int i = 0; i < lenght_text; i++)
        {
            printf("%c", rotate(plaintext[i], argv[1]));
        }
        printf("\n");
    }
}







int only_letters(string s)
{
// iterate through each caracther on the string s (==key) to make sure it's all letters
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isalpha(s[i]))
        {
            return 0;
        }
    }
    return 1;
}



int is_repeated(string s)
{

// first loop will select one character, second inner loop will iterate again through all of the string and if the values are equal, will add 1 to variable count
    // since each letter should appear once, the total result of count must be 26

    int count = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        for (int j = 0; j < strlen(s); j++)
        {
            if (tolower(s[j]) == tolower(s[i]))
            {
                count ++;
            }
        }
    }
    if (count != 26)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int total_digits(string s)
{
    int count = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        count += 1;
    }
    return count;
}


char rotate(char c, string key)
{

//define two arrays to serve as key library, and separate lower/upper to preserve case when encrypting
// this will give you one array where each char of string key is an ordened item in lower or upper case

    char key_lower[26];
    char key_upper[26];

    for (int i = 0; i <= 25; i++)
    {
        key_upper[i] = toupper(key[i]);
        key_lower[i] = tolower(key[i]);
    }

// check if the character if alphabetical - if so, check wheather is upper/not upper and apply formula accordling
// subtract the value of ascii "a" or "A" to threat each char as 0 - 25 and use this as index

    if (isalpha(c))
    {
        if (isupper(c))
        {
            char new_c = key_upper[(c - 65)];
            return new_c;
        }

        else
        {
            char new_c = key_lower[(c - 97)];
            return new_c;;
        }
    }
// if the characther is not alphabetical (like spaces, numbers or symbols - return the characther itself without changes

    else
    {
        return c;
    }
}