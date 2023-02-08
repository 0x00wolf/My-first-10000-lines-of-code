#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    int a;
    //remainder: atoi() converts an
    //ASCII string to an integer
    a = atoi(argv[1]);
    return 2*argc + a;
}
