#include <stdio.h>
#include <stdlib.h>

//Simply Linked List: How to insert at the end of the list?

// Begins by constructing a node that will compose our list:

typedef struct node
{
    int value;
    struct node *next;
} Node;

typedef struct
{
    Node *beginning;
    int size;
} List;

// this procedure we'll use when we create 
// our list structure in our main
void create_list(List *list)
{
    list->beginning = NULL;
    list->size = 0;
}

/* 
    First procedure: insert at the end;
    as it is a procedure, returns void.

    As parameters, we get an element of type 
    node which will be our list, but we get 
    a pointer to pointer, because we'll have 
    a pointer to a node called list, so it's 
    the address of this variable that we'll 
    get here;

    because as we are going to insert it at 
    the end, every insertion we are 
    going to be changing the contents of this 
    variable, so what I get is its address. 
    And this variable is going to point to a node. 
    That is why it is **.
*/

void insert_at_the_end(List *list, int num)
{
    Node *aux, *new = malloc(sizeof(Node));

    // if this new node is allocated correctly
    if(new)
    {
        // make my new node point to the end of the list
        // fill in the value we want to insert 
        // and say that the next one is null
        // because we are inserting it at the end
        new->value = num;
        new->next = NULL;
        // but even if we insert at the end, if 
        // it is the first time, this node will 
        // be the first in our queue. so we need
        // to check if the queue is empty...
        // is the first? the list is empty?
        if(list->beginning == NULL)
            // the content will be the new node
            list->beginning = new;
        // the list is not empty? has at least 1 node?
        else {
            // we'll need a loop to go through all the nodes
            // When we reach the last node of our list, we make the last node point to our new node.
            // to our new node. However, the pointer *list holds the contents of our variable
            // that is going to be created in main, so I can't use this *list pointer
            // to go through my list, otherwise as I go through the list I'll lose the list
            // because this pointer keeps pointing to the next one, to the next one, and so on
            // and, when it reaches the last one, it will be pointing to the last node of our list
            // and we'll lose the whole previous part of our list.

            // How do we solve this? By creating an auxiliary pointer *aux
            aux = list->beginning;
            // we are creating an auxiliary pointer to the beginning of our list 
            while(aux->next)
            // as long as there is a next one, aux will walk through the list
                aux = aux->next;
            aux->next = new;
        }
        list->size++;
    }
    else
        printf("Memory allocation error!\n");
}

int main()
{
    return 0;
}