// DELETING THE FIRST NODE OF SINGLE LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
}

struct node* del_last(struct node *head)
{
    if(head == NULL) // Check if there is no node in the linked list
        printf("List is already empty!");
    else if(head->link == NULL) // Check if there is ONE node in the linked list
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct node *temp = head;
        struct node *temp2 = head;
        while(temp->link != NULL) // If there are n nodes in the linked list, then the loop will run n times;
        {
            temp2 = temp;
            temp = temp->link;
        }
        temp2->link = NULL;
        free(temp);
        temp = NULL;
    }
    return head;
}

int main() {
    head = del_last(head);
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}

// Output: 45 98
