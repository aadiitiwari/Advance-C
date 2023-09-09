#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
    while (ptr!=NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for Nodes in the Linked list in Heap

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link first and the second Nodes
    head->data = 7;
    head->next = second;

    // Link second and the third Nodes
    second->data = 11;
    second->next = third;

    // Terminate the list at the third node
    third->data = 21;
    third->next = NULL;

    linkedListTraversal(head);
    return 0;
}