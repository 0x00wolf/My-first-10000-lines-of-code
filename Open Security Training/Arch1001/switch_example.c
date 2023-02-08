#include <stdlib.h>
int main(int argc, char * argv[]){
    int a = atoi(argv[1]);
    switch (a) {
        case 0:
            return 1;
        case 1:
            return 2;
        default:
            return 3;
        }
    return 0xfee1fed;
}
