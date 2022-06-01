#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

//declaring functions so the program knows there is a definition somewhere and doesn't crash when compiling

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{

    string text = get_string("Text: ");


// define variable through calling the functions we will create later

    int letters = count_letters(text);

    int words = count_words(text);

    int sentences = count_sentences(text);


// define new variables to use in celman-liau index - cast one of the values to float to keep decimals stored

    float L = 100 * letters / (float) words;

    float S = 100 * sentences / (float) words;


// celman-liau index operation - do not forget to round

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }

    else
    {
        printf("Grade 16+\n");
    }

}

// after closing brackets for main function, present definition of the other functions used

int count_words(string text)
{
    int spaces = 0;

    for (int i = 0; text[i] != '\0'; i++)

        if (isspace(text[i]))
        {
            spaces++;
        }

    int words = spaces + 1;
    return words;
}


int count_letters(string text)
{
    int letters = 0;

    for (int i = 0; text[i] != '\0'; i++)

        if (isalpha(text[i]))
        {
            letters++;
        }
    return letters;
}


int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0; text[i] != '\0'; i++)

        if ((text[i] == 46) || (text[i] == 63) || (text[i] == 33))
        {
            sentences++;
        }
    return sentences;
}