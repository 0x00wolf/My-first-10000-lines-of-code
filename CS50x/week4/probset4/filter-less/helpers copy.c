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
    return;
}

// Blur image
// Box blur, new value for a pixel
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    for (int i = 0, j = height; i < j; i++)
    {
        for (int c = 0, b = width; c > b; c--)
        {
            RGBTRIPLE tmp = image[i][c];
            copy[i][c] = tmp;

        }
    }
    for (int ii = 0, jj = height; ii < jj; ii++)
    {
        for (int cc = 0, bb = width; cc < bb; cc++)
        {
            if (ii == 0 && cc == 0)
            {
                RGBTRIPLE tmp;
                for (int xx = 0, yy = 1; xx <= yy; xx++)
                {
                    blue = round(copy[ii + xx][cc + xx].rgbtBlue);
                    green = round(copy[ii + xx][cc + xx].rgbtGreen);
                    red = round(copy[ii + xx][cc + xx].rgbtRed);
                    tmp.rgbtBlue += blue;
                    tmp.rgbtGreen += green;
                    tmp.rgbtRed += red;
                }
                image[ii][cc].rgbtBlue = (tmp.rgbtBlue / 4);
                image[ii][cc].rgbtGreen = (tmp.rgbtGreen / 4);
                image[ii][cc].rgbtRed = (tmp.rgbtRed / 4);
            }
            else if (ii != width && cc == 0)
            {
                RGBTRIPLE tmp;
                for (int xx = -1, yy = 1; xx <= yy; xx++)
                {
                    if (xx == -1)
                    {
                    blue = round(copy[ii + xx][cc + xx + 1].rgbtBlue);
                    green = round(copy[ii + xx][cc + xx + 1].rgbtGreen);
                    red = round(copy[ii + xx][cc + xx + 1].rgbtRed);
                    tmp.rgbtBlue += blue;
                    tmp.rgbtGreen += green;
                    tmp.rgbtRed += red;
                    }
                    else
                    {
                    blue = round(copy[ii + xx][cc + xx].rgbtBlue);
                    green = round(copy[ii + xx][cc + xx].rgbtGreen);
                    red = round(copy[ii + xx][cc + xx].rgbtRed);
                    tmp.rgbtBlue += blue;
                    tmp.rgbtGreen += green;
                    tmp.rgbtRed += red;
                    }
                }
                image[ii][cc].rgbtBlue = (tmp.rgbtBlue / 4);
                image[ii][cc].rgbtGreen = (tmp.rgbtGreen / 4);
                image[ii][cc].rgbtRed = (tmp.rgbtRed / 4);
            }
            else if (cc != height && ii == 0 ||)
            {
                continue;
            }
            else
            {

                for (int xx = -1, yy = 1; xx <= yy; xx++)
                {
                    blue = round(copy[ii + xx][cc + xx].rgbtBlue);
                    green = round(copy[ii + xx][cc + xx].rgbtGreen);
                    red = round(copy[ii + cc][ii + xx].rgbtRed);
                }
            }
        }
    }
    return;
}


    // Copy image
    // calculate the average amount of RGB in 3x3 grid and set the middle pixel to average value
        // loop through pixels

        //temp.rgbtBlue = round(copy[ii - 1][i -1].rgbtBlue + copy[ii - 1][i].rgbtBlue + copy[ii - 1][i + 1].rgbtBlue +
        //copy[ii][i -1].rgbtBlue + copy[ii][i].rgbtBlue + copy[ii][i + 1].rgbtBlue +
        //copy[ii + 1][i -1].rgbtBlue + copy[ii + 1][i].rgbtBlue + copy[ii + 1][i + 1].rgbtBlue / 9)

        //temp.rgbtRed = round(copy[ii - 1][i -1].rgbtRed + copy[ii - 1][i].rgbtRed + copy[ii - 1][i + 1].rgbtRed +
        //copy[ii][i -1].rgbtRed + copy[ii][i].rgbtRed + copy[ii][i + 1].rgbtRed +
        //copy[ii + 1][i -1].rgbtRed + copy[ii + 1][i].rgbtRed + copy[ii + 1][i + 1].rgbtRed / 9)

        //temp.rgbtGreen = round(copy[ii - 1][i -1].rgbtGreen + copy[ii - 1][i].rgbtGreen + copy[ii - 1][i + 1].rgbtGreen +
        //copy[ii][i -1].rgbtGreen + copy[ii][i].rgbtGreen + copy[ii][i + 1].rgbtGreen +
        //copy[ii + 1][i -1].rgbtGreen + copy[ii + 1][i].rgbtGreen + copy[ii + 1][i + 1].rgbtGreen / 9)
        //image


//RGBTRIPLE[height][width].rgbtblue
//RGBTRIPLE.rgbtgreen
//RGBTRIPLE.rgbtgreen
//ex image[0][0]    i == 0 && ii == 0  1 2 3
        //                             4 5 6
        //                             7 8 9

            //Loop through and make a copy of the original image
    //loop through again and for position x-1 to x +1, y-1 to y+1 take an average of rgbtRed, Blue and Green from the copy.
        //set the value of each pixel in the original image to it's respective average
        //Do recover before you come back to this old boy. Progress is.. progress.
        //IF recover stumps you. Spend the evening learning python
        //PROGRESS... is.... progress
        //Your unique biological and technological significance will be added to the whole
        //we are borg