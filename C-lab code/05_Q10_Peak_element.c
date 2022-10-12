/*Write a program that takes as input an integer n, an array A of n integers and prints the index of
any one of its peak elements. An element is called a peak element if its value is not smaller than
the value of its adjacent elements (if they exist).*/

#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    int a[n],start=0,end=n-1,mid;
    //a=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    /*for(int i=1;i<n;i++)
    {
        if((a[i]>a[i-1])&&(a[i]>a[i+1]))
        {
           printf("\nPeak element is %d",a[i]);
           break;
        }*/
    if(n<=2)
    {
        if(a[0]>a[1])
        {
            printf("\nPeak element is %d",a[0]);
        }
        else
        {
            printf("\nPeak element is %d",a[1]);
        }
        exit(1);
    }
    while(start<end)
    {
        mid=start+(end-start)/2;
        if((a[mid]>a[mid-1])&&(a[mid]>a[mid+1]))
        {
          printf("\nPeak element is %d",a[mid]);
          break;
        }
        if(a[mid]<a[mid+1])
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }

    }

    if(start==end)
    {
        printf("\nPeak element is %d",a[end]);
        exit(1);
    }
    else if (start==0)
    {
        printf("\nNo peak element");
    }



}

