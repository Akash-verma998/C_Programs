#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node* creat(int);
void display(struct node*);
void reverse(struct node*);
void swap(int*,int*);
int n;
int main()
{
	int option;
	do
	{
		printf("\n*******MAIN MENU********\n");
		printf("\n1.Create the linked list.");
		printf("\n2.Display the linked list.");
		printf("\n3.Reverse the linked list.");
	    printf("\n4.EXIT");
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
            case 3: reverse(start);
                    break;
		}
	}
    while(option!=4);
    return 0;
}
struct node *creat(int n)
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
            temp->next=NULL;
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

        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void reverse(struct node* start)
{
    struct node *ptr;
    int i,j;
    if(start==NULL)
    {
        printf("\n The list is empty");
    }
    else
    {
        for(i=n;i>1;i--)
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






