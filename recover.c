#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//a new type for save a byte
typedef uint8_t byte;

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        //open card raw
        FILE *infile = fopen(argv[1], "r");

        //check if the inputfile is ok
        if (infile == NULL)
        {
            printf("sorry, i can't open file\n");
            return 1;
        }

        //pointer to outfile
        FILE *outfile = NULL;

        //buffer array of 512bytes
        byte buffer[512];

        //count number of jpeg image
        int counter = 0;

        //store the name of each jpeg in an n - 1 array
        char filename[8];

        //reapet this loop until we have got to end of the card:
        while (fread(buffer, 512, 1, infile) == 1)
        {
            //check the header block of jpeg
            if (buffer[0] == 0xFF && buffer[1] == 0xD8 && buffer[2] == 0xFF && (buffer[3] & 0xF0) == 0xE0)
            {
                //make name for new jpeg
                sprintf(filename, "%03i.jpg", counter);

                //pp the counter of the jpeg name
                counter++;

                //open and read & write the jpeg
                outfile = fopen(filename, "w");
            }
            //check if there's jpeg image and then write in new file
            if (outfile != NULL)
            {
                fwrite(buffer, 512, 1, outfile);
            }
        }
        //close all of the files
        fclose(outfile);
        fclose(infile);
        return 0;
    }

    else
    {
        printf("usage: ./recover file\n");
        return 1;
    }
}