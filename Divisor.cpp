/*#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;

int divisors[100], d;
int Divisors(int n)
{
    int i, cnt = 0;
    for(i = 1; i*i <= n; i++){
        if(i*i == n){
           cnt++;
           divisors[d++] = i;
        }
        else if(n % i == 0){
            cnt += 2;
        divisors[d++] = i;
        divisors[d++] = n/i;
        }
    }

    return cnt;
}

int main()
{
    int i;
    printf("%d\n", Divisors(16));
    for(i = 0; divisors[i]; i++) printf("%d\t",divisors[i]);

}*/

//from progkriya.org

#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
#define Size 10000

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
}

int countdivisor(int n)
{
    int num = n;
    sieve();
    int divisor = 1, cnt , i, Sod = 1;

    for(i = 0; i < primes.size(); i++){
        if(n % primes[i] == 0){
            cnt = 1;
            //cout << primes[i] << endl;
            while(n % primes[i] == 0){
                n /= primes[i];
                cnt++;
            }
             Sod *= (pow(primes[i], cnt) - 1)/(primes[i] - 1);
            divisor *= cnt;
        }
    }

    printf("NOD of %d = %d\n", num, divisor);
    //printf("SOD of %d = %d\n", num, Sod);
    return 0;
}

/*if we need to find the value of nod very efficiently in time
we can find it by using half of size sieve() function.
here given sieve() size is 1000 here we can find the value of divisors
1000000.
#define Size 1000

vector<int> primes;
bool ara[Size+1];

int PrimeSize;
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
    PrimeSize = primes.size();
}

int countdivisor(int n)
{
    int nod  = 1;
    int k = 0;

    for(int j = primes[k]; k < PrimeSize && j*j <= n; j = primes[++k])
    {
        int cnt = 0;

        while(n % j == 0)
        {
            cnt++;
            n /= j;
        }
        nod *= cnt+1;
    }
    if(n != 1) nod *= 2;

    return nod;
}*/
int main()
{
   for(int i = 2; i <= 100; i++){
        printf("%d\t", i);
        countdivisor(i);
   }
    return 0;
}
