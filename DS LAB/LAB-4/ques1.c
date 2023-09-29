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

void traverse()
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
    while (ptr != NULL)
    {
        if (ptr->data == ele)
        {
            printf("\nElement is found\n");
            return;
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
    head = prev;
}
void sort()
{
    struct node *ptr = head;
    struct node *cpt = NULL;
    while (ptr->next != NULL)
    {
        cpt = ptr->next;
        while (cpt != NULL)
        {
            if (ptr->data > cpt->data)
            {
                int temp;
                temp = ptr->data;
                ptr->data = cpt->data;
                cpt->data = temp;
            }
            cpt = cpt->next;
        }
        ptr = ptr->next;
    }
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
    traverse();
    int choice;
    do
    {
        printf("\nEnter your choice :\n1.SEARCH an element in the list \n2.sort the list in ascending orfer \n3.reverse  \n0.EXIT\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            int ele;
            printf("Enter the elemnet to search ");
            scanf("%d", &ele);
            search_ll(ele);
        }
        if (choice == 2)
        {
            sort();
            traverse();
        }
        if (choice == 3)
        {
            reverse();
            traverse();
        }
    } while (choice != 0);
    return 0;
}