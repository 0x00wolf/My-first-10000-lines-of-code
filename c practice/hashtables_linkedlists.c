#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 15

typedef struct person{
    char name[MAX_NAME];
    int age;
    struct person *next;

} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for (int i=0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table() {
    for (int i=0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t", i);
            person *tmp = hash_table[i];
            while (tmp != NULL)
            {
                printf("%s -", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("End\n");
}

bool hash_table_inser(person *p)
{
    if (p == NULL) return false;
    int index = hash(p->name);
//linear probing method (not good for big data sets):
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}


//Find a person by their name in the table
person *hash_table_lookup(char *name)
{
    int index = hash(name);
    person *tmp = hash_table[index];
    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
    {
        tmp = tmp->next;
    }
    return tmp;
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    person *tmp = hash_table[index];
    person *prev = NULL;
    while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL) return NULL;
    if (prev == NULL)
    // Deleting the head of the list
    {
        hash_table[index] = tmp->next;
    }
    else
    {
        prev->next = tmp->next;
    }
    return tmp;
}


int main()
{
    init_hash_table();

    person wolf = {.name="Wolf", .age=37};
    person kayla = {.name="Kayla", .age=27};
    person bobf = {.name="Bob French", .age=57};
    person sue = {.name="Sue", .age=101};
    person regan = {.name="Regan", .age=88};
    person nixon = {.name="Nixon", .age=99};
    person zangief = {.name="Zangief", .age=44};
    person guile = {.name="Guile", .age=57};
    person genmccarthy = {.name="General Mccarthy", .age=157};
    person genzhukov = {.name="General Zhukov", .age=1157};
    person lopan = {.name="Lopan", .age=5444};

    hash_table_inser(&wolf);
    hash_table_inser(&kayla);
    hash_table_inser(&bobf);
    hash_table_inser(&sue);
    hash_table_inser(&regan);
    hash_table_inser(&nixon);
    hash_table_inser(&zangief);
    hash_table_inser(&guile);
    hash_table_inser(&genmccarthy);
    hash_table_inser(&genzhukov);
    hash_table_inser(&lopan);

    print_table();
    printf("Bob Saget rules the universe from the afterlife.\n");

    person *tmp = hash_table_lookup("Bob French");
    if (tmp == NULL) {
        printf("Sad face\n");
    }
    else
    {
        printf("Found %s.\n",tmp->name);
    }

    tmp = hash_table_lookup("Sad Panda");
    if (tmp == NULL) {
        printf("Sad face\n");
    }
    else
    {
        printf("Found %s.\n",tmp->name);
    }

    hash_table_delete("Bob French");
    tmp = hash_table_lookup("Bob French");
    if (tmp == NULL) {
        printf("Sad face\n");
    }
    else
    {
        printf("Found %s.\n",tmp->name);
    }

    print_table();
    return 0;
}