#include<iostream>
#include<string>
#include<cstdio>
#define LL long long int
using namespace std;

int reminder(string s, LL num)
{
    LL l = s.size(), i, n = 0;

    for(int i=0; i < l; i++){
        n = ( n*10 + (s[i]-'0') ) % num;     //here we get mod of every number
    }

    return n;
}

int main()
{
    LL n;
    string a;
    int ans;

    cin >> a >> n;

    ans = reminder(a, n);

    cout << ans <<endl;

    return 0;
}
