#include<stdio.h>

int func(){
    return 0xbeef;
}

int main(){
    func();
    return 0xf00d;
}

/* debugger output assembly cmd order:
 *
 * mov      eax, 0BEEFh
 * ret
 *
 * sub      rsp, 28h
 * call     func (<funcaddress>)
 * mov      eax, 0F00Dh
 * add      rsp,28h
 * ret
 */
