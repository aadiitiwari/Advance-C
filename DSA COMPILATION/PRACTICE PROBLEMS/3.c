// delete nth node from the end in single linked list
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void insert(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}
void traverse()
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int count()
{
    int lenghth = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        lenghth++;
        temp = temp->next;
    }
    return lenghth;
}

void delete_from_the_end(int p)
{
    struct node *ptr = head;
    struct node *prev = NULL;
    int l;
    l = count();
    if (p == 0)
    {
        prev = ptr;
        ptr = ptr->next;
        head = ptr;
        free(prev);
    }
    else if (p <= 0 || p > l)
        printf("INVALID POSITION ");
    else if (p = l)
    {
        struct node *t=head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
    }
    else
    {
        for (int i = 0; i < p - 1; i++)
            ptr = ptr->next;
        prev = ptr->next;
        ptr->next = (ptr->next)->next;
        free(prev);
    }
}
int main()
{
    printf("Enter the number of nodes : ");
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int data;
        printf("\nEnter data for node %d : ", i);
        scanf("%d", &data);
        insert(data);
    }

    printf("\nThe linked list is :");
    traverse();

    printf("\nEnter the position of the node to be deleted from the end ");
    int pos;
    scanf("%d", &pos);
    int c;
    c = count();
    pos = c - pos;
    delete_from_the_end(pos);
    printf("\nNode after deleting the n'th node from the end :");
    traverse();
    return 0;
}
