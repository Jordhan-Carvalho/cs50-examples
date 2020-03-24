#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int z = 0; z < width; z++)
        {
            int avg = (round(((float)image[i][z].rgbtRed + (float)image[i][z].rgbtGreen + (float)image[i][z].rgbtBlue)/3));
            avg %= 255;

            if (avg % 255 == 0)
                {}
            else
            {
               image[i][z].rgbtRed = avg;
               image[i][z].rgbtGreen = avg;
               image[i][z].rgbtBlue = avg;
            }

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int z = 0; z < width; z++)
        {
            int newred;
            int newblue;
            int newgreen;

            newred = round((float)(.393 * image[i][z].rgbtRed + .769 * image[i][z].rgbtGreen + .189 * image[i][z].rgbtBlue));
            newgreen = round((float)(.349 * image[i][z].rgbtRed + .686 * image[i][z].rgbtGreen + .168 * image[i][z].rgbtBlue));
            newblue = round((float)(.272 * image[i][z].rgbtRed + .534 * image[i][z].rgbtGreen + .131 * image[i][z].rgbtBlue));

            if (newred > 255)
                image[i][z].rgbtRed = 255;
            else
                image[i][z].rgbtRed = newred;


            if (newblue > 255)
                image[i][z].rgbtBlue = 255;
            else
                image[i][z].rgbtBlue = newblue;


            if (newgreen > 255)
                image[i][z].rgbtGreen = 255;
            else
                image[i][z].rgbtGreen = newgreen;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
        // first has to check if is odd
    if (height % 2 == 0 || width % 2 == 0)
    {
        for (int i = 0; i < height; i++)
        {
            for (int x = 0; x < width/2; x++)
            {
                int widback = (width-x) - 1;
                int switchgreen = image[i][x].rgbtGreen;
                int switchblue = image[i][x].rgbtBlue;
                int switchred = image[i][x].rgbtRed;

                image[i][x].rgbtGreen = image[i][widback].rgbtGreen;
                image[i][x].rgbtBlue = image[i][widback].rgbtBlue;
                image[i][x].rgbtRed = image[i][widback].rgbtRed;

                image[i][widback].rgbtGreen = switchgreen;
                image[i][widback].rgbtBlue = switchblue;
                image[i][widback].rgbtRed = switchred;
            }
        }
    }
    else
        for (int i = 0; i < height; i++)
            {
                for (int x = 0; x < (width/2)+1; x++)
                {
                    int widback = (width-x) - 1;

                    int switchgreen = image[i][x].rgbtGreen;
                    int switchblue = image[i][x].rgbtBlue;
                    int switchred = image[i][x].rgbtRed;

                    image[i][x].rgbtGreen = image[i][widback].rgbtGreen;
                    image[i][x].rgbtBlue = image[i][widback].rgbtBlue;
                    image[i][x].rgbtRed = image[i][widback].rgbtRed;

                    image[i][widback].rgbtGreen = switchgreen;
                    image[i][widback].rgbtBlue = switchblue;
                    image[i][widback].rgbtRed = switchred;
                }
            }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //another approach
    RGBTRIPLE imageCopy[height][width];
    for(int c = 0; c < height; c++)
    {
        for(int r = 0; r < width; r++)
        {
               if(c==0 && r==0){
                int avgRed =round((image[c][r].rgbtRed+image[c+1][r].rgbtRed+image[c][r+1].rgbtRed+image[c+1][r+1].rgbtRed)/4.0) ;
                imageCopy[c][r].rgbtRed=avgRed;
                int avgGreen =round((image[c][r].rgbtGreen+image[c+1][r].rgbtGreen+image[c][r+1].rgbtGreen+image[c+1][r+1].rgbtGreen)/4.0) ;
                imageCopy[c][r].rgbtGreen=avgGreen;
                int avgBlue =round((image[c][r].rgbtBlue+image[c+1][r].rgbtBlue+image[c][r+1].rgbtBlue+image[c+1][r+1].rgbtBlue)/4.0) ;
                imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else if(c==0 && r==width-1)
            {
               int avgRed =round((image[c+1][r].rgbtRed+image[c][r].rgbtRed+image[c][r-1].rgbtRed+image[c+1][r-1].rgbtRed)/4.0);
               imageCopy[c][r].rgbtRed=avgRed;
               int avgGreen =round((image[c+1][r].rgbtGreen+image[c][r].rgbtGreen+image[c][r-1].rgbtGreen+image[c+1][r-1].rgbtGreen)/4.0);
               imageCopy[c][r].rgbtGreen=avgGreen;
               int avgBlue =round((image[c+1][r].rgbtBlue+image[c][r].rgbtBlue+image[c][r-1].rgbtBlue+image[c+1][r-1].rgbtBlue)/4.0);
               imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else if(c==height-1 && r==width-1)
            {
                int avgRed =round((image[c-1][r].rgbtRed+image[c][r].rgbtRed+image[c][r-1].rgbtRed+image[c-1][r-1].rgbtRed)/4.0);
                imageCopy[c][r].rgbtRed=avgRed;
                 int avgBlue =round((image[c-1][r].rgbtBlue+image[c][r].rgbtBlue+image[c][r-1].rgbtBlue+image[c-1][r-1].rgbtBlue)/4.0);
                imageCopy[c][r].rgbtBlue=avgBlue;
                 int avgGreen =round((image[c-1][r].rgbtGreen+image[c][r].rgbtGreen+image[c][r-1].rgbtGreen+image[c-1][r-1].rgbtGreen)/4.0);
                imageCopy[c][r].rgbtGreen=avgGreen;
            }
            else if(c==height-1 && r==0)
            {
                int avgRed =round((image[c-1][r].rgbtRed+image[c][r].rgbtRed+image[c][r+1].rgbtRed+image[c-1][r+1].rgbtRed)/4.0);
                imageCopy[c][r].rgbtRed=avgRed;
                int avgGreen =round((image[c-1][r].rgbtGreen+image[c][r].rgbtGreen+image[c][r+1].rgbtGreen+image[c-1][r+1].rgbtGreen)/4.0);
                imageCopy[c][r].rgbtGreen=avgGreen;
                int avgBlue =round((image[c-1][r].rgbtBlue+image[c][r].rgbtBlue+image[c][r+1].rgbtBlue+image[c-1][r+1].rgbtBlue)/4.0);
                imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else if(r==0)
            {
                int avgRed =round((image[c][r].rgbtRed+image[c+1][r].rgbtRed+image[c][r+1].rgbtRed+image[c+1][r+1].rgbtRed+image[c-1][r].rgbtRed+image[c-1][r+1].rgbtRed)/6.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgBlue =round((image[c][r].rgbtBlue+image[c+1][r].rgbtBlue+image[c][r+1].rgbtBlue+image[c+1][r+1].rgbtBlue+image[c-1][r].rgbtBlue+image[c-1][r+1].rgbtBlue)/6.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            int avgGreen =round((image[c][r].rgbtGreen+image[c+1][r].rgbtGreen+image[c][r+1].rgbtGreen+image[c+1][r+1].rgbtGreen+image[c-1][r].rgbtGreen+image[c-1][r+1].rgbtGreen)/6.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            }
            else if(r==width-1)
            {
                int avgRed =round((image[c][r].rgbtRed+image[c-1][r].rgbtRed+image[c+1][r].rgbtRed+image[c+1][r-1].rgbtRed+image[c][r-1].rgbtRed+image[c-1][r-1].rgbtRed)/6.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgGreen =round((image[c][r].rgbtGreen+image[c-1][r].rgbtGreen+image[c+1][r].rgbtGreen+image[c+1][r-1].rgbtGreen+image[c][r-1].rgbtGreen+image[c-1][r-1].rgbtGreen)/6.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            int avgBlue =round((image[c][r].rgbtBlue+image[c-1][r].rgbtBlue+image[c+1][r].rgbtBlue+image[c+1][r-1].rgbtBlue+image[c][r-1].rgbtBlue+image[c-1][r-1].rgbtBlue)/6.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else if(c==0)
            {
                int avgRed =round((image[c][r].rgbtRed+image[c+1][r].rgbtRed+image[c+1][r-1].rgbtRed+image[c][r-1].rgbtRed+image[c][r+1].rgbtRed+image[c+1][r+1].rgbtRed)/6.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgBlue =round((image[c][r].rgbtBlue+image[c+1][r].rgbtBlue+image[c+1][r-1].rgbtBlue+image[c][r-1].rgbtBlue+image[c][r+1].rgbtBlue+image[c+1][r+1].rgbtBlue)/6.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            int avgGreen =round((image[c][r].rgbtGreen+image[c+1][r].rgbtGreen+image[c+1][r-1].rgbtGreen+image[c][r-1].rgbtGreen+image[c][r+1].rgbtGreen+image[c+1][r+1].rgbtGreen)/6.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            }
            else if(c==height-1)
            {
                int avgRed =round((image[c][r].rgbtRed+image[c-1][r].rgbtRed+image[c][r+1].rgbtRed+image[c-1][r-1].rgbtRed+image[c-1][r+1].rgbtRed+image[c][r-1].rgbtRed)/6.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgGreen =round((image[c][r].rgbtGreen+image[c-1][r].rgbtGreen+image[c][r+1].rgbtGreen+image[c-1][r-1].rgbtGreen+image[c-1][r+1].rgbtGreen+image[c][r-1].rgbtGreen)/6.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            int avgBlue =round((image[c][r].rgbtBlue+image[c-1][r].rgbtBlue+image[c][r+1].rgbtBlue+image[c-1][r-1].rgbtBlue+image[c-1][r+1].rgbtBlue+image[c][r-1].rgbtBlue)/6.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            }
            else
            {
              int avgRed =round((image[c-1][r].rgbtRed+image[c][r].rgbtRed+image[c+1][r].rgbtRed+image[c-1][r+1].rgbtRed+image[c][r+1].rgbtRed+image[c+1][r+1].rgbtRed+image[c-1][r-1].rgbtRed+image[c][r-1].rgbtRed+image[c+1][r-1].rgbtRed)/9.0) ;
            imageCopy[c][r].rgbtRed=avgRed;
            int avgBlue =round((image[c-1][r].rgbtBlue+image[c][r].rgbtBlue+image[c+1][r].rgbtBlue+image[c-1][r+1].rgbtBlue+image[c][r+1].rgbtBlue+image[c+1][r+1].rgbtBlue+image[c-1][r-1].rgbtBlue+image[c][r-1].rgbtBlue+image[c+1][r-1].rgbtBlue)/9.0) ;
            imageCopy[c][r].rgbtBlue=avgBlue;
            int avgGreen =round((image[c-1][r].rgbtGreen+image[c][r].rgbtGreen+image[c+1][r].rgbtGreen+image[c-1][r+1].rgbtGreen+image[c][r+1].rgbtGreen+image[c+1][r+1].rgbtGreen+image[c-1][r-1].rgbtGreen+image[c][r-1].rgbtGreen+image[c+1][r-1].rgbtGreen)/9.0) ;
            imageCopy[c][r].rgbtGreen=avgGreen;
            }
        }

    }
     for(int c = 0; c < height; c++)
    {
        for(int r = 0; r < width; r++)
        {
            image[c][r]=imageCopy[c][r];
        }
    }
    return;
}
