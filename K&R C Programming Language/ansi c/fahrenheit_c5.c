#include <stdio.h>
/* Print the fairenheit celcius table */
void main(){
    int fahr;
    puts("Hello, world.");
    for (fahr = 300; fahr >= 0; fahr -= 20) {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}