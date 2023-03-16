#include<stdio.h>

struct list
{
    int info;
    struct list *next;
};

typedef struct list node;

node *temp,*start,*p;

void back_insert(int info)
{
    node *item;
    item = malloc(sizeof(item));

    item->next = NULL;
    item->info = info;

    if(start == NULL)
    {
        start = temp = item;
        temp->next = NULL;
    }
    else
    {
        temp->next = item;
        temp = item;
    }
}

void front_insert(int info)
{
    node *item;
    item = malloc(sizeof(item));

    item->next = NULL;
    item->info = info;

    if(start == NULL)
    {
        start = temp = item;
        start->next = NULL;
    }
    else
    {
        item->next = start;
        start = item;
    }
}

void specific_insert(int pos,int info)
{
    node *ptr,*item;
    int count = 0;

    item = malloc(sizeof(item));
    item->info = info;
    item->next = NULL;

    if(start == NULL)
        printf("\nList is empty");
    else if(pos == 0)
    {
       item->next = start;
       start = item;
    }
    else
    {
        p = start;
        while(count != (pos-1))
        {
            count++;
            p = p->next;
        }
        ptr = p->next;
        p->next = item;
        item->next = ptr;
    }
}

void back_delete()
{
    node *ptr;

    if(start == NULL)
        printf("\nList empty");
    else if(start->next == NULL)
    {
        printf("\nDeleted item = %d",start->info);
        start = NULL;
    }
    else
    {
      p = start;
      while(p->next != temp)
      {
        p = p->next;
      }
      ptr = temp;
      printf("\nDeleted item = %d",temp->info);
      free(ptr);
      temp = p;
      temp->next = NULL;
    }
}

void front_delete()
{
    node *ptr;

    if(start == NULL)
        printf("\nList empty");
    else if(start->next == NULL)
    {
        printf("\nDeleted item = %d",start->info);
        start = NULL;
    }
    else
    {
      ptr = start;
      printf("\nDeleted item = %d",ptr->info);
      start = start->next;
      free(ptr);
    }
}

void specific_delete(int pos)
{
    node *ptr;
    int count = 0;

    if(start == NULL)
      return;
    else if(pos == 0)
    {
        ptr = start;
        start = start->next;
        printf("\nDeleted item = %d\n",ptr->info);
        free(ptr);
    }
    else
    {
        p = start;
        while(count != (pos-1))
        {
            count++;
            p = p->next;
        }
        ptr = p->next;
        printf("\nDeleted item = %d\n",ptr->info);
        p->next = (p->next)->next;
        free(ptr);
    }
}

void traverse()
{
    p = start;

    if(start == NULL)
        printf("\nList empty");
    else
    {
     while(p != 0)
     {
        printf("%d ",p->info);
        p = p->next;
     }
      printf("\n");
    }
}

void ui()
{
    printf("\n1) Back add");
    printf("\n2) Front add");
    printf("\n3) Specific pos add");
    printf("\n4) traverse");
    printf("\n5) Front delete");
    printf("\n6) Back delete");
    printf("\n7) Specific pos delete");
    printf("\n8) exit\n");
}

void main()
{
    node l;
    int x,data,val;
    start = NULL;

    ui();

    while(1)
    {
       printf("\nEnter choice : ");
       scanf("%d",&x);

       switch(x)
       {
           case 1: printf("Enter data to add to list from front : ");
                   scanf("%d",&data);
                   front_insert(data);
           break;
           case 2: printf("Enter data to add to list from back : ");
                   scanf("%d",&data);
                   back_insert(data);
           break;
           case 3: printf("Enter data to add at specific node : ");
                   scanf("%d",&data);
                   printf("Enter specific pos : ");
                   scanf("%d",&val);
                   specific_insert(val,data);
           break;
           case 4: traverse();
           break;
           case 5: front_delete();
           break;
           case 6: back_delete();
           break;
           case 7:if(start == NULL)
                    printf("\nList empty");
                    else
                    {
                     printf("Enter specific pos to delete node : ");
                     scanf("%d",&val);
                     specific_delete(val);
                    }
           break;
           case 8: exit(1);
           break;
           default: printf("Enter valid choice!!");
           break;
       }
    }
}
