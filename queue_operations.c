#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
int queue[MAX_SIZE];
int rear = -1,front = -1;
int isfull()
{
    if(rear == MAX_SIZE -1)
    {
       return 1;
    }
    else
        return 0;
}
int isEmpty()
{
    if(front == -1)
    {
        return 1;
    } else
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
       rear++;
       queue[rear] = data;
       printf("Element inserted successfully\n");
    }
}
void dequeue()
{
    if(isfull())
    {
        printf("Queue is Empty\n");
    }
    else
    {
       printf("Element Deleted\n");
       printf("deleted Element : %d\n",queue[front]);
       front++;
       if(front == MAX_SIZE)
       front = rear = -1;
    }
}
void elements()
{
    if(isEmpty())
    {
       printf("Queue is Empty\n");
    }
    else
    {
        printf("Front and Rear elements are: %d and %d\n",queue[front],queue[rear]);
    }
}
void display()
{
    if(isEmpty())
    {
       printf("Queue is Empty\n");
    }
    else
    {
        printf("Elements in the Queue: ");
        for(int i=front;i<=rear;i++)
        printf("%d\n",queue[i]);
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
            case 5:
            exit(1);
            break;
            default:
            printf("Wrong choice");

        }
    }
    return 0;
}