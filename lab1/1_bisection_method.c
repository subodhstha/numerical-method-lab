// write a C program for the following function 4x^3+2x^2+3x-6=0
//bisection method


#include<stdio.h>
#include<conio.h>
#include<math.h>
int a0,a1, a2, a3;
float f(float x)
{
	return (a3*x*x*x+a2*x*x+a1*x+a0);
}
int main()
{
	float x1,xm,xu,fx1,fxm,E,Era,fxu;
	printf("enter the coefficient a3,a2,a1,a0: ");
	scanf("%d %d%d%d",&a3,&a2,&a1,&a0);
	printf("enter initial guess and E(error): ");
	scanf("%f%f%f",&x1,&xu,&E);
	fx1=f(x1);
	fxu=f(xu);
	while(1)
	{
		fx1=f(x1);
   		fxu=f(xu);
   		xm=(x1+xu)/2;
   		fxm=f(xm);
   		if((fx1*fxm)==0)
   		printf("Root=%f\n",xm);
   		else if ((fx1*fxm)<0)
   		xu=xm;
   		else
   		x1=xm;
   		Era=(xu-x1)/xu;
   		if(Era<E)
   		{
   			printf("Root=%f\n",xm);
   			break;
	    }	
	}
	getch();
}