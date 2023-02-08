#include <stdio.h>

void main(int argc, char ** argv){
    if(argv[1] != NULL && argv[2] != ""){
        printf("You entered %s for argv[1]\n", argv[1]);
    }
    else {
        printf("You didn't enter an argv[1]\n");
    }
}
