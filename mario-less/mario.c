#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int h;

// get the height of the pyramid - number must be between 1 and 8 inclusive

    do
    {
        h = get_int("Height: ");
    }
    while (h < 1 || h > 8);


    int spaces = h - 1;

//for loop to print number of lines = heigh

    for (int c = 0; c < h; c++)
    {
// print number of spaces on the line (which will start as the number of heigh - 1, as defined in the variable spaces)

        for (int i = spaces; i != 0; i--)
        {
            printf(" ");
        }

//print number of blocks on each line (which will be the heigh - spaces)

        for (int j = (h - spaces); j != 0; j--)
        {

            printf("#");
        }

//when you subtract one space from the line, you will increase one block (because blocks = heigh - spaces)

        spaces--;
        printf("\n");

    }
}