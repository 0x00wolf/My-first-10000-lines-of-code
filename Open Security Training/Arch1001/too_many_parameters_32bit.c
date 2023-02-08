/* Change struct uint64 to int */

int func(int a, int b, int c, int d, int e){
    int i = a+b - c+d - e;
    return i;
}

int main(){
    return func(0x11, 0x22, 0x33, 0x44, 0x55);
}
