#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>


int main(void)
{
    //get string of the text from user
    string text = get_string("text: ");

    //number of text letters & words & sentence
    int letters = 0;

    int words = 0;

    int sentence = 0;

    //loop for count number of letters and sentences and word
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //count number of letters in text
        if (isalpha(text[i]))
        {
            letters++;

            //handle base case
            if (letters == 0)
            {
                return 1;
            }
        }
    }

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //count number of words in text
        if (text[i] == ' ')
        {
            words++;

            //handle base case
            if (words == 0)
            {
                return 2;
            }
        }
    }

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //count number of sentence in text
        if (words == 33 || text[i] == 46 || text[i] == 63)
        {
            sentence++;

            //handle base case
            if (sentence == 0)
            {
                return 3;
            }
        }
    }

    //add it because of some bug and i dont know if there is anothe soloution for handle words count! (for count the last word)
    words++;

    //check the grade of tex with this formula
    float l = (float) letters * 100 / (float) words;
    float s = (float) sentence * 100 / (float) words;
    float index = 0.0588 * l - 0.296 * s - 15.8;

    //grade of the text
    int grade = round(index);
    //what if the text is higher than grade 16
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }

    //what if grade is less than first grade
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %i\n", grade);
    }
}