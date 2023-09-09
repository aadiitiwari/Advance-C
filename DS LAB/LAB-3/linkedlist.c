#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void insert(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    struct node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void traverse() {
  struct node *temp = head;
  while (temp != NULL) {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

int main() {
  int n;
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int data;
    printf("Enter data for node %d: ", i + 1);
    scanf("%d", &data);
    insert(data);
  }

  printf("The linked list is:\n");
  traverse();

  return 0;
}