#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node*left;
    int data;
    struct node*right;
}node;
struct node*head;
void create_Dll(int n)
{
    int i;
    struct node *ptr,*temp;
    for(i=1;i<=n;i++)
    {
        if(i == 1)
        {
            head=(struct node*)malloc(sizeof(struct node));
            head->left=NULL;
            ptr=head;
        }
        else{
            temp=(struct node*)malloc(sizeof(struct node));
            ptr->right=temp;
            temp->left=ptr;
            ptr=temp;
        }
        printf("Enter the %d element\n",i);
        scanf("%d",&ptr->data);
    }
    ptr->right=NULL;
}
void insertBeg()
{
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));

    printf("Enter a element to insert at  beginning:\n");
    scanf("%d",&newnode->data);
    struct node*ptr=head;

    newnode->right=head;
    newnode->left=NULL;
    head->left=newnode;

    head=newnode;
}
void insertMid()
{
    struct node*newnode,*ptr;
    int loc,count=1;
    printf("Enter the location:\n");
    scanf("%d",&loc);
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data into newnode\n");
    scanf("%d",&newnode->data);
    if (head == NULL )
    {
       printf("Linked list is empty");
    }
    ptr=head;
    while(ptr!=NULL && count!=loc)
    {
        ptr = ptr->right;
    }
    newnode->left=ptr;
    newnode->right=ptr->right;
    ptr->right=newnode;
    ptr=newnode->right;
    ptr->left = newnode;
   
}
void insertEnd()
{
    struct node*newnode,*ptr;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value\n");
    scanf("%d",&newnode->data);
    if(head==NULL)
    {
        newnode->left=NULL;
        head=newnode;
        newnode->right=NULL;
    }
    ptr=head;
    while(ptr->right!=NULL)
    {
        ptr=ptr->right;
    }
    ptr->right=newnode;
    newnode->left=ptr;
}
void delete_beg()
{
    struct node*ptr;
    if(head==NULL)
    return;

    ptr=head;
    head=head->right;
    free(ptr);    
}
void delete_End()
{
    if(head==NULL)
    return;

    struct node*ptr=head,*temp;
    for(ptr=head;ptr->right!=NULL;ptr=ptr->right)
    {
        temp=ptr;
    }
    temp->right=NULL;
    free(ptr);
}
void delete_mid()
{
   int loc,count=1;
   printf("Enter a location\n");
   scanf("%d",&loc);
   struct node *ptr=head,*curr,*temp;
   if(head==NULL){
    return;
   }
   else {
   while (ptr!=NULL&&count<=loc)
   {
      curr=ptr;
      ptr=ptr->right;
   }
   curr->right=ptr->right;
   temp=ptr->right;
   temp->left=curr;
    free(ptr);
   }
}
void display()
{   
    if(head==NULL)
    return;
    struct node*ptr;
    ptr=head;
    while(ptr!=NULL){
    printf("%d\t",ptr->data);
        ptr=ptr->right;
    }
}
void max()
{
    int max;
    if(head==NULL)
    return;
    struct node*ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->data>max)
        {
            max = ptr->data;
        }
        ptr=ptr->right;
    }
    printf("Maximum Element:%d\n",max);
}
void search()
{
    struct node*ptr;
    int key, count=0,flag;
    printf("Enter an element to search:\n");
    scanf("%d",&key);
    if(head==NULL)
    return;
    for(ptr = head; ptr!= NULL; ptr = ptr->right)
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
    printf("Not found");
}
void reverse()
{  
    struct node*temp,*ptr=head;
   if(head==NULL)
    return;
    while(ptr!=NULL)
    {
        temp=ptr->right;
        ptr->right=ptr->left;
        ptr->left=temp;
        head=ptr;
        ptr=temp;
    }
}
int main()
{
    int choice,n;
  scanf("%d",&n);
   while(1)
   {
    printf("\n1.creation of DLL\n");
    printf("2.Insertion at the beginning\n");
    printf("3.Insertion at a position\n");
    printf("4.Insertion at the End\n");
    printf("5.Deletion at the beginning\n");
    printf("6.Deletion at a Position\n");
    printf("7.Deletion at the End\n");
    printf("8.Display Elements in DLL\n");
    printf("9.search an elements in DLL\n");
    printf("10.Maximum element in DLL\n");
    printf("11.Reverse the elements in DLL\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        create_Dll(n);
        break;
        case 2:
        insertBeg();
        break;
        case 3:
        insertMid();
        break;
        case 4:
        insertEnd();
        break;
        case 5:
        delete_beg();
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
        reverse();
        break;
        case 9:
        search();
        break;
        case 10:
        max();
        break;
        default:
        printf("\nWrong choice");
    }
   }
}
