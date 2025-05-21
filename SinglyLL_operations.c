#include<stdio.h>
#include<stdlib.h>
struct node{
    int data ;
    struct node *next;
};
struct node* head=NULL;
void create_sll(int n)
{ int i;
    struct node *ptr ;
    for(i=1;i<=n;i++)
    {
       if(i==1)
       {
        head = (struct node*)malloc(sizeof(struct node));
        ptr = head;
       }
       else{
        ptr->next=(struct node*)malloc(sizeof(struct node));
        ptr = ptr->next;
       }
       printf("enter the %d element\n",i);
       scanf("%d",&ptr->data);
    }
    ptr->next= NULL;
}
void display()
{  
    if(head == NULL)
    {
        printf("Linked list is empty\n");
    }
     struct node*ptr=NULL;
     ptr=head;
     while(ptr!= NULL)
     {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
     }  
}
void insertBig()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data into new node");
    scanf("%d",&newnode->data);
    newnode->next = head;
    head = newnode;   
}
void insertmid()
{
    int loc,count=1;
    printf("enter location\n");
    scanf("%d",&loc);

    struct node *newnode,*ptr;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("enter data");
    scanf("%d",&newnode->data);

    ptr=head;

    while(ptr!=NULL && count!=loc)
    {
        ptr=ptr->next;
        count++;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
}
void insertEnd()
{
    struct node *newnode,*ptr;
    newnode=(struct node*)malloc(sizeof(struct node));
    
    printf("Enter data");
    scanf("%d",&newnode->data);

    newnode->next=NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    ptr = head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;  
}
void delete_big()
{
    struct node*ptr;

    ptr = head;
    head = head->next;

    free(ptr);
   
}
void delete_mid()
{
    int loc,count=0;
    printf("enter location\n");
    scanf("%d",&loc);

    struct node*ptr,*curr;
    curr = head;

    if(curr == NULL)
      return ;
    if(curr!=NULL && curr->data == loc)
    {
        head = curr->next;
        free(curr);
        return;
    }
    while(curr!=NULL && curr->data!= loc)
    {
        ptr = curr->next;
        curr=curr->next;
    }
    ptr->next=curr->next;
    free(curr);
    
}
void delete_End()
{
    if(head==NULL)
    return ;
    
    struct node *curr,*ptr;
    for(curr=head;curr->next!=NULL; curr=curr->next)
    {
        ptr=curr;
    }
    ptr->next=NULL;
    free(curr);
  
}
void Reverse(){
   struct node *ptr=NULL,*temp=NULL,*curr=head;
   if(head==NULL)
   {
    printf("Linked list is empty");
   }
   while(curr!=NULL)
   {
    temp=curr->next;
    curr->next=ptr;
    ptr=curr;
    curr = temp;
   }
   head=ptr;
}
void search_SLL()
{
    struct node *ptr;
    int key, flag=0;
    printf("Enter an element to search: ");
    scanf("%d",&key);
    for(ptr = head; ptr!= NULL; ptr = ptr->next)
    {
      if((ptr->data)==key)
    {
       flag=1;
       break;
    }
    }
    if(flag==1)
    printf("found");
    else
    printf("not found");   
}
void maximun()
{ 
    int n,max;
    printf("Enter a value");
    scanf("%d",&n);
    max=n;
    struct node*ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data>max)
        {
            max = ptr->data;
        }
        ptr=ptr->next;
    }
    printf("Maximum Element:%d\n",max);  
}
int main()
{
   int choice,n;
  scanf("%d",&n);
   while(1)
   {
    printf("\n1.creation of SLL\n");
    printf("2.Insertion at the beginning\n");
    printf("3.Insertion at a position\n");
    printf("4.Insertion at the End\n");
    printf("5.Deletion at the beginning\n");
    printf("6.Deletion at a Position\n");
    printf("7.Deletion at the End\n");
    printf("8.Display Elements in SLL\n");
    printf("9.search an elements in SLL\n");
    printf("10.Maximum element in SLL\n");
    printf("11.Reverse the elements in SLL\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        create_sll(n);
        break;
        case 2:
       insertBig();
        break;
        case 3:
        insertmid();
        break;
        case 4:
        insertEnd();
        break;
        case 5:
        delete_big();
        break;
        case 6:
        delete_mid();
        break;
        case 7:
        delete_End();
        break;
        case 8:
        display();
        break;
        case 11:
        Reverse();
        break;
        case 9:
        search_SLL();
        break;
        case 10:
        maximun();
        break;
        default:
        printf("Wrong choice");
    }
   }
}
