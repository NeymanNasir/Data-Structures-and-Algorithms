#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int binomialcoeff(int n, int k)
{
    int res = 1;

    //since C(n, k) = C(n, n-k)
    if(k > n-k)
        k = n-k;

    //calculate value of [n*(n-1)*---*(n-k+1)]/[k*(k-1)*---*1]
    for(int i = 0; i < k; i++)
    {
        res *= (n-i);
        res /= (i+1);
    }

    return res;
}

int main()
{
    int n, k;
    printf("Enter the value of n and k for finding nCk: \n");
    scanf("%d %d", &n, &k);

    int nck = binomialcoeff(n, k);
    printf("value of %dC%d is %d\n", n, k, nck);

    return 0;
}
