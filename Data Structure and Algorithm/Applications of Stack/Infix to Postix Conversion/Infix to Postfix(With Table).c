#include<stdio.h>
#include<windows.h>
#define size 50

COORD coord= {0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

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
    else if(ch=='^' || ch=='$')
        return 3;
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
   //char Scan[]="(A+B*C-D/E)";
   char Scan[]="(a^b*c-d-e-f/e/(g-h))";
   char Postfix_str[50];


   gotoxy(0,0);printf("SN \t Scan Character \t Postfix String \t Stack");
   for(i=0;i<sizeof(Scan);i++)
   {
      if(Scan[i]=='{' || Scan[i]=='[' || Scan[i]=='(')
        push(&s,Scan[i]);
      else if(Scan[i]=='-' || Scan[i]=='+' || Scan[i]=='/' || Scan[i]=='*' || Scan[i]=='^' || Scan[i]=='$')
        append(&s,&Postfix,Scan[i]);
      else if(Scan[i]=='}' || Scan[i]==']' || Scan[i]==')')
      {
        while(s.Arr[s.top]!='(')
        {
         k = pop(&s);
         if(k=='(')
         {

         }
         else
          push(&Postfix,k);
        }
        if(s.Arr[s.top]=='(')
            pop(&s);
      }
      else
        push(&Postfix,Scan[i]);

      gotoxy(35,i+1);traverse(&Postfix);
      gotoxy(60,i+1);traverse(&s);
      gotoxy(0,i+1);printf("%d \t\t %c",i+1,Scan[i]);
   }
}
