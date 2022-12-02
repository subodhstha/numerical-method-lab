// Gauss Elimination Method

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int n;
    float pivot, term, sum = 0, a[10][10],b[10],x[10];
    printf("Enter Dimension of System of equations\n");
    scanf("%d",&n);
    printf("Enter coefficients row-wise\n");
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
    for (int k = 0; k <= n-2; k++)
    {
        pivot = a[k][k];
        if (fabs(pivot) < 0.000001)
        {
            printf("Method failed\n");
            return 0;
        }
        else
        {
            for (int  i = k + 1; i < n; i++)
            {
                term = a[i][k]/pivot;
                for (int j = 0; j < n; j++)
                {
                    a[i][j] = a[i][j]-a[k][j]*term;
                }
                b[i] = b[i] - b[k]*term;
            }
        }
    }
    x[n-1] = b[n-1]/a[n-1][n-1];
    for (int i = n-2; i >= 0; i--)
    {
        sum = 0;
        for (int j = i + 1; j <= n-1; j++)
        {
            sum = sum + a[i][j]*x[j];
        }
        x[i] = (b[i]-sum)/a[i][i];
    }
    printf("Solution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %f\t",i+1,x[i]);
    }
    getch();
    return 0;
}