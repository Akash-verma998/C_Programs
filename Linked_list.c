#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *creat(int);
void display(struct node*);
struct node *insert_beg(int);
struct node *getnode(void);
void insert_after(struct node*,int);
void insert_end(int);
int del_beg(void);
int del_after(struct node *p);
int del_end(void);
void reverse(struct node*);
void swap(int*,int*);
int count(void);
int n;
int main()
{
	int option,num,x,q,a,b;
	struct node *p,*ptr;
	do
	{
		printf("\n*******MAIN MENU********\n");
		printf("\n1.Create the linked list.");
		printf("\n2.Display the linked list.");
		printf("\n3.Insert a node in beginning.");
		printf("\n4.insert a node after a nod.");
		printf("\n5.insert a node in the end.");
		printf("\n6.Delete a value from beginning.");
		printf("\n7.delete the value after node.");
		printf("\n8.Delete the end node.");
		printf("\n9.Reverse the linked list.");
		printf("\n10.EXIT");
		printf("\n Enter the task option: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: printf("Enter the number of node in linked list:");
                    scanf("%d",&n);
                    start=creat(n);
                    break;
            case 2: display(start);
                    break;
            case 3: printf("\n Enter the value that to be add: ");
			        scanf("%d",&num);
			        start=insert_beg(num);
			        break;
			case 4: ptr=start;
	                printf("\n Enter the data: ");
	                scanf("%d",&x);
                    printf("\n Enter the value after that value add:");
	                scanf("%d",&q);
	                while(ptr->data!=q)
                        ptr=ptr->next;
                    p=ptr;
			        insert_after(p,x);
			        break;
            case 5: printf("\n Enter the value to be add in end in the list:");
                    scanf("%d",&num);
                    insert_end(num);
                    break;
            case 6: a=del_beg();
                    break;

            case 7: ptr=start;
                    printf("\n Enter the value after that value be deleted:");
	                scanf("%d",&q);
	                while(ptr->data!=q)
                        ptr=ptr->next;
                    p=ptr;
                    b=del_after(p);
                    break;
            case 8: del_end();
                    break;
            case 9: reverse(start);
                    break;
		}

	}
	while(option!=10);
	return 0;
}
struct node* creat(int n)
{
    int i,num;
    struct node *temp=NULL,*ptr=NULL;
    for(i=0;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\n Enter the data of %d node:",i+1);
        scanf("%d",&num);
        temp->data=num;
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=temp;
        }
      }
      return start;

}
void display(struct node *start)
{
    struct node *temp;
    temp=start;
    printf("\n\nLINKED LIST:    ");
    while(temp!=NULL)
    {

        printf("%d-->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n\n");
}
struct node *getnode(void)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	return(temp);
}
struct node *insert_beg(int num)
{
	struct node *temp;
	temp=getnode();
	temp->data=num;
	temp->next=start;
	start=temp;
	return start;
}
void insert_after(struct node *p,int x)
{
	struct node *temp;

	if(p==NULL)
	{
		printf("\nvoid insertion\n");
		exit(1);
	}
	temp=getnode();
	temp->data=x;
	temp->next=p->next;
	p->next=temp;
	return ;
}
void insert_end(int x)
{
    struct node *temp;
    if(start==NULL)
    {
        temp=getnode();
        temp->data=x;
        temp->next=NULL;
        start=temp;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        insert_after(temp,x);
    }
}
int del_beg(void)
{
    int x;
    struct node *temp;
    if(start==NULL)
    {
        printf("void deletion.");
        exit(1);
    }
    temp=start;
    start=start->next;
    x=temp->data;
    free(temp);
    return(x);
}
int del_after(struct node *p)
{
    int n;
    struct node *temp;
    if(start==NULL)
    {
        printf("Void deletion");
        exit(1);
    }
    temp=p->next;
    n=temp->data;
    p->next=temp->next;
    free(temp);
    return(n);
}
int del_end(void)
{
    struct node *temp;
    int x;
    if(start==NULL)
    {
        printf("void deletion");
        exit(1);
    }
    temp=start;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    x=del_after(temp);
    return (x);

}
void reverse(struct node* start)
{
    struct node *ptr;
    int i,j;
    int c=count();
    if(start==NULL)
    {
        printf("\n The list is empty");
    }
    else
    {
        for(i=c;i>1;i--)
        {
            ptr=start;
            for(j=1;j<i;j++)
            {
                swap(&(ptr->data),&(ptr->next->data));
                ptr=ptr->next;
            }
        }
    }
}
void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
int count(void)
{
	int c=0;
	struct node *temp;
	temp=start;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;	
	}
	return (c);
}
