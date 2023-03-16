#include<stdio.h>

void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void main()
{
    int Arr[] = {2,5,1,4,3};
    int j,i,size=0,pos;

    size = sizeof(Arr)/sizeof(int);

    for(j=0;j<size-1;j++)
    {
     pos = j;
     for(i=j+1;i<size;i++)
     {
        if(Arr[pos] > Arr[i])
        {
            swap(&Arr[pos],&Arr[i]);
        }
     }
    }

    for(j=0;j<size;j++)
     printf("%d",Arr[j]);
}
