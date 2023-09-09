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

// Case 1
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Case 2
struct Node *insertatIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
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

    printf("\nLinked List before Insertion \n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 5);
    printf("\nLinked List after Insertion at beginning \n");
    linkedListTraversal(head);
    printf("\nLinked List after Insertion at index. \n");
    head = insertatIndex(head, 10, 2);
    linkedListTraversal(head);
    printf("\nLinked List after Insertion at End \n");
    head = insertAtEnd(head, 31);
    linkedListTraversal(head);
    printf("\nLinked List after Insertion at Node. \n");
    head=insertAfterNode(head,second,15);
    linkedListTraversal(head);
    return 0;
}

/*

Linked List before Insertion
Element : 7
Element : 11
Element : 21

Linked List after Insertion at beginning
Element : 5
Element : 7
Element : 11
Element : 21

Linked List after Insertion at index.
Element : 5
Element : 7
Element : 10
Element : 11
Element : 21

Linked List after Insertion at End
Element : 5
Element : 7
Element : 10
Element : 11
Element : 21
Element : 31

Linked List after Insertion at Node.
Element : 5
Element : 7
Element : 10
Element : 11
Element : 15
Element : 21
Element : 31
 
*/