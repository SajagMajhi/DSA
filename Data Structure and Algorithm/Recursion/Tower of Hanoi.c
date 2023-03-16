#include<stdio.h>

void transfer(int n,char A,char B,char C)
{
    if(n>0)
    {
        transfer(n-1,A,C,B);
        printf("\nDisk %d moved from %c to %c ",n,A,C);
        transfer(n-1,B,A,C);
    }
}

void main()
{
    char A,B,C;
    int n;
    n = 4;

    transfer(n,'A','B','C');
}


