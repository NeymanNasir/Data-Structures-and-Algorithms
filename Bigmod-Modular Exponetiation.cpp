#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

/*int bigmod(int a, int b, int m)
{
    if(b == 0) return 1 % m;
    int x = bigmod(a, b/2, m);
    //printf("%d\n", x);
    x = (x * x) % m;
    if(b%2 == 1) x = (x * a) % m;

    return x;
}*/

int bigmod(int a, int b, int m)
{
    if(b == 0) return 1 % m; //Base Case

    if(b % 2 == 0){ // b is even
        int y = bigmod(a, b/2, m);
        return (y * y) %  m; //a^b = y * y
    }
    else{//b is odd
        //a^b = a * a^(b-1)
        return (a * bigmod(a, b - 1, m)) % m;
    }
}
int main()
{
    int x = bigmod(2, 5, 7);
    printf("%d\n",x);
    return 0;
}
