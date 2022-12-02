// Eigenvalue & Eigenvector
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
    int n, i;
    float el, k, E[10], a[10][10], nx[10], x[10], y[10];
     printf("Enter the Dimension of System of equations\n");
    scanf("%d", &n);
    printf("Enter the coefficient row-wise\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    printf("Enter guess vector\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f",&x[i]);
    }
    printf("Enter Accuracy Limit\n");
    scanf("%f",&el);
    while (1)
    {
        for (int i = 0; i < n; i++)
        {
            y[i] = a[i][0]*x[0]+a[i][1]*x[1]+a[i][2]*x[2];
        }
        k = y[0];
        for (int i = 0; i < n; i++)
        {
            if (k < y[i])
            {
                k = y[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            E[i] = (nx[i]-x[i])/nx[i];
            if (E[i] > el)
            {
                break;
            }
        }
        if (i == n)
        {
            printf("Largest Eigenvalue is %f\n",k);
            printf("Eigenvector is ");
            for (int i = 0; i < n; i++)
            {
                printf("%f\t",nx[i]);
            }
            break;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                x[i] = nx[i];
            }
        }
    }
    getch();
    return 0;
}