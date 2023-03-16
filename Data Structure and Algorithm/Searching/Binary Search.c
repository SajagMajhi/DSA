#include<stdio.h>

int i,j;
void insertion_sort(int Arr[],int size)
{
    int key;
    for(i=1;i<size;i++)
    {
        key = Arr[i];
        j = i - 1;
        while(key<Arr[j] && j>=0)
        {
            Arr[j+1] = Arr[j];
            j--;
        }
            Arr[j+1] = key;
    }
}

int BinarySearch(int Arr[],int size,int data)
{
    int mid,l,r;

    l=0;
    r=size-1;

    while(l <= r)
    {
      mid = l+(r-l)/2;
      if(data == Arr[mid])
        return mid;
      else if(data < Arr[mid])
        r = mid-1;
      else
        l = mid+1;
    }

    return -1;
}

void main()
{
    int Arr[] = {4,1,3,2,5};
    int size = sizeof(Arr)/sizeof(int);
    int data = 3;

    insertion_sort(Arr,size);

    if(BinarySearch(Arr,size,data) == -1)
        printf("\nData not found");
    else
        printf("\nData found at position = %d",BinarySearch(Arr,size,data));

}
