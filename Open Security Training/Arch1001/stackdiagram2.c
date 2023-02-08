#include <stdio.h>

int bar(int y){
    int a = 3*y;
    printf("bar returned %d\n", a);
    return a;
}

int foo(int x){
    int b = 5*x;
    printf("foo passed %d\n", b);
    return bar(b);
}

int main(){
    int c = foo(7);
    printf("main passed %d\n", c);
}


/*
            Stack bottom
    "return address" to return
    from main() to invoke_mainm
    ________________________
   |                        |
   |                        |main()
   |     "return addr"      |frame
   |    pushed onto stack   |
   |   from foo() to main() |
   |________________________|
   |                        |
   |                        |
   |    "return address"    |foo()
   |   to return from bar() |frame
   |        to foo()        |
   |________________________|
   |                        |
   |                        |bar()
   |                        |frame
   |                        |
   |________________________|

            Stack top
*/
