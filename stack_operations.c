#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
int arr[MAX_SIZE];
int top = -1;
int isfull()
{
    if(top == MAX_SIZE - 1){
       return 1;
    }else
        return 0;
}
int isEmpty()
{
    if(top == -1){
        return 1;
    }else
         return 0;
}
void push(int data)
{
    if(isfull())
    {
        printf("stack overflow\n");
        return ;
    }
    else
    {
        top = top + 1;
        arr[top] = data;
    }
}
int pop()
{
    int value;
    if(isEmpty())
    {
        printf("stack underflow\n");
        return 0;
    }
    value = arr[top];
    top = top - 1;
    return value;
}
int peek()
{
    if(isEmpty())
    {
        printf("stack underflow\n");
        exit (1);
    }
    return arr[top];
}
void display()
{
    int i;
    if(top==-1)
    {
      printf("stack underflow\n");
        return;
    }
    else{
        for(i=top;i>=0;i--)
        {
            printf("%d",arr[i]);
            printf("\n");
        }
    }
}

int main(){
    int choice, data;
    while(1)
    {
         printf("1. push\n");
         printf("2. pop\n");
         printf("3. top\n");
         printf("4. display elements\n");
         printf("5. exit program\n");
         printf("Enter a choice :");
         scanf("%d",&choice);

         switch(choice) {
            case 1:
            printf("Enter a value to push: ");
            scanf("%d",&data);
            push(data);
            break;
            case 2: 
            data = pop(); 
            printf("deleted element %d\n",data);
            break;
            case 3:
            printf("topmost element %d\n",peek());
            break;
            case 4:
            display();
            break;
            case 5:
            exit(1); 
            default:
            printf("Wrong choice\n");
            
         }
    }
  return 0;
}