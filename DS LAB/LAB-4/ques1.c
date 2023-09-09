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
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void tarverse()
{
    struct node *ptr = head;
    printf("\nThe linked list is :");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
void search_ll(int ele)
{
    struct node *ptr = head;
    int flag = 0;
    while (ptr != NULL)
    {
        if (ptr->data == ele)
        {
            printf("\nElement is found\n");
            return;
        }
        else
        {
            flag = 0;
        }
        ptr = ptr->next;
    }

    printf("\nNOT FOUND");
}

void reverse()
{
    struct node *prev = NULL;
    struct node *current = head;
    struct node *next_node = NULL;

    while (current != NULL)
    {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    head= prev;
}
int main()
{
    int x;
    printf("\nEnter the number of nodes :");
    scanf("%d", &x);

    for (int i = 0; i < x; i++)
    {
        int data;
        printf("Emter dat for node %d: ", i + 1);
        scanf("%d", &data);
        insert(data);
    }
    tarverse();
    printf("\nEnter your choice :\n1.SEARCH an element in the list \n2.sort the list in ascending orfer \n3.reverse  \n0.EXIT\n");
    int choice;
    scanf("%d", &choice);
    do
    {
        if (choice == 1)
        {
            int ele;
            printf("Enter the elemnet to search ");
            scanf("%d", &ele);
            search_ll(ele);
            break;
        }
        if (choice == 2)
        {
            break;
        }
        if (choice == 3)
        {
            reverse();
            tarverse();
        }
    } while (choice != 0);
    return 0;
}