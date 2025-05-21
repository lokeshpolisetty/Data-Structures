#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *ptr,*newnode;
struct node *create_CLL(int n)
{
	for(int i=0;i<n;i++)
	{
		if(head==NULL)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			head=newnode;
			ptr=head;
		}
		else
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			ptr->next=newnode;
			ptr=ptr->next;
		}
	printf("Enter the data in the node[%d]:",i);
	scanf("%d",&ptr->data);
	}
	ptr->next=head;
	return(head);
}
int display_CLL()
{
	if(head==NULL)
	printf("LinkedList is empty\n");
	else
	{   
		ptr=head;
		printf("Elements in linkedlist are:\n");
		do
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}while(ptr!=head);
	}
}
int max()
{
	if(head==NULL){
        printf("Linkedlist is empty\n");
    }
    else{
    struct node *temp;
    temp=head;
    ptr=head;
    for(ptr=ptr->next;ptr!=head;ptr=ptr->next)
    {
        if(temp->data < ptr->data){
            temp=ptr;
        }
    }
    printf("Max element:%d\n",temp->data);
	}
}
int search_CLL()
{
	int key,flag=0;
	printf("Enter element to be searched:");
	scanf("%d",&key);
	ptr=head;
	for(ptr = head; ptr!= NULL; ptr = ptr->next)
    {
      if ((ptr->data)==key)
      {
        flag=1;
        break;
      }
    }
	if(flag==1)
	printf("Found\n");
	else
	printf("Not found\n");
}
struct node *insertbegin_CLL(int value)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		ptr=head;
		while(ptr->next!=head)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		head=newnode;
	}
	newnode->data=value;
	return head;
}
struct node *insertend_CLL(int value)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		ptr=head;
		while(ptr->next!=head)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		newnode->next=head;
	}
	newnode->data=value;
	return head;
}
struct node * insertmid_CLL(int value,int loc)
{
	int count=1;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
        head=newnode;
    }
    else
    {
    	ptr=head;
    while(ptr->next!=head && count!=loc)
    {
    	ptr=ptr->next;
    	count++;
	}
	newnode->next=ptr->next;
	ptr->next=newnode;
	}
	newnode->data=value;
	return head;
}
struct node *deletebegin_CLL()
{
	struct node *d;
	if(head==NULL)
	{
		printf("Linkedlist is empty\n");
	}
	else
	{
		ptr=head;
		while(ptr->next!=head)
		{
			ptr=ptr->next;
		}
		d=head;
		printf("The deleted element is %d\n",head->data);
		head=head->next;
		ptr->next=head;
		free(d);
	}
	return head;
}
struct node *deleteend_CLL()
{
	struct node *prev,*curr=head;
	if(head==NULL)
	{
		printf("Linkedlist is empty\n");
	}
	else
	{
		while(curr->next!=head)
		{
			prev=curr;
			curr=curr->next;
		}
	}
	printf("The deleted element is %d\n",curr->data);
	prev->next=head;
	free(curr);
	return head;
}
struct node * deletemid_CLL(int key)
{
	struct node *curr,*prev;
	curr=head;
	while(curr->data!=key && curr!=head)
	{
		prev=curr;
		curr=curr->next;
	}
	if(curr==NULL)
	{
		printf("Element does not exist\n");
	}
	prev->next=curr->next;
	free(curr);
	return head;
}
int main()
{
	int ch,value1,loc,n;
	printf("OPERATIONS ON CIRCULARLY LINKED LIST:\n");
	printf("1.CREATE\n2.DISPLAY\n3.INSERT AT FRONT \n4.INSERT AT POSITION \n5.INSERT AT END\n6.DELETE AT FRONT\n7.DELETE AT POSITION\n8.DELETE AT END\n9.SEARCH\n10.MAX\n11.EXIT\n");
	while(1){
		printf("Enter a choice[1-12]:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter no.of nodes:");
				scanf("%d",&n);
				create_CLL(n);
				break;
			case 2:
					display_CLL();
					break;
			case 3:
            printf("Enter a value to be inserted at FRONT:");
            scanf("%d",&value1);
            insertbegin_CLL(value1);
            break;
            case 4:
            printf("Enter a value to be inserted at POSITION:");
            scanf("%d",&value1);
            printf("Enter the LOCATION after which it has to be inserted: ");
            scanf("%d",&loc);
            insertmid_CLL(value1,loc);
            break;
            case 5:
            printf("Enter a value to be inserted at END:");
            scanf("%d",&value1);
            insertend_CLL(value1);
            break;
            case 6: 
            printf("Deleting FRONT element....\n");
            deletebegin_CLL();
            break;
            case 7:
            printf("Enter a value to be deleted at position:");
            scanf("%d",&value1);
            deletemid_CLL(value1);
            break;
            case 8:
            printf("Deleting LAST element....\n");
            deleteend_CLL();
            break;
			case 9:
            search_CLL();
            break;
            case 10:
            max();
            break;
            case 11:
            printf("EXITING..");
            break;
            default:
            printf("Invalid Choice\n");
		}
	}
	return 0;
}