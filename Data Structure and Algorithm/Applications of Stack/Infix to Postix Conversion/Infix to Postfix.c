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

void traverse(struct stack *s)
{
    int i;
    if(s->top == -1)
      printf("\nStack underflow!!");
    else
        for(i=s->bottom;i<=s->top;i++)
            printf("%c",s->Arr[i]);
}

int precedence(char ch)
{
    if(ch=='(' || ch=='{' || ch=='[')
        return 0;
    else if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='*' || ch=='/')
        return 2;
}

void append(struct stack *s,struct stack *p,char ch)
{
    char var;
    if(precedence(s->Arr[s->top]) < precedence(ch))
      push(s,ch);
    else
    {
     while(precedence(s->Arr[s->top]) >= precedence(ch))
     {
        var = pop(s);
        push(p,var);
     }
      push(s,ch);
    }
}

void main()
{
   struct stack s;
   struct stack Postfix;

   Postfix.top = s.top = -1;
   Postfix.bottom = s.bottom = 0;

   int i;
   char k;
   char Scan[]="(A+B*C-D/E)";
   char Postfix_str[50];



   for(i=0;i<sizeof(Scan)-1;i++)
   {
      if(Scan[i]=='{' || Scan[i]=='[' || Scan[i]=='(')
        push(&s,Scan[i]);
      else if(Scan[i]=='-' || Scan[i]=='+' || Scan[i]=='/' || Scan[i]=='*')
        append(&s,&Postfix,Scan[i]);
      else if(Scan[i]=='}' || Scan[i]==']' || Scan[i]==')')
        while(s.Arr[s.top]!='(')
        {
         k = pop(&s);
         push(&Postfix,k);
        }
      else
         push(&Postfix,Scan[i]);
   }

   traverse(&Postfix);
   /*
   printf("\n");
   traverse(&s);*/
}
