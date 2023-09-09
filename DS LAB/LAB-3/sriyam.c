#include <stdio.h>
#include <stdlib.h>
void traverse();
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *new_node;

int main()
{
    int x;
    printf("ENTER THE DATA of linked list or enter -1 to exit ");
    scanf("%d", &x);
    while (x != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = x;
        if (start == NULL)
        {
            start = new_node;
            new_node->next = NULL;
        }
        else
        {
            new_node->next = start;
            start = new_node;
        }
        printf("\nEnter the next data of linked list or enter -1 to exit  ");
        scanf("%d", &x);
    }
    traverse();
    return 0;
}

void traverse()
{
    struct node *ptr = start;
    printf("The Linked list is:");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
