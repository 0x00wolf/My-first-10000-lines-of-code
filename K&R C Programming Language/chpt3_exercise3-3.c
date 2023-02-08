/* expands shorthand notation like a-z in the string s1 into the equivalent
complete list abc...xyz in s2 */
#include <stdio.h>
#include <ctype.h>

#define MAXLEN 1024
#define TESTNUM 13

int ischar(int prev);
void expand(char s1[], char s2[]);

int main(void)
{
    char tests[TESTNUM][MAXLEN] = {
        "a-z",
        "A-Z",
        "0-9",
        "a-z0-9",
        "a-b-c",
        "-a-z",
        "0-9-",
        "-a-z0-9-",
        "d-e-a-d-b-e-f-f",
        "0xblood",
        "ba1b0a"
    };
    char s[MAXLEN];

    for (int i = 0; i < TESTNUM; ++i) {
        printf("unexpanded: %s\n", tests[i]);
        expand(tests[i], s);
        printf("expanded: %s\n", s);
    }
    return 0;
}

int ischar(int prev)
{
    if ((prev >='0' && prev <='9') ||
        (prev >='a' && prev<='z') ||
        (prev >='A' && prev<='Z'))
        return 1;
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j, curr, prev, next;
    prev = '\0';
    for (i = j = 0; (curr = s1[i]) != '\0'; ++i)
    {
        next = s1[i + 1];
        if (curr == '-' && ischar(prev) && ischar(next)){
            while (++prev < next)
                s2[j++] = prev;
            } else {
                s2[j++] = curr;
            }
    }
    s2[j] = curr;
}


