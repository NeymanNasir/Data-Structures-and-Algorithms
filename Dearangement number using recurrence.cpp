#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

//tupi place arrange
//from mahbub sir book
int dearangement(int n)
{
    if(n == 0) return 1;
    else if(n == 1) return 0;
    else return (n - 1)*dearangement(n-2) + (n - 1)*dearangement(n-1);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("Arrangement number : %d\n", dearangement(n));
    return 0;
}
