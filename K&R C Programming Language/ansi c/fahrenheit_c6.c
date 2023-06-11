#include <stdio.h>
#define UPPER 300   // Upper limit of fahrenheit
#define LOWER 0     // Lower limit of fahrenheit    
#define STEP 20     // Increment of step

/* Print the fairenheit celcius table */

void main()
{
    int fahr;
    puts("Hello, world.");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) 
    {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}
// Elegance is simplicity.
// Contrast to sailing: A pretty sail is a fast sail.
                    //  Pretty code is elegant code.