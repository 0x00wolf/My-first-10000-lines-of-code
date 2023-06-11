//if set size of array don't need malloc
//if malloc can resize with realloc

/*
ex1:
int main() 
{
    int values[5];
    values[2] = 45;
    int x = values[2];
}

ex2: 
int main()
{
    int *values = malloc(40); //size of int 4bytes, so malloc 40 = 5 ints.
    values[2] = 45;
    int x = values[2];
    //if you want to grow:
    values = realloc(values, 20000*sizeof(int)); //dynamic resizing, but can be inefficient
    x = values[600];
}

*/

//Linked lists need to allocate memory for each because must remain static to reference each other.
//Need a start marker (head of list), next pointers, and a tail.
//great for dynamic sized data sets

#include <stdlib.h>
#include <stdio.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node node_t;

void printlist(node_t *head)
{
    node_t *temporary = head;
    while (temporary != NULL)
    {
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

int main()
{
    node_t n1, n2, n3;
    node_t *head;

    n1.value = 69;
    n2.value = 13;
    n3.value = 666;

    //link them up
    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL; // das end of linked list
    printlist(head);
}

//usual application is to grow list when items are added