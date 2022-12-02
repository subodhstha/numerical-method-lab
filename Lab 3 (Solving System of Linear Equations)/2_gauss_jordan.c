#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
    int n;
    float pivot, term, a[10][10];
    printf("Enter the Dimension of system of equation\n");
    scanf("%d",&n);
    printf("Enter the coefficients Augmented Matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    for (int k = 0; k < n; k++)
    {
        pivot = a[k][k];
        for (int p = 0; p < n + 1; p++)
        {
            a[k][p] = a[k][p]/pivot;
        }
        for (int i = 0; i < n; i++)
        {
            term = a[i][k];
            if (k != i)
            {
                for (int j = 0; j < n+1; j++)
                {
                    a[i][j] = a[i][j]-a[k][j]*term;
                }
            }
        }
        
    }
    printf("Solution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("x%d = %f\t",i+1,a[i][3]);
    }
    getch();
    return 0;
}