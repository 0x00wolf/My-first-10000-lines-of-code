#include "helpers.h"
#include <math.h>

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


// Reflect image horizontally
//swap the pixels on opposite sides for rows
//loop through every row
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, j = height - 1; i < j; i++)
    {
        RGBTRIPLE array[width];
        int x = 0;
        for (int cc = width - 1, bb = 0; cc >= bb; cc--)
        {
            // need to flip the pixels before reversing the image. think on how
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
    return;
}

//RGBTRIPLE[height][width].rgbtblue
//RGBTRIPLE.rgbtgreen
//RGBTRIPLE.rgbtgreen
//ex image[0][0]

void inverseworld(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0, j = height - 1; i < j; i++)
    {
        RGBTRIPLE array[width];
        int x = 0;
        for (int cc = width - 1, bb = 0; cc >= bb; cc--)
        {
            // need to flip the pixels before reversing the image. think on how
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



            else if (i == 0 && ii > 0)
            {
                int tmpb = round(copy[ii - 1][i -1].rgbtBlue + copy[ii - 1][i].rgbtBlue + copy[ii - 1][i + 1].rgbtBlue +
                    copy[ii][i -1].rgbtBlue + copy[ii][i].rgbtBlue + copy[ii][i + 1].rgbtBlue +
                    copy[ii + 1][i -1].rgbtBlue + copy[ii + 1][i].rgbtBlue + copy[ii + 1][i + 1].rgbtBlue / 9);

                int tmpr = round(copy[ii - 1][i -1].rgbtRed + copy[ii - 1][i].rgbtRed + copy[ii - 1][i + 1].rgbtRed +
                    copy[ii][i -1].rgbtRed + copy[ii][i].rgbtRed + copy[ii][i + 1].rgbtRed +
                    copy[ii + 1][i -1].rgbtRed + copy[ii + 1][i].rgbtRed + copy[ii + 1][i + 1].rgbtRed / 9);

                int tmpg = round(copy[ii - 1][i -1].rgbtGreen + copy[ii - 1][i].rgbtGreen + copy[ii - 1][i + 1].rgbtGreen +
                    copy[ii][i -1].rgbtGreen + copy[ii][i].rgbtGreen + copy[ii][i + 1].rgbtGreen +
                    copy[ii + 1][i -1].rgbtGreen + copy[ii + 1][i].rgbtGreen + copy[ii + 1][i + 1].rgbtGreen / 9);
            }
            else if (i > 0 && ii > 0)
            {
                int tmpb = round(copy[ii - 1][i -1].rgbtBlue + copy[ii - 1][i].rgbtBlue + copy[ii - 1][i + 1].rgbtBlue +
                    copy[ii][i -1].rgbtBlue + copy[ii][i].rgbtBlue + copy[ii][i + 1].rgbtBlue +
                    copy[ii + 1][i -1].rgbtBlue + copy[ii + 1][i].rgbtBlue + copy[ii + 1][i + 1].rgbtBlue / 9);

                int tmpr = round(copy[ii - 1][i -1].rgbtRed + copy[ii - 1][i].rgbtRed + copy[ii - 1][i + 1].rgbtRed +
                    copy[ii][i -1].rgbtRed + copy[ii][i].rgbtRed + copy[ii][i + 1].rgbtRed +
                    copy[ii + 1][i -1].rgbtRed + copy[ii + 1][i].rgbtRed + copy[ii + 1][i + 1].rgbtRed / 9);

                int tmpg = round(copy[ii - 1][i -1].rgbtGreen + copy[ii - 1][i].rgbtGreen + copy[ii - 1][i + 1].rgbtGreen +
                    copy[ii][i -1].rgbtGreen + copy[ii][i].rgbtGreen + copy[ii][i + 1].rgbtGreen +
                    copy[ii + 1][i -1].rgbtGreen + copy[ii + 1][i].rgbtGreen + copy[ii + 1][i + 1].rgbtGreen / 9);
            }
            else if (i > 0 && ii > 0)
            {
                int tmpb = round(copy[ii - 1][i -1].rgbtBlue + copy[ii - 1][i].rgbtBlue + copy[ii - 1][i + 1].rgbtBlue +
                    copy[ii][i -1].rgbtBlue + copy[ii][i].rgbtBlue + copy[ii][i + 1].rgbtBlue +
                    copy[ii + 1][i -1].rgbtBlue + copy[ii + 1][i].rgbtBlue + copy[ii + 1][i + 1].rgbtBlue / 9);

                int tmpr = round(copy[ii - 1][i -1].rgbtRed + copy[ii - 1][i].rgbtRed + copy[ii - 1][i + 1].rgbtRed +
                    copy[ii][i -1].rgbtRed + copy[ii][i].rgbtRed + copy[ii][i + 1].rgbtRed +
                    copy[ii + 1][i -1].rgbtRed + copy[ii + 1][i].rgbtRed + copy[ii + 1][i + 1].rgbtRed / 9);

                int tmpg = round(copy[ii - 1][i -1].rgbtGreen + copy[ii - 1][i].rgbtGreen + copy[ii - 1][i + 1].rgbtGreen +
                    copy[ii][i -1].rgbtGreen + copy[ii][i].rgbtGreen + copy[ii][i + 1].rgbtGreen +
                    copy[ii + 1][i -1].rgbtGreen + copy[ii + 1][i].rgbtGreen + copy[ii + 1][i + 1].rgbtGreen / 9);
            }
            else if (i == height - 1 && ii > 0)
            {
                int tmpb = round(copy[ii - 1][i -1].rgbtBlue + copy[ii - 1][i].rgbtBlue + copy[ii - 1][i + 1].rgbtBlue +
                    copy[ii][i -1].rgbtBlue + copy[ii][i].rgbtBlue + copy[ii][i + 1].rgbtBlue +
                    copy[ii + 1][i -1].rgbtBlue + copy[ii + 1][i].rgbtBlue + copy[ii + 1][i + 1].rgbtBlue / 9);

                int tmpr = round(copy[ii - 1][i -1].rgbtRed + copy[ii - 1][i].rgbtRed + copy[ii - 1][i + 1].rgbtRed +
                    copy[ii][i -1].rgbtRed + copy[ii][i].rgbtRed + copy[ii][i + 1].rgbtRed +
                    copy[ii + 1][i -1].rgbtRed + copy[ii + 1][i].rgbtRed + copy[ii + 1][i + 1].rgbtRed / 9);

                int tmpg = round(copy[ii - 1][i -1].rgbtGreen + copy[ii - 1][i].rgbtGreen + copy[ii - 1][i + 1].rgbtGreen +
                    copy[ii][i -1].rgbtGreen + copy[ii][i].rgbtGreen + copy[ii][i + 1].rgbtGreen +
                    copy[ii + 1][i -1].rgbtGreen + copy[ii + 1][i].rgbtGreen + copy[ii + 1][i + 1].rgbtGreen / 9);


                    if (ii == 0 && iii = 0)
            {
                int tmpb = round(copy[ii][iii].rgbtBlue + copy[ii][iii + 1].rgbtBlue +
                                    copy[ii + 1][iii].rgbtBlue +
                                    copy[ii + 1][iii + 1].rgbtBlue / 4);

                int tmpr = round(copy[ii][iii].rgbtRed + copy[ii][iii + 1].rgbtRed +
                                    copy[ii + 1][iii].rgbtRed +
                                    copy[ii + 1][iii + 1].rgbtRed / 4);

                int tmpg = round(copy[ii][iii].rgbtGreen + copy[ii][iii + 1].rgbtGreen +
                                copy[ii + 1][iii].rgbtGreen +
                                copy[ii + 1][iii + 1].rgbtGreen / 9);
            }

....

for (int ii = 0, jj = height; ii < jj; ii++)
    {
        for (int iii = 0, jjj = width; iii < jjj; iii++)
        {
            uint8_t blue;
            uint8_t green;
            uint8_t red;

            for (int x = -1, y = 1; x <= y; x++)
            {
                if (ii != 0 && iii != 0 && ii != height && ii != width)
                {
                    blue = copy[ii + x][iii + x].rgbtBlue;
                    green = copy[ii + x][iii + x].rgbtGreen;
                    red = copy[ii + x][iii + x].rgbtRed;
                }
            }
            uint8_t rblue = round(blue / 9);
            uint8_t rgreen = round(green / 9);
            uint8_t rred = round(red / 9);
            image[ii][iii].rgbtBlue = rblue;
            image[ii][iii].rgbtGreen = rgreen;
            image[ii][iii].rgbtRed = rred;
//      int tmpb = round(copy[ii][iii].rgbtBlue + copy[ii][iii + 1].rgbtBlue +
//                          copy[ii + 1][iii].rgbtBlue +
//                          copy[ii + 1][iii + 1].rgbtBlue / 4);
//      if (tmpb > 255)
//      {
//          tmpb = 255;
//      }
//
//      int tmpr = round(copy[ii][iii].rgbtRed + copy[ii][iii + 1].rgbtRed +
//                          copy[ii + 1][iii].rgbtRed +
//                          copy[ii + 1][iii + 1].rgbtRed / 4);
//
//      int tmpg = round(copy[ii][iii].rgbtGreen + copy[ii][iii + 1].rgbtGreen +
//                      copy[ii + 1][iii].rgbtGreen +
//                      copy[ii + 1][iii + 1].rgbtGreen / 9);

//image[ii][iii].rgbtBlue = tmpb;
//image[ii][iii].rgbtGreen = tmpg;
//image[ii][iii].rgbtRed = tmpr;



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
                    blue = round(copy[ii + xx[cc + xx].rgbtBlue);
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
            RGBTRIPLE tmp;
            for (int xx = -1, yy = 1; xx <= yy; xx++)
            {
                blue = round(copy[ii + xx][cc + xx].rgbtBlue);
                green = round(copy[ii + xx][cc + xx].rgbtGreen);
                red = round(copy[ii + xx][cc + xx].rgbtRed);
                tmp.rgbtBlue += blue;
                tmp.rgbtGreen += green;
                tmp.rgbtRed += red;
            }
            int tmpanswrb = (tmp.rgbtBlue / 4);
            image[ii][cc].rgbtBlue = tmpanswrb;
            int tmpanswrg = (tmp.rgbtGreen / 4);
            image[ii][cc].rgbtGreen = tmpanswrg;
            int tmpanswrr = (tmp.rgbtRed / 4);
            image[ii][cc].rgbtRed = tmpanswrr;
        }
    }