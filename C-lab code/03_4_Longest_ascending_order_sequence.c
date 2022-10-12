/*
Given an array of at most 100 integers, print the longest sequence
of consecutive elements that appear in ascending order
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char arr[100],start,end;
    scanf("%s",arr);
    int l=strlen(arr);
    int j;
    int max_len=1,cur_len;
    for(int i=0;i<l;i++)
    {
        j=i;
        cur_len = 1;
        while (arr[j]<arr[j+1])
        {
            j++;
            cur_len++;
            //printf("\nCurrent length is %d",cur_len);

        }

        if (cur_len>max_len)
        {
            max_len = cur_len;
            start = i;
            end = j;
            i=j;
            //printf("\nInside if %d",j);

        }
    }

    //printf("\nstart=%d and end=%d\n",start,end);

    for(int i=start;i<=end;i++)
    {
        printf("%c",arr[i]);
    }
    return 0;


}
