#include<stdio.h>
#define size 5

struct stack
{
    int Arr[size];
    int top,bottom;
};

void push(struct stack *s,int data)
{
    if(s->top == size-1)
        printf("\nStack overflow!!");
    else
    {
        s->top++;
        s->Arr[s->top] = data;
    }
}

void pop(struct stack *s)
{
    if(s->top == -1)
        printf("\nStack underflow!!");
    else
    {
        printf("\nPopped value = %d",s->Arr[s->top]);
        s->top--;
    }
}

void traverse(struct stack *s)
{
    int i;
    if(s->top == -1)
        printf("\nStack underflow!!");
    else
        for(i=s->top;i>=s->bottom;i--)
            printf("%d",s->Arr[i]);
}

void ui()
{
    printf("\n1) Push");
    printf("\n2) Pop");
    printf("\n3) Traverse");
    printf("\n4) exit\n");
}

void main()
{
   struct stack s;
   s.top = -1;
   s.bottom = 0;

   int x,data;
   ui();

   while(1)
   {
       printf("\nEnter choice : ");
       scanf("%d",&x);

       switch(x)
       {
           case 1: printf("Enter data to push into stack : ");
                   scanf("%d",&data);
                   push(&s,data);
           break;
           case 2: pop(&s);
           break;
           case 3: traverse(&s);
           break;
           case 4: exit(1);
           break;
           default: printf("\nEnter valid choice!!");
           break;
       }
   }
}
