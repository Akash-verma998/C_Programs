#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;
void display();
struct node *getnode(void);
void enqueue(int);
int dequeue(void);
int main()
{
	int option,num,a;
	do
	{
		printf("\n****MAIN MENU****\n");
		printf("\n1.Display Queue");
		printf("\n2.Insert");
		printf("\n3.Delete");
		printf("\n4.EXIT");
		printf("\n Enter your choice: ");
		scanf("%d",&option);
		switch(option)
		{
            case 2: printf("\n Enter the value to be add:");
                    scanf("%d",&num);
                    enqueue(num);
                    break;
            case 3: a=dequeue();
                    break;
            case 1: display();
                    break;
		}
    }
    while(option!=4);
	return 0;
}

void display()
{
    struct node *temp;
    temp=front;
    if(rear==NULL)
	{
		printf("\n Queue is empty.");
		return;
		
	}
    printf("\n\n QUEUE:");
    while(temp!=rear)
    {

        printf(" %d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    return;
}
struct node *getnode(void)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	return(temp);
}
void enqueue(int x)
{
    struct node *temp;
    temp=getnode();
    temp->data=x;
    if(rear==NULL)
    {
        front=temp;
        rear=temp;
        rear->next=NULL;
    }
    else
    {
       rear->next=temp;
       rear=temp;
       rear->next=NULL;
    }
}
int dequeue(void)
{
    int x;
    struct node *temp;
    temp=front;
    if(rear==NULL)
    {
        printf("void deletion.");
        exit(1);
    }
    front=front->next;
    x=temp->data;
    free(temp);
    return(x);
}

