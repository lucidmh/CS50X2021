#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //money that we owed
    float dollar = 0;

    //get the value of owed money from user
    do
    {
        dollar = get_float("owed money: ");
    }
    //check if owed money is true
    while (dollar < 0);

    //count number of coin and cent of money that we owed
    int count = 0;
    int cent = round(dollar * 100);

    //make 25, 10, 5, 1 cent and count them
    while (count == 0)
    {
        //25 cent coin
        while (cent >= 25)
        {
            cent -= 25;
            count++;
        }

        //10 cent coin
        while (cent >= 10)
        {
            cent -= 10;
            count++;
        }

        //5 cent coin
        while (cent >= 5)
        {
            cent -= 5;
            count++;
        }

        //1 cent coins
        while (cent >= 1)
        {
            cent -= 1;
            count++;
        }

        if (cent == 0)
        {
            //print number of coins (count)
            printf("number of rounded coin that i gave you: %i\n", count);
        }
    }
}
