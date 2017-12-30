//from forthright48
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int ext_gcd(int A, int B, int *X, int *Y)
{
    int x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for(r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y){
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;

    return r2;
}
//according to mahbub sir
int egcd(int a, int b, int &x, int &y)
{
    if(a == 0){
        x = 0; y = 1;
        return b;
    }

    int x1, y1;
    int d = egcd(b%a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return d;
}
//according to progkriya.org
typedef pair<int, int> pii;
#define x first
#define y second

pii extendedEuclid(int a, int b)//returns x, y / ax + by = gcd(a,b)
{
    if(b == 0) return pii(1, 0);
    else{
        pii d = entendedEuclid(b, a%b);
        return pii d.y, d.x - d.y * (a/b);
    }
}

int main()
{
    return 0;
}
