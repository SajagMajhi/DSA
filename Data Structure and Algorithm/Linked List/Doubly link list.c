#include<stdio.h>

struct list
{
    int info;
    struct list *prev,*next;
};

typedef struct list node;

node *start,*end,*p;

void back_insert(int info)
{
    node *item;
    item = malloc(sizeof(item));

    item->info = info;
    item->next = item->prev = NULL;

    if(start == NULL)
        start = end = item;
    else
    {
      item->prev = end;
      end->next = item;
      end = item;
    }
}

void front_insert(int info)
{
    node *item;
    item = malloc(sizeof(item));

    item->info = info;
    item->prev = item->next = NULL;

    if(start == NULL)
        start = end = item;
    else
    {
        item->next = start;
        start->prev = item;
        start = item;
    }
}

void specific_insert(int pos, int info)
{
    node *item;
    item = malloc(sizeof(item));

    int count = 0;

    item->info = info;
    item->prev = item->next = NULL;

    p = start;

    while(count != pos)
    {
        p=p->next;
        count++;
    }
    (p->prev)->next = item;
    item->prev = (p->prev);
    item->next = p;
    p->prev = item;
}

void back_delete()
{
    node *ptr;

    if(start == NULL)
        printf("\List empty");
    else if(start->next == NULL)
    {
        ptr = start;
        printf("\nDeleted item = %d\n",ptr->info);
        start = NULL;
        free(ptr);
    }
    else
    {
        ptr = end;
        printf("\nDeleted item = %d\n",ptr->info);
        end = ptr->prev;
        end->next = NULL;
        free(ptr);
    }
}

void front_delete()
{
    node *ptr;
    if(start == NULL)
        printf("\nList empty");
    else if(start->next == NULL)
    {
        ptr = start;
        printf("\nDeleted item = %d\n",ptr->info);
        start = NULL;
        free(ptr);
    }
    else
    {
        ptr = start;
        printf("\nDeleted item = %d\n",ptr->info);
        start = start->next;
        start->prev = NULL;
        free(ptr);
    }
}

void specific_delete(int pos)
{
    node *ptr;
    int count = 0;
    p = start;

    if(start == NULL)
        printf("\nList empty");
    else
    {
     while(count != pos)
     {
       p=p->next;
       count++;
     }
       ptr = p;
       printf("\nDeleted item = %d\n",ptr->info);
      (p->prev)->next = p->next;
      (p->next)->prev = p->prev;
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
     while(p)
     {
        printf("%d ",p->info);
        p = p->next;
     }
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
