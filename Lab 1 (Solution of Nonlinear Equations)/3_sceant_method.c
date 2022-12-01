// Secant method

#include<stdio.h>
#include<conio.h>
#include<math.h>

#define F(x) (a3*x*x*x+a2*x*x+a1*x+a0)
float a0 , a1 , a2 , a3;

int main()
{
	int i;
	float x0 , x1 , x2 , fx0 , fx1 , E , Er;
	
	printf("Enter the coefficients a3, a2, a1, and a0:\n");
	scanf("%d %d %d %d",&a3,&a2,&a1,&a0);
	
	printf("Enter two initial guess and E :\n");
	scanf("%f %f %f",&x0,&x1,&E);
	
	while(1)
	{
		fx0 = F(x0);fx1 = F(x1); 
		
		x2 = x1-(fx1*(x1-x0))/(fx1-fx0);
		
		Er = (x2-x1)/x2;
		
		if(fabs(Er)<E)
			printf("Roots = %f\n",x2);
			break;
		
		x0=x1;
		
		if(i==50)
			break;
		
	}
	getch();
}