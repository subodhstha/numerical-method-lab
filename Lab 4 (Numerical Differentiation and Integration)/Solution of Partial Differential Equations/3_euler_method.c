#include<stdio.h>
#include<conio.h>

#define f(x,y) x+y

int main()
{
    float x0, y0, xn, h, yn, slope;
    int i, n;    printf("Enter Initial Condition\n");
    printf("x0 = ");
    scanf("%f", &x0);
    printf("y0 = ");
    scanf("%f", &y0);
    printf("Enter calculation point xn = ");
    scanf("%f", &xn);
    printf("Enter number of steps: ");
    scanf("%d", &n);    
    h = (xn-x0)/n;  
    printf("\nx0\ty0\tslope\tyn\n");
    printf("------------------------------\n");
    for(i=0; i < n; i++)
    {
        slope = f(x0, y0);
        yn = y0 + h * slope;
        printf("%.4f\t%.4f\t%0.4f\t%.4f\n",x0,y0,slope,yn);
        y0 = yn;
        x0 = x0+h;
    }
    printf("\nValue of y at x = %0.2f is %0.3f",xn, yn);    
    getch();
    return 0;
}
/*output
Enter Initial Condition
x0 = 0
y0 = 1
Enter calculation point xn = 1
Enter number of steps: 3

x0      y0      slope   yn
------------------------------
0.0000  1.0000  1.0000  1.3333
0.3333  1.3333  1.6667  1.8889
0.6667  1.8889  2.5556  2.7407

Value of y at x = 1.00 is 2.741
*/