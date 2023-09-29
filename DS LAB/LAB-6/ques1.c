#include <stdio.h>
int main(){
    int n;
    printf("Enter the size of the stack: ");
    scanf("%d",&n);
    int arr[100];
    for(int i = 0;i<n;i++){
        printf("Enter the data at %d position of stack: ",i+1);
        scanf("%d",&arr[i]);
    }    
    int top = n-1;
    int choice;
    do{
        printf("1.Push\n2.Pop\n3.IsEmpty\n4.IsFull\n5.Display\n0.Exit\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        if(choice == 1){
            if(top == -1){
                printf("Stack Underflow\n");
            }
            else{
                int data;
                printf("Enter the data : ");
                scanf("%d",&data);
                top++;
                arr[top] = data;
            }
        }
        else if(choice == 2){
            if(top == -1){
                printf("Stack Underflow\n");
            }
            else{
                printf("The popped element is %d\n",arr[top]);
                top--;
            }
        }
        else if(choice == 3){
            if(top == -1){
                printf("The stack is empty\n");
            }
            else{
                printf("The stack is not empty\n");
            }
        }
        else if(choice == 4){
            if(top == n-1){
                printf("The stack is full\n");
            }
            else{
                printf("The stack is not full\n");
            }
        }
        else if(choice == 5){
            if(top == -1){
                printf("Stack Underflow\n");
            }
            else{
                printf("The elements of the stack are : ");
                for(int i = top;i>=0;i--){
                    printf("%d ",arr[i]);
                }
                printf("\n");
            }
        }
        else if(choice == 0){
            break;
        }
        else{
            printf("Invalid Choice\n");
        }
    }
    while(choice!=0);
return 0;
}
