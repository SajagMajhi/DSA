#include<stdio.h>

void main()
{
    int Arr[] = {1,5,4,3,2};
    int i,j,size,key;

    size = sizeof(Arr)/sizeof(int );

    for(i=1;i<size;i++)
    {
        key = Arr[i];
        j = i-1;

        while(j>=0 && key < Arr[j])
        {
            Arr[j+1] = Arr[j];
            j--;
        }
        Arr[j+1] = key;
    }

     for(j=0;j<size;j++)
      printf("%d",Arr[j]);
}
