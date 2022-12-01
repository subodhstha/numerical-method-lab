/*Write a program for Linear regression.
Time        0   10      15      20      22.5      30
Velocity    0   22704   362.78  517.35  602.97    901.67

determine the value of velocity at t=16.
*/
#include<stdio.h>
#include<conio.h>
int main()
{
    int n;
    float a=0,b=0,x[10],y[10],sx=0,sy=0,sxy=0,sx2=0;
    printf("Enter the number of points\n");
    scanf("%d",&n);
    printf("Enter the value of x and fx\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f%f",&x[i],&y[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sx=sx+x[i];
        sy=sy+y[i];
        sxy=sxy+x[i]*y[i];
        sx2=sx2+x[i]*x[i];
    }
    b=((n*sxy)-(sx*sy))/((n*sx2)-(sx*sx));
    a=(sy/n)-(b*sx/n);
    printf("Fitted line is: %f + %f x",a,b);
    getch();
}