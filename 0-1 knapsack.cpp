#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int knapsack(int W, int wt[], int val[], int n)
{
    int i, j;
    int K[n+1][W+1];
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
                 K[i][j] = 0;
            else if(j < wt[i-1])
                 K[i][j] = K[i-1][j];
            else
                K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]], K[i-1][j]);
        }
    }
    return K[n][W];
}
int main()
{
    int n, wt[50], val[50], W;
    cout << "enter the number of elements and weight and value of every element"<< endl;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    cout << "enter space of your storage: ";
    cin >> W;
    cout << "Maximum value U can steal: " << knapsack(W, wt, val, n) << endl;
    return 0;
}
