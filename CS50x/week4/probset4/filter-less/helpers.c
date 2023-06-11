#include "helpers.h"
#include <math.h>
#include <stdio.h>

//Header file:
//void grayscale(int height, int width, RGBTRIPLE image[height][width]);
//How to:
// Grayscale: (take an average of the values of each 24 byte valueset and change all values in the output of
// the corresponding dataset to the averaged amount) must round to an int value (not float).
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
//loop through pixels by row and then height.
    for (int i = 0, j = height; i < j; i++)
    {
        for (int cc = 0, bb = width; cc < bb; cc++)
        {
            int avrg = round((image[i][cc].rgbtBlue + image[i][cc].rgbtGreen + image[i][cc].rgbtRed) / 3.0);
            image[i][cc].rgbtBlue = avrg;
            image[i][cc].rgbtGreen = avrg;
            image[i][cc].rgbtRed = avrg;
        }
    }
    return;
}


// Convert image to sepia
// Sepia: Uses an algorithm relative to the desired color scheme of the output.
//sepiaRed = .393* originalRed + .769 * originalGreen + .189 * originalBlue
//sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
//sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
//****Have to be rounded to the nearest integer. Must be capped at 255 if (outcome > 255)
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
        for (int i = 0, j = height; i < j; i++)
    {
        for (int cc = 0, bb = width; cc < bb; cc++)
        {
            int sepiared = round((image[i][cc].rgbtRed * .393) +
            (image[i][cc].rgbtGreen * .769) +
            (image[i][cc].rgbtBlue * .189));
            if (sepiared > 255)
            {
                sepiared = 255;
            }
            int sepiagreen = round((image[i][cc].rgbtRed * .349) +
            (image[i][cc].rgbtGreen * .686) +
            (image[i][cc].rgbtBlue * .168));
            if (sepiagreen > 255)
            {
                sepiagreen = 255;
            }
            int sepiablue = round((image[i][cc].rgbtRed * .272) +
            (image[i][cc].rgbtGreen * .534) +
            (image[i][cc].rgbtBlue * .131));
            if (sepiablue > 255)
            {
                sepiablue = 255;
            }
            image[i][cc].rgbtBlue = sepiablue;
            image[i][cc].rgbtGreen = sepiagreen;;
            image[i][cc].rgbtRed = sepiared;
        }
    }
    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, j = height; i < j; i++)
    {
        RGBTRIPLE array[width];
        int x = 0;
        for (int cc = width - 1, bb = 0; cc >= bb; cc--)
        {
            RGBTRIPLE tmp = image[i][cc];
            array[x] = tmp;
            x += 1;
        }
        for (int ccc = 0, bbb = width; ccc < bbb; ccc++)
        {
            RGBTRIPLE bmp = array[ccc];
            image[i][ccc] = bmp;
        }
    }
    return;x
}

// Blur image
// Box blur, new value for a pixel
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            RGBTRIPLE tmp = image[y][x];
            copy[y][x] = tmp;
        }
    }
    for (int yy = 0; yy < height; yy++)
    {
        for (int xx = 0; xx < width; xx++)
        {
        //corners
            //upper left corner (xx, yy || xx + 1, yy || xx, yy + 1 || xx + 1, yy + 1) (0 + 1)
            if (xx == 0 && yy == 0)
            {
                image[yy][xx].rgbtBlue = round((copy[yy][xx].rgbtBlue + copy[yy][xx + 1].rgbtBlue + copy[yy + 1][xx].rgbtBlue + copy[yy + 1][xx + 1].rgbtBlue) / 4.0);

                image[yy][xx].rgbtGreen = round((copy[yy][xx].rgbtGreen + copy[yy][xx + 1].rgbtGreen + copy[yy + 1][xx].rgbtGreen + copy[yy + 1][xx + 1].rgbtGreen) / 4.0);

                image[yy][xx].rgbtRed = round(( copy[yy][xx].rgbtRed + copy[yy][xx + 1].rgbtRed + copy[yy + 1][xx].rgbtRed + copy[yy + 1][xx + 1].rgbtRed) / 4.0);
            }
            //upper right corner
            else if (xx == width - 1 && yy == 0)
            {
                image[yy][xx].rgbtBlue = round((copy[yy][xx].rgbtBlue + copy[yy][xx - 1].rgbtBlue + copy[yy + 1][xx].rgbtBlue + copy[yy + 1][xx - 1].rgbtBlue) / 4.0);

                image[yy][xx].rgbtGreen = round((copy[yy][xx].rgbtGreen + copy[yy][xx - 1].rgbtGreen + copy[yy + 1][xx].rgbtGreen + copy[yy + 1][xx - 1].rgbtGreen) / 4.0);

                image[yy][xx].rgbtRed = round(( copy[yy][xx].rgbtRed + copy[yy][xx - 1].rgbtRed + copy[yy + 1][xx].rgbtRed + copy[yy + 1][xx - 1].rgbtRed) / 4.0);
            }
             //Corner Bottom Left
            else if (xx == 0 && yy == height - 1)
            {
                image[yy][xx].rgbtBlue = round((copy[yy][xx].rgbtBlue + copy[yy][xx + 1].rgbtBlue + copy[yy - 1][xx].rgbtBlue + copy[yy - 1][xx + 1].rgbtBlue) / 4.0);

                image[yy][xx].rgbtGreen = round((copy[yy][xx].rgbtGreen + copy[yy][xx + 1].rgbtGreen + copy[yy - 1][xx].rgbtGreen + copy[yy - 1][xx + 1].rgbtGreen) / 4.0);

                image[yy][xx].rgbtRed = round((copy[yy][xx].rgbtRed + copy[yy][xx + 1].rgbtRed + copy[yy - 1][xx].rgbtRed + copy[yy - 1][xx + 1].rgbtRed) / 4.0);
            }
             else if (xx == width - 1 && yy == height - 1)
            {
                image[yy][xx].rgbtBlue = round((copy[yy][xx].rgbtBlue + copy[yy][xx - 1].rgbtBlue + copy[yy - 1][xx].rgbtBlue + copy[yy - 1][xx - 1].rgbtBlue) / 4.0);

                image[yy][xx].rgbtGreen = round((copy[yy][xx].rgbtGreen + copy[yy][xx - 1].rgbtGreen + copy[yy - 1][xx].rgbtGreen + copy[yy - 1][xx - 1].rgbtGreen) / 4.0);

                image[yy][xx].rgbtRed = round(( copy[yy][xx].rgbtRed + copy[yy][xx - 1].rgbtRed + copy[yy - 1][xx].rgbtRed + copy[yy - 1][xx - 1].rgbtRed) / 4.0);
            }
            //top side works ostensibly
            else if (yy == 0 && xx > 0 && xx < width - 1)
            {
                image[yy][xx].rgbtBlue = round((copy[yy][xx -1].rgbtBlue + copy[yy][xx].rgbtBlue + copy[yy][xx + 1].rgbtBlue + copy[yy + 1][xx -1].rgbtBlue + copy[yy + 1][xx].rgbtBlue + copy[yy + 1][xx + 1].rgbtBlue) / 6.0);

                image[yy][xx].rgbtGreen = round((copy[yy][xx -1].rgbtGreen + copy[yy][xx].rgbtGreen + copy[yy][xx + 1].rgbtGreen + copy[yy + 1][xx -1].rgbtGreen + copy[yy + 1][xx].rgbtGreen + copy[yy + 1][xx + 1].rgbtGreen) / 6.0);

                image[yy][xx].rgbtRed = round((copy[yy][xx -1].rgbtRed + copy[yy][xx].rgbtRed + copy[yy][xx + 1].rgbtRed + copy[yy + 1][xx -1].rgbtRed + copy[yy + 1][xx].rgbtRed + copy[yy + 1][xx + 1].rgbtRed) / 6.0);
            }
              else if (yy == height - 1 && xx > 0  && xx < width - 1)
            {
                image[yy][xx].rgbtBlue = round((copy[yy - 1][xx - 1].rgbtBlue + copy[yy - 1][xx].rgbtBlue + copy[yy - 1][xx + 1].rgbtBlue + copy[yy][xx - 1].rgbtBlue + copy[yy][xx].rgbtBlue + copy[yy][xx + 1].rgbtBlue) / 6.0);

                image[yy][xx].rgbtGreen = round((copy[yy - 1][xx - 1].rgbtGreen + copy[yy - 1][xx].rgbtGreen + copy[yy - 1][xx + 1].rgbtGreen + copy[yy][xx - 1].rgbtGreen + copy[yy][xx].rgbtGreen + copy[yy][xx + 1].rgbtGreen) / 6.0);

                image[yy][xx].rgbtRed = round((copy[yy - 1][xx - 1].rgbtRed + copy[yy - 1][xx].rgbtRed + copy[yy - 1][xx + 1].rgbtRed + copy[yy][xx - 1].rgbtRed + copy[yy][xx].rgbtRed + copy[yy][xx + 1].rgbtRed) / 6.0);
            }
             //Left side works ostensibly
            else if (xx == 00 && yy > 0 && yy < height - 1)
            {
                image[yy][xx].rgbtBlue = round((copy[yy - 1][xx].rgbtBlue + copy[yy - 1][xx + 1].rgbtBlue + copy[yy][xx].rgbtBlue + copy[yy][xx + 1].rgbtBlue + copy[yy + 1][xx].rgbtBlue + copy[yy + 1][xx + 1].rgbtBlue) / 6.0);

                image[yy][xx].rgbtGreen = round((copy[yy - 1][xx].rgbtGreen + copy[yy - 1][xx + 1].rgbtGreen + copy[yy][xx].rgbtGreen + copy[yy][xx + 1].rgbtGreen + copy[yy + 1][xx].rgbtGreen + copy[yy + 1][xx + 1].rgbtGreen) / 6.0);

                image[yy][xx].rgbtRed = round((copy[yy - 1][xx].rgbtRed + copy[yy - 1][xx + 1].rgbtRed + copy[yy][xx].rgbtRed + copy[yy][xx + 1].rgbtRed + copy[yy + 1][xx].rgbtRed + copy[yy + 1][xx + 1].rgbtRed) / 6.0);
            }
            //EVIL RIGHT SIDE
            else if (xx == width - 1 && yy > 0 && yy < height - 1)
            {
                image[yy][xx].rgbtBlue = round((copy[yy - 1][xx - 1].rgbtBlue + copy[yy - 1][xx].rgbtBlue + copy[yy][xx - 1].rgbtBlue + copy[yy][xx].rgbtBlue + copy[yy + 1][xx -1].rgbtBlue + copy[yy + 1][xx].rgbtBlue) / 6.0);

                image[yy][xx].rgbtGreen = round((copy[yy - 1][xx - 1].rgbtGreen + copy[yy - 1][xx].rgbtGreen + copy[yy][xx - 1].rgbtGreen + copy[yy][xx].rgbtGreen + copy[yy + 1][xx -1].rgbtGreen + copy[yy + 1][xx].rgbtGreen) / 6.0);

                image[yy][xx].rgbtRed = round((copy[yy - 1][xx - 1].rgbtRed + copy[yy - 1][xx].rgbtRed + copy[yy][xx - 1].rgbtRed + copy[yy][xx].rgbtRed + copy[yy + 1][xx -1].rgbtRed + copy[yy + 1][xx].rgbtRed) / 6.0);
            }
            else
            {
                image[yy][xx].rgbtBlue = round((copy[yy - 1][xx -1].rgbtBlue + copy[yy - 1][xx].rgbtBlue + copy[yy - 1][xx + 1].rgbtBlue + copy[yy][xx -1].rgbtBlue + copy[yy][xx].rgbtBlue + copy[yy][xx + 1].rgbtBlue +
                copy[yy + 1][xx -1].rgbtBlue + copy[yy + 1][xx].rgbtBlue + copy[yy + 1][xx + 1].rgbtBlue) / 9.0);

                image[yy][xx].rgbtGreen = round((copy[yy - 1][xx -1].rgbtGreen + copy[yy - 1][xx].rgbtGreen + copy[yy - 1][xx + 1].rgbtGreen + copy[yy][xx -1].rgbtGreen + copy[yy][xx].rgbtGreen + copy[yy][xx + 1].rgbtGreen +
                copy[yy + 1][xx -1].rgbtGreen + copy[yy + 1][xx].rgbtGreen + copy[yy + 1][xx + 1].rgbtGreen) / 9.0);

                image[yy][xx].rgbtRed = round((copy[yy - 1][xx -1].rgbtRed + copy[yy - 1][xx].rgbtRed + copy[yy - 1][xx + 1].rgbtRed + copy[yy][xx -1].rgbtRed + copy[yy][xx].rgbtRed + copy[yy][xx + 1].rgbtRed +
                copy[yy + 1][xx -1].rgbtRed + copy[yy + 1][xx].rgbtRed + copy[yy + 1][xx + 1].rgbtRed) / 9.0);
            }
        }
    }
    return;
}

