#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("height for the hashes: ");
    }
    while (height < 1 || height > 8);

    for (int row = 0; row < height; row++)
    {
        for (int space = height - row - 1; space > 0; space--)
        {
            printf(" ");
        }
        int r = row;

        for (int hash = 0; hash < r + 1; hash++)
        {
            printf("#");
        }
        printf("\n");
    }
}