// write the function any(s1, s2) which returns the first location
// in the string s1 where any character from the string s2 occurs,
// or -1 if s1 contains no characters from s2.

int any(s1, s2)
{
    int i, j;
    int k = 0;
    // loop through characters in s1 until '\0'
        // for every character in s1 loop through s2 and see if they match
            // if they match return s1[0]
    // if s1[i] == '\0' return -1.
    for(i=0; s1[i] != '\0'; i++)
        for(j=0; s2[j] != '\0'; j++)
            if (s1[i] == s2[j])
                k = s1[0];
        if (s2[j] == '\0')
            k = -1;
        return k;
}



