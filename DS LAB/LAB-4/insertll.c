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
void insert_at_end(int edata)
{
  struct node *ptr = head;
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = edata;
  newnode->next = NULL;
  while (ptr->next != NULL)
  {
    ptr = ptr->next;
  }
  ptr->next = newnode;
}
void insert_after_data(int adata, int edata)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  struct node *ptr = head;
  newnode->data = edata;
  newnode->next = NULL;
  while (ptr != NULL)
  {
    if (ptr->data == adata)
    {
      newnode->next = ptr->next;
      ptr->next = newnode;
      break;
    }
    ptr = ptr->next;
  }
}
void traverse()
{
  struct node *temp = head;
  while (temp != NULL)
  {
    printf("%d\n", temp->data);
    temp = temp->next;
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
  int edata, adata;
  printf("Enter the data after which you want to insert ");
  scanf("%d", &adata);
  printf("Enter the data you want to insert ");
  scanf("%d", &edata);
  // insert_at_end(edata);
  insert_after_data(adata, edata);
  traverse();

  return 0;
}