#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

/*#define Size 100

vector<int> primes;
int phi[Size];
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
}

void numbersofPhi(int n)//all values of phi(n) from 1 to n
{
    sieve();
    int i, j;
    for(i = 1; i <= n; i++) phi[i] = i;

    for(i = 2; i <= n; i++){
        if(ara[i] == 0){//if i is prime
            for(j = i; j <=  n; j += i){
                ara[j] = 1;

                phi[j] -= phi[j]/i;
            }
        }
    }
}

int Eulersphi(int n) //naive implementation
{
    sieve();
    int ret = n;
    for(int i = 0; i < primes.size(); i++){
        if(n % primes[i] == 0){
            ret -= ret / primes[i];
        }
    }

    return ret;
}*/

int Eulersphioptimaized(int n) //without any help of sieve function
{
    int ret = n;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
            }
            ret -= ret / i;
        }
    }

    // this case will happen if n is a prime
    if(n > 1) ret -= ret / n;
    return ret;
}

int main()
{
    int n = 12;
    //printf("Phi(%d) = %d\n",n, Eulersphi(n));
    //numbersofPhi(12);
    //for(int i = 1; phi[i]; i++) printf("%d\t", phi[i]);
    printf("Phi(%d) = %d\n",n, Eulersphioptimaized(n));
    return 0;
}
