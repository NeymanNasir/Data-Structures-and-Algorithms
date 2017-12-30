#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    int N = 267;

        for(int i = 1; i*i <= N; i++){
            if(i*i == N) printf("%d\n", i);
            else if(N % i == 0) printf("%d\n%d\n", i, N/i);
        }


    return 0;
}

