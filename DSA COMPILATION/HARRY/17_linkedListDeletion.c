#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1 : Deleting the first element from the linked list
struct Node *deletefirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2 : Deleting the element at a given index from the given linked list
struct Node *deleteatindex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Case 3 : Deleting the last element
struct Node *deletelastnode(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// Case 4 : Deleting the element with a given value from the linked list
struct Node *deletenodewithValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for Nodes in the Linked list in Heap

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and the second Nodes
    head->data = 4;
    head->next = second;

    // Link second and the third Nodes
    second->data = 3;
    second->next = third;

    // Link third and the fourth Nodes
    third->data = 8;
    third->next = fourth;

    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = NULL;

    printf("Linked list before deletion \n");
    linkedListTraversal(head);

    // Linked list before deletion 
    // Element : 4
    // Element : 3
    // Element : 8
    // Element : 1

    // 1. printf("\nLinked list after deletion of first node \n");
    // head = deletefirst(head); // For deleting first element in the Linked List
    // linkedListTraversal(head);

    // Linked list after deletion of first node                                 <---- OUTPUTS
    // Element : 3
    // Element : 8
    // Element : 1 


    // 2. printf("\nLinked list after deletion of element at given index \n");
    // head= deleteatindex(head,2);
    // linkedListTraversal(head);

    // Linked list after deletion of element at given index                   <---- OUTPUTS
    // Element : 4
    // Element : 3
    // Element : 1 


    // 3. printf("\nLinked list after deletion of last node \n");
    // head=deletelastnode(head);
    // linkedListTraversal(head);

    // Linked list after deletion of last node                              <---- OUTPUTS
    // Element : 4
    // Element : 3
    // Element : 8 

    // 4. printf("\nLinked list after deletion of the node with the given value  \n");
    // head=deletenodewithValue(head,3);
    // linkedListTraversal(head);

    // Linked list after deletion of the node with the given value          <---- OUTPUTS
    // Element : 4
    // Element : 8
    // Element : 1

    return 0;
}