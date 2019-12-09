                                                                                                                                                                                                                                                                                                                                       #include<stdio.h>
#include<ctype.h>
#include<math.h>
#define MAX 100
struct stack
{
	int top;
	float item[MAX];	
};
struct stack opndstack;
void push(float val);
float pop();
float evaluatepostfixexp(char exp[]);
int main()
{
   opndstack.top=-1;
   float val;
   char exp[100];
   printf("\n Enter any postfix expression: ");
   gets(exp);
   val=evaluatepostfixexp(exp);
   printf("\n The value of the post fix exp: %.2f",val);
   return 0;
}
float evaluatepostfixexp(char exp[])
{
    int i=0;
    float op1,op2,value;
    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
            push((float)(exp[i]-'0'));

        else
        {
        op2=pop();
        op1=pop();
        switch(exp[i])
        {
            case '+':
                value=op1+op2;
                break;
            case '-':
                value=op1-op2;
                break;
            case '/':
                value=op1/op2;
                break;
            case '*':
                value=op1*op2;
                break;
            case '%':
                value=(int)op1%(int)op2;
                break;
            case '^':
			    value=(pow(op1,op2));    
                break;
            default:
			 printf("illegal operation"); 
			 exit(1);   
        }
        push(value);
    }
    i++;
  }
  return(pop());
}
void push(float val)
{
    if(opndstack.top==(MAX-1))
    {
        printf("\n STACK IS OVERFLOW");
        exit(1);
    }
    else
    {
        opndstack.top++;
        opndstack.item[opndstack.top]=val;
    }
}
float pop()
{
	float val;
    if(opndstack.top==-1)
    {
        printf("\n STACK UNDERFLOW");
        exit(1);
    }
    else
    {
        val=opndstack.item[opndstack.top];
        opndstack.top--;
    }
    return val;
}
