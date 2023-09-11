#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *create(struct node *);
struct node *insertAft(struct node *, int, int);
struct node *delAft(struct node *, int);
int count(struct node *);
void traverse(struct node *);

struct node *insertAft(struct node *head, int nd, int d)
{
    struct node *newnode;
    newnode->data = d;

    struct node *ptr = head;

    while (ptr->data != nd)
        ptr = ptr->next;

    newnode->next = ptr->next;
    ptr->next = newnode;

    return (head);
}

struct node *delAft(struct node *head, int n)
{
    struct node *ptr = head;
    while (ptr->data != n)
        ptr = ptr->next;

    struct node *nex = ptr->next;

    ptr->next = nex->next;

    free(nex);

    return (head);
}

int count(struct node *head)
{
    int c = 0;
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        c++;
    }

    return (c + 1);
}

void traverse(struct node *head)
{
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d \n", ptr->data);
}

struct node *create(struct node *start)
{
    struct node *newnode, *ptr;
    int num;

    printf("Enter the number:\n");
    printf("Enter -1 to stop entering the data \n");
    scanf("%d", &num);

    while (num != -1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = num;

        if (start == NULL)
        {
            start = newnode;
            newnode->next = NULL;
        }
        else
        {
            ptr = start;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = NULL;
        }
        printf("Enter data \n");
        scanf("%d", &num);
    }

    return (start);
}

int main()
{
    printf("Enter the elements of the linked list \n");
    head = create(head);

    int ch, e, nde;
    do
    {
        printf("**MENU**\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Count the number of nodes \n");
        printf("4. Traverse the linked list \n");
        printf("5. EXIT\n");
        printf("Enter your choice \n");

        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            printf("Enter the element after which you want to insert a node \n");
            scanf("%d", &e);

            printf("Enter the element to be inserted \n");
            scanf("%d", &nde);

            head = insertAft(head, e, nde);
            printf("Node inserted \n");
            break;

        case 2:
            printf("Enter the element after which you want to delete the node\n");
            scanf("%d", &e);
            head = delAft(head, e);
            printf("Element deleted after the given position \n");
            break;

        case 3:
            e = count(head);
            printf("the number of nodes in the linked list = %d  \n", e);
            break;

        case 4:
            printf("The linked list \n");
            traverse(head);
            break;

        default:
            printf("EXIT\n");
        }

    } while (ch != 5);

    return (0);
}