#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
#define Size 100

vector<int> primes;
int ara[(Size>>5)+2];  //here we use bit of int.
                    //so for size 100, we need arasize 100/32 integer
bool Check(int N, int pos)
{
    return(bool)(N & (1<<pos));
}

int Set(int N, int pos)
{
    N = N | (1<<pos);
    return N;
}

void sieve()
{
    int i, j;
    int limit = sqrt(Size * 1.) + 2;

    ara[0] = Set(ara[0], 0);
    ara[0] = Set(ara[0], 1);

    for(int i = 4; i <= Size; i += 2)
        ara[i>>5] = Set(ara[i>>5], i&31);

    primes.push_back(2);

    for(i = 3; i <= Size; i += 2){
        if(Check(ara[i>>5], i&31) == 0){
            primes.push_back(i);

            if(i <= limit){
                for(j = i*i; j <= Size; j += (i<<1)){
                    ara[j>>5] = Set(ara[j>>5], j&31);
                }
            }
        }
    }
}
int main()
{
    sieve();
    int n;
    scanf("%d", &n);

    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(Check(ara[i>>5], i&31)== 0)cnt++;
    }

    printf("%d\n", cnt);

}
