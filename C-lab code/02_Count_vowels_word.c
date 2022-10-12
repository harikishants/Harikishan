/*
Write a program that reads text typed at the terminal, and counts
(a) the number of occurrences of vowels in the input text;
(b) the number of words in the input text. Assume that any contiguous
sequence of letters and / or digits forms one word.
*/
#include<stdio.h>
int main()
{
    int c,vowel_count=0,word_count=0;
    while(EOF!=(c=getchar()))
    {
        if ((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u'))
        {
            vowel_count++;
        }

        if ((c=='A')||(c=='E')||(c=='I')||(c=='O')||(c=='U'))
        {
            vowel_count++;
        }
        if ((c==' ')||(c=='\n'))
        {
            word_count++;
        }
    }
    printf("Vowel count is %d\n Word count is %d\n",vowel_count,word_count);

    return 0;
}
