#include <stdio.h>
#include <stdlib.h>

//Simply Linked List: How to print the linked list?

// Begins by constructing a node that will compose our list:

typedef struct node
{
    int value;
    struct node *next;
} Node;

// procedimento para imprimir a lista encadeada:
void print(Node *node)
{
    printf("\n\tLista: ");
    // enquanto o nó for diferente de nulo
    while(node)
    {
        printf("%d", node->value);
        // precisamos percorrer essa lista, 
        // senão ficaremos nesse loop infinito
        node = Node->next;
        // em algum momento, esse proximo nó será nulo
        // então, a repetição será quebrada
    }
    printf("\n\n");
    // apenas colocarei essas duas quebras de linhas
    // para separar a impressão no terminal
}

// No main, vamos construí-lo em partes
// teremos uma repetição do tipo "faça enquanto"

int main()
{
    int option, value, ant;

    // no inicio, nossa lista está vazia!
    Node *list = NULL;

    // vou dar a opção zero como opção de saída
    do 
    {
        // impressão de um menu para esse usuário
        // \t é de tabulação!
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - Imprimir\n");
        // agora vamos fazer a leitura do que o usuario escolheu, usando & para acessar o conteudo
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
    // significa que o usuário quer permanecer nesse laço
    while(option != 0);

    return 0;
}