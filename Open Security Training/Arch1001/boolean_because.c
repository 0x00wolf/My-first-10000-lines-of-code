#include <stdio.h>
#define uint64 unsigned long long

unsigned long long main(){
    unsigned int i = 0x50da;
    unsigned int j = 0xc0ffee;
    uint64 k = 0x7ee707a11ed;
    k ^= ~(i & j) | 0x7ab00;
    return k;
}
