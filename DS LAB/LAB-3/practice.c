#include <stdio.h>
#include <stdlib.h>
void traverse();
void insert_at_pos(int);
// void insert_after_data(int);
// void delete_pos(int);
// void delete_data(int);
int count();
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

    int choice;
    printf("\nEnter your choice:\n1.Insert a node at specific position \n2.Insert after a given data \n3.Deletion of an element from specific position \n4.Delete of a given data \n5.Count nodes \n6.Traverse the linked list \n7.EXIT \n");
    scanf("%d", &choice);
    do
    {
        if (choice == 1)
        {
            int pos;
            printf("Enter the position at which you want to insert the node: ");
            scanf("%d", &pos);
            insert_at_pos(pos);
            traverse();
            break;
        }

        if (choice == 2)
        {
            int dt;
            printf("enter the data after which you want to insert the node: ");
            scanf("%d", &dt);
            // insert_after_data(dt);
            traverse();
            break;
        }

        if (choice == 3)
        {
            int pos;
            printf("enter the position at which you want to delete the node: ");
            scanf("%d", &pos);
            // delete_pos(pos);
            traverse();
            break;
        }

        if (choice == 4)
        {
            int dt;
            printf("enter the data which you want to delete: ");
            scanf("%d", &dt);
            // delete_data(dt);
            traverse();
            break;
        }

        if (choice == 5)
        {
            int c = count();
            printf("The  nos. of nodes in linked list are:%d\n", c);
            break;
        }

        if (choice == 6)
        {
            traverse();
            break;
        }

    } while (choice != 7);
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

int count()
{
    int count = 0;
    struct node *ptr = start;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}
void insert_at_pos(int pos)
{
    int item;
    struct node *ptr = start;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to enter at given positiopn :\n ");
    scanf("%d", &item);
    new_node->data = item;
    if (new_node == NULL)
    {
        printf("Overflow\n");
        return;
    }

    else
    {
        int c = count();
        if (pos == 1 || start == NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        else if (pos == c + 1)
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }
        else if (pos < 1 || pos > c + 1)
            printf("INVALID POSITION \n");
        else
        {
            int i = 1;
            ptr = start;
            while (i <= pos - 1)
            {
                ptr = ptr->next;
                i++;
            }
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
    }
}
