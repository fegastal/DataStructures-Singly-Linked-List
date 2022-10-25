#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

void insert_at_the_beginning(Node **list, int num)
{
    Node *new = malloc(sizeof(Node));

    if(new)
    {
        new->value = num;
        new->next = *list;

        *list = new;
    }
    else
    {
        printf("Memory allocation error!\n");
    }
}


void insert_at_the_end(Node **list, int num)
{
    Node *aux, *new = malloc(sizeof(Node));

    if(new)
    {
        new->value = num;
        new->next = NULL;

        if(*list == NULL)
            *list = new;
        else {
            aux = *list;
            while(aux->next)
                aux = aux->next;
            aux->next = new;
        }

    }
    else
    {
        printf("Memory allocation error!\n");
    }
}


void insert_in_the_middle(Node **list, int num, int ant)
{
    Node  *aux, *new = malloc(sizeof(Node));

    if(new)
    {
        new->value = num;

        if(*list == NULL){
            new->next = NULL;
            *list = new;
        }
        else {
            aux = *list;
            while(aux->value != ant && aux->next)
                aux = aux->next;
            new->next = aux->next;
            aux->next = new;
        }
    }
    else
    {
        printf("Memory allocation error!\n");
    }
}

void print(Node *node)
{
    printf("\n\tLista: ");
    while(node)
    {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n\n");
}

int main()
{
    int option, value, ant;

    Node *list = NULL;

    do 
    {
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - Imprimir\n");
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
                scanf("%d%d", &value, &ant);
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
    while(option != 0);

    return 0;
}