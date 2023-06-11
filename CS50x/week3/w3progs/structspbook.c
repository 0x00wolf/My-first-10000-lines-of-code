#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}person;

int main(void)
{
    person people[2];
    people[0].name = "John Connor";
    people[0].number = "8008531";
    people[1].name = "El Terminator";
    people[1].number = "T1000";
//Find the terminator
    for (int i = 0; i < 2; i ++)
    {
        if (strcmp(people[i].name, "El Terminator") == 0)
        {
            printf("Found %s, Hasta la vista baby\n", people[i].number);
            return 0;
        }
    }
    printf("Give me your clothes, your boots, and your motorcycle.\n");
    return 1;
}