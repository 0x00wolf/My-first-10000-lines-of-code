#include <stdio.h>

void main(void)
{
	int i = 0;
	while (i < 100)
	{
		i++;
		if (i % 5 == 0 && i % 3 == 0)
		{
			printf("Buzz.\n");
		}
		else if (i % 3 == 0)
	   	{
			printf("Fizz\n");
		}
		else
		{
			printf("%d\n", i);
		}	
	}
}	
