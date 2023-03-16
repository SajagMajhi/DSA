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

void traverse(struct stack *s)
{
    int i;
    if(s->top == -1)
        printf("\nStack underflow!!");
    else
        for(i=s->top;i>=s->bottom;i--)
            printf("%c",s->Arr[i]);
}

void main()
{
   struct stack s;
   s.top = -1;
   s.bottom = 0;

   int i;
   char Scan[]="Sajag Majhi";

   for(i=0;i<sizeof(Scan)-1;i++)
        push(&s,Scan[i]);

    traverse(&s);
}
