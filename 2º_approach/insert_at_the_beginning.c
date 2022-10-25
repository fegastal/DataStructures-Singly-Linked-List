#include <stdio.h>
#include <stdlib.h>

//Simply Linked List: How to insert at the beginning of the list?

// Begins by constructing a node that will compose our list:

typedef struct node
{
    int value;
    struct node *next;
} Node;

/* 
    First procedure: insert at the beginning;
    as it is a procedure, returns void.

    As parameters, we get an element of type 
    node which will be our list, but we get 
    a pointer to pointer, because we'll have 
    a pointer to a node called list, so it's 
    the address of this variable that we'll 
    get here;

    because as we are going to insert it at 
    the beginning, every insertion we are 
    going to be changing the contents of this 
    variable, so what I get is its address. 
    And this variable is going to point to a node. 
    That is why it is **.
*/

void insert_at_the_beginning(Node **list, int num)
{
    Node *new = malloc(sizeof(Node));

    // if this new node is allocated correctly
    if(new)
    {
        // make my new node point to the beginning of the list
        new->value = num;
        new->next = *list;
        // now I need to update the beginning of my list
        // I want to get the contents of that position
        // in order to make an assignment
        // then the content will be the address of the new node
        *list = new;
    }
    else if
    {
        printf("Memory allocation error!\n");
    }
}

int main()
{
    return 0;
}