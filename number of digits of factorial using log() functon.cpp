#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

//we could use log() function
//we know that log(a x b) = log(a) + log(b);

int find_no_of_digits_of_facto(int n)
{
    double cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt += log10(i);
    }

    return 1 + floor(cnt);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("the number of digits of %d! = %d\n", n, find_no_of_digits_of_facto(n));
    return 0;
}
