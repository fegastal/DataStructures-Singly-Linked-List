#include <stdio.h>
#include <stdlib.h>

//Simply Linked List: How to insert at the middle of the list?

// Begins by constructing a node that will compose our list:

typedef struct node
{
    int value;
    struct node *next;
} Node;

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

    aqui, vamos receber um parâmetro a mais:
    Node **list, int num, int ant 
    ant = anterior
    "eu quero inserir esse elemento após 
    a ocorrência desse elemento aqui"
*/

void insert_in_the_middle(Node **list, int num, int ant)
{
    Node  *new = malloc(sizeof(Node));

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
        if(*list == NULL){
            new->next = NULL;
            // o inicio dessa nossa lista será um novo nó
            *list = new;
        }
        // the list is not empty? has at least 1 node?
        else {
        // precisamos percorrer a lista em busca de um elemento 
        // de referência, que é o anterior (ant);
        // precisamos criar um ponteiro para a nossa lista,
        // porque não podemos alterar o **list! só podemos alterar
        // esse ponteiro quando a gente insere o primeiro nó! se não for,
        // então a gente não pode alterar o conteúdo dessa variável 
        // portanto, criamos uma variável auxiliar
            aux = *list;
            // pegamos agora o endereço do nosso primeiro nó da lista
            // agora, vamos verificar e percorrer a lista até encontrar o ant

            //while(aux->value != ant)

            // vamos inserir o novo nó após o elemento ant
            // porém, quem garante que o valor passado como ant existe
            // em algum nó da nossa lista?
            // se esse valor não existir, vamos ter que percorrer nossa lista
            // até o final. a gente vai inserir o nó só no final, portanto.
            // então, vamos fazer o seguinte:
            while(aux->value != ant && aux->next)
            // se aux->next for nulo, significa que não encontramos ant
            // e a inserção vai ocorrer no fim
            // aux vai portanto receber o valor de aux->proximo
                aux = aux->next;
            new->next = aux->next;
            // dessa forma, eu linkei meu novo nó com a parte final da lista
            aux->next = new;
        }
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