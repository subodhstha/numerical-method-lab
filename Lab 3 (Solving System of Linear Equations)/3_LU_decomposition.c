// LU decomposition
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int n;
    float sum = 0, a[10][10], b[10], x[10], z[10], u[10][10], l[10][10];
    printf("Enter the Dimension of System of equations\n");
    scanf("%d", &n);
    printf("Enter the coefficient matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    printf("Enter RHS vector\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&b[i]);
    }
    for (int j = 0; j < n; j++)
    {
        u[0][j]=a[0][j];
    }
    for (int i = 0; i < n; i++)
    {
        l[i][i] = 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        l[i][0] = a[i][0]/u[0][0];
    }
    for (int j = 1; j < n; j++)
    {
        for (int i = 1; i <= j; i++)
        {
            for (int k = 0; k <= j-1; k++)
            {
                sum = sum + (l[i][k]*u[k][j]);
            }
            u[i][j] = a[i][j]-sum;
            sum = 0;
        }
        for (int i = j+1; i < n; i++)
        {
            for (int k = 0; k <= j-1; k++)
            {
                sum = sum + (l[i][k]*u[k][j]);
            }
            l[i][j] = (a[i][j]-sum)/u[j][j];
            sum = 0;
        }
        
    }
    z[0] = b[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            sum = sum + (l[i][j]*z[j]);
        }
        z[i] = b[i] - sum;
        sum = 0;
    }
    x[n-1]=z[n-1]/u[n-1][n-1]; 
    for(int i=n-2;i>=0;i--)
    {
        for(int j=i+1;j<n;j++)
        {
            sum=sum+(u[i][j]*x[j]);
        }
        x[i]=(z[i]-sum)/u[i][i];
        sum=0;
    }
    printf("Solution:\n");
    for(int i=0;i<n;i++)
    {
        printf("x%d=%f\t",i+1,x[i]);
    }
    getch();
    return 0;
}
