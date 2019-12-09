#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *start=NULL;
void insert_element(int,int);
struct node *create_node(void);
int del_element(void);
void display(void);
int main()
{
    int option,val,pri;
    do
    {
        printf("\n\n******MAIN MENU********");
        printf("\n1.INSERT ELEMENT");
        printf("\n2.DELETE ELEMENT");
        printf("\n3.DISPLAY QUEUE");
        printf("\n4.EXIT");
        printf("\n Enter your choice:");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("Enter the value and priority:");
            scanf("%d%d",&val,&pri);
            insert_element(val,pri);
            break;
        case 2:
            val=del_element();
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
void insert_element(int x,int p)
{
    struct node *temp,*ptr;
    temp=create_node();
    temp->data=x;
    temp->priority=p;
    if(start==NULL||p<start->priority)
    {
        temp->next=start;
        start=temp;
    }
    else
    {
        ptr=start;
        while((ptr->next!=NULL)&&(ptr->next->priority<=p))
            ptr=ptr->next;
        temp->next=ptr->next;
        ptr->next=temp;
    }
    return;
}
int del_element(void)
{
    struct node *temp;
    if(start==NULL)
    {
        printf("void deletion");
        return;
    }
    else
    {
        temp=start;
        start=start->next;
        free(temp);
    }
    return(temp->data);
}
void display(void)
{
    struct node *temp;
    temp=start;
    if(start==NULL)
    {
        printf("\n Queue is empty.");
    }
    else
    {
        printf("Priority queue is:");
        while(temp!=NULL)
        {
            printf("\t[%d][priority=%d]",temp->data,temp->priority);
            temp=temp->next;
        }
    }
}
