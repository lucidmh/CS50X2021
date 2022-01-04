#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //2d array of height and width of pixels
    for (int i = 0; height > i; i++)
    {
        for (int j = 0; width > j; j++)
        {
            //make a float for every picture rgb colors pixel
            float red = (image[i][j].rgbtRed);
            float green = (image[i][j].rgbtGreen);
            float blue = (image[i][j].rgbtBlue);
            
            //make an average between pixels
            float rgb = (red + green + blue);
            int average = round(rgb / 3.0);
            
            //every rgb pixels equels to average of them
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
            
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //2d array of height and width pixels
    for (int i = 0; height > i; i++)
    {
        for (int j = 0; width > j; j++)
        {
            
            //calculate the value of sepias pixel with the formula
            float sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            float sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            float sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            
            //check if sepia pixels are less than 255
            if (sepiaRed < 255 && sepiaGreen < 255 && sepiaBlue < 255)
            {
                image[i][j].rgbtRed = sepiaRed;
                image[i][j].rgbtGreen = sepiaGreen;
                image[i][j].rgbtBlue = sepiaBlue;
            }
            
            //if not equel the rgb of pixels to 255(the highest hexsadecimal value)
            else if (sepiaRed > 255)
            {
                image[i][j].rgbtRed = 255;
                
                if (sepiaGreen > 255)
                {
                    image[i][j].rgbtGreen = 255;
                    
                    if (sepiaBlue > 255)
                    {
                        image[i][j].rgbtBlue = 255;
                    }
                }
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //2d array of height and width
    for (int i = 0; height > i; i++)
    {
        for (int j = 0; width / 2 > j; j++)
        {
            //int of rgb of each pixel
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            //each rgb pixel will go to opposite side
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            //each new pixel is equal to real rgb
            image[i][width - j - 1].rgbtRed = red;
            image[i][width - j - 1].rgbtGreen = green;
            image[i][width - j - 1].rgbtBlue = blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newimg[height][width];

    //each pixel of new image array
    for (int a = 0; height > a; a++)
    {
        for (int b = 0; width > b; b++)
        {
            newimg[a][b] = image[a][b];
        }
    }
    //2d array of height and width
    for (int i = 0; height > i; i++)
    {
        for (int j = 0; width > j; j++)
        {
            float red = 0;
            float blue = 0;
            float green = 0;
            int counter = 0;
            //check the horizantaly neighbour of our origin pixel
            for (int x = -1; x < 2; x++)
            {
                //check the verticaly neighbor of our origin pixel
                for (int y = -1; y < 2; y++)
                {

                    //check if the neighbor pixels are actually exist and is they really exist retutn 0
                    //that pixel is neighbor with origin pixel horizantally
                    if (i + x < 0 || x + i >= height)
                    {
                        continue;
                    }

                    //that pixel is neighbor with origin pixel verticaly
                    if (j + y < 0 || y + j >= width)
                    {
                        continue;
                    }

                    //check the neighbor pixel and go throuh them
                    blue += newimg[i + x][j + y].rgbtBlue;
                    red += newimg[i + x][j + y].rgbtRed;
                    green += newimg[i + x][j + y].rgbtGreen;

                    //pp number of neighbor pixels
                    counter++;
                }
            }
            //get average of neighbor width and height pixels to blur the real picture
            image[i][j].rgbtRed = (int)round(red / counter);
            image[i][j].rgbtBlue = (int)round(blue / counter);
            image[i][j].rgbtGreen = (int)round(green / counter);
        }
    }
    return;
}