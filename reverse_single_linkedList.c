// DELETING THE NODE AT A PARTICULAR POSITION
// https://www.youtube.com/watch?v=XgABnoJLtG4&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=56

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node* reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *next = NULL;
    while(head != NULL)
    {
        next = head->link;
        head->link = prev;
        prev = head;
        head = next;
    }
    head = prev;
    return head;
}

int main() {
    head = reverse(head);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->link;
    }
    return 0;
}

// Output: 3 98 45