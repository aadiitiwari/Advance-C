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
            exit(1);
        }
    }

    return 0;
}
struct node *delete_specific(struct node *start)
{
    struct node *del = start;
    int pos;
    printf("Enter the Position : ");
    scanf("%d", &pos);
    int count = count_nodes(start);
    if (pos > count || pos < 0)
    {
        printf("Invalid Position.\n");
    }
    else if (start == NULL)
    {
        printf("List is Empty.");
        exit(1);
    }
    else if (pos == 1)
    {
        start->prev->next = start->next;
        start = start->next;
        start->prev = del->prev;
        free(del);
        del = NULL;
    }
    else
    {
        while (pos != 1)
        {
            del = del->next;
            pos--;
        }
        del->prev->next = del->next;
        del->next->prev = del->prev;
        free(del);
    }
    return start;
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
    if (pos > count + 1 || pos < 0)
    {
        printf("Invalid Position.\n");
    }
    else if (start == NULL)
    {
        start = new;
    }
    else if (pos == 1)
    {
        new->next = start;
        new->prev = start->prev;
        start->prev->next = new;
        start->prev = new;
        start = new;
        new->data = val;
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
        new->prev = ptr;
        ptr->next = new;
        new->data = val;
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
        new->prev = start;
        new->next = start;
        return start;
    }
    else
    {
        ptr = start;
        do
        {
            ptr = ptr->next;
        } while (ptr->next != start);
        new->data = val;
        new->prev = ptr;
        new->next = ptr->next;
        ptr->next = new;
        start->prev = new;
    }
    return start;
}
void display(struct node *start)
{
    struct node *ptr = start;
    printf("Linked List is : ");
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("\n");
}
int count_nodes(struct node *start)
{
    int count = 0;
    struct node *ptr = start;
    do
    {
        count++;
        start = start->next;
    } while (ptr != start);
    return count;
}