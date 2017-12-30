#include<iostream>
#include<cstdio>
using namespace std;
///from shafayet vai blog
int table[50][50];
int nCr(int n, int r)
{
    if(r == 1) return n;
    if(n == r) return 1;
    if(table[n][r] != -1)
        return table[n][r];

    table[n][r] = nCr(n-1, r) + nCr(n-1, r-1);
    return table[n][r];
}
int main()
{
    for(int i = 0; i < 50; i++)
        for(int j = 0; j < 50; j++)
            table[i][j] = -1;

    int n, r;
    scanf("%d %d", &n, &r);
    printf("nCr = %d\n", nCr(n, r));
    return 0;
}
