#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct stack
{
	int top;
	int item[MAX];
};
struct stack s;
void push(int);
int pop();
int peek();
void display();
int main()
{
	s.top=-1;
    int val,option;
    do
    {
        printf("\n*****MENU*******\n");
        printf("\n 1.PUSH");
        printf("\n 2.POP");
        printf("\n 3.PEEK");
        printf("\n 4.DISPLAY");
        printf("\n 5.EXIT");
        printf("\n Enter your option :   ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("enter the to be pushed on stack: ");
            scanf("%d",&val);
            push(val);
            break;
        case 2:
            val=pop();
            if(val!=-1)
            {
                printf("\n The value deleted from the stack is: %d ",val);
            }
            break;
        case 3:
            val=peek();
            if(val!=-1)
            {
                printf("\n The value stored at the top of the stack is : %d",val);
            }
            break;
        case 4:
            display();
            break;
        }
    }
    while(option!=5);
}
void push(int val)
{
    if(s.top==(MAX-1))
    {
        printf("\n Stack Overflow");
    }
    else
    {
        s.top++;
        s.item[s.top]=val;
    }
}
int pop(int st[])
{
    int val;
    if(s.top==-1)
    {
        printf("\n Stack underflow");
        return -1;
    }
    else
    {
       val=s.item[s.top];
       s.top--;
       return val;
    }
}
void display()
{
    int i;
    if(s.top==-1)
    {
        printf("\nStack is empty");
    }
    else
    {
    	printf("\nSTACK:");
        for(i=s.top;i>=0;i--)
        {
            printf("\t%d",s.item[i]);
        }
    }
}
int peek()
{
    if(s.top==-1)
    {
        printf("\n Stack is empty");
        return -1;
    }
    else
        return(s.item[s.top]);
}

