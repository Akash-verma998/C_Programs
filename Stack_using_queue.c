#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void push(int);
struct node *create_node(void);
int pop(void);
void display(void);
int main()
{
    int option,val;
    do
    {
        system("cls");
        printf("\n\n******MAIN MENU********");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.display");
        printf("\n4.exit");
        printf("\n Enter your choice:");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("Enter the value :");
            scanf("%d",&val);
            push(val);
            break;
        case 2:
            val=pop();
            break;
        case 3:
            display();
            break;
        }
    }
    while(option!=4);
    return 0;
}
struct node *create_node(void)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    return(temp);
}
void push(int x)
{
    struct node *temp;
    temp=create_node();
    temp->data=x;
    if(front==NULL)
    {
        temp->next=front;
        front=temp;
    }
    else
    {
        temp->next=front;
        front=temp;
        rear=temp;
    }
    printf("stack created....");
    getch();
    return;
}
int pop(void)
{
    struct node *temp;
    if(front==NULL)
    {
        printf("void deletion");
        return;
    }
    else
    {
        temp=front;
        front=front->next;
        rear=front;
        free(temp);
    }
    printf("value deleted...");
    getch();
    return(temp->data);
}
void display(void)
{
    struct node *temp;
    temp=front;
    if(front==NULL)
    {
        printf("\n Queue is empty.");
    }
    else
    {
        printf("Queue:");
        while(temp!=NULL)
        {
            printf("\t[%d]",temp->data);
            temp=temp->next;
        }
    }
    getch();
}
