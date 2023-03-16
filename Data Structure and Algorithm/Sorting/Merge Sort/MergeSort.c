#include<stdio.h>
int i,j,k;
void merge(int Arr[],int l,int mid,int r)
{

    int n1,n2;

    n1 = mid-l+1;
    n2 = r-mid;

    int A[n1],B[n2];

    for(i=0;i<n1;i++)
        A[i] = Arr[i+l];

    for(j=0;j<n2;j++)
        B[j] = Arr[mid+1+j];

    i=j=0;
    k=l;

    while(i<n1 && j<n2)
    {
        if (A[i]<B[j])
        {
            Arr[k] = A[i];
            i++;
            k++;
        }
        else
        {
            Arr[k] = B[j];
            j++;
            k++;
        }
    }

    while(i<n1)
    {
        Arr[k] = A[i];
        k++;
        i++;
    }

    while(j<n2)
    {
        Arr[k] = B[j];
        k++;
        j++;
    }
}

void mergeSort(int Arr[],int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(Arr, l, mid);
        mergeSort(Arr, mid + 1, r);
        merge(Arr, l, mid, r);
    }
}

void main()
{
    int Arr[] = {4,1,3,2,5};

    int size = sizeof(Arr)/sizeof(int);
    mergeSort(Arr,0,4);

    for(int p=0;p<5;p++)
      printf("%d\n",Arr[p]);
}
