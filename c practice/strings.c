#include <stdio.h>

int get_string_length(char *str);
char* copy_string(char *from);

void main()
{
	char *str1 = "Bob French Esquire.";
	printf("%s\nHas this many characters: %d\n", str1, get_string_length(str1));
}

int get_string_length(char *str)
{
    int off = 0;
	while (str[off] != '\0')
	{
	    off++;
	}
	return off;
}