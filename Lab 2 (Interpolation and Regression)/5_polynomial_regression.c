// Polygon Regression
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int m,n;
    float a[20][20],b[20],z[20], x[20],fx[20];
    float sum,pivot,term; 
    printf("Enter no of data points\n"); 
    scanf("%d",&n); 
    printf("Enter degree of polynomial to be fitted\n"); 
    scanf("%d",&m); 
    printf("Enter data points (xi,fx(i))\n"); 
    for(int i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&fx[i]);
    }
    //Construction of coefficient matrix 
    for(int i=0;i<=m;i++) 
    for(int j=0;j<=m;j++)
    {
        sum=0;
        for(int k=0;k<n;k++) 
            sum=sum+pow(x[k],i+j);
        a[i][j]=sum;
    }
    //Construction of RHS vectors 
    for(int i=0;i<=m;i++)
    {
        sum=0;
        for(int k=0;k<n;k++)
        sum=sum+fx[k]*pow(x[k],i);
        b[i]=sum;
    }
    //Forward Elimination
    for (int k=0;k<m;k++) 
    {
        pivot=a[k][k];
            if (pivot<0.000001) 
                printf("Method failed\n");
        else
        for(int i=k+1;i<=m;i++)
        {
            term=a[i][k]/pivot; 
            for(int j=0;j<=m;j++)
            {
                a[i][j]=a[i][j]-a[k][j]*term;
            }
            b[i]=b[i]-b[k]*term;
        }
    }
    z[m]=b[m]/a[m][m];
    //Back substitution
    for(int i=m-1;i>=0;i--)
    {
        sum=0;
        for(int j=i+1;j<=m;j++)
        {
            sum=sum+a[i][j]*z[j];
        }
        z[i]=(b[i]-sum)/a[i][i];
    }
    printf("The polynomial of regression is :\n"); 
    printf("y=%f+ %fx",z[0],z[1]);
    for (int i = 2; i <= m; i++)
    {
        printf("+%fx^%d",z[i],i);
        getch();
        return 0;
    }
}