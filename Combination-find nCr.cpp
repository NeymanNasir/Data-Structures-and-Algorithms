#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

//according to geeksforgeeks
//A Naive recursive implementation
int findnCr(int n, int k)
{
    //Base Cases
    if(k == 0 || k == n)
        return 1;
    //recursion
    return findnCr(n - 1, k - 1) + findnCr(n - 1, k);
}
//A O(n*k) solution
int min(int a, int b)
{
    return (a<b)? a: b;
}

int binomialcoeff(int n, int k)
{
    int C[n+1][k+1];
    int i, j;

    for(i = 0; i <= n; i++){
        for(j = 0; j <= min(i, k); j++){
            //Base Case
            if(j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }

    return C[n][k];
}

int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    printf("nCr = %d\n", binomialcoeff(n, r));
    return 0;
}
