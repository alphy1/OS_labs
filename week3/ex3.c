#include <stdio.h>
#include <stdlib.h>

struct list
{
    int val;
    struct list *next;
};

typedef struct list list;

void print_list(list head)
{
    list *first = head.next;
    while (first != NULL)
    {
        printf("%d ", first -> val);
        first = first -> next;
    }
    printf("\n\n");
}

void insert_node(list *after, int value)
{
    list *cell = (list *)malloc(sizeof(list));
    cell -> val = value;
    cell -> next = after -> next;
    after -> next = cell;
}

void delete_node(list *head, int certain)
{
// find node with certain value
    list *first = head;
    while (first -> next != NULL && first -> next -> val != certain)
        first = first -> next;
// delete node
    list *temp = first -> next;
    first -> next = (first -> next) -> next;
    free(temp);
}

int main()
{
    list l;             // head is dummy node
    l.next = NULL;      // used for simplification of implementation
// testing
    insert_node(&l, 5);
    insert_node(&l, 3);
    insert_node(&l, -2);
    print_list(l);          // -2 3 5
    delete_node(&l, 3);
    print_list(l);          // -2 5
    insert_node(&l, 10);
    print_list(l);          // 10 -2 5
    delete_node(&l, 5);
    print_list(l);          // 10 -2
    return 0;
}
