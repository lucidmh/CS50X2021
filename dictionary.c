// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
//mine is number of alphabets, 26 letters
const unsigned int N = 26;

unsigned int hashValue;

int size_of_words = 0;

// Hash table
node *table[N];

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //EOF = End Of File

    //aray of the next words
    char nextt[LENGTH + 1];
    //array of word
    //char word[LENGTH];

    //open and load dictionary file
    FILE *infile = fopen(dictionary, "r");

    //check if the is not empty and do the whole function
    if (infile != NULL)
    {
        while (fscanf(infile, "%s", nextt) != EOF)
        {
            //allocate memory for struct
            node *n = malloc(sizeof(node));

            //handle base case
            if (n == NULL)
            {
                printf("oh no, there's something wrong with allocate memmory\n");
                return false;
            }

            else
            {
                //get words from file and copy them into struct node
                strcpy(n->word, nextt);

                //hash words
                hashValue = hash(nextt);

                //now each word should point to next word(make hash table)
                n->next = table[hashValue];
                table[hashValue] = n;

                //pp the number of words
                size_of_words++;
            }
            fclose(infile);
        }
        return true;
    }
    //if dictionary was not ok, return false
    else if (infile == NULL)
    {
        printf("sorry, i cant open the dictionary:)\n");
        return false;
    }
    return false;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //index of words to itrate in a hash table field like a or b or c and...
    hashValue = hash(word);
    node *n = table[hashValue];
    //here we go through hash table
    //but h case comes first!
    //if (n == NULL)
    //{
    //  printf("sorry, there's something wrong with itrate through the dictionary\n");
    //}

    while (n != NULL)
    {
        //we use STRCMP method to check if words in dict
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //this function take str, and then return an index for it
    //i prefer to use hash function with ascii code of first letter
    long x = 0;
    for (int i = 0; strlen(word) > i; i++)
    {
        x += tolower(word[i]);
    }
    return x % N;
}







// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //handle h case and then return the num of words
    if (size_of_words > 0)
    {
        return size_of_words;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    //itrate in hash tables and free up every thing
    for (int i = 0; N > i; i++)
    {
        node *n = table[i];
        //handle h case and then itrate through linked list and free up every thing
        while (n != NULL)
        {
            //tmp
            node *tmp = n;

            //move n to next struct
            n = n->next;

            //free up tmp
            free(tmp);
        }
        //after reading speller hints and src codes week 5, dude i realize i should ass i == n-1 because of the aray start from zero and i will remember this for my whole life
        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
