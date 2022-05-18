// INSERTING THE DATA AT THE BEGINNING OF AN ARRAY

#include <stdio.h>
#include <stdlib.h>

void add_at_pos(struct node* head, int data, int pos)
{
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    pos--;
    while(pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

int main() {
    struc node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    add_at_end(head, 98);
    add_at_end(head, 3);

    int data = 67, position = 3;

    add_at_pos(head, data, position);
    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}