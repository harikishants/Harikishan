/*

Write a program that takes as input an integer n, an array A of n integers in the range 0 to n-1,
two integers p and q and returns an s-t common index stroll point on the array A. Consider the
two strolls starting from s and t. You are required to find out whether the strolls share a common
index. If not, print that and return. If there is a common index r, the function should print the walk
from s to r and the walk from t to r. The index r should be so chosen that the two walks printed
must not have any common index except the last one (r).
n = 60
The array A is:
33 33 56 35 14 9 53 31 44 23
13 9 35 58 50 22 31 27 40 52
21 35 15 29 8 17 31 54 38 3
32 12 36 20 47 43 30 32 14 14
56 20 16 23 18 6 45 50 33 17
34 46 45 41 15 53 58 38 48 37
s = 5
t = 8
+++ Path from Cell 5:
5 9 23
+++ Path from Cell 8:
8 44 18 40 56 58 48 33 20 21 35 43 23

*/

#include<stdio.h>

void main()
{
int n,*A,*seq_s,*seq_t,seq_len_s,seq_len_t,s,t,r_s,r_t,i,j,check,check_r,cyclic_start_index_s,cyclic_start_index_t;
    printf("Enter no. of elements = ");
    scanf("%d",&n);
    A=(int *)malloc(n*sizeof(int));
    seq_s=(int *)malloc(n*sizeof(int));
    seq_t=(int *)malloc(n*sizeof(int));
    printf("\nEnter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    printf("\nEnter s = ");
    scanf("%d",&s);
    seq_s[0]=s;
    seq_len_s=1;
    check=0;
    while (check!=1)
    {
        s=A[s];
        for(i=0;i<seq_len_s;i++)
        {
            if (s==seq_s[i])
            {
                check=1;
                cyclic_start_index_s=i;
                break;
            }
        }
        if(check!=1)
        {
            seq_s[seq_len_s]=s;
            seq_len_s++;
        }
    }
    printf("\nStroll is");
    for(i=0;i<cyclic_start_index_s;i++)
    {
        printf(" %d",seq_s[i]);
    }
    printf("\nLength = %d",cyclic_start_index_s);
    printf("\nCyclic part is");
    for(i=cyclic_start_index_s;i<seq_len_s;i++)
    {
        printf(" %d",seq_s[i]);
    }
    printf("\nLength = %d",seq_len_s - cyclic_start_index_s);

//t
    printf("\nEnter t = ");
    scanf("%d",&t);
    check=0;
    seq_t[0]=t;
    seq_len_t=1;
    while (check!=1)
    {
        t=A[t];
        for(i=0;i<seq_len_t;i++)
        {
            if (t==seq_t[i])
            {
                check=1;
                cyclic_start_index_t=i;
                break;
            }
        }
        if(check!=1)
        {
            seq_t[seq_len_t]=t;
            seq_len_t++;
        }
    }
    printf("\nStroll is");
    for(i=0;i<cyclic_start_index_t;i++)
    {
        printf(" %d",seq_t[i]);
    }
    printf("\nLength = %d",cyclic_start_index_t);
    printf("\nCyclic part is");
    for(i=cyclic_start_index_t;i<seq_len_t;i++)
    {
        printf(" %d",seq_t[i]);
    }
    printf("\nLength = %d",seq_len_t - cyclic_start_index_t);

//check common index in strolls
    check_r=0;
    for(i=0;(i<seq_len_s)&&(check_r!=1);i++)
    {
        for(j=0;j<seq_len_t;j++)
        {
            if (seq_s[i]==seq_t[j])
            {
                r_s=i;
                r_t=j;
                check_r=1;
                break;
            }
        }
        if (seq_s[i]==seq_t[j])
            {break;}
    }
if (check_r==1)
{
    printf("\nCommon element 'r' is %d",seq_s[i]);
    printf("\nStroll s upto r is ");
    for(i=0;i<=r_s;i++)
    {
        printf(" %d",seq_s[i]);
    }

    printf("\nStroll t upto r is ");
    for(i=0;i<=r_t;i++)
    {
        printf(" %d",seq_t[i]);
    }
}
else
{
    printf("\nNo common stroll element");
}





}


