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

    printf("\nBefore\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    int i,j=n-1,temp;
    for(i=0;i<n;i++)
    {
      while((arr[i]>0)&&(i<j))
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            j--;
        }
    }

    printf("\nAfter\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}
