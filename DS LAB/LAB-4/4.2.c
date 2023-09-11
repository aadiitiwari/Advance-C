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
void search(struct node *, int);
struct node *sort(struct node *);
struct node *rev(struct node *);

struct node *rev(struct node *head)
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *nex = NULL;

    while (curr != NULL)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    head = prev;

    return (head);
}

void search(struct node *head, int d)
{
    struct node *ptr = head;
    int p = 0, pos = 0;

    while (ptr->next != NULL)
    {
        if (ptr->data == d)
            pos = p;
        p++;
        ptr = ptr->next;
    }

    if (pos != 0)
        printf("Element found at node number %d \n", pos);
    else
        printf("Element not found \n");
}

struct node *sort(struct node *head)
{
    struct node *ptr = head;
    struct node *ptr2;

    while (ptr != NULL)
    {
        ptr2 = ptr;
        while (ptr2 != NULL)
        {
            if (ptr->data > ptr2->data)
            {
                int temp = ptr->data;
                ptr->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr = ptr->next;
    }

    return (head);
}

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

    printf("Enter the numbers:\n");
    printf("(Enter -1 to stop entering the data) \n");
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
        printf("5. Search an element in the linked list \n");
        printf("6. Sort the linked list \n");
        printf("7. Reverse the linked list \n");
        printf("8. EXIT\n");
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

        case 5:
            printf("Enter the element to be searched \n");
            scanf("%d", &e);
            search(head, e);
            break;

        case 6:
            printf("The linked list has been sorted \n");
            head = sort(head);
            break;

        case 7:
            prinf("The linked list has been reversed \n");
            head = rev(head);
            break;

        default:
            printf("EXIT\n");
        }

    } while (ch != 8);

    return (0);
}