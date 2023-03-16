#include<stdio.h>
#define size 5

int Arr[5],rear=-1,front=0;

void enqueue(int data)
{
    if(rear == size-1)
        printf("\nQueue overflow!!!");
    else
    {
        rear++;
        Arr[rear] = data;
    }
}

void dequeue()
{
    if(front > rear)
        printf("\nQueue underflow");
    else
    {
        printf("\nDequeued value = %d",Arr[front]);
        front++;
    }
}

void traverse()
{
    int i;
    if(front > rear)
        printf("\nQueue underflow!!");
    else
        for(i=front;i<=rear;i++)
         printf("%d",Arr[i]);
}

void ui()
{
    printf("\n1) Enqueue");
    printf("\n2) Dequeue");
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
           case 1: printf("Enter data to enqueue : ");
                   scanf("%d",&data);
                   enqueue(data);
           break;
           case 2: dequeue();
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
