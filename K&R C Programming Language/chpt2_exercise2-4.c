/* write an alternate version of squeeze (s1, s2) that
 *  deletes each character in _string1 that
 *  matches any character in _string2 */
#include <stdio.h>

void squeeze(char s[], char s2[])
{
    int i, j, k;
    for (i = j = 0; s[i] != '\0'; i++){
        for (k = 0; s2[k] != '\0'; k++){
            if (s[i] == s2[k])
                break;
        }
        if (s[k] == '\0')
            s[j++] = s[i];
    }
}
