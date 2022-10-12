#include<stdio.h>
#include<math.h>

/*
1.a)Read floating point of coordinates of 3 points and compute area
 .b) Repeat for another traingle and determine whether two traingle is congruent.
 */
float distance(float x1,float y1,float x2,float y2);
int main()
{
    float ax1,ay1,ax2,ay2,ax3,ay3;
    float bx1,by1,bx2,by2,bx3,by3;
    double areaA, areaB;

    scanf("%f %f %f %f %f %f",&ax1, &ay1, &ax2, &ay2, &ax3, &ay3);
    scanf("%f %f %f %f %f %f",&bx1, &by1, &bx2, &by2, &bx3, &by3);

    printf("\n%f %f %f %f %f %f",ax1, ay1, ax2, ay2, ax3, ay3);
    printf("\n%f %f %f %f %f %f",bx1, by1, bx2, by2, bx3, by3);

    areaA = fabs(0.5*(ax1*(ay2-ay3)+ax2*(ay3-ay1)+ax3*(ay1-ay2)));
    areaB = fabs(0.5*(bx1*(by2-by3)+bx2*(by3-by1)+bx3*(by1-by2)));

    printf("\nArea A = %f \nArea B = %f", areaA, areaB);

    float distA1,distA2,distA3,distB1,distB2,distB3;

    distA1 = distance(ax1,ay1,ax2,ay2);
    distA2 = distance(ax1,ay1,ax3,ay3);
    distA3 = distance(ax2,ay2,ax3,ay3);
    distB1 = distance(bx1,by1,bx2,by2);
    distB2 = distance(bx1,by1,bx3,by3);
    distB3 = distance(bx2,by2,bx3,by3);

    printf("\n%f %f %f %f %f %f",distA1,distA2,distA3,distB1,distB2,distB3);

    float addA = distA1 + distA2 + distA3;
    float addB = distB1 + distB2 + distB3;
    float multA = distA1 * distA2 * distA3;
    float multB = distB1 * distB2 * distB3;

    if ((addA==addB)&&(multA==multB)&&(areaA==areaB))
    {
        printf("\nCongruent");
    }
    else
    {
        printf("\nNOT Congruent");
    }

    return 0;

}

float distance(float x1,float y1,float x2,float y2)
    {
    return sqrt(pow((x1-x2),2) + pow((y1-y2),2));
    }
