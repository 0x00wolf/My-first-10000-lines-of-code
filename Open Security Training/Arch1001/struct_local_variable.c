typedef struct mystruct {
    short a;
    int b[6];
    long long c;
} mystruct_t;

short main(){
    mystruct_t foo;
    foo.a = 0xbabe;
    foo.c = 0xba1b0ab1edb100d;
    foo.b[1] = foo.a;
    foo.b[4] = foo.b[1] + foo.c;
    return foo.b[4];
} 
