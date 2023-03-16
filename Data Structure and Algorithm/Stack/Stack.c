#include<stdio.h>
#define size 5

int Arr[size],top=-1,bottom=0;

void push(int data)
{
    if(top == size-1)
        printf("\nStack overflow!!");
    else
    {
        top++;
        Arr[top] = data;
    }
}

void pop()
{
    if(top == -1)
        printf("\nStack underflow!!");
    else
    {
        printf("\nPopped value = %d",Arr[top]);
        top--;
    }
}

void traverse()
{
    int i;
    if(top == -1)
        printf("\nStack underflow!!");
    else
     for(i=top;i>=bottom;i--)
        printf("%d",Arr[i]);
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
                   push(data);
           break;
           case 2: pop();
           break;
           case 3: traverse();
           break;
           case 4: exit(1);
           break;
           default: printf("\nEnter valid choice!!");
           break;
       }
   }
}
