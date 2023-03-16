#include<stdio.h>

struct stack
{
    int info;
    struct stack *prev,*next;
};

typedef struct stack node;

node *p,*top,*bottom;

void push(int info)
{
    node *item;
    item = malloc(sizeof(item));

    item->info = info;
    item->prev = item->next = NULL;

    if(top==NULL && bottom==NULL)
        top = bottom = NULL;
    else
    {
        item->prev = top;
        top->next = item;
        top = item;
    }
}

void pop()
{
    p=top;
    if(!p)
        printf("\nStack Underflow");
    else
    {
        printf("Popped value = %d",top->info);
        top = top->prev;
    }
}

void traverse()
{
    p=top;
    while(p)
    {
        printf("%d ",p->info);
        p = p->prev;
    }
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
    top = bottom = NULL;
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

