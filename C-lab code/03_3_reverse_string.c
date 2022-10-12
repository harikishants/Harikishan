/*
Write a program that takes a single string as input and prints the
reverse of the string to the terminal. You are told that the input
string will contain at most 80 characters, and will not contain any
whitespace (blanks, tabs or newlines).

*/

#include<stdio.h>
#include<string.h>

int main()
{
    char a[80];
    /*gets(arr);
    printf("\n%s",strrev(arr));*/

    scanf("%s",a);
    //printf("\n%s",strrev(arr));

    //printf("\n%d",strlen(a));
    int l=strlen(a);
    //printf("%d",l);
    for(int i=l-1;i>=0;i--)
    {
      printf("%c",a[i]);
    }


    return 0;
}
