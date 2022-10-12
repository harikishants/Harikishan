/*
1. Run-length encoding and decoding.
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
string s′ to its original form s. For example, given a3bc2d, your
program should print aaabccd. Note that, given abcd, your program
should print abcd itself. The input format will be the same as for part
(a)
*/

#include<stdio.h>
#include<string.h>

void main()
{
    int count = 1,max_count = count;
    char c,prev;
    prev=getchar();
   while(EOF!=(c=getchar()))
   {
       if (prev==c)
       {
          count++;
          continue;
       }

       if (count>1)
        {
            printf("%c%d",prev,count);
        }
        if (count==1)
        {
            printf("%c",prev);
        }
        if(count>max_count)
        {
            max_count = count;
        }
        count = 1;
        prev = c;
    }
    printf("\nMax count is %d",max_count);
}
