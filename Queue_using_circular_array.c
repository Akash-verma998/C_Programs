#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct queue
{
    int item[MAX];
    int front,rear;
};
struct queue q;
void enqueue(int);
int dequeue(void);
void display(void);
int main()
{
    int option,val;
    q.front=0;
    q.rear=0;
    while(option!=5)
    {
        printf("\n \n*****MAIN MENU*****");
        printf("\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display queue");
        printf("\n5.EXIT");
        printf("\n Enter your choice:");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("Enter the that to be add: ");
            scanf("%d",&val);
            enqueue(val);
            break;
        case 2:
            val=dequeue();
            break;

        case 3:
            display();
            break;
        }
    }
    return 0;
}
int dequeue()
{
    if(q.front==q.rear)
    {
        printf("Queue underflow");
    }
    if(q.front==MAX-1)
    {
        q.front=0;
    }
    else
        q.front++;
    return (q.item[q.front]);
}
void enqueue(int x)
{
    if(q.rear==MAX-1)
        q.rear=0;
    else
        q.rear++;
    if(q.rear==q.front)
    {
        printf("Queue overflow");
        if(q.rear==0)
           q.rear=MAX-1;
        else
           q.rear--;
           exit(1);
    }
    q.item[q.rear]=x;
    return ;
}
void display(void)
{
    int i;
    if(q.front==q.rear)
    {
        printf("Queue is empty");
        exit(1);
    }
    else
    {
        printf("QUEUE:");
        for(i=(q.front+1);i<=q.rear;i++)
        {
           printf("\t%d",q.item[i]);
        }
    }
}
