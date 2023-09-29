#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;


struct node *push(struct node *start){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&ptr->data);
    ptr->next = start;
    start = ptr;
    return start;
}
struct node *pop(struct node *start){
    struct node *ptr;
    ptr = start;
    start = start->next;
    printf("The popped element is %d\n",ptr->data);
    free(ptr);
    return start;
}
void isEmpty(struct node *start){
    if(start == NULL){
        printf("The stack is empty\n");
    }
    else{
        printf("The stack is not empty\n");
    }   
}
void display(struct node *start){
    struct node *ptr;
    ptr = start;
    printf("The elements of the stack are : ");
    while(ptr != NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main(){
    struct node *start = NULL;
    int n;
    printf("Enter the size of stack: ");
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        start = push(start);
    }
    int choice;

    do{
        printf("1.Push\n2.Pop\n3.IsEmpty\n4.Display\n0.Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        if(choice == 1){
            start = push(start);
        }
        else if(choice == 2){
            if(start == NULL){
                printf("Stack Underflow\n");
            }
            else{
                start = pop(start);
            }
        }
        else if(choice == 3){
            isEmpty(start);
        }
        else if(choice == 4){
            if(start == NULL){
                printf("Stack Underflow\n");
            }
            else{
                display(start);
            }
        }
        else{
            printf("Invalid choice");
            break;
        }
    }while(choice != 0);
    return 0;
}