#include <stdio.h>

#define MAXLINE 1000    // max input line size
#define TAB2SPACE 4     // 4 space to a tab

char line[MAXLINE];     // current input line
int getlinex(void);     // KnR

int main()
{
    int i, t;
    int spacecount, len;

    while ((len = getlinex()) > 0)
    {
        spacecount = 0;
        for(i = 0; i < len; i++)
        {
            if(line[i] == ' ')
                spacecount++;   // increment counter for each space
            if(line[i] != ' ')
                spacecount = 0; // reset counter
            if(spacecount == TAB2SPACE)
            {
                i -= 3;
                len -= 3;
                line[i] = '\t';

                for(t=i+1;t<len;t++)
                    line[t]=line[t+3];

                spacecount = 0;
                line[len] = '\0';
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
    
    for (i=0; i<MAXLINE-1&& (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if(c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
