#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *rptr;
  struct Node *lptr;
};

struct Node *head = NULL;

void insert(int data)
{
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->rptr = head;
  new_node->lptr = NULL;

  if (head == NULL)
  {
    head = new_node;
    return;
  }
  else
  {
    head->lptr = new_node;
    head = new_node;
  }
}

int count()
{
  int c = 1;
  struct Node *t = head;
  t = t->rptr;
  while (t != head)
  {
    c++;
    t = t->rptr;
  }
  return c;
}

void traverse()
{
  struct Node *temp = head;
  if (head == NULL)
  {
    printf("List is empty.\n");
  }

  do
  {
    printf("%d ", temp->data);
    temp = temp->rptr;
  } while (temp != head);

  printf("\n");
}

void insert_at_specific_pos(int pos, int item)
{
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  struct Node *ptr = head;
  newnode->data = item;
  if (head == NULL)
  {
    newnode->lptr = NULL;
    newnode->rptr = NULL;
    head = newnode;
    printf("\nAs the linked list is empty, the node is inserted at the first position.\n");
  }
  else
  {
    int c = count();
    while (c != pos - 1)
    {
      ptr = ptr->rptr;
      c--;
    }
    newnode->lptr = ptr;
    newnode->rptr = ptr->rptr;
    ptr->rptr->lptr = newnode; // Update the previous next node's left pointer
    ptr->rptr = newnode;
  }
}

void delete_at_specific_pos()
{
  // Provide the implementation for deleting a node at a specific position
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

  printf("Doubly Linked List: ");
  traverse();

  int choice;
  do
  {
    printf("\nEnter your choice:\n");
    printf("0. Enter 0 to exit\n");
    printf("1. Insert an element at a specific position\n");
    printf("2. Delete an element from a specific position\n");
    printf("3. Traverse the list\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
      int pos, item;
      printf("Enter the position: ");
      scanf("%d", &pos);
      printf("Enter the data to insert: ");
      scanf("%d", &item);
      insert_at_specific_pos(pos, item);
      traverse();
    }

    if (choice == 2)
    {
      // Implement the delete_at_specific_pos function
      // Call it here to delete a node from a specific position
      // Example: delete_at_specific_pos();
      // traverse();
    }

    if (choice == 3)
    {
      traverse();
    }
  } while (choice != 0);

  return 0;
}
