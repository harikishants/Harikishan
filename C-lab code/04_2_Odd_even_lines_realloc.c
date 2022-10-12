/*
Write a program that first reads multiple lines of text from the terminal,
and then, depending on the user’s choice, prints either the odd- or the
even-numbered lines, either in their original or in reverse order.
You may assume that
lines are numbered starting with one;
each line is no more than 80 characters long;
the input text will not consist of more than 10 lines.
Redesign your program so that it will run correctly even if the number
of lines in the input text is not known a priori.
*/

#include<stdio.h>

void main()
{
    int rows=4,cols=80,i,j,line=0;
    char **a,c=0;

    if(NULL==(a = (char **)calloc(rows,sizeof(char*))))
    {
        printf("\nERROR\n");
    }
    for(i=0;(i<rows);i++)
    {
        if(NULL==(a[i] = (char *)calloc(cols,sizeof(char))))
        {
            printf("\nERROR\n");
        }
        j=0;
        while(((c=getchar())!='\n')&&(c!=EOF))
        {
            a[i][j]=c;
            j++;

        }
        if(c==EOF)
        {
            break;
        }
        line++;
        if(line==rows)
        {
            rows*=3;
            if(NULL==(a=(char **)realloc(a,rows*sizeof(char))))
            {
                printf("\nERROR\n");
            }
        }


    }
    printf("\nRows = %d, Line = %d\n",rows,line);

    for(i=0;i<line;i++)
    {
        printf("\nRow %d -> ",i);
        for(j=0;j<cols;j++)
        {
            printf("%c",a[i][j]);
        }
    }
    int oe,r;
    printf("\nEnter 1 for odd rows and 2 for even rows");
    scanf("%d",&oe);
    printf("\nEnter 1 for normal order and 2 for reverse order");
    scanf("%d",&r);

 if((oe==1)&&(r==1))
    {
        for(i=1;i<line;i=i+2)
            {
            printf("\nOdd row %d -> %s",i,a[i]);
            }
    }
if    ((oe==2)&&(r==1))
    {
       for(i=0;i<line;i=i+2)
            {
            printf("\nEven row %d -> %s",i,a[i]);
            }
    }

    if((oe==1)&&(r==2))
    {
        if(line%2!=0)
        {
            for(i=line-2;i>=0;i=i-2)
            {
              printf("\nOdd row %d -> %s",i,a[i]);
            }
        }
        else
        {
            for(i=line-1;i>=0;i=i-2)
            {
              printf("\nOdd row %d -> %s",i,a[i]);
            }
        }
    }

        if((oe==2)&&(r==2))
    {
        if(line%2!=0)
        {
            for(i=line-1;i>=0;i=i-2)
            {
              printf("\nEven row %d -> %s",i,a[i]);
            }
        }
        else
        {
            for(i=line-2;i>=0;i=i-2)
            {
              printf("\nEven row %d -> %s",i,a[i]);
            }
        }
    }

}

