/*#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define size 1000
bool ara[size];

void sieve()
{
    int i, j, limit;
    limit = sqrt(size + 1);
    ara[1] = 1;
    for(i = 4; i < size; i += 2) ara[i] = 1;

    for(i = 3; i <= limit; i += 2){
        if(ara[i] == 0){
            for(j = i*i; j <= size; j += i*2){
                ara[j] = 1;
            }
        }
    }
}
int main()
{
    sieve();
    for(int i = 1; i < 100; i++){
        if(ara[i] == 0) printf("%d\t", i);
    }
    return 0;
}
*/

//from mahbub sir book

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define size 1000
int prime[500], p;
bool ara[size+1];

void sieve()
{
    int limit, i, j;
    limit = sqrt(size * 1.) + 2;

    ara[1] = 1;
    for(i = 4; i <= size; i += 2) ara[i] = 1;

    prime[p++] = 2;

    for(i = 3; i <= size; i += 2)
        if(ara[i] == 0){
            prime[p++] = i;

            if(i <= limit){
                for(j = i * i; j <= size; j += i*2){
                    ara[j] = 1;
                }
            }
        }
}

/*#define Size 100

vector<int> primes;
bool ara[Size+1];

void sieve()
{
    int i, j;
    int limit = sqrt(Size * 1.) + 2;

    ara[1] = 1;
    for(i = 4; i <= Size; i += 2) ara[i] = 1;

    primes.push_back(2);

    for(i = 3; i <= Size; i += 2){
        if(ara[i] == 0){
            primes.push_back(i);

            if(i <= limit){
                for(j = i*i; j <= Size; j += i*2) ara[j] = 1;
            }
        }
    }
}*/
int main()
{
    sieve();
    for(p = 1; prime[p]; p++) printf("%d\t", prime[p-1]);
    return 0;
}
