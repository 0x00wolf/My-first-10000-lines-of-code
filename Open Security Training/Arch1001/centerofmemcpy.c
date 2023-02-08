#include <stdio.h>
#include <string.h>

#pragma pack(1)
typedef struct mystruct{
    int var1;
    char var2[4];
} mystruct_t;
#pragma

#define uint64 unsigned long long
uint64 main(){
    mystruct_t a, b;
    a.var1 = 0xFF;
    memcpy(&b, &a, sizeof(mystruct_t));
    return 0xAce0fba5e;
}
