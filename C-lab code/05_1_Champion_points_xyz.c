/*Let P and Q be two points in the three-dimensional plane. We say that P dominates Q if all the
conditions x(P) ≥ x(Q), y(P) ≥ y(Q) and z(P) ≥ z(Q) are satisfied. A point P in a collection is called a
champion if P dominates all other points in the collection. Not all collections contain champions
(for example, consider the three points (1,1,1), (3,3,3), (2,2,4)). But if a champion exists in a
collection, it is unique. In this case, the champion has both the largest x-coordinate, the largest ycoordinate, and the largest z-coordinate in the collection.
Write a program that enters a loop. Each iteration of the loop body first reads the x-, y- and zcoordinates of a new point (call them x, y and z). Assume that x, y and z are integer values. If any
one of x, y or z is negative, then the program terminates. Otherwise, the champion among all the
points read so far is printed, provided that the champion exists. Maintain the largest x-coordinate
and the largest y-coordinate read so far. Suppose that just before reading the current point (x, y,
z), a champion existed. If the new point (x’, y’, z’) dominates the old champion, then the new point
now becomes the current champion. If the new point is dominated by the old champion, then the
old champion continues to remain the current champion. Otherwise, the current champion ceases
to exist.*/

#include<stdio.h>

void main()
{
    int n,x,y,z,c_x,c_y,c_z,champ;
    printf("Enter no. of points = ");
    scanf("%d",&n);
    printf("Enter points\n");
    c_x=c_y=c_z=0;

    for(int i=0;i<n;i++)
    {
        printf("\n");
        printf("x = ");
        scanf("%d",&x);
        printf("y = ");
        scanf("%d",&y);
        printf("z = ");
        scanf("%d",&z);

        if((x<0)||(y<0)||(z<0))
        {
            exit(1);
        }

        if((x>=c_x)&&(y>=c_y)&&(z>=c_z))
        {
            champ = 1;
        }
        else if ((x>c_x)||(y>c_y)||(z>c_z))
        {
            champ=0;
        }
        if(x>=c_x)
        {
            c_x=x;
        }
        if(y>=c_y)
        {
            c_y=y;
        }
        if(z>=c_z)
        {
            c_z=z;
        }
    }
    if (champ==0)
    {
        printf("\nNo champion exists");
    }
    else
    {
       printf("\nChampion (%d,%d,%d)",c_x,c_y,c_z);
    }


}
