#include<stdio.h>
#include<string.h>
int st[10];
int top=-1;
int pop();
void push(int);
int get_type(char);
int main()
{
   char prefix[10];
   int len,val,i,op1,op2,res;
   printf("\n Enter the prefix expression  : ");
   gets(prefix);
   len=strlen(prefix);
   for(i=len-1;i>=0;i--)
   {
       switch(get_type(prefix[i]))
       {
       case 0:
        val=prefix[i]-'0';
        push(val);
        break;
       case 1:
           op1=pop();
           op2=pop();
           switch(prefix[i])
           {
           case '+':
            res=op1+op2;
            break;
           case '-':
            res=op1-op2;
            break;
           case '*':
            res=op1*op2;
            break;
           case '/':
            res=op1/op2;
            break;
           }
           push(res);
       }
   }
   printf("result=%d",st[0]);
   return 0;
}
void push(int val)
{
    st[++top]=val;
}
int pop()
{
    return(st[top--]);
}
int get_type(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
        return 1;
    else return 0;

}
