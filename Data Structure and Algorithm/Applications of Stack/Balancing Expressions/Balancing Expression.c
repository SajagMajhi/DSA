#include<stdio.h>
#define size 50

struct stack
{
    char Arr[size];
    int top,bottom;
};

void push(struct stack *s,char data)
{
    if(s->top == size-1)
        printf("\nStack overflow!!");
    else
    {
        s->top++;
        s->Arr[s->top] = data;
    }
}

int pop(struct stack *s)
{
    char ch;
    if(s->top == -1)
      return 0;
    else
    {
        ch = s->Arr[s->top];
        s->top--;
        return ch;
    }
}

void main()
{
   struct stack s;
   s.top = -1;
   s.bottom = 0;

   int i;
   char k;
   char Scan[]="{x+(y-[a+b])*c-[(d+2)]}";


   for(i=0;i<sizeof(Scan)-1;i++)
   {
       if(Scan[i]=='{' || Scan[i]=='[' || Scan[i]=='(')
        push(&s,Scan[i]);
       else if(Scan[i]=='}' || Scan[i]==']' || Scan[i]==')')
       {
         k = pop(&s);
         if(k == 0)
         {
             printf("\nExpression is not balanced");
             exit(1);
         }
       }
   }

   if(s.top == -1)
    printf("\nExpression is balanced");
   else
    printf("\nExpression is not balanced");
}
