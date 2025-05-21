#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node* leftchild, *rightchild;  
}node;
node* newnode_func(int x)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data=x;
    newnode->leftchild=NULL;
    newnode->rightchild=NULL;

    return newnode;
}
node* insert(node* root,int k)
{
    if(root==NULL)
        return newnode_func(k);
    else if(k<root->data)
        root->leftchild=insert(root->leftchild,k);
    else if(k>root->data)
        root->rightchild=insert(root->rightchild,k);
    return root;
}  
void display(node* root)
{
    if(root!=NULL)
    {
        display(root->leftchild);
        printf("%d\n",root->data);
        display(root->rightchild);
    }
}
int count(node*root)
{
    if(root==NULL)
       return root;
    else
       return 1 + count(root->leftchild) + count(root->rightchild);
}
node* search_bst(node* root,int key)
{
    if(root == NULL || root->data ==key)
        return root;
    else if(key<root->data)
        return search_bst(root->leftchild,key);
    else
        return search_bst(root->rightchild,key);
}
node* smallest(node* root)
{
    if(root==NULL || root->leftchild == NULL)
        return root;
    else
        return smallest(root->leftchild);
}
node* largest(node* root)
{
    if(root==NULL || root->rightchild == NULL)
        return root;
    else
        return largest(root->rightchild);
}
int height(node* root)
{
    if(root==NULL)
        return -1;
    else
    {
        int left=height(root->leftchild);
        int right=height(root->rightchild);
        if(left>right)
            return left+1;
        else
            return right+1;
    }
}
int depth(node*root)
{
    if(root==NULL)
        return 0;
    else
    {
        int left=height(root->leftchild);
        int right=height(root->rightchild);
        if(left>right)
            return left+1;
        else
            return right+1;
    }
}
void inorder(node*root)
{
    if(root!=NULL)
    {
        inorder(root->leftchild);
        printf("%d",root->data);
        inorder(root->rightchild);
    }
}
void postorder(node*root)
{
    if(root!=NULL){
        postorder(root->leftchild);
        postorder(root->rightchild);
        printf("%d",root->data);
    }
}
void preorder(node*root)
{
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}
node*deleteNode(node*root,int k)
{    
    if(root == NULL)
      return root;
    if(root->data > k)
    {
        root->leftchild = deleteNode(root->leftchild,k);
    }
    else if(root->data < k)
    {
        root->rightchild = deleteNode(root->rightchild,k);
    }
    else
    {
         if(root->leftchild==NULL || root->rightchild==NULL)
         {
            node* temp = root->leftchild ? root->leftchild :root->rightchild;

         if(temp == NULL)
         { 
            temp=root;
            root=NULL;
         }
         else
           root = temp ;
           free(temp);
        }
        else{
            node*temp = smallest(root->rightchild);
            root->data=temp->data;
            root->rightchild = deleteNode(root->rightchild,temp->data);
        }
    }
}
int main()
{
    int sel,n,h,num;

    node *root=NULL;
    node * temp=NULL;
    printf("\t1.Create Node\n\t2.display\n\t3.Search number\n"
            "\t4.Smallest number\n\t5.largest number\n\t6.height of bst\n\t7.count of bst\n\t8.Depth of BST\n\t9.Delete a node in Bst\n");
    printf("\t10.inorder traversal\n\t11.preorder traversal\n\t12.postorder traversal\n");
    printf("enter your choice ( enter -1 to exit ) : ");
    scanf("%d",&sel);

    while(sel != -1)
    {
        
        switch(sel)
        {


            case 1:
                printf("Enter new number to add into bst : ");
                scanf("%d",&n);
                root=insert(root,n);
                break;
            
            case 2:
                display(root);
                break;

            case 3:
                printf("Enter key to search in bst : ");
                scanf("%d",&n);
                temp=search_bst( root, n);
                
                if(temp==NULL)
                    printf("%d not found in BST.\n",n);
                else
                    printf("%d found in BST.\n",n);

                break;

            case 4:
                temp=smallest( root);

                if(temp==NULL)
                    printf(" BST is empty !\n");
                else
                    printf("Smallest number : %d\n",temp->data);                
                break;

            case 5:
                temp=largest( root);

                if(temp==NULL)
                    printf(" BST is empty !\n");
                else
                    printf("Largest number : %d\n",temp->data); 
                break;

            case 6:
                h=height( root);
                if(h==-1)
                    printf(" BST is empty !\n");
                else
                    printf("Height of BST : %d\n",h); 
                break;
            case 7:
                num = count(root);
                printf("No.of nodes in Bst: %d\n",num);
                break;
            case 8:
               num = depth(root);
               printf("depth is : %d\n",num);
            break;
            case 9:
              printf("Enter a number to delete: \n");
              scanf("%d",&n);
              root = deleteNode(root,n);
            break;
            case 10:
              inorder(root);
              break;
            case 11:
              preorder(root);
              break;
            case 12:
              postorder(root);
              break;
            default:
                printf("wrong choice !!!\n");

        }
        printf("Successfully completed operation %d\n\n",sel);
        printf("Enter your selection ( enter -1 to exit ) : ");
        scanf("%d",&sel);
    }
    return 0;
}
