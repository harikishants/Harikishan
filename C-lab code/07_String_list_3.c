
//Passing address of LIST instead of passing entire list

#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define MAXLEN 10
typedef char MYSTRING[10];

typedef struct
{
    int size;
    char **list1;
    //char list2[][10];
    //MYSTRING *list3;
    //char (*list4)[10];

}LIST;

LIST create_list()
{
    LIST L;
    L.size=0;
    L.list1 = NULL;
    //L.list3 = NULL;
    //L.list4 = NULL;
    return L;
}

void init_list(LIST *l)
{
    l->size=0;
    l->list1 = NULL;
}
void printlist(LIST *L)
{
    for(int i=0;i<L->size;i++)
    {
        printf("%s ",L->list1[i]);
        //printf("%s ",L.list3[i]);
        //printf("%s ",L.list4[i]);
    }
    printf("\n");
}

void append(LIST *L, char *a)
{
    L->size++;

    if(NULL==(L->list1=(char **)realloc(L->list1,L->size*sizeof(char *))))
    {
        printf("\nERROR");
    }

    if(NULL==(L->list1[L->size-1]=(char*)malloc(10*sizeof(char))))
    {
        printf("\nERROR");
    }
    strcpy(L->list1[L->size-1],a);
    L->list1[L->size-1] = strdup(a);

    /*if(NULL==(L.list3=(MYSTRING*)realloc(L.list3,L.size*sizeof(MYSTRING))))
    {
        printf("\nERROR");
    }
    strncpy(L.list3[L.size-1],a,10);*/

    /*if(NULL==(L.list4=(char (*)[10])realloc(L.list4,L.size*sizeof(char (*)[10]))))
    {
        printf("\nERROR");
    }
    strncpy(L.list4[L.size-1],a,10);*/
    //return L;
}


void main()
{
    LIST l;
	init_list(&l);
	int i=0;
    /*char buf[10];
    int i;
	for(i=0;i<3;i++)
    {
        scanf("%9s",buf);
        buf[9]='\0';
        l = append(l,buf);
    }*/

	/*l=append(l,"apple");
	//printlist(l);
	l=append(l,"lemon");
	//printlist(l);
	l=append(l,"banana");*/

	append(&l,"apple");
    append(&l,"mango");
	printlist(&l);

	printf("\n%lu %lu %lu %lu %lu %lu",&(l.list1),&(l.size),&i,&(l.list1[0]),&(l.list1[1]),l.list1[0]);

}



