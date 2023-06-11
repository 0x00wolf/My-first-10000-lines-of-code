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
int main()
{
    init_hash_table();

    person jacob = {.name="Jacob", .age=37};
    person sally = {.name="Sally", .age=27};
    person susan = {.name="Susan", .age=57};

    hash_table_inser(&jacob);
    hash_table_inser(&sally);
    hash_table_inser(&susan);

    print_table();

    return 0;
}