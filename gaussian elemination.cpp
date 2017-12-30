//from greekforgreeks

#include<bits/stdc++.h>
using namespace std;

#define N 3    //Number of unknowns

int forwardElim(double mat[N][N+1]);

void backSub(double mat[N][N+1]);

//function to get matrix content
void gaussianElimination(double mat[N][N+1])
{
    int singular_flag = forwardElim(mat);

    if(singular_flag != -1)
    {
        printf("Singular Matrix.\n");

        if(mat[singular_flag][N])
            printf("Inconsistent system.");
        else
            printf("May have infinitely many solutions.");

        return;
    }

    backSub(mat);
}

void swap_row(double mat[N][N+1], int i, int j)
{
    for(int k=0; k<=N; k++)
    {
        double temp = mat[i][k];
        mat[i][k] = mat[j][k];
        mat[j][k] = temp;
    }
}

void print(double mat[N][N+1])
{
    for(int i=0; i<N; i++, printf("\n"))
        for(int j=0; j<=N; j++)
        printf("%.1lf ", mat[i][j]);

    printf("\n");
}

int forwardElim(double mat[N][N+1])
{
    for(int k=0; k<N; k++)
    {
        int i_max = k;
        int v_max = mat[i_max][k];

        for(int i = k+1; i < N; i++)
            if(abs(mat[i][k]) > v_max)
            v_max = mat[i][k], i_max = i;

        if(!mat[k][i_max])
            return k;

        if(i_max != k)
            swap_row(mat, k, i_max);

        for(int i = k+1; i < N; i++)
        {
            double f = mat[i][k]/mat[k][k];

            for(int j = k+1; j <= N; j++)
                mat[i][j] -= mat[k][j]*f;

            mat[i][k] = 0;
        }
    }

    return -1;
}

//function to calculate the values of unknowns
void backSub(double mat[N][N+1])
{
    double x[N];

    /*start calculating from last equation up to the first*/
    for(int i = N-1; i >= 0; i--)
    {
        x[i] = mat[i][N];

        for(int j = i+1; j < N; j++)
        {
            x[i] -= mat[i][j]*x[j];
        }
        x[i] = x[i]/mat[i][i];
    }

    printf("\nSolution for the system:\n");
    for(int i = 0; i < N; i++)
        printf("%.1lf\n", x[i]);
}

int main()
{
    double mat[N][N+1] = {{3.0, 2.0, -4.0, 3.0},
                          {2.0, 3.0, 3.0, 15.0},
                          {5.0, -3, 1.0, 14.0}
                         };

    gaussianElimination(mat);

    return 0;
}
