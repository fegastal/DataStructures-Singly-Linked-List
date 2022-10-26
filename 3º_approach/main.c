#include <stdio.h>
#include <stdlib.h>

//Simply Linked List: How to print the linked list?

// Begins by constructing a node that will compose our list:

typedef struct node
{
    int value;
    struct node *next;
} Node;

// procedure to print the linked list:
// we'll do a copy, so you don't need the pointer
void print(List list)
{
    Node *node = list.beginning;
    // when we are accessing a pointer, we use the ->
    // but list is now no longer a pointer, we are 
    // getting the list element that comes from main
    // so list.start I have an element
    // a copy of the list, so it's dot!
    // struct element - use dot
    // pointer element - use ->
    printf("\n\tList size %d: ", list.tam);
    // as long as the node is other than null
    while(node)
    {
        printf("%d", node->value);
        // we need to go through this list, 
        // otherwise we'll be in this infinite loop
        node = node->next;
        // at some point, this next node will be null
        // then the repeat will be broken
    }
    printf("\n\n");
    // just put these two line breaks
    // to separate the printout in the terminal
}

// In main, we'll build it in parts
// we'll have a "do while" loop
int main()
{
    int option, value, ant;

    // at the beginning, our list is empty!
    // create a variable of type list, called list:

    List list;

    // call the create list procedure:
    criar_lista(&lista);

    do 
    {
        // printing a menu for this user
        // is tabbed!
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - Imprimir\n");
        // now let's read what the user chose, using & to access the content
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &value);
                insert_at_the_beginning(&list, value);
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &value);
                insert_at_the_end(&list, value);
                break;
            case 3:
                printf("Digite um valor e o valor de referência: ");
                scanf("%d", &value, &ant);
                insert_in_the_middle(&list, value, ant);
                break;
            case 4:
                print(list);
                break;
            default:
                if(option != 0)
                    printf("Opção inválida!\n");
        }
    }
    // means that the user wants to stay in this loop
    while(option != 0);

    return 0;
}