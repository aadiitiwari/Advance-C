#include <stdio.h>
#include <stdlib.h>
void insert_pos(int);
void insert_data(int);
void delete_pos(int);
void delete_data(int);
int count();
void traverse();
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *new_node;

int main()
{

    printf("enter the data or enter -1 to exit\n");
    int x;
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
        printf("enter the next data,or enter -1 to exit\n");
        scanf("%d", &x);
    }
    traverse();
    printf("\nThe number of nodes are %d\n", count());
    int ch;
    printf("\nyour choices are:\n1.insert a node at a specific position\n2.insert a node after a given data\n3.deletion of a element from certain position\n4.delete a given data\n5.count no. nodes\n6.traverse\nenter yor choice: \n");
    scanf("%d", &ch);
    while (ch == 1 || ch == 2 || ch == 3 || ch == 4 || ch == 5 || ch == 6)
    {
        switch (ch)
        {
        case 1:
        {
            int pos;
            printf("enter the position at which you want to insert the node: ");
            scanf("%d", &pos);
            insert_pos(pos);
            traverse();
            break;
        }

        case 2:
        {
            int dt;
            printf("enter the data after which you want to insert the node: ");
            scanf("%d", &dt);
            insert_data(dt);
            traverse();
            break;
        }

        case 3:
        {
            int pos;
            printf("enter the position at which you want to delete the node: ");
            scanf("%d", &pos);
            delete_pos(pos);
            traverse();
            break;
        }

        case 4:
        {
            int dt;
            printf("enter the data which you want to delete: ");
            scanf("%d", &dt);
            delete_data(dt);
            traverse();
            break;
        }

        case 5:
        {
            int c = count();
            printf("The  nos. of nodes in linked list are:%d\n", c);
            break;
        }

        case 6:
        {
            traverse();
            break;
        }
        }

        scanf("%d", &ch);
    }
}
void traverse()
{
    struct node *ptr = start;
    printf("\nThe Linked List is :");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

}
int count()
{
    struct node *ptr = start;
    int c = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        c++;
    }
    return c;
}
void insert_pos(int pos)
{
    int item = 100, co;
    struct node *ptr;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("enter the data you want to eneter at the given pos:");
    scanf("%d", &item);
    if (new_node == NULL)
    {
        printf("Overflow\n");
        return;
    }

    else
    {

        if (pos == 1 || start == NULL)
        {
            new_node->data = item;
            new_node->next = start;
            start = new_node;
        }
        else
        {
            co = count();
            if (pos == co + 1)
            {
                ptr = start;
                while (ptr->next != NULL)
                    ptr = ptr->next;
                ptr->next = new_node;
                new_node->data = item;
                new_node->next = NULL;
            }
            else if (pos > co + 1 || pos < 1)
            {
                printf("invalid position\n");
            }
            else
            {
                int i = 1;
                ptr = start;
                while (i <= pos - 1)
                {
                    ptr = ptr->next;
                    i++;
                }
                new_node->data = item;
                new_node->next = ptr->next;
                ptr->next = new_node;
            }
        }
    }
    // new_node->next = NULL;
}
void insert_data(int dt)
{
    struct node *ptr;
    printf("enetr the data that want to insert: ");
    int d;
    scanf("%d",&d);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data =d ;
    if (new_node == NULL)
        printf("Overflow\n");
    else if (start == NULL)
    {
        new_node->next = start;
        start = new_node;
    }
    else
    {
        ptr = start;
        int c = 0;
        while (ptr->data != dt || ptr->next == NULL)
        {
            c++;
            ptr = ptr->next;
        }
        int co = count();
        if (c >= co)
            printf("no such data found\n");
        else
        {
            int i = 1;
            ptr = start;
            while (i <= c - 1)
            {
                ptr = ptr->next;
                i++;
            }
            new_node->next = ptr->next;
            ptr->next = new_node;
        }
    }
}
void delete_pos(int pos)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("underflow\n");
    }
    else if (pos == 1)
    {
        ptr = start;
        start = start->next;
        free(ptr);
    }
    else if (pos > count())
        printf("invalid position\n");
    else
    {
        int co = count();
        int i = 1;
        ptr = start;
        while (i < pos - 1)
        {
            ptr = ptr->next;
            i++;
        }
        struct node *temp = ptr->next;
        ptr->next = (ptr->next)->next;
        free(temp);
    }
}
void delete_data(int dt)
{
    struct node *ptr;
    int co = count(), c = 0;
    if (start == NULL)
    {
        printf("underflow\n");
    }
    else
    {
        ptr = start;
        while (ptr->data != dt || ptr->next == NULL)
        {
            c++;
            ptr = ptr->next;
        }
        if (c == 1)
        {
            start = start->next;
            free(ptr);
        }
        else if (c > co)
            printf("invalid position\n");
        else
        {
            int i = 1;
            ptr = start;
            while (i < c - 1)
            {
                ptr = ptr->next;
                i++;
            }
            struct node *temp = ptr->next;
            ptr->next = (ptr->next)->next;
            free(temp);
        }
    }
}