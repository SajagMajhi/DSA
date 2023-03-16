#include<stdio.h>

int i,j,k;

void insertion_sort(int Arr[],int size)
{
   int key;
   for(i=1;i<size;i++)
   {
     key = Arr[i];
     j=i-1;
     while(key<Arr[j] && j>=0)
     {
	   if(key < Arr[j])
	   {
	    Arr[j+1] = Arr[j];
	    j--;
       }
     }
	Arr[j+1] = key;
   }
}

void swap(int *x,int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void selection_sort(int Arr[],int size)
{
   int min_pos;
   for(i=0;i<size;i++)
   {
      min_pos = i;
     for(j=i+1;j<size;j++)
     {
	if(Arr[min_pos]>Arr[j])
	  min_pos = j;
     }
	swap(&Arr[min_pos],&Arr[i]);
   }
}

void merge(int Arr[],int l,int mid,int r)
{
   int n1,n2;

   n1 = mid-l+1;
   n2 = r-mid;

   int A[n1],B[n2];

   for(i=0;i<n1;i++)
      A[i] = Arr[l+i];

   for(j=0;j<n2;j++)
      B[j] = Arr[mid+1+j];

   i=j=0;
   k=l;
   while(i<n1 && j<n2)
   {
     if(A[i]<B[j])
     {
       Arr[k] = A[i];
       i++;
     }
     else
     {
       Arr[k] = B[j];
       j++;
     }
       k++;
   }

    while(i<n1)
    {
      Arr[k] = A[i];
      i++; k++;
    }

    while(j<n2)
    {
      Arr[k] = B[j];
      j++; k++;
    }
}

void merge_sort(int Arr[],int l,int r)
{
    int mid;
    if(l<r)
    {
        mid = l + (r-l)/2;
        merge_sort(Arr,l,mid);
        merge_sort(Arr,mid+1,r);
        merge(Arr,l,mid,r);
    }
}

void display(int Arr[],int size)
{
  for(i=0;i<size;i++)
    printf("%d",Arr[i]);

    printf("\n");
}


void main()
{
   int Arr1[] = {4,1,5,3,2};
   int Arr2[] = {4,1,5,3,2};
   int Arr3[] = {4,1,5,3,2};

   int size1 = sizeof(Arr1)/sizeof(int);
   int size2 = sizeof(Arr2)/sizeof(int);
   int size3 = sizeof(Arr3)/sizeof(int);

   insertion_sort(Arr1,size1);
   selection_sort(Arr2,size2);
   merge_sort(Arr3,0,size3-1);

   display(Arr1,size1);
   display(Arr2,size2);
   display(Arr3,size3);
}

