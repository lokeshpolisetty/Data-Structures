#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
int cirqueue[MAX_SIZE];
int rear = -1,front = -1;
int i;

int isfull()
{
    if(rear == (rear + 1)%MAX_SIZE)
    return 1;
    else
       return 0;
}
int isempty()
{
    if(front == -1)
    return 1;
    else  
      return 0;
}
void enqueue(int data)
{
    if(isfull())
    {
        printf("Queue is full\n");
    }
    else
    {
       if(front == -1)
          front = 0;
        rear = (rear + 1)%MAX_SIZE;
        cirqueue[rear] = data;
        printf("Sucessfully inserted\n");
    }
}
void dequeue()
{
    if(isempty()){
        printf("Queue is empty\n");
    }
    else{
        printf("sucessfully deleted\n");
        printf("deleted element = %d\n",cirqueue[front]);
        if(front == rear)
          front = rear = -1;
          else
          front = (front+1)%MAX_SIZE;
    }
}
void elements()
{
    if (isempty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("front and raer elements are : %d and %d\n", cirqueue[front],cirqueue[rear]);
    }
}
void display()
{
    if(isempty())
    {
        printf("Queue is Empty\n");
    }
    else{
        printf("Elements in queue are: \n");
        for(int i=front; i<=rear ;i++);
        printf("%d\n", cirqueue[i]);
    }
}
int main()
{
    int choice,data;
    while(1)
    {
        printf("1. enqueue:\n");
        printf("2. dequeue:\n");
        printf("3. front and rear Elements: \n");
        printf("4. print all Elements: \n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("ENTER A VALUE TO ENQUEUE\n");
            scanf("%d",&data);
            enqueue(data);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            elements();
            break;
            case 4:
            display();
            break;
            exit(1);
            break;
            default:
            printf("Wrong choice\n");
         }
    }
    return 0;
}
