/* write the function strrindex(s,t) which returns the position of the
   rightmost occurence of t in s, or -1 if there is none. */
#include <stdio.h>

int strrindex(char s[], int t)
{
    int i, count;
    i = 0;
    count = -1;
    for (i = (strlen(s) - 1); i >= 0; i--)
        if (s[i] == t)
            count = s[i];
            i = 0;
    return count;
}
