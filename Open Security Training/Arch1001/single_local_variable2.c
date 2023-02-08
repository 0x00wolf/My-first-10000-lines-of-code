int func3() {
    int i = 0x7a11;
    return i;
}

int func2() {
    int j = 0x7a1e;
    return func3();
}

int func() {
    return func2();
}

int main() {
    return func();
}
