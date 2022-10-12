/*
Consider 2 sequences of integers, A and B, stored in arrays.
(a) Write a program to find the number of (possibly overlapping)
occurrences of the sequence B in A.
(b) Write a program to find whether the multisets corresponding to A and
B are equal.
*/

#include<stdio.h>
int ac[26],bc[26];
void main()
{
    char a[100],b[100];
    gets(a);
    gets(b);
    int la=strlen(a);
    int lb=strlen(b);
    int count = 0,occ=0;
    int i,j,k=0;
    for(i=0;i<la;i++)
    {
        k=i;
        for(j=0;j<lb;j++)
        {
            if(b[j]==a[k])
            {
                k++;
            }
            else
            {
                break;
            }
        }
        if((k-i)==lb)
        {
            count++;
        }
    }
    printf("\nCount is %d\n",count);

    for(i=0;i<la;i++)
    {
        ac[a[i]-97]++;
    }

    for(i=0;i<lb;i++)
    {
        bc[b[i]-97]++;
    }

    for(i=0;i<26;i++)
    {
        if(ac[i]!=bc[i])
        {
            printf("\nNot a multiset");
            break;
        }
        //printf("%c->%d ",i+97,bc[i]);
        //printf("%c->%d ",i+97,bc[i]);
    }
    if(i==26)
    {
       printf("\n It is multiset");
    }

}
