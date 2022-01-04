#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int start;
    do
    {
        start = get_int("start size: ");
    }
    while (start < 9);

    int end;
    do
    {
        end = get_int("end size: ");
    }
    while (end < start);
    int years = 0;
    while (end > start)
    
    {
        start = start + (start / 3) - (start / 4);
        \
        years++;
    }
    printf("Years: %i/start", years);
}