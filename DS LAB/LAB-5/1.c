#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *insert_specific(struct node *start);
struct node *create(struct node *start);
struct node *delete_specific(struct node *start);
int count_nodes(struct node *start);
void display(struct node *start);
int main()
{
    int n;
    int choice;
    struct node *start = NULL;
    printf("Enter the Number of Node : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        start = create(start);
    }
    display(start);
    while (1)
    {
        printf("1.Insert an element at specific Positon\n");
        printf("2.Delete an element at specific Positon\n");
        printf("3.Traverse the List\n");
        printf("Enter the choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            start = insert_specific(start);
            display(start);
        }
        else if (choice == 2)
        {
            start = delete_specific(start);
            display(start);
        }
        else if (choice == 3)
        {
            display(start);
        }
        else
        {
            printf("Invalid Choice.");
            exit(1);
        }
    }

    return 0;
}
struct node *delete_specific(struct node *start)
{
    struct node *del = NULL;
    struct node *ptr = start;
    int pos;
    printf("Enter the Position : ");
    scanf("%d", &pos);
    int count = count_nodes(start);
    if (pos > count || pos < 0)
    {
        printf("Postion is Invalid.\n");
    }
    else if (start == NULL)
    {
        printf("Linked List is Empty.");
    }
    else if (pos == 1)
    {
        ptr = start;
        start = ptr->next;
        start->prev = NULL;
        free(ptr);
    }
    else if (pos == count)
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
    }
    else if (start->next == NULL)
    {
        del = start;
        free(del);
        start = NULL;
    }
    else
    {
        pos--;
        ptr = start;
        while (pos != 1)
        {
            ptr = ptr->next;
            pos--;
        }
        del = ptr->next;
        ptr->next = del->next;
        del->next->prev = ptr;
        free(del);
        del = NULL;
    }
    return start;
}
int count_nodes(struct node *start)
{
    int count = 0;
    while (start != NULL)
    {
        count++;
        start = start->next;
    }
    return count;
}
struct node *insert_specific(struct node *start)
{
    int val, pos;
    printf("Enter the Position : ");
    scanf("%d", &pos);
    printf("Enter the Value : ");
    scanf("%d", &val);
    struct node *new = malloc(sizeof(struct node));
    struct node *ptr = start;
    int count = count_nodes(start);
    new->data = val;
    new->next = NULL;
    new->prev = NULL;
    if (pos > count + 1 || pos < 0)
    {
        printf("Postion is Invalid.\n");
    }
    else if (start == NULL)
    {
        start = new;
    }
    else if (pos == 1)
    {
        new->next = start;
        start->prev = new;
        start = new;
    }
    else if (pos == count + 1)
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        new->next = NULL;
        new->prev = ptr;
        ptr->next = new;
    }
    else
    {
        pos--;
        while (pos != 1)
        {
            ptr = ptr->next;
            pos--;
        }
        new->next = ptr->next;
        ptr->next = new;
        new->prev = ptr;
        ptr->next->next->prev = new;
    }
    return start;
}
struct node *create(struct node *start)
{
    int val;
    printf("Enter the Value : ");
    scanf("%d", &val);
    struct node *new = malloc(sizeof(struct node));
    struct node *ptr = start;
    new->data = val;
    new->prev = NULL;
    new->next = NULL;
    if (start == NULL)
    {
        start = new;
        return start;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        new->data = val;
        new->prev = ptr;
        ptr->next = new;
    }
    return start;
}
void display(struct node *start)
{
    struct node *ptr = start;
    printf("Linked List is : ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}