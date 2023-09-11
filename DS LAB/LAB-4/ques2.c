#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *newnode, *temp, *start;
void insert_at_any_pos(struct node *start, int data, int pos)
{

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    if (start == NULL)
    {
        new_node->next = new_node;
        start = new_node;
        return;
    }

    struct node *current = start;
    for (int i = 1; i < pos - 1; i++)
    {
        current = current->next;
        if (current == start)
        {
            printf("invalid pos");
            return;
        }
    }

    new_node->next = current->next;
    current->next = new_node;
}

void delete_at_any_pos(struct node *start, int pos)
{
    if (start == NULL)
    {
        printf("next is empty");
        return;
    }
    struct node *current = start;
    struct node *prev = NULL;

    int count = 1;
    while (count < pos)
    {
        prev = current;
        current = current->next;
        if (current == start)
        {
            printf("Position out of bounds.\n");
            return;
        }

        count++;
    }

    if (prev == NULL)
    {
        struct node *tail = start;

        while (tail->next != start)
        {
            tail = tail->next;
        }
        start = (start)->next;
        tail->next = start;
    }
    else
    {
        prev->next = current->next;
    }

    free(current);
}

void create(int n)
{
    if (n == 0)
        return;
    newnode = (struct node *)malloc(sizeof(struct node));
    int x;
    printf("Enter data in Linked List\t");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    if (start == NULL)
    {
        start = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
    if (n == 1)
    {
        temp->next = start;
    }
    create(n - 1);
}

void print()
{
    printf("current list:\t");
    temp = start;
    while (temp->next != start)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
}

int main()
{

    int n = 5;
    printf("Enter the no of terms in Linked List\t");
    scanf("%d", &n);
    start = NULL;
    create(n);
    print();

    int pos, data;
    printf("\nEnter the pos and data to be inserted\t");
    scanf("%d %d", &pos, &data);

    insert_at_any_pos(start, data, pos);
    print();
    printf("\nEnter the pos to be deleted of the current Linked List\n");
    scanf("%d", &pos);
    delete_at_any_pos(start, pos);
    print();
    return 0;
}