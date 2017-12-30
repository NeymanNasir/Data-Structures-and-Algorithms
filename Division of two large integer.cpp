#include<iostream>
#include<cstdio>
#include<string>
#define LL long long int
using namespace std;

string division(string s, LL n)
{
    LL i, sum = 0, flg = 0, t, l = s.size();
    string ans;
    for(i = 0; i < l; i++)
    {
        sum = sum * 10 + (s[i] - '0'); //here we have integers from left side from normal division form
        t = sum / n;                   //here we find our quotiont(vagfal)
        if(t == 0 && flg == 0) continue;
        else
        {
            ans += t + '0';     //here we store our every quotiont
            flg = 1;
            sum = sum % n;
        }
    }
    if(flg == 0) ans = "0";

    return ans;
}
int main()
{
    string s, ans;
    LL n;

    cin >> s >> n;

    ans = division(s, n);

    cout << ans << endl;

    return 0;
}
