/*
Read a sequence of integers and determine max(i)[Summation(j=0 to 4) a(i+j)]
*/
#include<stdio.h>
#include<string.h>

int main()
{
    int num[100];
    for(int i=0;i<100;i++)
    {
        scanf("%d", &num[i]);
        if (num[i]==EOF)
        {
            break;
        }
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ", num[i]);
    }

    printf("\n lenght is %lu", strlen(num));

    int max_sum=0,current_sum;

    for(int i=0;i<(sizeof(num)/4)-4;i++)
    {
        current_sum = num[i]+num[i+1]+num[i+2]+num[i+3]+num[i+4];
        printf("\nCurrent sum is %d",current_sum);
        if (current_sum>max_sum)
        {
            max_sum=current_sum;
        }
    }

    printf("\nMax sum is %d",max_sum);

    printf("\n sizeof %d",sizeof(num));


    return 0;
}
