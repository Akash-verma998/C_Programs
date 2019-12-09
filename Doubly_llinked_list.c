#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    struct node *next;
    int data;
    struct node *prev;
};
struct node *start=NULL;
struct node *creat(int);
void display(struct node*);
int main()
{
	int n,option;
	do
	{
		printf("\n*******MAIN MENU********\n");
		printf("\n1.Create the linked list.");
		printf("\n2.Display the linked list.");
		printf("\9.EXIT");
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
		}
	}
	while(option!=3);
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
        temp->prev=NULL;
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
            temp->prev=ptr;
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
    printf("NULL<-->");
    while(temp!=NULL)
    {

        printf("%d<-->",temp->data);
        temp=temp->next;
    }
    printf("start\n\n");
}
