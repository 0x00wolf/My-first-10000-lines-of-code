#include <stdio.h>
/* the floating point version
of print the fahrenheit-celcius table
{ 0, 20, ..., 300}*/

int main()
{
    float fahr, celc;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("Hello, world.\n");
    while (fahr <= upper) 
    {
        celc = (5.0/9.0) * (fahr -32);
        printf("%6.1f %3.0f\n", celc, fahr);
        fahr = fahr + step;
    }    
}