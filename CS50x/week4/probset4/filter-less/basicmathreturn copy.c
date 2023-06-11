#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
} __attribute__((__packed__))
RGBTRIPLE;

int main(void)
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