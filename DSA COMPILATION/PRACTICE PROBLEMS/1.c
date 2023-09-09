// find middle in the linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *new_node;
struct node* find_middle()
{
    struct node *slow = start;
    struct node *fast = start;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = (fast->next)->next;
    }
    return slow;
}

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

    struct node * middle_node=find_middle();
    printf("\nTHE MIDDLE OF THE NODE IS %d .\n",middle_node->data);
    return 0;
}