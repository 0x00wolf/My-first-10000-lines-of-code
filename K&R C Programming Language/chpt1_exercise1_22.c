#include <stdio.h>

#define MAXLINE 1000

char line[MAXLINE];      // current input line
int getlinex(void);     // taken from the knr book

int main(void)
{
    int i, len;
    int location, spaceholder;
    const int FOLDLENGTH = 70;  // the max length of a line

    while ((len = getlinex()) > 0)
    {
        if (len < FOLDLENGTH)
        {
        }
        else
        {
            i = 0;
            location = 0;
            while(i<len)
            {
                if(line[i] == ' ')
                    spaceholder = i;
                if(location == FOLDLENGTH)
                {
                    line[spaceholder] = '\n';
                    location = 0;
                }
                location++;
                i++;
            }
        }
        printf("%s", line);
    }
    return 0;
}

int getlinex(void)
{
    int c, i;
    extern char line[];

    for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
