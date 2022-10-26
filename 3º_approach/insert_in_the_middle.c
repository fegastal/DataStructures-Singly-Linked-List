#include <stdio.h>
#include <stdlib.h>

//Simply Linked List: How to insert at the middle of the list?

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
    list->size= 0;
}

/* 
    First procedure: insert at the middle;
    as it is a procedure, returns void.

    As parameters, we get an element of type 
    node which will be our list, but we get 
    a pointer to pointer, because we'll have 
    a pointer to a node called list, so it's 
    the address of this variable that we'll 
    get here;

    because as we are going to insert it at 
    the middle, every insertion we are 
    going to be changing the contents of this 
    variable, so what I get is its address. 
    And this variable is going to point to a node. 
    That is why it is **.

    here, we will get one more parameter:
    Node **list, int num, int ant 
    ant = previous
    "I want to insert this element after 
    the occurrence of this element here".
*/

void insert_in_the_middle(Node *list, int num, int ant)
{
    Node  *aux, *new = malloc(sizeof(Node));

    // if this new node is allocated correctly
    if(new)
    {
        // make my new node point to the middle of the list
        // fill in the value we want to insert 
        // because we are inserting it at the middle
        new->value = num;
        // but even if we insert at the middle, if 
        // it is the first time, this node will 
        // be the first in our queue. so we need
        // to check if the queue is empty...
        // is the first? the list is empty?
        if(list->beginning == NULL){
            new->next = NULL;
            // the beginning of this list will be a new node
            list->beginning = new;
        }
        // the list is not empty? has at least 1 node?
        else {
        // we need to scroll through the list looking for an element 
        // reference element, which is the previous one (ant);
        // we need to create a pointer to our list
        // because we can't change the **list! we can only change
        // this pointer when we insert the first node!
        // then we can't change the contents of that variable 
        // so we create an auxiliary variable
            aux = list->beginning;
            // we now get the address of our first node in the list
            // now we'll scan and scroll the list until we find ant

            //while(aux->value != ant)

            // we'll insert the new node after the ant element
            // but who's to say that the value passed as ant exists
            // in any node of our list?
            // if it doesn't exist, we'll have to go through our list
            // we will insert the node only at the end, so.
            // so, let's do the following:
            while(aux->value != ant && aux->next)
            // if aux->next is null, it means that we can't find ant
            // and the insertion will happen at the end
            // aux will therefore take the value of aux->next
                aux = aux->next;
            new->next = aux->next;
            // this way, I link my new node to the end of the list
            aux->next = new;
        }
        list->size++;
    }
    else
    {
        printf("Memory allocation error!\n");
    }
}

int main()
{
    return 0;
}