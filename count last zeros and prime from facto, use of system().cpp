#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;

// to find this we just count the number of
// fives, here every 5 * 2 makes 10.
// And Every 10 gives zeros at last of factorial of any number.

int lastzerosfacto(int n)
{
    int five = 5;
    int fives = n;
    int zeros = 0;
    while(fives != 0)
    {
        fives = n / five;
        zeros += fives;
        five *= five;
    }
    return zeros;
}
//the number of primes in n!
int numberofprimes(int n, int p)
{
    int num = n;
    int cnt = 0;
    while(num != 0)
    {
        num = n / p;
        cnt += num;
        p *= p;
    }

    return cnt;
}
int main()
{
    int p, m;
    int n;
    scanf("%d", &n);
    printf("%d! have zeros at last digits = %d\n", n, lastzerosfacto(n));
    printf("If u want to find number of prime p in n!, then enter.....");
    system("pause");
    scanf("%d %d", &m, &p);
    printf("number of the prime %d in %d! is = %d\n", p, m, numberofprimes(m, p));
    return 0;
}
