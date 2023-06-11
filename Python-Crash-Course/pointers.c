#include <stdio.h>

struct Person
{
    char name[64];
    int age;
};

int main(int argc, char *argvp[])
{
    struct Person people[100];

    struct Person* p_Person = &people;

    for (int i = 0; i < 100; i ++)
    {
        p_Person->age += 0;
        p_Person += 1;
        printf("hello\n");

    }
    printf("P Person's age is %i\n", p_Person->age);

    return 0;
}