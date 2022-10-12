/*
Run-length encoding and decoding.
(a) Write a program to convert a given string s to s
′
, its run-length
encoded form. This means that s
′ will contain the same sequence
of distinct characters as s, but any m > 1 consecutive occurrences
of a character will be replaced by a single occurrence of the
character immediately followed by the integer m (in base 10). For
example, aaabccd should be converted to a3bc2d.
The string s should be read from the terminal. It may contain letters,
digits, blanks and tabs (’\t’), but no newline. The length of the
string s will not be known to you in advance.
(b) Add code to your program so that it prints the character that occurs
consecutively the maximum number of times. For the example
above, your program should print a. If the maximum number of
consecutive occurrences is the same for two or more characters,
you may print any one.
Intro. to Prog. (ISI) Simple Arrays and Strings 5 / 6
Programming problems II
(c) Modify your program so that it decodes a given run-length encoded
string s
′
to its original form s. For example, given a3bc2d, your
program should print aaabccd. Note that, given abcd, your program
should print abcd itself. The input format will be the same as for part
(a)
*/

#include<stdio.h>
#include<string.h>

void main()
{
    char str[100];
    gets(str);
    int l=strlen(str),count;
    printf("%c",str[0]);
    for(int i=1;i<l;i++)
    {
        //printf("\nstr is %c",str[i]);
        //printf("%c",str[i]);
        if ((str[i]-'0'>1)&&(str[i]-'0'<10))
        {
            int count = str[i]-'0';
            for(int j=0;j<count-1;j++)
            {
                printf("%c",str[i-1]);
            }

        }
        else
        {
        printf("%c",str[i]);
        }
    }
}
