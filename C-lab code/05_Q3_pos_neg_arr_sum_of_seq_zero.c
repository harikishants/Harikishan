/*Write a program that takes as input an integer n, an array A of n non-zero integers (positive /
negative) and separates the positive integers from the negative ones. */

/*Write a program that takes as input an integer n, an array A of n non-zero integers (positive /
negative). It is assumed that all the negative elements of A appear before all the positive elements
of A. Your task is to find out whether there exist indices i and j (with i < j) in A such that
A[i] + A[i+1] + ... + A[j] = 0*/

#include<stdio.h>

void main()
{
   int n;
    printf("\nEnter no. of elements -> ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    /*printf("\nBefore\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }*/


    int i=0;
    int mid=0;
    while (arr[i]<0)
    {
        i++;
    }
    if (i==n-1)
    {
        //printf("\nNo mid");
    }
    else
    {
        mid=i;
        //printf("\nMid element %d",arr[mid]);
    }
    i=mid-1;
    int j=mid;
    int sum=0;
    sum=arr[i]+arr[j];
    if(sum!=0)
    {
        while ((sum!=0)&&(i>0)&&(j<n))
        {
            if(sum>0)
            {
                i--;
                sum+=arr[i];
            }
            else
            {
                j++;
                sum+=arr[j];
            };
        }
    }

    if (sum==0)
    {
        printf("\nIndex %d to %d",i,j);
    }
    else
    {
        printf("\nNo sum");
    }

}

