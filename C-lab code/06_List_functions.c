#include<stdio.h>
#include<stdlib.h>

typedef struct
    {
        int size;
        int *arr;
    }LIST;

LIST create_list()
{
    LIST L;
    L.size = 0;
    L.arr =  NULL;
    return L;
}

void print_list(LIST L)
{
    int i;
    for(i=0;i<L.size;i++)
    {
        printf("%d ",L.arr[i]);
    }
    putchar('\n');
}

LIST append(LIST L,int a)
{
    L.size++;
    if(NULL==(L.arr=(int *)realloc(L.arr,L.size*sizeof(int))))
    {
        printf("\nERROR");
        exit(1);
    }
    L.arr[L.size-1] = a;
    return L;
}

LIST prepend(LIST L,int a)
{
    L.size++;
    if(NULL==(L.arr=(int *)realloc(L.arr,L.size*sizeof(int))))
    {
        printf("\nERROR");
        exit(1);
    }
    int i;
    for(i=L.size-1;i>0;i--)
    {
        L.arr[i] = L.arr[i-1];
    }
    L.arr[0] = a;
    return L;

}

LIST deletelast(LIST L)
{
    L.size--;
    if(NULL==(L.arr=(int *)realloc(L.arr,L.size*sizeof(int))))
    {
        printf("\nERROR");
        exit(1);
    }
    return L;

}

LIST deletefirst(LIST L)
{
    L.size--;
    int i;
    for(i=0;i<L.size;i++)
    {
        L.arr[i] = L.arr[i+1];
    }
    if(NULL==(L.arr=(int *)realloc(L.arr,L.size*sizeof(int))))
    {
        printf("\nERROR");
        exit(1);
    }
    return L;
}

LIST deleteall(LIST L, int a)
{
    int i,j=0;
    for(i=0;i<L.size;i++)
    {
        if(L.arr[i]!=a)
        {
            L.arr[j]=L.arr[i];
            j++;
        }
    }
    L.size=j;
    if (L.size==0)
    {
        L.arr=NULL;
    }
    else if(NULL==(L.arr=(int *)realloc(L.arr,L.size*sizeof(int))))
    {
        printf("\nERROR");
        exit(1);
    }
    return L;
}
void main()
{
    LIST l = create_list();
    /*L = append(L,1);
    L = append(L,5);
    L = append(L,7);
    L = append(L,7);
    L = append(L,9);
    //L = prepend(L,20);
    //L = prepend(L,30);
    //L = deletelast(L);
    //L = deletefirst(L);
    L = deleteall(L,7);
    print_list(L);*/

    /*
    l = append(l,2);
    l = append(l,2);
    l = append(l,2);
    l = append(l,2);
    l = append(l,2);

    l = deleteall(l,2);

    print_list(l);

*/


    l=append(l,9);
    l=append(l,1);
    l=append(l,2);
    l=append(l,3);
    l=append(l,6);
    l=append(l,7);
    l=append(l,8);
    l=append(l,4);
    l=append(l,2);
    l=append(l,3);

   //print_list(l);

    l=prepend(l,9);
    l=prepend(l,2);
    l=prepend(l,4);
    l=prepend(l,8);
    l=prepend(l,2);
    l=prepend(l,5);
    l=prepend(l,9);
    l=prepend(l,8);
    l=prepend(l,9);
    l=prepend(l,1);

       // print_list(l);

    l=deletelast(l);
    l=deletelast(l);
    l=deletelast(l);
    l=deletelast(l);
    l=deletelast(l);

        //print_list(l);

    l=deletefirst(l);
    l=deletefirst(l);
    l=deletefirst(l);
    l=deletefirst(l);
    l=deletefirst(l);

    //print_list(l);

    l=deleteall(l,7);
     //print_list(l);
    l=deleteall(l,2);
     //print_list(l);
    l=deleteall(l,9);
     //print_list(l);
    l=deleteall(l,4);
     //print_list(l);
    l=deleteall(l,7);

    print_list(l);

    free(l.arr);
}
