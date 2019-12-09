#include <stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *tree=NULL;
void insert(int);
struct node *getnode(void);
void preordertraversal(struct node*);
void inordertraversal(struct node*);
void postordertraversal(struct node*);
int findsmallestelement(struct node*);
int findlargestelement(struct node*);
void deletetree(struct node*);
void mirrorimage(struct node*);
int totalnode(struct node*);
int totalexternalnode(struct node*);
int totalinternalnode(struct node*);
int height(struct node*);
int main()
{
    int option,val;
    struct node *ptr;
    do
    {
        printf("\n *********Main Menu*******");
        printf("\n 1.INSERT");
        printf("\n 2.Preorder Traversal");
        printf("\n 3.Inorder Traversal");
        printf("\n 4.postorder Traversal");
        printf("\n 5.Find the smallest element ");
        printf("\n 6.Find the largest element");
        printf("\n 7.Delete the element ");
        printf("\n 8.Count the total number of nodes");
        printf("\n 9.Count the total number of  external nodes");
        printf("\n 10.Count the total number of internal nodes");
        printf("\n 11.Determine the height of the tree");
        printf("\n 12.Find the mirror image of the tree");
        printf("\n 13.EXIT");
        printf("\n Enter the choice:");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("\n Enter the value of the  new node:");
            scanf("%d",&val);
            insert(val);
            break;
        case 2:
            printf("\n Preorder:\n");
            preordertraversal(tree);
            break;
        case 3:
            printf("\n Inorder :\n");
            inordertraversal(tree);
            break;
        case 4:
            printf("\n Postorder:\n");
            postordertraversal(tree);
            break;
        case 5:
            val=findsmallestelement(tree);
            printf("\n Smallest element is :%d",val);
            break;
        case 6:
            val=findlargestelement(tree);
            printf("\n Largest element is :%d",val);
            break;
        case 7:
            printf("\n Enter the number to be deleted:\n");
            scanf("%d",&val);
            deletetree(val);
            break;
        case 8:
            val=totalnode(tree);
            printf("\n Total nodes in tree=%d",val);
            break;
        case 9:
            val=totalexternalnode(tree);
            printf("\n Total number of external nodes=%d",val);
            break;
        case 10:
            val=totalinternalnode(tree);
            printf("\n Total number of internal nodes=%d",val);
            break;
        case 11:
            val=height(tree);
            printf("The height of the tree=%d",val);
            break;
        case 12:
            mirrorimage(tree);
            break;
        }

    }
    while(option!=13);
}
struct node *getnode(void)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    return (temp);
}
void insert(int val)
{
   struct node *ptr1,*ptr2,*ptr3;
   ptr1=getnode();
   ptr1->data=val;
   ptr1->left=NULL;
   ptr1->right=NULL;
   if(tree==NULL)
   {
       tree=ptr1;
       tree->left=NULL;
       tree->right=NULL;
   }
   else
   {
       ptr3=NULL;
       ptr2=tree;
       while(ptr2!=NULL)
       {
           ptr3=ptr2;
           if((ptr2->data)>val)
           {
               ptr2=ptr2->left;
           }
           else
           {
               ptr2=ptr2->right;
           }
       }
       if(ptr3->data<val)
       {
           ptr3->right=ptr1;
       }
       else
       {
           ptr3->left=ptr1;
       }
   }
}
void preordertraversal(struct node *tree)
{

    if(tree!=NULL)
    {
        printf(" %d ",tree->data);
        preordertraversal(tree->left);
        preordertraversal(tree->right);
    }
}
void inordertraversal(struct node *tree)
{
    if(tree!=NULL)
    {
        inordertraversal(tree->left);
        printf(" %d ",tree->data);
        inordertraversal(tree->right);
    }
}
void postordertraversal(struct node* tree)
{
    if(tree!=NULL)
    {
       postordertraversal(tree->left);
       postordertraversal(tree->right);
       printf(" %d",tree->data);
    }
}
int findsmallestelement(struct node *tree)
{
    if((tree==NULL)||(tree->left==NULL))
        return (tree->data);
    else
       findsmallestelement(tree->left);
}
int findlargestelement(struct node* tree)
{
    if((tree==NULL)||(tree->right==NULL))
        return (tree->data);
    else
        findlargestelement(tree->right);

}
int totalnode(struct node *tree)
{
    if(tree==NULL)
        return 0;
    else
        return(totalnode(tree->left)+totalnode(tree->right)+1);
}
int totalexternalnode(struct node *tree)
{
    if(tree==NULL)
        return 0;
    else if((tree->left==NULL)&&(tree->right==NULL))
        return 1;
    else
        return(totalexternalnode(tree->left)+totalexternalnode(tree->right));
}
int totalinternalnode(struct node *tree)
{
    if((tree==NULL)||(tree->left==NULL)&&(tree->right==NULL))
        return 0;
    else
        return(totalinternalnode(tree->left)+totalinternalnode(tree->right)+1);
}
int height(struct node *tree)
{
    int leftheight, rightheight;
    if(tree==NULL)
        return 0;
    else
    {
        leftheight=height(tree->left);
        rightheight=height(tree->right);
        if(leftheight>rightheight)
            return(leftheight+1);
        else
            return(rightheight+1);
    }
}
void mirrorimage(struct node* tree)
{
    struct node *ptr;
    if(tree!=NULL)
    {
      mirrorimage(tree->left);
      mirrorimage(tree->right);
      ptr=tree->left;
      ptr->right=ptr->left;
      tree->right=ptr;
    }
}
void deletetree(struct node* tree)
{
    if(tree!=NULL)
    {
      deletetree(tree->left);
      deletetree(tree->right);
      free(tree);
    }
}








