// Write a C program for computing integration by using composite trapezoidal rule.

#include<stdio.h>
#include<math.h>
 
double f(double x){
    return x*x;
}
 

double trapezoidal(double f(double x), double a, double b, int n)
{
    double x,h,sum=0,integral;
    int i;
    h=fabs(b-a)/n;
    for(i=1;i<n;i++)
    {
        x=a+i*h;
        sum=sum+f(x);
    }
    integral=(h/2)*(f(a)+f(b)+2*sum);
    return integral;
}

int main()
{
    int n,i=2;
    double a,b,h,eps,sum=0,integral,integral_new;
    printf("\nEnter the initial limit: ");
    scanf("%lf",&a);
    printf("\nEnter the final limit: ");
    scanf("%lf",&b);
    printf("\nEnter the desired accuracy: ");
    scanf("%lf",&eps);
    integral_new=trapezoidal(f,a,b,i);
    do
    {
        integral=integral_new;
        i++;
        integral_new=trapezoidal(f,a,b,i);
    }while(fabs(integral_new-integral)>=eps);
    printf("The integral is: %lf\n with %d intervals",integral_new,i);
}

/*output
Enter the initial limit: 5

Enter the final limit: 10

Enter the desired accuracy: 0.005
The integral is: 291.713908
 with 21 intervals
*/