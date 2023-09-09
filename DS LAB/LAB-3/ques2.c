#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;
void traverse()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void insert(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insert_node_pos(int data, int pos)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;

    while (i != pos - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}

void delete_at_pos(int pos){
    struct node *ptr;
    struct node *prev;
    int i=0;
    while(i!=pos-1)
    {
        
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int data;
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insert(data);
    }

    printf("The linked list is:\n");
    traverse();

    int choice=1;
    do
    {
        printf("*****MENU*****\n1.INSERT at position \n2. insert after given data \n3. delete an element at specific position \n4.delete of agiven data \n5.count nodes \n6.EXIT \n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int data, pos;
            printf("Enter the position \n");
            scanf("%d", &pos);
            printf("ENTER THE DATA \n");
            scanf("%d", &data);
            insert_node_pos(data, pos);
            printf("LINKED LIST AFTER INSERSION \n");
            traverse();
        }

        if(choice==3)
        {
            int pos;
            printf("ENTER the position");
            scanf("%d",&pos);
            delete_at_pos(pos);
            printf("LINKED LIST AFTER INSERSION \n");
            traverse();
        }

    }while(choice!=6);
    return 0;
}