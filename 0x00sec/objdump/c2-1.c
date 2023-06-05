#include <unistd.h>

int main(void){
    int a = 10;
    int b = 20;

    a = a + b;
    _exit(a);
}
