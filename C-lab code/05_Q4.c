/*4. Write a program that takes as input an integer n, an array A of n integers in the range 0 to n-1, an
integer p and returns a stroll starting from index p on the array A. A stroll on the array A is defined
in the following way. You start from some index i in the range 0 to n – 1. You then visit the cells
A[i], A[A[i]], A[A[A[i]]], ... in that sequence. The cells visited are i, A[i], A[A[i]], A[A[A[i]]], ...A walk
starting from s will be eventually periodic. Indeed, there is an
initial part of the walk (may be empty). However, after the first duplication of a visited index, the
walk will be cyclic (that is, the same sequence of indices will be visited again and again). Print the
initial part of the walk (before the cycle begins), and the indices in the cycle in the sequence
as they are visited. Print also the length of the cycle.
n = 60
The array A is:
44 47 19 15 23 6 49 7 11 40
49 54 25 12 22 29 2 24 15 34
9 4 46 12 12 2 9 41 30 18
9 6 57 20 21 20 26 10 20 29
43 9 23 0 21 38 21 15 2 36
49 11 41 35 23 53 29 32 27 51
p = 31
Initial part:
31 6 49 36 26 9 40 43 0 44
Cyclic part:
21 4 23 12 25 2 19 34
Length of the cycle = 8

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
    int n,*A,*seq,seq_len,p,i,check,cyclic_start_index;
    printf("Enter no. of elements = ");
    scanf("%d",&n);
    A=(int *)malloc(n*sizeof(int));
    seq=(int *)malloc(n*sizeof(int));
    printf("\nEnter elements\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    printf("\nEnter p = ");
    scanf("%d",&p);
    check=0;
    seq[0]=p;
    seq_len=1;
    while (check!=1)
    {
        p=A[p];
        for(i=0;i<seq_len;i++)
        {
            if (p==seq[i])
            {
                check=1;
                cyclic_start_index=i;
                break;
            }
        }
        if(check!=1)
        {
            seq[seq_len]=p;
            seq_len++;
        }
    }
    printf("\nStroll is");
    for(i=0;i<cyclic_start_index;i++)
    {
        printf(" %d",seq[i]);
    }
    printf("\nLength = %d",cyclic_start_index);
    printf("\nCyclic part is");
    for(i=cyclic_start_index;i<seq_len;i++)
    {
        printf(" %d",seq[i]);
    }
    printf("\nLength = %d",seq_len-cyclic_start_index);








}
