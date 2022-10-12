/*Write a program to determine the roots of a quadratic equation
ax2 + bx + c = 0. Your program should ask for the values of a, b
and c, and print the roots (real or complex)
*/

#include<stdio.h>
#include<math.h>

int main()
{
    float a,b,c,r1,r2,p;

    scanf("%f %f %f",&a,&b,&c);
    printf("\n%f %f %f",a,b,c);
    p = pow(b,2)-(4*a*c);

    printf("\nValue of p is %f",p);
    if (p>=0)
    {
      r1 = (-b+sqrt(p))/(2*a);
      r2 = (-b-sqrt(p))/(2*a);
      printf("\nRoots are %f and %f",r1,r2);
    }
    else
    {
        printf("\nComplex roots");
        float x,y;
        x = -b/(2*a);
        y = sqrt(-p)/(2*a);
        printf("\nRoots are %f+%fi and %f-%fi",x,y,x,y);

    }

    return 0;

}
