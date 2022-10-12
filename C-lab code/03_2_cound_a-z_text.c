/*
2 Write a program that reads text typed at the terminal, and counts
the number of occurrences of the letters a–z in the text. For this
problem, you should not distinguish between uppercase and
lowercase letters. The input text may span multiple lines, and may
contain digits, punctuation marks, blanks, tabs, and other printable
characters, which you should ignore.
*/

#include<stdio.h>

void main()
{
    int count[26];
    for(int i=0;i<26;i++)
    {
        count[i]=0;
        //printf("\n%c -> %d",(i+65),count[i]);
    }

    char c;
    while(EOF!=(c=getchar()))
    {
            if (65<=c<=90)
            {
            count[c-65]++;
            }
            if (97<=c<=122)
            {
            count[c-97]++;
            }

    }
    for(int i=0;i<26;i++)
    {
        printf("\n%c -> %d",(i+65),count[i]);
    }
}
