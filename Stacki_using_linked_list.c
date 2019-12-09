#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL;
void display();
void push(int);
int pop(void);
int main()
{
	int option,num,a;
	do
	{
		printf("\n*******MAIN MENU********\n");
        printf("\n1.DISPLAY ");
		printf("\n2.PUSH");
        printf("\n3.POP");
        printf("\n4.EXIT");
		printf("\n Enter the task option: ");
		scanf("%d",&option);
		switch(option)
		{

            case 1: display();
                    break;
            case 2: printf("\n Enter the value that to be add: ");
			        scanf("%d",&num);
			        push(num);
			        break;
            case 3: a=pop();
                    break;
        }

	}
	while(option!=4);
	return 0;
}
void display()
{
    struct node *temp;
    temp=top;
    printf("\n\nstack:   ");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
struct node *getnode(void)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	return(temp);
}
void push(int num)
{
	struct node *temp;
	temp=getnode();
	temp->data=num;
	temp->next=top;
	top=temp;
}
int pop(void)
{
    int x;
    struct node *temp;
    if(top==NULL)
    {
        printf("void deletion.");
        exit(1);
    }
    temp=top;
    top=top->next;
    x=temp->data;
    free(temp);
    return(x);
}
