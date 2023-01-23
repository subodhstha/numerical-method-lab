// Write a C program for solving poison’s equation by using finite difference method.
//Assumption: fii=X1 f12=X2 f21=X3 f22=X4

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define g(x,y) 2*(x)*(x)*(y)*(y)
int main()
{
    int n,i,j,k;
    float sum,error,E[10],a[10][10],b[10],new_x[10],old_x[10],tl, tr, tu, tb,h;
    printf("Enter Dimension of plate \n");
    scanf("%d",&n);
    printf("Enter Dimension of grid \n");
    scanf("%f",&h);
    printf("Enter temperatures at left, right, bottom & upper part of plate \n");
    scanf("%f %f %f %f",&tl,&tr,&tb,&tu);
    for(i=0;i<=n;i++)
    	a[i][i]=-4;
    for(i=0;i<=n;i++)
    	a[i][n-i]=0;
    for(i=0;i<=n;i++)
    	for(j=0;j<=n;j++)
    	{
    		if(i!=j && j!=(n-i))
    		a[i][j]=1;
    	}	
    k=0;
    for(i=1;i<n;i++)
        for(j=1;j<n;j++)
            b[k++]=h*h*g(i,j);
    k=0;
    for(i=1;i<n;i++)
    {
    	for(j=1;j<n;j++)
    	{
    		if((i-1)==0)
    		    b[k]=b[k]-tl;
    		if((i+1)==n)
    		    b[k]=b[k]-tr;
    		if((j-1)==0)
    		    b[k]=b[k]-tb;
    		if((j+1)==n)
    		    b[k]=b[k]-tu;
    		k++;
    	}
    }
    printf("Enter Accuracy Limit \n");
    scanf("%f",&error);	
    for(i=0;i<=n;i++)
    {
        new_x[i]=0;	
    }
    while (1)
    {
    for(i=0;i<=n;i++)
    {
        sum=b[i];
        for(j=0;j<=n;j++)
        {
        	if(i!=j)
        	    sum=sum-a[i][j]*new_x[j];	
        }
        old_x[i]=new_x[i];
        new_x[i]=sum/a[i][i];
        E[i]=fabs(new_x[i]-old_x[i])/fabs(new_x[i]);
    }
    for(i=0;i<=n;i++)
    {
        if(E[i]>error)
        break;	
    }
    if(i==(n+1))
        break;
    else
        continue;	
    }
    printf("Solution:\n");
    for(i=0;i<=n;i++)
        printf("x%d=%6.2f\n",i+1,new_x[i]);
    getch();
    return 0;
}


/*output
Enter Dimension of plate
3
Enter Dimension of grid
1
Enter temperatures at left, right, bottom & upper part of plate
20
5
60
55
Enter Accuracy Limit
0.001
Solution:
x1= 34.25
x2= 30.75
x3= 28.25
x4= 21.75

*/
