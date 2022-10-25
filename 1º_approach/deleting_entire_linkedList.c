// DELETING THE NODE AT A PARTICULAR POSITION
// https://www.youtube.com/watch?v=f1r_jxCyOl0&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=54

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node* del_list(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        temp = temp->link;
        free(head);
        head = temp;
    }
    return head;
}

int main() {
    head = del_list(head);
    if(head == NULL);
        printf("Linked List Deleted Succesfully!");
    return 0;
}