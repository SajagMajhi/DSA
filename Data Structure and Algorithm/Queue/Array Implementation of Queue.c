#include<stdio.h>
#define size 5

struct queue
{
    int Arr[size];
    int front,rear;
};

void enqueue(struct queue *q,int data)
{
    if(q->rear == size-1)
        printf("\nQueue overflow!!");
    else
    {
        q->rear++;
        q->Arr[q->rear] = data;
    }
}

void dequeue(struct queue *q)
{
    if(q->front > q->rear)
        printf("\nQueue underflow!!");
    else
    {
        printf("\nDequeued data = %d",q->Arr[q->front]);
        q->front++;
    }
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
   struct queue q;
   q.front = 0;
   q.rear = -1;

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
                   enqueue(&q,data);
           break;
           case 2: dequeue(&q);
           break;
           case 3: traverse(&q);
           break;
           case 4: exit(1);
           break;
           default: printf("\nEnter valid choice!!");
           break;
       }
   }
}

