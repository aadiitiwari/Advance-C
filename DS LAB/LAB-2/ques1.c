#include<stdio.h>
#include<stdlib.h>
int traverse(int arr[], int n){
    printf("Array Elements : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int insert_pos(int arr[],int n,int pos,int element,int size)
{
    if(n==0)
    {
        arr[0]=element;
        n=1;
        traverse(arr,n);
    }

    else
    {
        if(pos>n+1 || pos>=size+1)
        printf("INVALID POSITION");

        else{
            for(int i=n;i>=pos;i--){
            arr[i]=arr[i-1];    
            }

            arr[pos-1]=element;
            n=n+1;
            traverse(arr,n);
        }
    }
}

int delete_pos(int arr[],int pos,int n)
{
    if(n==0)
    {
        printf("The array is empty");
    }

    else if(pos>=n+1)
    {
        printf("INVALID POSITION");
    }

    else{
        for(int i=pos-1;i<=n;i++)
        {
            arr[i]=arr[i+1];
        }
        n=n-1;
        traverse(arr,n);
    }
}

int linear_search(int arr[],int element,int n)
{
    if(n==0)
    {
        printf("The array is empty");
    }
     int flag=0;
     int pos=0;
    for (int i=0;i<=n;i++)
    {
        if (arr[i]==element)
        {
            flag=1;
            pos=i;
        }

        else 
        continue;
    }
    if(flag==1)
    printf("Element found at %d \n",pos+1);
    else
    printf("Element not found \n");
}

int main()
{
    int n,size=20;
    printf("Enter size of n : ");
    scanf("%d",&n);
    int arr[n];
    //int *ptr = (int *)malloc(n*sizeof(int)) ;

    printf("Enter elements of array \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int choice ;
    do{
    printf("*****MENU*****\n1.INSERT\n2.DELETE\n3.LINEAR SEARCH\n4.TRAVERSE\n5.EXIT \n");
    scanf("%d",&choice);
    
    if(choice==1)
    {
        int element,pos;
        printf("Enter position ");
        scanf("%d",&pos);
        printf("Enter the element to insert ");
        scanf("%d",&element);
        insert_pos(arr,n,pos,element,size);
    }

    if(choice==2)
    {
        int pos;
        printf("Enter the position of array at which you want to delete the element ");
        scanf("%d",&pos);
        delete_pos(arr,pos,n);
    }

    if (choice==3)
    {
        int element;
        printf("Enter the element you want to search linearly ");
        scanf("%d",&element);
        linear_search(arr,element ,n);
    }

    if (choice==4)
    {
        traverse(arr,n);
    }
    }while(choice!=5);

    return 0;
}
