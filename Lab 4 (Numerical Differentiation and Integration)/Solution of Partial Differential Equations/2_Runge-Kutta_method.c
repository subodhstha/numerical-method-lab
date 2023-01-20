#include<stdio.h>
#include<math.h>
float f(float x,float y);
int main()
{
    float x0,y0,m1,m2,m3,m4,m,y,x,h,xn;
    printf("Enter x0,y0,xn,h:");
    scanf("%f %f %f %f",&x0,&y0,&xn,&h);
    x=x0;
    y=y0;
    printf("\n\nX\t\tY\n");
    while(x<xn)
    {
        m1=f(x0,y0);
        m2=f((x0+h/2.0),(y0+m1*h/2.0));
        m3=f((x0+h/2.0),(y0+m2*h/2.0));
        m4=f((x0+h),(y0+m3*h));
        m=((m1+2*m2+2*m3+m4)/6);
        y=y+m*h;
        x=x+h;
        printf("%f\t%f\n",x,y);
    }
}

float f(float x,float y)
{
    float m;
    m=(x-y)/(x+y);
    return m;
}

/*output
Enter x0,y0,xn,h:0
2
2
0.6


X               Y
0.600000        1.572659
1.200000        1.145317
1.800000        0.717976
2.400000        0.290634
*/