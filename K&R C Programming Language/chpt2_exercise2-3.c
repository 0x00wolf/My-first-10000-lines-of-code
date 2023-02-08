#include <stdio.h>
#include <ctype.h>

unsigned long htoi(const char s[]);

int main(void)
{
    printf("%1d\n", htoi("0xDEAD"));
    printf("%1d\n", htoi("0xB33F"));
    printf("%1d\n", htoi("0x1337"));
    printf("%1d\n", htoi("0xD00D"));
    return 0;
}

unsigned long htoi(const char s[])
{
    unsigned long n = 0;

    for (int i = 0; s[i] != '\0'; i++){
        int c = tolower(s[i]);
        if (c == '0' && tolower(s[i+1]) == 'x')
            i++;
        else if (c >= '0' && c <= '9')
            n = 16 * n + (c-'0');
        else if (c >= 'a' && c <= 'f')
            n = 16 * n + (c - 'a' + 10);
    }
    return n;
}
