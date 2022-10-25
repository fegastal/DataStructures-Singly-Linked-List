#include <stdio.h>
#include <stdlib.h>

//Simply Linked List: How to insert at the end of the list?

// Begins by constructing a node that will compose our list:

typedef struct node
{
    int value;
    struct node *next;
} Node;

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

/* 

*/
void insert_at_the_end(Node **list, int num)
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
        if(*list == NULL)
            // the content will be the new node
            *list = new;
        // the list is not empty? has at least 1 node?
        else {
            // a gente vai precisar de uma repetição para ir percorrendo todos os nós
            // quando chegar no último nó da nossa lista, a gente faz o último nó apontar
            // para o nosso novo nó. porém, o ponteiro *list possui o conteúdo da nossa variável
            // que vai ser criada no main, então não posso utilizar esse ponteiro *list
            // para percorrer minha lista, senão conforme vou percorrendo a lista, eu vou perdendo ela
            // porque esse ponteiro vai apontando para o próximo, para o próximo e assim vai indo
            // e, quando chega no último, ele vai estar apontando para o último nó da nossa lista
            // e perderemos toda a parte anterior da nossa lista.

            // como resolvemos isso? criando um ponteiro auxiliar *aux
            aux = *list;
            while(aux->next)
            // enquanto existir um proximo, aux vai caminhar pela lista
                aux = aux->next;
            aux->next = new;
        }

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