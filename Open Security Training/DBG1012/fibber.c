#include <stdio.h>

unsigned int fibbonacci(unsigned int n){
    if(n <= 1){
        return n;
    }
    else{
        return (fibbonacci(n-1) + fibbonacci(n-2));
    }
}

int main(){
    unsigned int n = 10;

    printf("First %d elements of the Fibbonacci sequence: ", n);

    for(unsigned int i = 0; i < n; i++){
        printf("%d ", fibbonacci(i));
    }
    printf("\n");
    return 0;
}
