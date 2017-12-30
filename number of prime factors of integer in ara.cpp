#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

#define Size 1000000
int factor[Size + 10];

void number_of_primefactors_lies_in_n() //distinct prime factorization
{
    //primeFactorization
    for(int i = 2; i <= Size; i++)
    {
        if(factor[i] == 0)
        {
            for(int j = i; j <= Size; j += i) //here if a prime divide a
                factor[j]++;            //integer we increase divisor
        }
    }
}

int main()
{
    number_of_primefactors_lies_in_n();

    for(int i = 2; i <= 100; i++)
        printf("%d\t%d\n", i, factor[i]);

    return 0;
}

