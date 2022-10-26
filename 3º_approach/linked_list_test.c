#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}Node;

typedef struct
{
    Node *beginning;
    int size;
}List;

void create_list(List *list)
{
    list->beginning = NULL;
    list->size = 0;
}

// procedure to insert in the beginning
void insert_at_the_beginning(List *list, int num)
{
    Node *new = malloc(sizeof(Node));

    if(new)
    {
        new->value = num;
        new->next = list->beginning;
        list->beginning = new;
        list->size++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedure to insert at the end
void insert_at_the_end(List *list, int num)
{
    Node *aux, *new = malloc(sizeof(Node));

    if(new)
    {
        new->value = num;
        new->next = NULL;

        // é o primeiro?
        if(list->beginning == NULL)
            list->beginning = new;
        else{
            aux = list->beginning;
            while(aux->next)
                aux = aux->next;
            aux->next = new;
        }
        list->size++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedure to insert in the middle
void insert_in_the_middle(List *list, int num, int ant)
{
    Node *aux, *new = malloc(sizeof(Node));

    if(new)
    {
        new->value = num;
        // is the first?
        if(list->beginning == NULL)
        {
            new->next = NULL;
            list->beginning = new;
        }
        else
        {
            aux = list->beginning;
            while(aux->value != ant && aux->next)
                aux = aux->next;
            new->next = aux->next;
            aux->next = new;
        }
        list->size++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void print(List list)
{
    Node *node = list.beginning;
    printf("\n\tLista tam %d: ", list.size);
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
    //Node *list = NULL;
    List list;

    create_list(&list);

    do
    {
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - Imprimir\n");
        scanf("%d", &option);

        switch(option){
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
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d%d", &value, &ant);
            insert_in_the_middle(&list, value, ant);
            break;
        case 4:
            print(list);
            break;
        default:
            if(option != 0)
                printf("Opcao invalida!\n");
        }

    }
    while(option != 0);

    return 0;
}