#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, string argv[])

//if argc ok, do the whole pset
{
    if (argc == 2)
    {
        //turn second argv ant turn it to an integer(because its string right now)
        int a = atoi(argv[1]);

        //handle base case
        if (0 > a)
        {
            printf("usage: ./caesar key\n");
            return 1;
        }

        //check if all of the key char is alphabetical
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                printf("key most contain only numbers\n");
                return 1;
            }
        }
        //get plaintext from user
        string plaintext = get_string("plaintext: ");
        string ciphertext = malloc(sizeof(plaintext));

        //print ciphertext for user
        printf("ciphertext: ");



        //check if plaintext is okay and encipher
        for (int j = 0; (strlen(plaintext)) > j; j++)
        {
            //check if text letter is uppercase
            if (isupper(plaintext[j]))
            {
                printf("%c", (((plaintext[j] - 65) + a) % 26) + 65);
            }

            //check if text letter is lowercase
            if (islower(plaintext[j]))
            {
                printf("%c", (((plaintext[j] - 97) + a) % 26) + 97);
            }
            //check anything else
            else
            {
                printf("%c", plaintext[j]);
            }

            //print the ciphertext string
            printf("%s", ciphertext);
        }
        printf("\n");

        //free memmory that we get from system to dont have leck memmory
        free(ciphertext);
    }
    //if argc is not 2, print usage bla bla bla
    else
    {
        printf("usage: ./caesar key\n");
        return 1;
    }
}
