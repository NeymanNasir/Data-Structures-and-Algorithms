#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int findGCD(int a, int b)
{
    if(b == 0) return a;
    return findGCD(b, a%b);
}

int findLCM(int a, int b)
{
    int LCM = (a * b)/findGCD(a, b);

    return LCM;
}
int main()
{
    int a, b;
    printf("Enter the numbers those u want GCD and LCM: \n");
    scanf("%d %d", &a, &b);

    printf("GCD of %d and %d: %d\n", a, b, findGCD(a, b));
    printf("LCM of %d and %d: %d\n", a, b, findLCM(a, b));
    return 0;
}
