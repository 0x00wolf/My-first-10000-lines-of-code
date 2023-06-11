#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct {
    char name[MAX_NAME];
    int age;
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
    for (int i=0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

bool hash_table_inser(person *p) {
    if (p == NULL) return false;
    int index = hash(p->name);
    if (hash_table[index] != NULL)
    {
        return false;
    }
    hash_table[index] = p;
    return true;
}

//Find a person by their name in the table
person *hash_table_lookup(char *name)
{
    int index = hash(name);
    if (hash_table[index] != NULL &&
        strncmp(hash_table[index]->name, name, TABLE_SIZE)== 0) {
            return hash_table[index];
    }
    else
    {
        return NULL;
    }
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    if (hash_table[index] != NULL &&
        strncmp(hash_table[index]->name, name, TABLE_SIZE)== 0) {
            person *tmp = hash_table[index];
            hash_table[index] = NULL;
            return tmp;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    init_hash_table();

    person wolf = {.name="Wolf", .age=37};
    person kayla = {.name="Kayla", .age=27};
    person bobf = {.name="Bob French", .age=57};
    
    hash_table_inser(&wolf);
    hash_table_inser(&kayla);
    hash_table_inser(&bobf);

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