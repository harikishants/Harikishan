/*Write a program that takes in an array A of n digits (0 to 9) and prints the largest multiple of 3 that
can be formed from the array elements. If the input array is {8, 1, 9}, the output should be 981,
and if the input array is {8, 1, 7, 6, 0}, output should be 8760*/

#include<stdio.h>

void main()
{
    int n,*arr,i,j,temp;
    scanf("%d",&n);
    arr = (int *)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    //Insertion sort
    for(i=1;i<n;i++)
    {
      j=i;
      temp=arr[i];
      while((temp>arr[j-1])&&(j>0))
      {
        arr[j]=arr[j-1];
        j--;
      }
      arr[j]=temp;

    }

    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }

    int sum=0,min1=n,min2=n,min1_index,min2_index;
    for(i=0;i<n;i++)
    {
        sum += arr[i];
    }

    if(sum%3==0)
    {
        printf("\nLargest number divisible by 3 is");
        for(i=0;i<n;i++)
        {
            printf(" %d",arr[i]);
        }
        exit(1);
    }
    //if (sum%3==1)
    //{
      for(i=0;i<n;i++)
        {
        if (arr[i]%3==1)
            {
            if(arr[i]<min1)
            {
                min1=arr[i];
                min1_index=i;
            }
            }
        }
    //}
    //if (sum%3==2)
    //{
      for(i=0;i<n;i++)
        {
        if (arr[i]%3==2)
        {
            if(arr[i]<min2)
            {
                min2=arr[i];
                min2_index=i;
            }
        }
        }
    //}
    if((arr[min1_index]<n)&&(sum%3==1))
    {
       for(i=min1_index;i<n-1;i++)
       {
           arr[i]=arr[i+1];
       }
       arr[n-1]='\0';
    }
    else if ((arr[min2_index]<n)&&(sum%3==2))
    {
        for(i=min2_index;i<n-1;i++)
       {
           arr[i]=arr[i+1];
       }
       arr[n-1]='\0';
    }

    printf("\nSum %d\nmin1 %d\nmin2 %d",sum,arr[min1_index],arr[min2_index]);

    printf("\nLargest number divisible by 3 after removing is");
    for(i=0;i<n;i++)
    {
        printf(" %d",arr[i]);
    }



}
